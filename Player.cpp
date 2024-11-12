//
// Created by ICEJJ on 2024/11/11.
//

#include "Player.h"

Player::Player() {

    m_PlayerInstruction = std::make_unique<PlayerInstruction>();
}

Player::Player(const std::string& symbol) {

    m_PlayerInstruction = std::make_unique<PlayerInstruction>();
    m_PlayerInstruction->setSymbol(symbol);
}

void Player::processInput() {

    m_PlayerInstruction->processInput();
//    m_PlayerInstruction->setData();
}

void Player::onUpdate() {

    m_PlayerInstruction->onUpdate();
}

void Player::onRender() {
    

}

std::shared_ptr<ToBeUpdateData>& Player::getToBeUpdateData() {

    return m_PlayerInstruction->getToBeUpdateData();
}


