#include "GameSession.h"


GameSession::GameSession() : m_level(0), m_lives(0)
{
}

GameSession::GameSession(int in_level, int in_lives) : m_level(in_level), m_lives(in_lives)
{
}

GameSession::GameSession(
    std::string_view in_first_name,
    std::string_view in_last_name,
    std::string_view in_game,
    std::string_view in_char_name,
    int in_level,
    int in_lives
) : 
    Player(in_first_name, in_last_name, in_game, in_char_name),
    m_level(in_level),
    m_lives(in_lives)
{
}

GameSession::GameSession(const GameSession& src) :
    Player(src), m_level(src.m_level), m_lives(src.m_lives)
{   
}

GameSession::~GameSession()
{
}


std::ostream& operator << (std::ostream& os, const GameSession& a) {
    os  << "Player " << a.m_char_name << " is in game " << a.m_game 
        << " controlled by " << a.m_first_name << " " << a.m_last_name 
        << ".\nCurrent Level: " << a.m_level << " Lives: " << a.m_lives;
    return os;
}