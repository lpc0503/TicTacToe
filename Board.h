//
// Created by ICEJJ on 2024/11/11.
//
#pragma once
#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include "pch.h"
#include "Entity.h"
#include "UpdateData.h"
#include "Exception.h"

class Board : Entity {

public:

    Board();
    ~Board() override;

    void processInput() override {}
    void onUpdate() override;
    void onRender() override;
    bool setToBeUpdateData (const std::shared_ptr<ToBeUpdateData>& toBeUpdateData);
    std::string getWinner();
    std::set<std::pair<int, int>> getUnselectedPos();

private:

    struct pair_hash {
        template <typename T1, typename T2>
        std::size_t operator ()(const std::pair<T1, T2>& p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };

    std::array<std::array<std::string, 3>, 3> m_Board;
    std::shared_ptr<ToBeUpdateData> m_ToBeUpdateData;
    std::unordered_map<std::string, std::unordered_multiset<std::pair<int, int>, pair_hash>> m_PiecePos;
    std::set<std::pair<int, int>> m_UnselectedPos;

    std::unordered_set<std::pair<int, int>, pair_hash> winningCombinations[8] = {
            {{0, 0}, {0, 1}, {0, 2}}, // Row 1
            {{1, 0}, {1, 1}, {1, 2}}, // Row 2
            {{2, 0}, {2, 1}, {2, 2}}, // Row 3
            {{0, 0}, {1, 0}, {2, 0}}, // Column 1
            {{0, 1}, {1, 1}, {2, 1}}, // Column 2
            {{0, 2}, {1, 2}, {2, 2}}, // Column 3
            {{0, 0}, {1, 1}, {2, 2}}, // Diagonal 1
            {{0, 2}, {1, 1}, {2, 0}}  // Diagonal 2
    };
};


#endif //TIKTACKTOE_BOARD_H
