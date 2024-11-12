//
// Created by ICEJJ on 2024/11/11.
//
#pragma once
#ifndef TICTACCTOE_PLAYERINSTRUCTION_H
#define TICTACCTOE_PLAYERINSTRUCTION_H

#include "pch.h"
#include "Instruction.h"
#include "UpdateData.h"

class PlayerInstruction : Instruction {

public:

    PlayerInstruction();
    ~PlayerInstruction() override;

    void processInput() override;
    void onUpdate() override;
    void setData();
    void setSymbol(const std::string& symbol);
    int getCurrentPieces();
    std::shared_ptr<ToBeUpdateData>& getToBeUpdateData();
//    void setAvailability(const std::shared_ptr<Board>& board);
//    std::set<std::pair<int, int>> getAvailability();

private:

    int m_PrevRowIndex;
    int m_PrevColIndex;
    int m_NewRowIndex;
    int m_NewColIndex;
    int m_CurrentPieces;
    std::string m_Symbol;

    std::shared_ptr<ToBeUpdateData> m_ToBeUpdateData;
};


#endif //TIKTACKTOE_PLAYERINSTRUCTION_H
