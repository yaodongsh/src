#ifndef STACKSEQ_H
#define STACKSEQ_H
#include <iostream>
#include "IStack.h"

class StackSeq
{
public:
    StackSeq (IStack const & stack) : _stack(stack), _done(false)
    {
        std::cout << "Stack Sequencer Created " << std::endl;
    }
    bool AtEnd () const {return _done;}
    void Advance() {_done = true;}
    int GetNum() const {return 13;}
private:
    IStack const & _stack;
    bool _done;

};
#endif
