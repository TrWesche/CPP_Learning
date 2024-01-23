#ifndef SUMMABLE_H
#define SUMMABLE_H

namespace TW {
    class Summable
    {
        friend Summable& operator += (Summable& left, const Summable& right);
        friend Summable& operator + (const Summable& left, const Summable& right);

    private:
        /* data */
    public:
        virtual void add_and_update(const Summable& right) = 0;
        virtual Summable& add_create_new(const Summable& right) const = 0;
    };
    
}

#endif