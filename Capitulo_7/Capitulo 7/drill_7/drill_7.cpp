#include "Includes.h"

struct Token {
	char kind;
	double value;
	string varname;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string val) :kind(ch), varname(val) { }
};


class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(' ') { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};


const char let = 'L';
const char sqroot = 'S';
const char power = 'P';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';

Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	if (!cin) return(Token(quit));
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
	case '#':
		return Token(let);
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
	{	cin.unget();
	double val;
	cin >> val;
	if (!cin) error("Bad token");
	return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
				s += ch;
			cin.unget();
			if (!cin) error("Bad token");
			if (s == "let") return Token(let);
			if (s == "sqrt") return Token(sqroot);
			if (s == "pow") return Token(power);
			if (s == "q" || s == "quit" || s == "exit")
				return Token(quit);  
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
	while (cin >> ch)
		if (ch == c) return;
}


struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

double get_value(string s)
{
	for (int i = 0; i<int(names.size()); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
	return 0.0;
}


void set_value(string s, double d)
{
	for (int i = 0; i <= int(names.size()); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}


bool is_declared(string s)
{
	for (int i = 0; i<int(names.size()); ++i)
		if (names[i].name == s) return true;
	return false;
}


Token_stream ts;


double expression();

double powerup()
{
	Token t = ts.get();
	if (t.kind != '(') error("'(' expected");
	double x = expression();
	t = ts.get();
	if (t.kind != ',') error("',' expected");
	double y = expression();
	int n = int(y);
	if (n != y) error("non-integral powers not supported");
	t = ts.get();
	if (t.kind != ')') error("')' expected");
	y = 1.0;
	if (n < 0)
		for (int i = 0; i < n; ++i) y /= x;
	else
		for (int i = 0; i < n; ++i) y *= x;
	return y;
}


double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("')' expected");
	return d;
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case sqroot:
	{       t = ts.get();
	if (t.kind != '(') error("')' expected");
	ts.unget(t);
	double x = primary();
	if (x < 0.0) error("square root of negative number");
	return sqrt(x);
	}
	case power:
		return powerup();
	case name:
		return get_value(t.varname);
	default:
		error("primary expected");
		return 0.0;
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string name = t.varname;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

double statement()
{
	Token t = ts.get();
	double d;
	if (t.kind == let)
		d = declaration();
	else {
		ts.unget(t);
		d = expression();
	}
	t = ts.get();
	if (t.kind != print) error("Missing terminator");
	return d;
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";


void calculate()
{
	while (cin)
		try {
		cout << prompt;
		Token t = ts.get();
		if (t.kind == print)
			;
		else if (t.kind == quit)
			return;
		else {
			ts.unget(t);
			cout << result << statement() << endl;
		}
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}



int main() {
	Token k(name, "k");
	names.push_back(Variable("k", 1000));
	calculate();
	return 0;
}