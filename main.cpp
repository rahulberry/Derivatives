#include <iostream>
#include <string>
#include <vector>
#include "expr.cpp"

using namespace std;

AddExpr* termsToAddExpr(vector<Expr*> terms) {
	if (terms.size() == 2) {
		return new AddExpr(terms[0], terms[1]);
	}
	else {
		Expr* back = terms.back();
		terms.pop_back();
		return new AddExpr(termsToAddExpr(terms), back);
	}
}

int main(){

	cout <<  "\n \n \n******************************************************************"<< endl ;
	cout << " This program can be used to determine the derivatives of polynomials " << endl;
	cout << "\n1. Please enter the number of terms in the polynomials" << endl;
	cout << "2. To exit the program please enter 0" << endl;
	cout <<  "\n ******************************************************************" << endl;

	int numTerms;
	cin >> numTerms;

	if(numTerms == 0){
		cout << "\nBye!" << endl;
		return 0;
	}

	cout << "Please enter the coefficient and exponent of the "<< numTerms << " terms" << endl;
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
	AddExpr* expr = termsToAddExpr(terms);
	cout <<"You have entered f(x) = " <<expr->toString() << endl;
	cout << "Would you like to know the first, second or third derivative of the polynomial" << endl;
	cout << "\n1. Please enter 1, 2 or 3 for the first, second or third derivative" << endl;

	int n;
	cin >> n;
	if ( n == 1 ){
		cout << "The derivative is " <<  expr->differentiate()->toString() << endl;
	return 0;
	}

	if ( n == 2 ){
		cout << "The second derivative is " <<  expr->differentiate()->differentiate()->toString() << endl;
	return 0;
	}
	if ( n == 3 ){
		cout << "The third derivative is " <<  expr->differentiate()->differentiate()->differentiate()->toString() << endl;
	return 0;
	}
}

/* if ( n == 1) {
 *	cout << expr->differentiate()->toString() << endl;
 *
 * 	else{
 * 	bye
 *
 *
 */
