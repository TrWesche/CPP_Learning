#include "Player.h"
// #include "Person.h"



Player::Player()
{
}

Player::Player(std::string_view in_game, std::string_view in_char_name) : 
    m_game(in_game), m_char_name(in_char_name)
{
}

Player::Player(
    std::string_view in_game, 
    std::string_view in_char_name, 
    std::string_view in_first_name, 
    std::string_view in_last_name
    ) : 
    Person(in_first_name, in_last_name),
    m_game(in_game),
    m_char_name(in_char_name)
{
}

Player::Player(const Player& src) :
    Person(src), m_game{src.m_game}, m_char_name{src.m_char_name}
{   
}


Player::~Player()
{
}




std::ostream& operator << (std::ostream& os, const Player& a) {
    os  << "Player " << a.m_char_name << " is in game " << a.m_game 
        << " controlled by " << a.m_first_name << " " << a.m_last_name;
    return os;
}