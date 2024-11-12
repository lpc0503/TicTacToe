//
// Created by ICEJJ on 2024/11/11.
//

#include "App.h"

App::App() {

}

App::~App() {


}

void App::init() {

    Exception::Init();
    m_Game = std::make_shared<Game>();
    m_Game->init();
    m_PlayerA = std::make_shared<Player>("O");
    m_PlayerB = std::make_shared<Player>("X");
}

void App::run() {

    m_Game->onRender();

    while(!m_Game->gameEnds()) {

        if(Exception::hasGameException()) {

            std::cout << Exception::getGameExceptionMessage() << std::endl;
            m_Game->onRender();
        }
        else {

            if(m_Game->getCurrentPlayer() == m_PlayerA) {

                m_Game->connectPlayer(m_PlayerB);
            }
            else {

                m_Game->connectPlayer(m_PlayerA);
            }
        }

        Exception::resetGameException();
        m_Game->processInput();
        m_Game->onUpdate();
        m_Game->onRender();
    }
    std::cout << m_Game->getWinner() << " wins the game!\n";
}

