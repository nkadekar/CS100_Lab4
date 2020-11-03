#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include <string>

using namespace std;

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

TEST(SubTest, SubEvaluateStringify){
	Op* test = new Op(2); Op* test2 = new Op(1); Base* s = new Sub(test, test2);
	EXPECT_EQ(s->stringify(), "2 - 1");
}

TEST(PowTest, PowEvaluateNonZero){
	Op* test = new Op(2); Op* test2 = new Op(3); Base* p = new Pow(test, test2);
	EXPECT_NEAR(p->evaluate(), 8, 0.001);
}

TEST(PowTest, PowEvaluateZero){
	Op* test = new Op(2); Op* test2 = new Op(0); Base* p = new Pow(test, test2);
	EXPECT_NEAR(p->evaluate(), 1, 0.001);
}

TEST(PowTest, PowEvaluate2Zero){
	Op* test = new Op(0); Op* test2 = new Op(0); Base* p = new Pow(test, test2);
	EXPECT_NEAR(p->evaluate(), 1, 0.001);
}

TEST(PowTest, PowEvaluateNegative){
	Op* test = new Op(2); Op* test2 = new Op(-1); Base* p = new Pow(test, test2);
	EXPECT_NEAR(p->evaluate(), 0.5, 0.001);
}

TEST(PowTest, PowEvaluateLargeFloat){
	Op* test = new Op(20.3); Op* test2 = new Op(5.1); Base* p = new Pow(test, test2);
	EXPECT_NEAR(p->evaluate(), 4658325.09, 0.001);
}

TEST(PowTest, PowEvaluateStringify){
	Op* test = new Op(2); Op* test2 = new Op(3); Base* p = new Pow(test, test2);
	EXPECT_EQ(p->stringify(), "2 ** 3");
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

TEST(OpTest, OpEvaluateStringify){
    Op* test = new Op(1578);
    EXPECT_EQ(test->stringify(), "1578");
}

TEST(AddTest, AddEvaluateZero){
    Op* test1 = new Op(0);
    Op* test2 = new Op(0);
    Base* ad = new Add(test1, test2);
    EXPECT_EQ(ad->evaluate(), 0);
}

TEST(AddTest, AddEvaluateZero2){
    Op* test1 = new Op(8);
    Op* test2 = new Op(-8);
    Base* ad = new Add(test1, test2);
    EXPECT_EQ(ad->evaluate(), 0);
}

TEST(AddTest, AddEvaluateNeg){
    Op* test1 = new Op(8);
    Op* test2 = new Op(-18);
    Base* ad = new Add(test1, test2);
    EXPECT_EQ(ad->evaluate(), -10);
}

TEST(AddTest, AddEvaluateNeg2){
    Op* test1 = new Op(-7);
    Op* test2 = new Op(-8);
    Base* ad = new Add(test1, test2);
    EXPECT_EQ(ad->evaluate(), -15);
}

TEST(AddTest, AddEvaluateLarge){
    Op* test1 = new Op(783878);
    Op* test2 = new Op(473827);
    Base* ad = new Add(test1, test2);
    EXPECT_EQ(ad->evaluate(), 1257705);
}

TEST(AddTest, AddEvaluateStringify){
    Op* test1 = new Op(7);
    Op* test2 = new Op(14);
    Base* ad = new Add(test1, test2);
    EXPECT_EQ(ad->stringify(), "7 + 14");
}

TEST(MultTest, MultEvaluateZero){
    Op* test1 = new Op(0);
	Op* test2 = new Op(1);
	Base* mu = new Mult(test1, test2);
    EXPECT_EQ(mu->evaluate(), 0);
}

TEST(MultTest, MultEvaluateNeg){
    Op* test1 = new Op(8);
    Op* test2 = new Op(-8);
    Base* mu = new Mult(test1, test2);
    EXPECT_EQ(mu->evaluate(), -64);
}

TEST(MultTest, MultEvaluateNeg2){
    Op* test1 = new Op(-7);
    Op* test2 = new Op(-8);
    Base* mu = new Mult(test1, test2);
    EXPECT_EQ(mu->evaluate(), 56);
}

TEST(MultTest, MultEvaluateFloat){
    Op* test1 = new Op(7838.78);
    Op* test2 = new Op(47382.7);
    Base* mu = new Mult(test1, test2);
    EXPECT_NEAR(mu->evaluate(), 371422561.106, 0.0001);
}

TEST(MultTest, MultEvaluateFloat2){
    Op* test1 = new Op(78.3878);
    Op* test2 = new Op(473.827);
    Base* mu = new Mult(test1, test2);
    EXPECT_NEAR(mu->evaluate(), 37142.2561106, 0.0001);
}

TEST(MultTest, MultEvaluateLarge){
    Op* test1 = new Op(783878);
    Op* test2 = new Op(473827);
    Base* mu = new Mult(test1, test2);
    EXPECT_EQ(mu->evaluate(), 371422561106);
}

TEST(MultTest, MultEvaluateStringify){
    Op* test1 = new Op(7);
    Op* test2 = new Op(14);
    Base* mu = new Mult(test1, test2);
    EXPECT_EQ(mu->stringify(), "7 * 14");
}

TEST(RandTest, RandEvaluate1){
    Rand* test = new Rand();
    EXPECT_LT(test->evaluate(), 100);
 }

TEST(RandTest, RandEvaluate2){
    Rand* test = new Rand();
    EXPECT_LT(test->evaluate(), 100);
}

TEST(RandTest, RandEvaluateStringify){
    Rand* test = new Rand();
    EXPECT_NEAR(test->evaluate(), stod(test->stringify()), 0.001);
}

#endif //__OP_TEST_HPP__
