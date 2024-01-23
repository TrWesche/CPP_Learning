// Nested Classes
//      - When inner is private its objects cannot be created from the outside
//      - Outer doesn't have access to inner's private variables
//      - Inner has access to outer's private section but:
//          - Inner can only directly access static members
//          - Inner must go through an object to access Outer's member variables

class Outer
{
    public:
        Outer() = default;
        ~Outer();

    private:
        /* data */
        int m_out1;
        double m_out2;
        class Inner {
            public:
                Inner() = default;
            private:
                int var1;
        };
};

Outer::Outer(/* args */)
{
}

Outer::~Outer()
{
}
