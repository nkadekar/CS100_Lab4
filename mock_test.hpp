#ifndef __MOCK_TEST_HPP__
#define __MOCK_TEST_HPP__

class SevenOpMock: public Base {
    public:
        SevenOpMock() { };

        virtual double evaluate() { return 7.5; }
        virtual string stringify() { return "7.5"; }
};

class NegValMock: public Base {
    public:
        NegValMock() { };

        virtual double evaluate() { return -1; }
        virtual string stringify() { return "-1"; }
};

class ZeroMock: public Base {
    public:
        ZeroMock() { };

        virtual double evaluate() { return 0; }
        virtual string stringify() { return "0"; }
};

class LargeValMock: public Base {
    public:
        LargeValMock() { };

        virtual double evaluate() { return 100000; }
        virtual string stringify() { return "100000"; }
};


#endif
