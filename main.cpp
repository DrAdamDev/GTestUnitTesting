#include "stack.hpp"
#include "../GitProject/print.hpp"
#include <iostream>

int main() {

	Stack stack;
	stack.push(82);
	int pop = stack.pop();

	(void) pop;

	print("SUCCESS");
	return 0;
}
