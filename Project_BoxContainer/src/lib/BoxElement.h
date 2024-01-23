#ifndef BOX_ELEMENT_H
#define BOX_ELEMENT_H

class BoxElement
{
friend BoxElement& operator == (const BoxElement& a, const BoxElement& b);

private:
    /* data */

protected:
    virtual bool is_equal(const BoxElement& a, const BoxElement& b) = 0;

public:
    BoxElement(/* args */);
    ~BoxElement();
};

BoxElement::BoxElement(/* args */)
{
}

BoxElement::~BoxElement()
{
}



#endif