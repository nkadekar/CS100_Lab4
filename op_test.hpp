#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "div.hpp"
#include "sub.hpp"

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

TEST(SubTest, SubEvaluateNonZero){
	Op* test = new Op(14); Op* test2 = new Op(10); Base* s = new Sub(test, test2);
	EXPECT_NEAR(s->evaluate(), 4, .001);
}

TEST(SubTest, SubEvaluateZero){
	Op* test = new Op(0); Op* test2 = new Op(0); Base* s = new Sub(test, test2);
    EXPECT_NEAR(s->evaluate(), 0, .001);
}

TEST(SubTest, SubEvaluate2Negative){
	Op* test = new Op(-4); Op* test2 = new Op(-1); Base* s = new Sub(test, test2);
    EXPECT_NEAR(s->evaluate(), -3, .001);
}

TEST(SubTest, SubEvaluateSubtractNegative){
	Op* test = new Op(4); Op* test2 = new Op(-10); Base* s = new Sub(test, test2);
    EXPECT_NEAR(s->evaluate(), 14, .001);
}

TEST(SubTest, SubEvaluateFloats){
	Op* test = new Op(1.999); Op* test2 = new Op(0.998); Base* s = new Sub(test, test2);
    EXPECT_NEAR(s->evaluate(), 1.001, .001);
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
