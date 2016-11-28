#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
#include "IStack.h"
#include "Input.h"

class Calculator
{
public:
    Calculator(): _done(false)
    {
        std::cout << "Calculator Created\n";  
    }
    bool Execute (Input& input) 
    {
        std::cout << "Calculator::Execute\n";
        return !_done;
    }
    IStack const & GetStack() 
    {
        _done = true;
        return _stack; 
    }
    
private:
    IStack _stack;
    bool _done;
};
#endif
