//
// Created by ICEJJ on 2024/11/11.
//

#ifndef TICTACTOE_ENTITY_H
#define TICTACTOE_ENTITY_H

#include "pch.h"

class Entity {

public:
    Entity() = default;
    virtual ~Entity() = default;

    virtual void processInput() {std::cout << "on Entity process input\n";}
    virtual void onUpdate() {std::cout << "on Entity update\n";}
    virtual void onRender() {std::cout << "on Entity render\n";}

protected:
    std::string m_DebugName;

};


#endif //TIKTACKTOE_ENTITY_H
