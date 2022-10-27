#ifndef PROJECT_EX1_H
#define PROJECT_EX1_H

#include <iostream>
#include "Expression.h"
#include "interpreter.h"

using namespace std;

class BinaryOperation : public Expression {
protected:
    Expression* exp1;
    Expression* exp2;

    BinaryOperation(Expression* exp1, Expression* exp2);

    virtual ~BinaryOperation();
};

class UnaryOperation : public Expression {
protected:
    Expression* exp;

    UnaryOperation(Expression* expression);

    virtual ~UnaryOperation();
};

class UPlus : public UnaryOperation {
public:
    UPlus(Expression* exp1);

    virtual ~UPlus();

    double calculate();
};

class UMinus : public UnaryOperation {
public:
    UMinus(Expression* exp1);

    virtual ~UMinus();

    double calculate();
};


class Value : public Expression {
public:
    double val;

    Value(double val);

    virtual ~Value();

    double calculate();
};

class Variable : public Expression {
public:
    string name;
    double value;

    Variable(string name, double value);

    virtual ~Variable();

    Variable& operator ++ ();

    Variable& operator ++ (int);

    Variable& operator -- ();

    Variable& operator -- (int);

    Variable& operator += (double valForAddition);

    Variable& operator -= (double valForSubmission);

    double calculate();
};

class Plus : public BinaryOperation {
public:
    Plus(Expression* exp1, Expression* exp2);

    virtual ~Plus();

    double calculate();
};

class Minus : public BinaryOperation {
public:
    Minus(Expression* exp1, Expression* exp2);

    virtual ~Minus();

    double calculate();
};

class Mul : public BinaryOperation {
public:
    Mul(Expression* exp1, Expression* exp2);

    virtual ~Mul();

    double calculate();
};

class Div : public BinaryOperation {
public:
    Div(Expression* exp1, Expression* exp2);

    virtual ~Div();

    double calculate();
};

#endif //PROJECT_EX1_H