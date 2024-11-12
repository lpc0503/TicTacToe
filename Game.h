//
// Created by ICEJJ on 2024/11/11.
//
#pragma once
#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H
#include "pch.h"
#include "Board.h"
#include "Player.h"
#include "Exception.h"

class Game {

public:

    Game();
//    Game(uint32_t ID);
    ~Game();

    void onAttached();
    void onDetached();

    void init();
    void processInput();
    void onUpdate();
    void onRender();
    bool gameEnds();
    std::string getWinner();

    void connectPlayer(std::shared_ptr<Player>& player);

    std::shared_ptr<Player>& getCurrentPlayer() { return m_CurrentPlayer; }
    void setID(uint32_t ID) { m_ID = ID; }
    uint32_t getID() { return m_ID; }

private:
    std::shared_ptr<Board> m_Board;
    std::shared_ptr<Player> m_CurrentPlayer;
    uint32_t m_ID;
};


#endif //TIKTACKTOE_GAME_H
