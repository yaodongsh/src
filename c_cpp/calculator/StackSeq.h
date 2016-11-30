#ifndef STACKSEQ_H
#define STACKSEQ_H
#include <iostream>
#include "IStack.h"

class StackSeq
{
public:
    StackSeq (IStack const & stack) ; 
    bool AtEnd () const; 
    void Advance(); 
    int GetNum() const ;
private:
    IStack const & _stack;
    int _iCur;

};
#endif
