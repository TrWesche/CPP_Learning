#ifndef POLY_EXCEPTIONS_H
#define POLY_EXCEPTIONS_H

#include <string>

class PolymorphicExceptions{
public : 
    PolymorphicExceptions(const std::string& s) : m_message(s){}
     virtual ~PolymorphicExceptions(){}
    virtual std::string what()const{return m_message;}
protected : 
    std::string m_message;
};

class Warning : public PolymorphicExceptions{
    public : 
    Warning(const std::string& s) : PolymorphicExceptions(s){}
	virtual std::string what()const override{return m_message + " Yellow";}
};

class SmallError : public Warning{
    public : 
    SmallError(const std::string& s) : Warning(s){}
	virtual std::string what()const override {return m_message + " Orange";}

};

class CriticalError : public SmallError{
    public : 
    CriticalError(const std::string& s) : SmallError(s){}
	virtual std::string what()const override {return m_message + " Red";}

};



#endif // POLY_EXCEPTIONS_H