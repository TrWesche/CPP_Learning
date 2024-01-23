#include <initializer_list>
#include <iostream>

class Reverser
{
    private:
        int values[5];

    public:
        Reverser(std::initializer_list<int> list) {
            for (size_t i {}; i < list.size(); i++) {
                std::cout << "Initializing " << i << " : " << *(list.end() - i - 1) << std::endl;
                values[i] = *(list.end() - i - 1);
            }
        }
        ~Reverser();

    public:
        void print() {
            std::cout << "Collection [";
            for (int& value : values) {
                std::cout << value << " ";
            }
            std::cout << "]" << std::flush;
        }
};

Reverser::~Reverser()
{
}

