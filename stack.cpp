#include "stack.hpp"
#include <iostream>
#include <stdexcept>

// Constructor initialises an empty stack with a small initial capacity
Stack::Stack() : stackArray(new int[1]), capacity(1), top(-1) {}

// Destructor frees the dynamic memory allocated for the stack
Stack::~Stack() {

	delete[] stackArray;
}

// Resize method doubles the capacity of the stack when it's full
void Stack::resize() {

	// Create new stack array
	int newCapacity = capacity * 2;
	int* newArray = new int[newCapacity];
	
	// Copy the old over to it
	for (int i = 0; i < capacity; i++) {

		newArray[i] = stackArray[i];
	}
	
	// Delete the old one
	delete[] stackArray;
	
	// Update the necessary
	capacity = newCapacity;
	stackArray = newArray;
}

// Push method adds a new element to the top of the stack
void Stack::push(int val) {

	// Check for full capacity
	if (top == capacity - 1) {

		resize();
	}
	// Add element to stackArray
	// Update top (implicit)
	stackArray[++top] = val;
}

// Pop method removes and returns the top element of the stack
int Stack::pop() {
	// Check for empty stackArray
	if (isEmpty()) {

		throw std::out_of_range("Stack Underflow");
	} 
	// Return value
	return stackArray[top--];
}

// isEmpty method checks if the stack has no elements
bool Stack::isEmpty() const {

	return top == -1;
}
