#include <iostream>
#include "Item.h"
#include "PolymorphicExceptions.h"


class Animal{
public: 
     Animal() = default;
     virtual void breathe() const{} ;
private : 
     std::string m_description;
};

class Dog : public Animal
{
public : 
   Dog() = default;  
   virtual void breathe()const override{};
   void run(){
	   std::cout << "Dog running..." << std::endl;
   }
private : 
     std::string m_fur_color;
};

class SomethingIsWrong{
public : 
    SomethingIsWrong(const std::string& s) 
        : m_message(s)
        {
        }
        
    //Copy Constructor
    SomethingIsWrong(const SomethingIsWrong& source){
        std::cout << "Copy constructor for SomethingIsWrong called" << std::endl;
        m_message = source.m_message;
    }
    
    //Destructor
    ~SomethingIsWrong(){
        std::cout << "SomethingIsWrong destructor called" << std::endl;
    }
    const std::string& what()const{
        return m_message;
    }
private : 
    std::string m_message;
};

void do_something(size_t i){
      if(i == 2){
          throw SomethingIsWrong("i is 2");
      }
      std::cout << "Doing something at iteration : " << i << std::endl;
}

void do_something_poly(size_t i){
      if(i == 2){
          throw CriticalError("i is 2");
      }
      
      if(i == 3){
          throw SmallError("i is 3");
      }
	  
      if(i == 4){
          throw Warning("i is 4");
      }
      std::cout << "Doing something at iteration : " << i << std::endl;
}

void non_propogating_function() noexcept {
    try {
        throw 1;
    }
    catch (int ex) {
        std::cout << "Int exception in non propogating function" << std::endl;
        throw; // Because of the noexcept keyword this function will not propagate the exception to higher levels - it will be treated as unhandled
    }
}

// Extending standard exception library
class DivideByZeroException : public std::exception {
public :   
    DivideByZeroException(int a, int b) noexcept : std::exception(),m_a(a),m_b(b){}
	
     virtual const char* what() const noexcept override {
         /*
         //Some compilers will give a warning that we're returning the address of a local string
         //link : https://www.udemy.com/instructor/communication/qa/17488954/detail/?course=2987082
         return (std::string("Divide by zero detected , dividing ") +
            std::to_string(m_a) + std::string(" by ") +
                std::to_string(m_b)).c_str();
                */
               return"divide by zero detected, dividing ";
     }
     
     int get_a() const{
         return m_a;
     }
     
     int get_b() const{
         return m_b;
     }
     
private : 
     int m_a{};
     int m_b{};
    
};

int divide( int a, int b){
    
    if(b==0)
        throw DivideByZeroException(a,b);
        
    return a/b;
}



int main(int argc, char **argv){
    int a{10};
    int b{0};

    try {
        Item item;
        // Item* item_ptr = new Item() // DON'T DO THIS, WILL CAUSE MEMORY LEAKS.  Can be handled with the <memory> library or other methods.

        if (b == 0) {
            throw 0;
        }

        a++;
        b++;
        std::cout << "Normal Operation" << std::endl;
    } catch (int ex) {
        std::cout << "Caught Error: " << ex << std::endl;
    }



    //Downcast using dynamic_cast with references example
    //The hierarchy of Animal->Dog has to be polymorphic to be able to do 
    //this. This throws an exception because animal has no dog part so the 
	//cast won't really work.
    
    try
    {
        Animal animal1{};
        Dog& dog1{dynamic_cast<Dog&>(animal1)};
    }
    catch(std::bad_cast e) 
    {
        std::cout << "Cast Failure: Animal -> Dog" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(...){
        std::cout << "Catch All Block" << std::endl;
    }


    // Throwing a custom class with a Copy Constructor Example
    for(size_t i{0}; i < 5 ; ++i){
        
      try{
          do_something(i);
      }
      catch(SomethingIsWrong& ex){
          std::cout << "Exception cought : " << ex.what() << std::endl;
      }
    }

    

    // Polymorphic Exception Handling
    for(size_t i{0}; i < 5 ; ++i){
        try{
            do_something_poly(i);
        }

        catch(PolymorphicExceptions& ex){
            std::cout << "PolymorphicExceptions Exception caught : " << ex.what() << std::endl;
        }    
    }


    // Can rethrow exceptions
    // try {

    // } catch {
    //     throw; // This will "rethrow" the exception to the higher level
    //            // Use this syntax to make sure data is not lost
    // }


    // Function will not propogate exceptions
    // non_propogating_function(); // It is treated as unhandled
    // Note: Destructors are noexcept by default


    // Standard Exceptions
    // Some Examples:
    try {
        throw std::out_of_range("Whoa, its out of range");
    }
    catch (std::invalid_argument& ex) {
        std::cout << "Standard Exception - Logic Error" << std::endl;
    }
    catch (std::length_error& ex) {
        std::cout << "Standard Exception - Logic Error" << std::endl;
    }
    catch (std::out_of_range& ex) {
        std::cout << "Standard Exception - Logic Error" << std::endl;
        std::cout << ex.what() << std::endl;
    }
    catch (std::logic_error& ex) { // This encapsulates the previous 3
        std::cout << "Standard Exception - Logic Error" << std::endl;
    }
    catch (std::overflow_error& ex) {
        std::cout << "Standard Exception - Logic Error" << std::endl;
    }
    catch (std::underflow_error& ex) {
        std::cout << "Standard Exception - Logic Error" << std::endl;
    }
    catch (std::runtime_error& ex) { // This encapsulates the previous 2
        std::cout << "Standard Exception - Logic Error" << std::endl;
    }
    catch (std::bad_alloc& ex) {
        std::cout << "Standard Exception - Logic Error" << std::endl;
    }
    catch (std::bad_cast& ex) {
        std::cout << "Standard Exception - Logic Error" << std::endl;
    }
    catch (...) {
        std::cout << "Standard Excepetion - Catch All" << std::endl;
    }


    // Standard Exception Override and Use
    try{
        divide(10,0);
    }
    catch(std::exception& ex){
        //We know that the thrown exception contains a DivideByZeroException
        //part do ws can downcast safely and call non virtual functions
        /*
        DivideByZeroException * d_z = dynamic_cast<DivideByZeroException*> (&ex);
        if(d_z){
            std::cout<< ex.what() << ": dividing " << d_z->get_a() << 
                " by "<<  d_z->get_b() << std::endl;
        }
        */
       
       std::cout << ex.what() << std::endl;
		
    }
    return 0;
}