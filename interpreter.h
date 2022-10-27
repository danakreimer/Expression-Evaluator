#ifndef PROJECT_INTERPRETER_H
#define PROJECT_INTERPRETER_H
#include <string>
#include <stack>
#include <queue>
#include "Expression.h"

using namespace std;

class interpreter {
private:
    stack<string> operatorStack;
    queue<string> outputQueue;
    stack<Expression*>expressionStack;
public:
    Expression* interpret(string expression);
    bool isNum(string);
    bool isGreaterPrecedence(string opr1,string opr2);
};


#endif //PROJECT_INTERPRETER_H
