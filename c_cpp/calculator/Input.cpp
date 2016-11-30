#include <cctype>
#include <cassert>
#include <cstdlib>
#include "Input.h"

Input::Input()
{
    std::cin >> _buf;
    int c = _buf[0];
    if(std::isdigit(c))
       _token = tokNumber;
    else if(c == '+' || c=='*' || c == '/')
       _token = c;
    else if(c == '-') 
    {
        if(std::isdigit(_buf[1])) // next is a digit which means this is neg indication
            _token = tokNumber;
        else
            _token = c;
    }
    else
       _token = tokError;
}

int Input::Number() const
{
    assert(_token == tokNumber);
    return std::atoi(_buf); //string to int
}
