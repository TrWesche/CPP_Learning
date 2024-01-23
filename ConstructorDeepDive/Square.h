class Square
{
    private:
        double side {0};
        
    public:
        Square() = default;
        explicit Square(double in_side); // Explicit Flag prevents the constructor from being used with implicit conversions
        ~Square();
};

Square::Square(double in_side)
{
    side = in_side;
}

Square::~Square()
{
}
