#include <gtest/gtest.h>
#include "stack.hpp"

TEST(Stack, PushPop) {

	Stack stack;
	stack.push(82);
	int pop = stack.pop();

	EXPECT_TRUE(pop == 82);
} 
