//
// Created by ICEJJ on 2024/11/11.
//
#pragma once
#ifndef TIKTACKTOE_APP_H
#define TIKTACKTOE_APP_H
#include "pch.h"
#include "Game.h"
#include "Exception.h"
#include "Player.h"

class App {

public:

    App();
    ~App();

    void init();
    void run();


private:
    std::shared_ptr<Game> m_Game;
    std::shared_ptr<Player> m_PlayerA;
    std::shared_ptr<Player> m_PlayerB;
};


#endif //TIKTACKTOE_APP_H
