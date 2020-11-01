#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "div.hpp"

TEST(DivTest, DivEvaluateNonZero) {
    Op* test = new Op(10); Op* test2 = new Op(2); Base* d = new Div(test, test2);
    EXPECT_NEAR(d->evaluate(), 5, .001);
}

TEST(DivTest, DivEvaluateZero) {
    Op* test = new Op(0); Op* test2 = new Op(10); Base* d = new Div(test, test2);
    EXPECT_NEAR(d->evaluate(), 0, .001);
}

TEST(DivTest, DivEvaluateNegative) {
	Op* test = new Op(-8); Op* test2 = new Op(0.5); Base* d = new Div(test, test2);
	EXPECT_NEAR(d->evaluate(), -16, .001);
}

TEST(DivTest, DivStringify) {
	Op* test = new Op(10); Op* test2 = new Op(2); Base* d = new Div(test, test2);
	EXPECT_EQ(d->stringify(), "10 / 2");
}

TEST(OpTest, OpEvaluateZero){
	Op* test = new Op(0);
	EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpEvaluateNeg){
    Op* test = new Op(-8);
    EXPECT_EQ(test->evaluate(), -8);
}

TEST(OpTest, OpEvaluateLarge){
    Op* test = new Op(1574838237348);
    EXPECT_EQ(test->evaluate(), 1574838237348);
}

#endif //__OP_TEST_HPP__
