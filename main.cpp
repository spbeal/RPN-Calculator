// main.cpp 
// Samuel Beal CS 121
// Assignment: Calculator
//

#include <iostream>
#include <string>

#include "Calculator.h"

using namespace std;

int main()
{
    Stack s;
    bool loop = 1;

    while (loop) {
        loop = s.Calculate();
    }

    return 0;
}
