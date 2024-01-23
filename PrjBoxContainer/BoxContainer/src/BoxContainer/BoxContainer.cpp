#include "BoxContainer.hpp"
#include <algorithm>

namespace TW {

// Contructors
// Reservation Size Specified Constructor
BoxContainer::BoxContainer(size_t reservation)
    : m_reserved(reservation)
{
    m_elements = std::make_shared<data_type[]>(m_reserved);
}

// Default Constructor
BoxContainer::BoxContainer()
    : BoxContainer(DEFAULT_CAPACITY)
{
}

// Copy Constructor
BoxContainer::BoxContainer(const BoxContainer& in)
{
    m_reserved = in.m_reserved;
    m_allocated = in.m_allocated;
    m_empty = in.m_empty;

    m_elements = std::make_shared<data_type[]>(m_reserved);

    for (size_t i = 0; i < in.m_allocated; i++)
    {
        m_elements[i] = in.m_elements[i];
    }
}

// Default Destructor
BoxContainer::~BoxContainer()
{
}

// Inherited
void BoxContainer::stream_insert(std::ostream& os) const {
    os << "[ ";
    
    for (size_t i{}; i < m_allocated; i++) {
        os << m_elements[i] << " ";
    }

    os << "]";
}

void BoxContainer::push(const data_type& item) {
    if (m_reserved == m_allocated) {
        this->expand_storage(DEFAULT_INCREMENT);
    }

    m_elements[m_allocated] = item;
    m_allocated++;
    m_empty = false;
}

BoxContainer::data_type& BoxContainer::pop() {
    BoxContainer::data_type& instance = m_elements[m_allocated];
    m_allocated--;
    return instance;
}

void BoxContainer::remove_first_of(const data_type& item, bool rightToLeft) {
    if (rightToLeft) {
        remove_item_right(item);
    }
    else {
        remove_item_left(item);
    }
}

void BoxContainer::remove_item_at(size_t index) {
    m_elements[index] = m_elements[m_allocated - 1];
    m_allocated--;

    if (m_allocated == 0) {
        m_empty = true;
    }
}

void BoxContainer::remove_item_left(const data_type& item) {
    if (m_empty) {
        return;
    }

    size_t i{};
    
    for (i; i < m_allocated; i++) {
        if (m_elements[i] == item) {
            remove_item_at(i);
            break;
        }
    }
}

void BoxContainer::remove_item_right(const data_type& item) {
    if (m_empty) {
        return;
    }

    size_t i{m_allocated};
    
    for (i; i > 0; i--) {
        if (m_elements[i] == item) {
            remove_item_at(i);
            break;
        }
    }
}

void BoxContainer::remove_all_of(const data_type& item) {
    if (m_empty) {
        return;
    }

    size_t i{};
    
    while (i < m_allocated) {
        if (m_elements[i] == item) {
            remove_item_at(i);
        }
        i++;
    }
}

void BoxContainer::remove_duplicates_of(const data_type& item) {
    if (m_allocated == -1) {
        return;
    }

    size_t i{0};
    bool found_first = false;

    while (i < m_allocated) {
        if (m_elements[i] == item && !found_first) {
            found_first = true;
        }
        else if (m_elements[i] == item && found_first) {
            remove_item_at(i);
        }
        i++;
    }
}

void BoxContainer::compress() {
    m_reserved = m_allocated;
    std::shared_ptr<data_type[]> elements_new = std::make_shared<data_type[]>(m_reserved);

    for (size_t i{}; i < m_allocated; i++) {
        elements_new[i] = m_elements[i];
    }

    m_elements.swap(elements_new);
    elements_new.reset();
}

void BoxContainer::expand_storage() {
    this->expand_storage(DEFAULT_INCREMENT);
}

void BoxContainer::expand_storage(int size) {
    m_reserved += size;
    std::shared_ptr<data_type[]> elements_new = std::make_shared<data_type[]>(m_reserved);

    for (size_t i{}; i < m_allocated; i++) {
        elements_new[i] = m_elements[i];
    }

    m_elements.swap(elements_new);
    elements_new.reset();
}

BoxContainer& BoxContainer::sum(BoxContainer& left, const BoxContainer& right) {
    size_t total_size_req = left.m_allocated + right.m_allocated;

    if (total_size_req > left.m_reserved) {
        size_t expansion_req = (left.m_allocated + right.m_allocated) - left.m_reserved;
        left.expand_storage(expansion_req);
    }


    for (size_t i{0}; i < right.m_allocated; i++) {
        left.m_elements[left.m_allocated] = right.m_elements[i];
        left.m_allocated++;
    }

    return left;
}

BoxContainer BoxContainer::sum(const BoxContainer& left, const BoxContainer& right) const {
    BoxContainer output = BoxContainer(left.m_allocated + right.m_allocated);
    output.m_allocated = left.m_allocated + right.m_allocated;
    output.m_empty = left.m_empty || right.m_empty;


    for (size_t i{0}; i < left.m_allocated; i++) {
        output.m_elements[i] = left.m_elements[i];
    }

    for (size_t i{0}; i < right.m_allocated; i++) {
        output.m_elements[i + left.m_allocated] = right.m_elements[i];
    }

    return output;
}

BoxContainer& BoxContainer::operator= (const BoxContainer& source) {
    if (this != &source) {
        m_elements.reset();

        m_reserved = source.m_reserved;
        m_allocated = source.m_allocated;
        m_empty = source.m_empty;

        m_elements = std::make_shared<data_type[]>(m_reserved);

        for (size_t i = 0; i < source.m_allocated; i++)
        {
            m_elements[i] = source.m_elements[i];
        }
    }

    return *this;
}

BoxContainer& operator+= (BoxContainer& left, const BoxContainer& right) {
    return left.sum(left, right);
}

BoxContainer operator+ (const BoxContainer& left, const BoxContainer& right) {
    return left.sum(left, right);
}

}