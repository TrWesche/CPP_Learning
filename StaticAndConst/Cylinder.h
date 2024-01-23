class Cylinder
{
private:
    static inline const double m_PI {3.141592};
    double m_radius;
    double m_height;
public:
    Cylinder(double in_radius, double in_height) : 
        m_radius(in_radius), m_height(in_height) {};
    Cylinder() : 
        Cylinder(1.0, 1.0) {};
    ~Cylinder();
};

Cylinder::Cylinder(/* args */)
{
}

Cylinder::~Cylinder()
{
}
