#pragma once

#include <iostream>
#include <string>

using namespace std;

class Stack
{
	public:
		bool Calculate();

		Stack()
		{
			top = NULL;
			count = 0;
		}
		
	private:
		struct stackNode
		{
			double info;
			stackNode* next;
		};
		typedef struct stackNode* StackNodePtr;

		StackNodePtr top;
		int count;

		void PrintStack();
		double Peek();
		void Push(double a);
		double Pop();


		// Extra Functions
		bool CheckInput(string input, int first);
		void Run(string curr);
		bool IsLetter(char str);
		bool IsNumber(char str);
		bool IsSymbol(char str);
		void CallOpcode(std::string str);

		// Basic Functions

		void Multiplication();
		void Division();
		void Subtraction();
		void Addition();
		void Square();
		void Sqrt();
		void Duplicate();
		void Swap();

};