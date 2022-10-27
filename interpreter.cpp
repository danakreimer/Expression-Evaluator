//
// Created by Dana on 10/11/2019.
//

#include <regex>
#include <iostream>
#include "interpreter.h"
#include "ex1.h"

using namespace std;

bool interpreter::isNum(string strToCheck) {
    return regex_match(strToCheck, regex("^[-+]?[0-9]+\\.?[0-9]*$"));
}

bool interpreter::isGreaterPrecedence(string opr1, string opr2) {
    if (opr1 == "*" || opr1 == "/") {
        if (opr2 == "+" || opr2 == "-") {
            return false;
        }
    }

    return true;
}

Expression *interpreter::interpret(string expression) {
    for (int i = 0; i < expression.length(); i++) {
        string token = expression.substr(i, 1);
        if (isNum(token)) {
            int chars = 1;
            string possibleNumber = token;
            while (isNum(possibleNumber) && i + chars < expression.length()) {
                token = possibleNumber;
                possibleNumber = expression.substr(i, ++chars);
            }

            outputQueue.push(expression.substr(i, token.length()));
            i += token.length() - 1;
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            while (!operatorStack.empty() && isGreaterPrecedence(token, operatorStack.top()) &&
                   operatorStack.top() != "(") {
                outputQueue.push(operatorStack.top());
                operatorStack.pop();
            }

            operatorStack.push(token);
        } else if (token == "(") {
            operatorStack.push(token);
        } else if (token == ")") {
            while (!operatorStack.empty() && operatorStack.top() != "(") {
                outputQueue.push(operatorStack.top());
                operatorStack.pop();
            }

            if (operatorStack.top() == "(") {
                operatorStack.pop();
            }
        }
    }

    while (!operatorStack.empty()) {
        outputQueue.push(operatorStack.top());
        operatorStack.pop();
    }
// end of shunting yard
    string operandOrOperatorStr;
    Expression* leftSide;
    Expression* rightSide;
    while (!outputQueue.empty()) {
        operandOrOperatorStr = outputQueue.front();
        if (isNum(operandOrOperatorStr)) {
            expressionStack.push(new Value(stod(operandOrOperatorStr)));
        } else if (operandOrOperatorStr == "+" || "-" || "*" || "/") {
            if (expressionStack.size() < 2) {
                throw "illegal math expression";
            }

            rightSide = expressionStack.top();
            expressionStack.pop();
            leftSide = expressionStack.top();
            expressionStack.pop();
            if (operandOrOperatorStr == "+") {
                expressionStack.push(new Plus(leftSide, rightSide));
            } else if (operandOrOperatorStr == "-") {
                expressionStack.push(new Minus(leftSide, rightSide));
            } else if (operandOrOperatorStr == "*") {
                expressionStack.push(new Mul(leftSide, rightSide));
            } else if (operandOrOperatorStr == "/") {
                expressionStack.push(new Div(leftSide, rightSide));
            }
        }

        outputQueue.pop();
    }

    return expressionStack.top();
}