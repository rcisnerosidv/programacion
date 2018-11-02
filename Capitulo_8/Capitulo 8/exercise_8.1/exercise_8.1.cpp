#include "Includes.h"


struct Token {
	char kind;
	double value;
	string varname;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string val) :kind(ch), varname(val) { }
};

struct Token_stream {
	istream & str;
	bool full;
	Token buffer;

	Token_stream(istream & arg) : str(arg), full(0), buffer(' ') { }
	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};


const char let = 'L';
const char constant = 'C';
const char reset = 'R';
const char sqroot = 'S';
const char power = 'P';
const char quit = 'Q';
const char help = 'H';
const char print = ';';
const char number = '8';
const char name = 'a';



Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	str >> ch;
	if (!str) return(Token(quit));
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	str.unget();
	double val;
	str >> val;
	if (!str) error("Bad token");
	return Token(number, val);
	}
	default:
		if (isalpha(ch) || ch == '_') {
			string s;
			s += ch;
			while (str.get(ch) &&
				(isalpha(ch) || isdigit(ch) || ch == '_'))
				s += ch;
			str.unget();
			if (!str) error("Bad token");
			if (s == "let") return Token(let);
			if (s == "const") return Token(constant);
			if (s == "reset") return Token(reset);
			if (s == "sqrt") return Token(sqroot);
			if (s == "pow") return Token(power);
			if (s == "help") return Token(help);
			if (s == "quit" || s == "exit")
				return Token(quit);  // FIX 1
			return Token(name, s);
		}
		error("Bad token");
		return Token(' ');
	}
}


void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (str >> ch)
		if (ch == c) return;
}



struct Variable {
	string name;
	double value;
	bool immutable;
	Variable(string n, double v, bool b) :
		name(n), value(v), immutable(b) { }
};



class Symbol_table {
	vector<Variable> names;
public:



	double get(string s)
	{
		for (int i = 0; i<int(names.size()); ++i)
			if (names[i].name == s) return names[i].value;
		error("get: undefined name ", s);
		return 0.0;
	}



	void set(string s, double d)
	{
		for (int i = 0; i <= int(names.size()); ++i)
			if (names[i].name == s) {
				names[i].value = d;
				return;
			}
		error("set: undefined name ", s);
	}



	void declare(string s, double d, bool b)
	{
		for (int i = 0; i<int(names.size()); ++i)
			if (names[i].name == s) error("declare: existing name ", s);
		names.push_back(Variable(s, d, b));
	}


	bool is_declared(string s)
	{
		for (int i = 0; i<int(names.size()); ++i)
			if (names[i].name == s) return true;
		return false;
	}


	bool is_immutable(string s)
	{
		for (int i = 0; i<int(names.size()); ++i)
			if (names[i].name == s && names[i].immutable) return true;
		return false;
	}

};

Symbol_table symbols;


double expression(Token_stream &);

double powerup(Token_stream &str)
{
	Token t = str.get();
	if (t.kind != '(') error("'(' expected");
	double x = expression(str);
	t = str.get();
	if (t.kind != ',') error("',' expected");
	double y = expression(str);
	int n = int(y);
	if (n != y) error("non-integral powers not supported");
	t = str.get();
	if (t.kind != ')') error("')' expected");
	y = 1.0;
	if (n < 0)
		for (int i = 0; i < n; ++i) y /= x;
	else
		for (int i = 0; i < n; ++i) y *= x;
	return y;
}



double primary(Token_stream &str)
{
	Token t = str.get();
	switch (t.kind) {
	case '(':
	{	double d = expression(str);
	t = str.get();
	if (t.kind != ')') error("')' expected");
	return d;
	}
	case '-':
		return -primary(str);
	case '+':
		return +primary(str);
	case number:
		return t.value;
	case sqroot:
	{       t = str.get();
	if (t.kind != '(') error("')' expected");
	str.unget(t);
	double x = primary(str);
	if (x < 0.0) error("square root of negative number");
	return sqrt(x);
	}
	case power:
		return powerup(str);
	case name:
		return symbols.get(t.varname);
	default:
		error("primary expected");
		return 0.0;
	}
}


double term(Token_stream &str)
{
	double left = primary(str);
	while (true) {
		Token t = str.get();
		switch (t.kind) {
		case '*':
			left *= primary(str);
			break;
		case '/':
		{	double d = primary(str);
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		case '%':
		{	double d = primary(str);
		if (d == 0) error("remainder by zero");
		left -= int(left / d)*d;
		break;
		}
		default:
			str.unget(t);
			return left;
		}
	}
}


double expression(Token_stream &str)
{
	double left = term(str);
	while (true) {
		Token t = str.get();
		switch (t.kind) {
		case '+':
			left += term(str);
			break;
		case '-':
			left -= term(str);
			break;
		default:
			str.unget(t);
			return left;
		}
	}
}


double declaration(Token_stream &str, char kind)
{
	Token t = str.get();
	if (t.kind != name) error("name expected in declaration");
	string name = t.varname;
	if (kind == let || kind == constant) {
		if (symbols.is_declared(name)) error(name, " declared twice");
	}
	else if (kind == reset) {
		if (!symbols.is_declared(name))
			error(name, " has not been declared");
		if (symbols.is_immutable(name))
			error(name, " is a constant");
	}
	else
		error("unknown statement");
	Token t2 = str.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression(str);
	if (symbols.is_declared(name))
		symbols.set(name, d);
	else
		symbols.declare(name, d, (kind == constant));
	return d;
}

void showhelp()
{
	cout << "Commands:" << endl;
	cout << "    let <name> = <expression> ;    Define a variable" << endl;
	cout << "    const <name> = <expression> ;    Define a constant" << endl;
	cout << "    reset <name> = <expression> ;    Reset a variable" << endl;
	cout << "    quit ;    (or exit) Stop execution" << endl;
	cout << "    help ;    What you are doing" << endl;
	cout << "Names may include letters and underscores" << endl;
	cout << "Expressions are fixed-point decimal numbers, and" << endl;
	cout << "     the usual operators +, -, *, / and % (remainder)" << endl;
	cout << "Parentheses () may be used for grouping" << endl;
	cout << "Functions are square root sqrt(<expression> and" << endl;
	cout << "    exponentiation pow(<expression>,<expression>)" << endl;
}


double statement(Token_stream &str)
{
	Token t = str.get();
	double d;
	if (t.kind == let || t.kind == reset || t.kind == constant)
		d = declaration(str, t.kind);
	else {
		str.unget(t);
		d = expression(str);
	}
	t = str.get();
	if (t.kind != print) error("Missing terminator");
	return d;
}



void clean_up_mess(Token_stream &str)
{
	str.ignore(print);
}


const string prompt = "> ";
const string result = "= ";



void calculate(Token_stream &str)
{
	while (str.str)
		try {
		cout << prompt;
		Token t = str.get();
		if (t.kind == print)
			;
		else if (t.kind == quit)
			return;
		else if (t.kind == help)
			showhelp();
		else {
			str.unget(t);
			cout << result << statement(str) << endl;
		}
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess(str);
	}
}


int main() {
	Token_stream ts(cin);
	Token k(name, "k");
	symbols.declare("k", 1000, true);
	calculate(ts);
	system("pause");
	return 0;
}