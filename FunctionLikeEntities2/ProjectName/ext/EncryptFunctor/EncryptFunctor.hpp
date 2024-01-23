#pragma once

class EncryptFunctor
{
private:
    /* data */
public:
    // EncryptFunctor(/* args */);
    // ~EncryptFunctor();

    char operator() (const char& input) 
    {
        return static_cast<char> (input + 3);
    }
};

// EncryptFunctor::EncryptFunctor(/* args */)
// {
// }

// EncryptFunctor::~EncryptFunctor()
// {
// }
