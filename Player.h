//
// Created by ICEJJ on 2024/11/11.
//
#pragma once
#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H
#include "pch.h"
#include "PlayerInstruction.h"

class Player: Entity {

public:

    Player();
    explicit Player(const std::string& symbol);
    ~Player() = default;

    void processInput() override;
    void onUpdate() override;
    void onRender() override;
    std::shared_ptr<ToBeUpdateData>& getToBeUpdateData();

private:

    std::unique_ptr<PlayerInstruction> m_PlayerInstruction;
    std::shared_ptr<ToBeUpdateData> m_ToBeUpdateData;
    std::string m_symbol;
    std::set<std::pair<int, int>> m_Availability;
};


#endif //TIKTACKTOE_PLAYER_H
