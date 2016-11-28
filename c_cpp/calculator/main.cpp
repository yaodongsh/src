#include <iostream>
#include "Calculator.h"
#include "Input.h"
#include "StackSeq.h"


int main()
{
    Calculator TheCalculator;
    bool status;
    do {
        std::cout << "<";
        Input input;
        status = TheCalculator.Execute(input);
        if(status) {
            for(StackSeq seq (TheCalculator.GetStack()); !seq.AtEnd(); seq.Advance()) {
                std::cout << " " << seq.GetNum() << std::endl;
            }
            
        } 
    } while (status);
}
