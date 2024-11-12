//
// Created by ICEJJ on 2024/11/11.
//
#pragma once
#ifndef TICTACTOE_INSTRUCTION_H
#define TICTACTOE_INSTRUCTION_H
#include "pch.h"
#include "UpdateData.h"
#include "Board.h"

class Instruction {

public:

    Instruction() = default;
    virtual ~Instruction() = default;

    virtual void processInput() = 0;
    virtual void onUpdate() = 0;

protected:

};


#endif //TIKTACKTOE_INSTRUCTION_H
