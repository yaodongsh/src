#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
#include "IStack.h"
#include "Input.h"

class Calculator
{
public:
    Calculator()
    {
    }
    bool Execute (Input const & input) ;
    IStack const & GetStack() 
    {
        return _stack; 
    }
    
private:
    IStack _stack;
    int Calculate (int num1, int num2, int token) const;
};
#endif
