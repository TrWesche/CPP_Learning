#pragma once

class DecryptFunctor
{
private:
    /* data */
public:
    // DecryptFunctor(/* args */);
    // ~DecryptFunctor();

    char operator() (const char& input) 
    {
        return static_cast<char> (input - 3);
    }
};

// DecryptFunctor::DecryptFunctor(/* args */)
// {
// }

// DecryptFunctor::~DecryptFunctor()
// {
// }
