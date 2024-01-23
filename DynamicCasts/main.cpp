#include <iostream>
#include <memory>
#include "Dog.h"

int main(int argc, char **argv){
    std::cout << "====================" << std::endl;
    std::cout << "Basic Functionality with Smart Pointers" << std::endl;
    std::cout << "====================" << std::endl;

    std::shared_ptr<Animal> animal1(new Dog("Bobby", "Terrier", "Wire"));
    std::shared_ptr<Animal> animal2(new Dog("Timmy", "Malamut", "Straight"));

    // Only breathe is directly accessible because this is using an Animal Pointer
    animal1->breathe();
    std::cout << "-------------------" << std::endl;

    // After dynamic cast to quadraped you can access the run and walk methods
    std::shared_ptr<Quadraped> quadraped1 = std::dynamic_pointer_cast<Quadraped>(animal1);
    quadraped1->breathe();
    quadraped1->run();
    quadraped1->walk();    
    std::cout << "-------------------" << std::endl;

    // After dynamic cast to dog you can access the bark method
    std::shared_ptr<Dog> dog1 = std::dynamic_pointer_cast<Dog>(animal1);
    dog1->breathe();
    dog1->run();
    dog1->walk();
    dog1->bark();


    std::cout << "\n\n====================" << std::endl;
    std::cout << "Failed Conversions with Smart Pointers" << std::endl;
    std::cout << "====================" << std::endl;


    // Handling for Failed Casts (Pointer Version)
    std::shared_ptr<Animal> animal3(new Quadraped("Oscar", "Cat", "Straight"));

    std::shared_ptr<Dog> dog3 = std::dynamic_pointer_cast<Dog>(animal3);
    if(dog3 == nullptr) {
        // THIS WILL RUN: Animal 3 is not a dog
        std::cout << "Failed to convert animal3 to a dog" << std::endl;
    }
    else {
        // THIS WILL NOT RUN: Animal 3 is not a dog
        dog3->breathe();
        dog3->run();
        dog3->walk();
        dog3->bark();
    }
    std::cout << "-------------------" << std::endl;

    std::shared_ptr<Quadraped> quadraped3 = std::dynamic_pointer_cast<Quadraped>(animal3);
    if(quadraped3 == nullptr) {
        // THIS WILL NOT RUN: Animal 3 will successfully convert
        std::cout << "Failed to convert animal3 to a quadraped" << std::endl;
    }
    else {
        // THIS WILL RUN: Animal 3 is a quadraped
        quadraped3->breathe();
        quadraped3->run();
        quadraped3->walk();
    }



    std::cout << "\n\n====================" << std::endl;
    std::cout << "Functionality with Standard Pointers" << std::endl;
    std::cout << "====================" << std::endl;

    Animal* animal4 = new Dog("Rascal", "Aussie", "Striaght");
    Animal* animal5 = new Quadraped("Phoenix", "Lizard", "None");

    Dog* dog4 = dynamic_cast<Dog*>(animal4);
    Dog* dog5 = dynamic_cast<Dog*>(animal5);
    Quadraped* quadraped5 = dynamic_cast<Quadraped*>(animal5);


    if (dog4 == nullptr) {
        // Won't Run
        std::cout << "Failed to Convert animal4 to dog" << std::endl;
    } else {
        // Will Run
        dog4->breathe();
        dog4->run();
        dog4->walk();
        dog4->bark();
    }


    if (dog5 == nullptr) {
        // Will Run
        std::cout << "Failed to Convert animal5 to dog" << std::endl;
    } else {
        // Won't Run
        dog5->breathe();
        dog5->run();
        dog5->walk();
        dog5->bark();
    }

    if (quadraped5 == nullptr) {
        // Won't Run
        std::cout << "Failed to Convert animal5 to dog" << std::endl;
    } else {
        // Will Run
        quadraped5->breathe();
        quadraped5->run();
        quadraped5->walk();
    }


    



    std::cout << "\n\n====================" << std::endl;
    std::cout << "Functionality with References (Note: Not Recommended, Can't do nullptr checks directly - Need to convert to pointer)" << std::endl;
    std::cout << "====================" << std::endl;

    Quadraped quadraped6("Franky", "Fox", "Straight");
    Animal & animal_ref6 = quadraped6;
    animal_ref6.breathe();

    Quadraped & quadraped_ref6{dynamic_cast<Quadraped&>(animal_ref6)};
    quadraped_ref6.breathe();
    quadraped_ref6.run();
    quadraped_ref6.walk();


    std::cout << "-------------------" << std::endl;
    std::cout << "Converting to Pointer for Null Pointer Checking" << std::endl;
    std::cout << "-------------------" << std::endl;
    Dog* dog6_ptr {dynamic_cast<Dog*>(&animal_ref6)};

    if (dog6_ptr) {
        dog6_ptr->bark();
    }
    else {
        std::cout << "Failed to convert animal6 to dog" << std::endl;
    }



    std::cout << "\n\n====================" << std::endl;
    std::cout << "TypeID Operator" << std::endl;
    std::cout << "====================" << std::endl;

    std::cout << "Fundamental Types (Returns Static Type)" << std::endl;
    std::cout << "Type of int: " << typeid(int).name() << std::endl;

    if (typeid(22) == typeid(int)) {
        std::cout << "22 is an int" << std::endl;
    } else {
        std::cout << "22 is not an int" << std::endl;
    }


    std::cout << "-------------------" << std::endl;
    std::cout << "Polymorphic Types (Returns Dynamic Type) - Using Smart Pointers" << std::endl;
    std::cout << "Animal1 Type: " << typeid(*animal1).name() << std::endl;
    std::cout << "Quadraped1 Type: " << typeid(*quadraped1).name() << std::endl;
    std::cout << "Dog1 Type: " << typeid(*dog1).name() << std::endl;

    std::cout << "-------------------" << std::endl;
    std::cout << "Polymorphic Types (Returns Dynamic Type) - Using Standard Pointers" << std::endl;
    std::cout << "Animal4 Type: " << typeid(*animal4).name() << std::endl;
    std::cout << "Dog4 Type: " << typeid(*dog4).name() << std::endl;

    std::cout << "-------------------" << std::endl;
    std::cout << "Polymorphic Types (Returns Dynamic Type) - Using References" << std::endl;
    std::cout << "Animal6 Type: " << typeid(animal_ref6).name() << std::endl;
    std::cout << "Quandraped6 Type: " << typeid(quadraped6).name() << std::endl;

    delete animal4;
    delete animal5;

    return 0;
}