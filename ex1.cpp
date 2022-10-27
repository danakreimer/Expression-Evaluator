#include "ex1.h"

BinaryOperation::BinaryOperation(Expression *exp1, Expression *exp2) {
    this->exp1 = exp1;
    this->exp2 = exp2;
}

BinaryOperation::~BinaryOperation() {
    delete this->exp1;
    delete this->exp2;
}

UnaryOperation::UnaryOperation(Expression *exp) {
    this->exp = exp;
}

UnaryOperation::~UnaryOperation() {
    delete this->exp;
}

UPlus::UPlus(Expression *exp1) : UnaryOperation(exp1) {
}

UPlus::~UPlus() {}

double UPlus::calculate() {
    return this->exp->calculate();
}

UMinus::UMinus(Expression *exp1) : UnaryOperation(exp1) {
}

UMinus::~UMinus() {}

double UMinus::calculate() {
    return this->exp->calculate() * (-1);
}

Value::Value(double val) {
    this->val = val;
}

Value::~Value() {
}

double Value::calculate() {
    return this->val;
}

Variable::Variable(string name, double value) {
    this->name = name;
    this->value = value;
}

Variable::~Variable() {}

Variable &Variable::operator++() {
    ++this->value;
    return *this;
}

Variable &Variable::operator++(int) {
    this->value++;
    return *this;
}

Variable &Variable::operator--() {
    --this->value;
    return *this;
}

Variable &Variable::operator--(int) {
    this->value--;
    return *this;
}

Variable &Variable::operator+=(double valForAddition) {
    this->value += valForAddition;
    return *this;
}

Variable &Variable::operator-=(double valForSubmission) {
    this->value -= valForSubmission;
    return *this;
}

double Variable::calculate() {
    return this->value;
}

Plus::Plus(Expression *exp1, Expression *exp2) : BinaryOperation(exp1, exp2) {
}

Plus::~Plus() {}

double Plus::calculate() {
    return this->exp1->calculate() + this->exp2->calculate();
}

Minus::Minus(Expression *exp1, Expression *exp2) : BinaryOperation(exp1, exp2) {
}

Minus::~Minus() {}

double Minus::calculate() {
    return this->exp1->calculate() - this->exp2->calculate();
}

Mul::Mul(Expression *exp1, Expression *exp2) : BinaryOperation(exp1, exp2) {
}

Mul::~Mul() {}

double Mul::calculate() {
    return this->exp1->calculate() * this->exp2->calculate();
}

Div::Div(Expression *exp1, Expression *exp2) : BinaryOperation(exp1, exp2) {
}

Div::~Div() {}

double Div::calculate() {
    return this->exp1->calculate() / this->exp2->calculate();
}