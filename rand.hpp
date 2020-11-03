#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <string>
#include <iostream>

class Rand: public Base {
	private:
		double num;
    public:
        Rand() { num = rand() % 100; }
        virtual double evaluate() { return num; }
        virtual std::string stringify() { return std::to_string(num);}	
};

#endif //__RAND_HPP__
