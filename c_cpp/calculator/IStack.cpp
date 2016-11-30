#include "IStack.h"
#include <cassert>
#include <iostream>

void IStack::Push (int i)
{
    assert (_top < maxStack);
    _array[_top] = i;
    _top++;
}

int IStack::Pop()
{
    assert(_top > 0);
    _top--;
    return _array[_top];
}

bool IStack::IsEmpty()
{
    return (_top == 0);
}

bool IStack::IsFull()
{
    return (_top == maxStack);
}
