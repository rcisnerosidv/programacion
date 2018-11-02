#include "Includes.h"

using namespace std;


class Token {
public:
	char kind;        
	double value;     
	Token(char ch)    
		:kind(ch), value(0) { }
	Token(char ch, double val)     
		:kind(ch), value(val) { }
};


class Token_stream {
public:
	Token_stream();
	Token get();
	void putback(Token t);
private:
	bool full;
	Token buffer;
};

Token_stream ts;

Token_stream::Token_stream() :
	full(false), buffer(' ') {
}

void Token_stream::putback(Token t) {
	if (full) error("putback into full stream");
	full = true;
	buffer = t;
}

Token Token_stream::get() {
	if (full) {
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch (ch) {
	case ';': case 'q': case '(': case ')': case '{': case '}':
	case '+': case '-': case '*': case '/': case '%': case '!':
		return Token(ch);
	case '.': case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		cin.putback(ch);
		double val;
		cin >> val;
		return Token('8', val);
	default:
		error("Bad token");
	}
}


double expression();  


double term();        


double primary()    
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':   
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case '{':   
	{
		double d = expression();
		t = ts.get();
		if (t.kind != '}') error("'}' expected");
		return d;
	}
	case '8':           
		return t.value;  
	default:
		error("primary expected");
	}
}


int main() {
	double val = 0;
	try {
		while (cin) {
			Token t = ts.get();

			if (t.kind == 'x' || t.kind == 'q') break;
			if (t.kind == ';' || t.kind == '=')
				cout << "=" << val << '\n';
			else {
				ts.putback(t);
				val = expression();
			}
		}
		
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		
		return 1;
	}
	catch (...) {
		cerr << "exception \n";
		
		return 2;
	}
}

//------------------------------------------------------------------------------

double expression()
{
	double left = term();    
	Token t = ts.get();     
	while (true) {
		switch (t.kind) {
		case '+':
			left += term();    
			t = ts.get();
			break;
		case '-':
			left -= term();   
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;      
		}
	}
}



double unit()
{
	double left = primary();
	Token t = ts.get();    

	if (t.kind == '!') {
		int n = left;
		double d = 1.0;
		for (int i = 1; i <= n; ++i) d *= i;
		left = d;
	}
	else
		ts.putback(t);
	return left;
}



double term()
{
	double left = unit();
	Token t = ts.get();    

	while (true) {
		switch (t.kind) {
		case '*':
			left *= unit();
			t = ts.get();
			break;
		case '/':
		{
			double d = unit();
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

