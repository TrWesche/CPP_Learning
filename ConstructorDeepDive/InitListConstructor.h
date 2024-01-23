#include <initializer_list>

class InitListConstructor
{
private:
    double a {};
    double b {};

public:
    InitListConstructor(std::initializer_list<double> list) {
        a = *(list.begin());
        b = *(list.end());  
    }
    ~InitListConstructor();
};

InitListConstructor::~InitListConstructor()
{
}
