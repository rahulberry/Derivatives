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
	cout << "\n1. Please enter the number of derivatives you would like to know" << endl;

	int n;
	cin >> n;

	Expr* derivative = expr;
	for (int i = 0; i < n; i++) {
		derivative = derivative->differentiate();
		cout << "f"<<i+1<<"(x)=" << derivative->toString() << endl;
	}
}
