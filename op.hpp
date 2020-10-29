#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <string>

class Op : public Base {
	private:
		double num;
    public:
        Op(double value) : Base() { num = value; }
        virtual double evaluate() { return num; }
        virtual std::string stringify() { return std::to_string(num); }
};

#endif //__OP_HPP__
