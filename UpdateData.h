//
// Created by ICEJJ on 2024/11/11.
//
#pragma once
#ifndef TICTACTOE_UPDATEDATA_H
#define TICTACTOE_UPDATEDATA_H
#include "pch.h"

struct ToBeUpdateData {

    std::pair<int, int> prevPos;
    std::pair<int, int> afterPos;
    std::string symbol;
};

#endif //TIKTACKTOE_UPDATEDATA_H
