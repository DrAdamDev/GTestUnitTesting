#include <gtest/gtest.h>
#include "../include/stack.hpp"
#include <cmath>

TEST(StackTest, StackConstruct) {

	Stack* newStack = new Stack();

	EXPECT_NE(dynamic_cast<Stack*>(newStack), nullptr);
}

TEST(StackTest, PushPop) {

	Stack stack;
	const int val = 1;
	
	stack.push(val);
	int pop = stack.pop();

	EXPECT_EQ(pop, val);

	EXPECT_THROW(stack.pop(), std::out_of_range);
} 

TEST(StackTest, Resizing) {


// test both edge and generic cases too
	const int val = 1;
	const int exp = 20;
	const size_t it = std::pow(2, exp);
	Stack stack;
	
	for (size_t i = 0; i < it; i++) {

		stack.push(val);
	}
	for (size_t i = 0; i < it; i++) {
		EXPECT_FALSE(stack.isEmpty());
		stack.pop();
	}
	EXPECT_TRUE(stack.isEmpty());

	EXPECT_THROW(stack.pop(), std::out_of_range);
} 

TEST(StackTest, isEmptyInit) {

	Stack stack;

	EXPECT_TRUE(stack.isEmpty());
}
