#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
	private:
		num;
    public:
        Op(double value) : Base() { }
        virtual double evaluate() { return num; }
        virtual std::string stringify() { return string(num); }
};

#endif //__OP_HPP__
