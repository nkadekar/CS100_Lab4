#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "op.hpp"
#include <string>

using namespace std;

class Sub : public Base {
   private:
        Base* leftChild = nullptr;
   		Base* rightChild = nullptr;
   public:
   		Sub(Base* leftChild, Base* rightChild) {
		    this->leftChild = leftChild;
			this->rightChild = rightChild;
		}
		virtual double evaluate() { return leftChild->evaluate() - rightChild->evaluate(); }
		virtual std::string stringify() {
			std::ostringstream inSS;
			inSS << std::setprecision(5) << leftChild->stringify() << " - " << rightChild->stringify();
			return inSS.str();
		}
};
#endif //__SUB_HPP__
