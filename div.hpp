#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include "op.hpp"
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Div : public Base {
   private:
        Base* leftChild = nullptr;
		Base* rightChild = nullptr;
   public:
   		Div(Base* leftChild, Base* rightChild) {
		    this->leftChild = leftChild;
			this->rightChild = rightChild;
		}
		virtual double evaluate() { return leftChild->evaluate() / rightChild->evaluate(); }
		virtual std::string stringify() {
			ostringstream inSS;
			inSS << setprecision(5) << leftChild->stringify() << " / " << rightChild->stringify();
			return inSS.str(); }
};

#endif //__DIV_HPP__
