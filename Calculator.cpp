#include <iostream>
#include <string>
#include <math.h>

#include "Calculator.h"

using namespace std;

const char* opcode[10] = { "*", "/", "+", "-", "sq", "sqrt", "dup", "swap", "ps",};

// Main calculator function for managing everything
bool Stack::Calculate()
{
    string input = "";
    std::cout << "RPN ";
    if (Peek() == NULL) {
        cout << "(empty) > ";
    }
    else {
        cout << Peek() << " > ";
    }
    // Get input and check base cases 
    getline(cin, input);
    if (input.empty())
    {
        return 1;
    }
    if (input == "quit" || input == "quit ")
    {
        return 0;
    }
    
    int first = 0;
    int last = 0;
    string curr = "";
    double a = { 0 };

    // Handle start of input
    for (int u = 0; u < input.length(); u++)
    {
        input[u] = tolower(input[u]);
    }
    first = input.find_first_not_of(" ");
    last = input.find_last_not_of(" ");
    if (last < 0) return 1; 
    input += " ";
        
    if (CheckInput(input, first) == 1);

    // Seperates input
    for (int j = first; j <= last+1; j++)
    {
        if (input[j] != ' ' || input[j] == '.')
            curr += input[j];

        else {
            if (curr == "quit" || curr == "quit ")
            {
                return 0;
            }
            if (curr == ".")
            {
                cout << "Bad character: ." << endl;
                curr = "";
            }
            else
            {
                Run(curr);
                curr = "";
            }
        }
    }

    return 1;
}

// Checks input to see if its valid
bool Stack::CheckInput(string input, int first)
{
    if (input.length() > 0) {
        for (int t = first; t < input.length(); t++)
        {
            if (IsNumber(input[t]) || IsLetter(input[t]) || IsSymbol(input[t]))
            {

            }
            else if (input[t] == ' ' || input[t] == '.')
            {

            }
            else
            {
                cout << "Bad character: " << input[t] << endl;
                return 1;
            }
        }
        return 0;
    }
}

// Either pushes numbers or CallOpcode()
void Stack::Run(string curr)
{
    bool current = true;
    for (int i = 0; i < curr.length(); i++)
    {
        if (IsNumber(curr[i]))
        {

        }
        else {
            current = false;
            break;
        }
    }
    if (current) Push(stod(curr));
    else CallOpcode(curr);
}

// Calls our basic functions, checks for non-function input
void Stack::CallOpcode(std::string str)
{
    int i = 0;
    bool cont = false;
    for (i = 0; i < 9; i++)
    {
        if (opcode[i] == str)
        {
            cont = true;
            break;
        }
    }
    if (cont) {
        switch (i)
        {
        case 0:
            Multiplication();
            break;
        case 1:
            Division();
            break;
        case 2:
            Addition();
            break;
        case 3:
            Subtraction();
            break;
        case 4:
            Square();
            break;
        case 5:
            Sqrt();
            break;
        case 6:
            Duplicate();
            break;
        case 7:
            Swap();
            break;
        case 8:
            PrintStack();
            break;
        }
    }
    else {
        std::cout << "Bad characters: " << str << endl;
    }
}

// Functions to check input

bool Stack::IsSymbol(char str)
{
    bool symbol = false;
    for (int i = 0; i < 4; i++)
        if (str == *opcode[i])
        
    return false;
}

bool Stack::IsLetter(char str) {
    if (str >= 'a' || str <= 'z')
    {
        return true;
    }
    return false;
}

bool Stack::IsNumber(char str)
{
    if ((str <= '9' && str >= '0') || str == '.')
        return true;
    return false;
}

// Stack Functions

void Stack::PrintStack()
{
    StackNodePtr p = top;

    cout << "Stack contents: ";
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->next;
    }
    cout << " " << endl;
}

double Stack::Peek()
{
    if (top != NULL)
    {
        double a = top->info;
        return a;
    }
    return NULL;
}

void Stack::Push(double b)
{
    StackNodePtr n = new stackNode;

    n->info = b;
    n->next = top;

    top = n;
    count++;
}

double Stack::Pop()
{
    double a = { 0 };

    if (top == NULL) {
        cout << "Error::Pop: stack empty" << endl;
        return NULL;
    }

    else {
        StackNodePtr del;
        a = top->info;

        del = top;
        top = top->next;

        del->next = NULL;

        delete del;
    }
    count--;
    return a;
}

// Basic Functions

void Stack::Multiplication()
{
    if (count >= 2)
    {
        double a = Pop();
        double b = Pop();
        Push(a * b);
    }
}

void Stack::Division()
{
    if (count >= 2)
    {
        double a = Pop();
        double b = Pop();
        Push(b / a);
    }
}

void Stack::Subtraction()
{
    if (count >= 2)
    {
        double a = Pop();
        double b = Pop();
        Push(b - a);
    }
}

void Stack::Addition()
{
    if (count >= 2)
    {
        double a = Pop();
        double b = Pop();
        Push(a + b);
    }
}

void Stack::Square()
{
    if (count >= 1)
    {
        double a = Pop();
        Push(a * a);
    }
}

void Stack::Sqrt()
{
    if (count >= 1)
    {
        double a = Peek();
        if (a < 0)
        {

        }
        else {
            Push(sqrt(a));
        }
    }
}

void Stack::Duplicate()
{
    if (count >= 1)
    {
        Push(top->info);
    }
}

void Stack::Swap()
{
    if (top != NULL && top->next != NULL)
    {
        double a = Pop();
        double b = Pop();

        Push(a);
        Push(b);
    }
}

