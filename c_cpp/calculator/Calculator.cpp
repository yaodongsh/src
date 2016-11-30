#include "Calculator.h"
#include <cassert>

bool Calculator::Execute (Input const & input)
{
    int token = input.Token();
    bool status = false;
    if (token == tokError) {
        std::cout << "Unknown token\n";
    } 
    else if (token == tokNumber) {
        if (_stack.IsFull()) {
            std::cout << "Stack is full \n";
        } 
        else {
            _stack.Push(input.Number());
            status = true;
        }
    } 
    else { //operator
        assert(token == '+' || token == '-' || token == '*' || token == '/');
        if(_stack.IsEmpty()) {
            std::cout << "Stack is empty\n";
        } 
        else {
            int num2 = _stack.Pop();
            int num1;
            if(_stack.IsEmpty()) //2 operator will be same once there is only 1 data left in stack
                num1 = num2;
            else
                num1 = _stack.Pop();
            _stack.Push(Calculate(num1, num2, token));
            status = true;
        }
         
    }
    return status;
}

int Calculator::Calculate (int num1, int num2, int token) const
{
    int result;
    if (token == '+')
        result = num1 + num2;
    else if (token == '-')
        result = num1 - num2;
    else if (token == '*')
        result = num1 * num2;
    else if (token == '/')
    {
        if (num2 == 0){
            std::cout << "Divide by zero\n";
            result = 0;
        }
        else {
            result = num1/num2;
        }
    }
    return result;
}
