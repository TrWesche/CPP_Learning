class Box {
    private:
        double m_x {1.0};
        double m_y {1.0};
        double m_z {1.0};
        double* heap_variable;

    public:
        // Constructors
        // Box() = default; // How to Use Default Constructor if you defined a constructor
        Box(); // Default Constructor
        Box(double x, double y, double z);

        // Destructor
        ~Box();

        // Setters
        Box* set_x(double x);
        Box* set_y(double y);
        Box* set_z(double z);

        // Getters
        double get_x();
        double get_y();
        double get_z();

        // Methods
        double volume();


};