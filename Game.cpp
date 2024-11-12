//
// Created by ICEJJ on 2024/11/11.
//

#include "Game.h"

Game::Game() {

    init();
}

//Game::Game(uint32_t ID) : m_ID(ID) {
//
//    init();
//}

Game::~Game() {


}

void Game::init() {

    m_Board = std::make_shared<Board>();
    m_CurrentPlayer = nullptr;
}

void Game::onAttached() {

    m_CurrentPlayer = std::make_shared<Player>();
    std::cout << "Player attached\n";
}

void Game::onDetached() {


}

void Game::processInput() {

    m_CurrentPlayer->processInput();
}

void Game::onUpdate() {

    m_CurrentPlayer->onUpdate();
    if(!m_Board->setToBeUpdateData(m_CurrentPlayer->getToBeUpdateData())){

        return;
    }
    m_Board->onUpdate();
}

void Game::onRender() {

    m_Board->onRender();
}

void Game::connectPlayer(std::shared_ptr<Player> &player) {

    m_CurrentPlayer = player;
}

bool Game::gameEnds() {

    return m_Board->getWinner() != "#";
}

std::string Game::getWinner() {

    return m_Board->getWinner();
}


