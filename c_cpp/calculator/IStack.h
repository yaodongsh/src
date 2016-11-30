#ifndef ISTACK_H
#define ISTACK_H
const int maxStack = 16;
class IStack
{
    friend class StackSeq;
public:
    IStack(): _top(0) {};
    void Push (int i);
    int Pop();
    bool IsEmpty();
    bool IsFull();
private:
    int _array[maxStack];
    int _top;
};
#endif
