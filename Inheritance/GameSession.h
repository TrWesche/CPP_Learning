#pragma once
#include "Player.h"
#include <string_view>

class GameSession : public Player
{
friend std::ostream& operator << (std::ostream& os, const GameSession& a);

private:
    int m_level;
    int m_lives;
public:
    GameSession();
    GameSession(int in_level, int in_lives);
    GameSession(
        std::string_view in_first_name,
        std::string_view in_last_name,
        std::string_view in_game,
        std::string_view in_char_name,
        int in_level,
        int in_lives
    );
    GameSession(const GameSession& src); // Copy Constructor
    ~GameSession();

    std::string_view print_something() {
        return "Game Session Printing Something";
    }

    std::string_view print_something2() {
        return Player::print_something();
    }
};

