#include <iostream>
#include <string>
#include <vector>
#include "expr.cpp"

using namespace std;

/*
 *  Example:
 *
 *    "(2 * (x ^ 3)) + (4 * (x ^ 2))
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

int main() {

	cout <<  "\n \n \n******************************************************************"<< endl ;
	cout << " This program can be used to determine the derivatives polynomials " << endl;
	cout << "\n1. Please enter the number of terms in the polynomials" << endl;
	cout << "2. To exit the program please enter 0" << endl;
	cout <<  "\n ******************************************************************" << endl;

	int numTerms;
	cin >> numTerms;

	if(numTerms == 0){
		cout << "\nBye!" << endl;
		return 0;
	}

	cout << "Please enter the coefficient and exponent of all "<< numTerms << " terms" << endl;
	int coef;
	int exponent;

	vector<Expr*> terms;
	for (int i = 0; i < numTerms; i++) {
		cin >> coef;
		cin >> exponent;
		terms.push_back(new MulExpr(
			new ConstExpr(coef),
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
