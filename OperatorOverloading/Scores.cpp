#include "Scores.h"


Scores::Scores(const std::string& course_name) : m_course_name(course_name)
{
}

Scores::~Scores()
{
}

void Scores::print_info() {
    std::cout << "The Scores for Class: " << m_course_name << " are: ";

    for (size_t i = 0; i < 20; i++)
    {
        std::cout << m_scores[i];
        if (i < 19) {
            std::cout << ",";
        }
    }
    
    std::cout << std::endl;
}


double& Scores::operator[] (size_t index) {
    assert(index >= 0 && index < 20);
    return m_scores[index];
}


const double& Scores::operator[] (size_t index) const {
    assert(index >= 0 && index < 20);
    return m_scores[index];
}