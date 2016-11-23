#include <iostream>
#include <string>
#include <vector>
#include "expr.cpp"

using namespace std;

/*
 *  Example:
 *
 *    "(2 * (x ^ 3)) + (4 * (x ^ 2)) + (4 * (x ^ 2)) + (4 * (x ^ 2)) + (4 * (x ^ 2))"
 *
 *    			|
 *    			v
 *
 *    new AddExpr(
 *        new MulExpr(
 *        	  ConstExpr(2),
 *        	  ExpExpr(
 *        	  	  VarExpr('x'),
 *        	  	  ConstExpr(3)
*        	  )
 *        ),
 *        new MulExpr(
 *        	  ConstExpr(4),
 *        	  ExpExpr(
 *        	  	  VarExpr('x'),
 *        	  	  ConstExpr(2)
*        	  )
 *        )
 *    )
 *
 *    for( i = n,
 */

int main(int argc, char** argv) {

	int numTerms;
	cin >> numTerms;

	int multiplier;
	int exponent;

	vector<Expr*> terms;
	for (int i = 0; i < numTerms; i++) {
		cin >> multiplier;
		cin >> exponent;
		terms.push_back(new MulExpr(
			new ConstExpr(multiplier),
			new ExpExpr(
				new VarExpr('x'),
				new ConstExpr(exponent)
			)
		));
	}

	for (int i = 0; i < terms.size(); i++) {
		cout << terms[i]->toString() << endl;
	}

	AddExpr* expr;
	// add terms into the AddExpr

	cout << expr->toString() << endl;
	cout << expr->differentiate()->toString() << endl;
	return 0;

//	string input;
//	getline(cin, input);
//	Expr* expr = parse(input);
//	cout << expr->toString() << endl;
//	cout << expr->differentiate()->toString() << endl;
	return 0;
}
