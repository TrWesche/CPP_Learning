#pragma once

class Book{
    friend std::ostream& operator<< (std::ostream& out, const Book& operand);

public : 
    Book(int year, std::string title) 
        : m_year(year),m_title(title)
    {}
    
    bool operator< (const Book & right_operand) const {
        return this->m_year < right_operand.m_year;
    }

private : 
    int m_year;
    std::string m_title;
};

std::ostream& operator<< (std::ostream& out, const Book& operand){
    out << "Book [" << operand.m_year << ", " << operand.m_title << "]";
    return out;
}
