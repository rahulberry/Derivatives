#include <iostream>
#include <string>
#include "expr.cpp"

using namespace std;

/*
 *
 */
Expr* parse(string input) {
	return new ConstantExpr(5);
}

int main(int argc, char** argv) {
	string input;
	getline(cin, input);
	Expr* expr = parse(input);
	cout << expr->toString() << endl;
	cout << expr->differentiate()->toString() << endl;
	return 0;
}
