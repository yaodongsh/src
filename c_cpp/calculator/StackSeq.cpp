#include "StackSeq.h"
#include "IStack.h"
#include <cassert>

StackSeq::StackSeq(IStack const &stack)
    : _iCur(0), _stack(stack)
{}

bool StackSeq::AtEnd() const
{
    return _iCur ==_stack._top;
}

void StackSeq::Advance()
{
    assert(!AtEnd());
    ++_iCur;
}

int StackSeq::GetNum() const
{
    assert(!AtEnd());
    return _stack._array[_iCur];
}
