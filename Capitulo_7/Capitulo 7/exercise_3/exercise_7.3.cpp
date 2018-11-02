#include "Includes.h"

struct Token {
	char kind;
	double value;
	string varname;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string val) :kind(ch), varname(val) { }
};

/* This is a token stream, with buffer being the lookahead character
if full is true.  buffer is initialised more cleanly [ NONFIX ].  See
below for the methods.
*/

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(' ') { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};

// Definitions for Token kind codes, which would be better next to it.

const char let = 'L';
const char constant = 'C';
const char reset = 'R';
const char sqroot = 'S';
const char power = 'P';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';

// Get a character from a Token stream, filling from cin, as necessary.
// It detects bad input, crudely [ NONFIX ], and handles EOF correctly
// [ FIX? ].

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
		// Numbers are handled by using the built-in integer reader once
		// a digit is found.
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
	// Anything else is a name.  I don't like reading beyond the end, and
	// backing off, but the standard requires it to work even at EOF.
	default:
		if (isalpha(ch) || ch == '_') {
			string s;
			s += ch;
			while (cin.get(ch) &&
				(isalpha(ch) || isdigit(ch) || ch == '_'))
				s += ch;
			cin.unget();
			if (!cin) error("Bad token");
			if (s == "let") return Token(let);
			if (s == "const") return Token(constant);
			if (s == "reset") return Token(reset);
			if (s == "sqrt") return Token(sqroot);
			if (s == "pow") return Token(power);
			if (s == "q" || s == "quit" || s == "exit")
				return Token(quit);  // FIX 1
			return Token(name, s);
		}
		error("Bad token");
		return Token(' ');
	}
}

// Skip characters until its argument is matched, and throw that
// character away.

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

//  This is a named variable.

struct Variable {
	string name;
	double value;
	bool immutable;
	Variable(string n, double v, bool b) :
		name(n), value(v), immutable(b) { }
};

//  The active variables.

vector<Variable> names;

//  Get the value of a variable, or fail if no match.

double get_value(string s)
{
	for (int i = 0; i<int(names.size()); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
	return 0.0;
}

//  Set the value of a variable, or fail if no match.  Not efficient,
// of course.

void set_value(string s, double d)
{
	for (int i = 0; i <= int(names.size()); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

//  Check if a variable exists.  Not efficient, of course.

bool is_declared(string s)
{
	for (int i = 0; i<int(names.size()); ++i)
		if (names[i].name == s) return true;
	return false;
}

//  Check if a variable exists and is immutable.  Not efficient, of
// course.

bool is_immutable(string s)
{
	for (int i = 0; i<int(names.size()); ++i)
		if (names[i].name == s && names[i].immutable) return true;
	return false;
}

//  The token stream.  This would be better next to the class.

Token_stream ts;

//  C was once a 'single pass' language :-)

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

//  Read a primary (value, operator etc. or compound expression).
// Handling square root and power separately isn't ideal.

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

//  Read a multiplicative expression.

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

// Read an additive expression.

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


// Read a variable declaration.  'a' has been changed to name [ NONFIX ].

double declaration(int kind)
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string name = t.varname;
	if (kind == let || kind == constant) {
		if (is_declared(name)) error(name, " declared twice");
	}
	else if (kind == reset) {
		if (!is_declared(name))
			error(name, " has not been declared");
		if (is_immutable(name))
			error(name, " is a constant");
	}
	else
		error("unknown statement");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	if (is_declared(name))
		set_value(name, d);
	else
		names.push_back(Variable(name, d, (kind == constant)));
	return d;
}

// Read a statement.  Missing print detection added [ NONFIX ].

double statement()
{
	Token t = ts.get();
	double d;
	if (t.kind == let || t.kind == reset || t.kind == constant)
		d = declaration(t.kind);
	else {
		ts.unget(t);
		d = expression();
	}
	t = ts.get();
	if (t.kind != print) error("Missing terminator");
	return d;
}

// Skip to the next print character.

void clean_up_mess()
{
	ts.ignore(print);
}

// Mneumonics for output strings.

const string prompt = "> ";
const string result = "= ";

// The main calculation loop.  The exception handling was a right mess,
// so I have cleaned it up, but probably not as intended.  Indentation
// improved [ NONFIX ].  Case handling fixed [ FIX 2 ].

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

// The main program.  See comments on calculate.  Duplicated error
// recovery removed [ FIX 3 ].  Add a predefined constant 'k'.  I really
// don't like the use of 'name' for multiple purposes, but haven't
// cleaned up systematically - this is a token category.

int main() {
	Token k(name, "k");
	names.push_back(Variable("k", 1000, true));
	calculate();
	return 0;
}