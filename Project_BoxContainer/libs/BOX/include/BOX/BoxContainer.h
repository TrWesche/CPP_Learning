#ifndef BOX_CONTAINER_H
#define BOX_CONTAINER_H

#include <iostream>
#include <memory>
#include "StreamInsertable.h"

namespace TW {

class BoxContainer : public StreamInsertable
{
    typedef int data_type;
    static const size_t DEFAULT_CAPACITY = 10;
    static const size_t DEFAULT_INCREMENT = 5;
    friend BoxContainer& operator += (BoxContainer& left, const BoxContainer& right);
    friend BoxContainer& operator + (const BoxContainer& left, const BoxContainer& right);
    // friend std::ostream& operator << (std::ostream& os, const BoxContainer& right);

public:
    // Contructor/Destructor
    BoxContainer(); 
    BoxContainer(int reservation);
    BoxContainer(const BoxContainer& in);  // Copy Constructor
    ~BoxContainer();

    // Operator Overloads
    BoxContainer& operator = (const BoxContainer& right);

    // Inherited
    virtual void stream_insert(std::ostream& os) const override;
    // virtual void add_and_update(const Summable& right) override;
    // virtual Summable& add_create_new(const Summable& right) const override;


    // Methods
    virtual void push(const data_type& item);
    virtual void remove_first_of(const data_type& item, bool rightToLeft = false);
    virtual void remove_all_of(const data_type& item);
    virtual void remove_duplicates_of(const data_type& item);
    virtual void compress();
    virtual data_type& pop();
    virtual BoxContainer& sum(BoxContainer& left, const BoxContainer& right);
    virtual BoxContainer& sum(const BoxContainer& left, const BoxContainer& right) const;

    int get_reserved() const {
        return m_reserved;
    }

    int get_size() const {
        return m_last;
    }

protected:
    int m_reserved; // Space reserved in the system
    int m_last; // Last index where valid data is present
    std::shared_ptr<data_type[]> m_elements;

private:
    /* data */
    void expand_storage();
    void expand_storage(int size);


    void remove_item_at(size_t index);
    void remove_item_right(const data_type& item);
    void remove_item_left(const data_type& item);
};


}




#endif