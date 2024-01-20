#ifndef STACK_HPP
#define STACK_HPP

class Stack {

	public:
		Stack();
		~Stack();
		void push(int value);
		int pop();
		bool isEmpty() const;

	private:
		int* stackArray;
		int capacity;
		int top;
		void resize();
};

#endif
