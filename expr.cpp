#include <iostream>
#include <string>

using namespace std;

class Expr {
public:
	virtual string toString() {
		return "";
	}

	virtual Expr* differentiate() {
		return new Expr();
	}
};


class ConstExpr : public Expr {
private:
	int value;

public:
	ConstExpr(int value) {
		this->value = value;
	}

	string toString() {
		return to_string(this->value);
	}

	Expr* differentiate() {
		return new ConstExpr(0);
	}
};


class VarExpr : public Expr {
private:
	char value;

public:
	VarExpr(char value) {
		this->value = value;
	}

	string toString() {
		return string(1, this->value);
	}

	Expr* differentiate() {
		return new ConstExpr(1);
	}
};


class AddExpr : public Expr {
private:
	Expr* lExpr;
	Expr* rExpr;

public:
	AddExpr(Expr* lExpr, Expr* rExpr) {
		this->lExpr = lExpr;
		this->rExpr = rExpr;
	}

	string toString() {
		return "(" + this->lExpr->toString() +  "+" + this->rExpr->toString() + ")";
	}

	Expr* differentiate() {
		return new AddExpr(lExpr->differentiate(), rExpr->differentiate());
	}
};

class SubExpr : public Expr {
private:
	Expr* lExpr;
	Expr* rExpr;
public:
	SubExpr(Expr* lExpr, Expr* rExpr) {
		this->lExpr = lExpr;
		this->rExpr = rExpr;
	}

	string toString() {
		return "(" + this->lExpr->toString() +  "-" + this->rExpr->toString() + ")";
	}

	Expr* differentiate() {
		return new SubExpr(lExpr->differentiate(), rExpr->differentiate());
	}
};

class MulExpr : public Expr {
private:
	Expr* lExpr;
	Expr* rExpr;

public:
	MulExpr(Expr* lExpr, Expr* rExpr) {
		this->lExpr = lExpr;
		this->rExpr = rExpr;
	}

	string toString() {
		return "(" + this->lExpr->toString() +  "*" + this->rExpr->toString() + ")";
	}

	Expr* differentiate() {
		return new AddExpr(
			new MulExpr(lExpr, rExpr->differentiate()),
			new MulExpr(lExpr->differentiate(), rExpr)
		);
	}
};


class DivExpr : public Expr {
private:
	Expr* lExpr;
	Expr* rExpr;

public:
	DivExpr(Expr* lExpr, Expr* rExpr) {
		this->lExpr = lExpr;
		this->rExpr = rExpr;
	}

	string toString() {
		return "(" + this->lExpr->toString() +  "/" + this->rExpr->toString() + ")";
	}

	Expr* differentiate() {
		return new DivExpr(
			new SubExpr(
				new MulExpr(lExpr->differentiate(), rExpr),
				new MulExpr(lExpr, rExpr->differentiate())
			),
			new MulExpr(rExpr, rExpr)
		);
	}
};

// 4x ^ 3
// 3 * (x ^ 2)
class ExpExpr : public Expr {
private:
	Expr* lExpr;
	Expr* rExpr;

public:
	ExpExpr(Expr* lExpr, Expr* rExpr) {
		this->lExpr = lExpr;
		this->rExpr = rExpr;
	}

	string toString() {
		return "(" + this->lExpr->toString() +  "^" + this->rExpr->toString() + ")";
	}

	Expr* differentiate() {
		return new MulExpr(
			rExpr,
			new ExpExpr(
				lExpr,
				new SubExpr(
					rExpr,
					new ConstExpr(1)
				)
			)
		);
	}
};
