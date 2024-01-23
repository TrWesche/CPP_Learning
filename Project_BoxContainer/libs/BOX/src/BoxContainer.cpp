#include "BoxContainer.h"
#include <algorithm>

using namespace TW;

BoxContainer::BoxContainer(int reservation)
    : m_reserved(reservation)
{
    // m_elements = std::make_shared(new BoxContainer[m_size]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    // m_elements = std::shared_ptr<BoxElement*[m_size]>();
}

BoxContainer::BoxContainer()
{
    BoxContainer(DEFAULT_CAPACITY);
}

BoxContainer::~BoxContainer()
{
}

// Inherited
void BoxContainer::stream_insert(std::ostream& os) const {
    os << "[ ";
    
    for (size_t i{}; i < m_last; i++) {
        os << m_elements[i] << " ";
    }

    os << "]" << std::endl;
}


void BoxContainer::push(const data_type& item) {
    if (m_reserved == m_last) {
        this->expand_storage(DEFAULT_INCREMENT);
    }

    m_elements[m_last] = item;
    m_last++;
}

BoxContainer::data_type& BoxContainer::pop() {
    BoxContainer::data_type& instance = m_elements[m_last];
    m_last--;
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
    m_elements[index] = m_elements[m_last - 1];
    m_last--;
}


void BoxContainer::remove_item_left(const data_type& item) {
    if (m_last == -1) {
        return;
    }

    size_t i{};
    
    for (i; i < m_last; i++) {
        if (m_elements[i] == item) {
            remove_item_at(i);
            break;
        }
    }
}


void BoxContainer::remove_item_right(const data_type& item) {
    if (m_last == -1) {
        return;
    }

    size_t i{m_last};
    
    for (i; i > 0; i--) {
        if (m_elements[i] == item) {
            remove_item_at(i);
            break;
        }
    }
}


void BoxContainer::remove_all_of(const data_type& item) {
    if (m_last == -1) {
        return;
    }

    size_t i{m_last};
    
    while (i > 0) {
        if (m_elements[i] == item) {
            remove_item_at(i);
        }
        i--;
    }
}

void BoxContainer::remove_duplicates_of(const data_type& item) {
    if (m_last == -1) {
        return;
    }

    size_t i{0};
    bool found_first = false;

    while (i < m_last) {
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
    m_reserved = m_last;

    std::shared_ptr<data_type[]> elements_new(new data_type[m_reserved]);

    for (size_t i{}; i < m_last; i++) {
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
    std::shared_ptr<data_type[]> elements_new(new data_type[m_reserved]);

    for (size_t i{}; i < m_last; i++) {
        elements_new[i] = m_elements[i];
    }

    m_elements.swap(elements_new);
    elements_new.reset();
}

BoxContainer& BoxContainer::sum(BoxContainer& left, const BoxContainer& right) {
    int diff = (left.m_reserved - left.m_last) - right.m_last;

    if (diff < 0) {
        left.expand_storage(std::abs(diff) + DEFAULT_INCREMENT);
    }

    size_t end_idx = left.m_last + std::abs(diff);

    for (size_t i{0}; i < right.m_last; i++) {
        left.m_elements[left.m_last] = right.m_elements[i];
        left.m_last++;
    }
}

BoxContainer& BoxContainer::sum(const BoxContainer& left, const BoxContainer& right) const {
    BoxContainer* output = new BoxContainer(left.m_last + right.m_last + DEFAULT_INCREMENT);

    for (size_t i{0}; i < left.m_last; i++) {
        output->m_elements[i] = left.m_elements[i];
    }

    for (size_t i{0}; i < right.m_last; i++) {
        output->m_elements[i + left.m_last] = right.m_elements[i];
    }

    return *output;
}


BoxContainer& operator += (BoxContainer& left, const BoxContainer& right) {
    return left.sum(left, right);
}

BoxContainer& operator + (const BoxContainer& left, const BoxContainer& right) {
    return left.sum(left, right);
}