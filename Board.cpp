//
// Created by ICEJJ on 2024/11/11.
//
#include "Board.h"

Board::Board() {

    std::cout << "Board Construct\n";

    for(int i = 0 ; i < 3 ; i++) {

        for(int j = 0 ; j < 3 ; j++) {

            m_Board[i][j] = "#";
            m_UnselectedPos.insert({i+1, j+1});
        }
    }


    m_PiecePos.insert({"O", std::unordered_multiset<std::pair<int, int>, pair_hash>{}});
    m_PiecePos.insert({"X", std::unordered_multiset<std::pair<int, int>, pair_hash>{}});

}

Board::~Board() {

    std::cout << "Board Destruct\n";
}

void Board::onRender() {

    for(int i = 0 ; i < 3 ; i++) {

        for(int j = 0 ; j < 3 ; j++) {

            std::cout << m_Board[i][j] << " ";
        }

        std::cout << "\n";
    }
    std::cout << "\n";
}

void Board::onUpdate() {

    auto prevPos = m_ToBeUpdateData->prevPos;
    auto afterPos = m_ToBeUpdateData->afterPos;
    auto symbol = m_ToBeUpdateData->symbol;

    auto& piecePos = m_PiecePos[m_ToBeUpdateData->symbol];

    auto row = prevPos.first;
    auto col = prevPos.second;

    if(piecePos.contains(prevPos)) {

        auto it = piecePos.find(prevPos);
        piecePos.erase(it);
        m_UnselectedPos.insert({row+1, col+1});
    }

    m_Board[row][col] = "#";

    row = afterPos.first;
    col = afterPos.second;
    m_Board[row][col] = symbol;
    piecePos.insert({row, col});
    auto it = m_UnselectedPos.find({row+1, col+1});

    m_UnselectedPos.erase(it);

}

bool Board::setToBeUpdateData(const std::shared_ptr<ToBeUpdateData>& toBeUpdateData) {

    auto prevPos = toBeUpdateData->prevPos;
    auto afterPos = toBeUpdateData->afterPos;
    auto symbol = toBeUpdateData->symbol;
    auto currentSet = m_PiecePos[symbol];
    // Check if moved piece is same with player's piece
    // TODO throw exception
    if(prevPos.first != -1) {

        if(currentSet.size() < 3) {

            Exception::setGameException("You should pick an empty cell\n");
            return false;
        }
        else {


            if(m_Board[prevPos.first][prevPos.second] != symbol) {

                Exception::setGameException("You should pick a cell you picked before\n");
                return false;
            }
        }
    }

    if(m_Board[afterPos.first][afterPos.second] != "#") {

        Exception::setGameException("You should pick an empty cell\n");
        return false;
    }

    m_ToBeUpdateData = std::move(toBeUpdateData);
    return true;
}

std::string Board::getWinner() {

    auto circlePos = m_PiecePos["O"];
    auto crossPos = m_PiecePos["X"];

    if(circlePos.size() == 3) {

        for(const auto& e : winningCombinations) {

            bool win = true;
            for(const auto& pos : e) {

                if(!circlePos.contains(pos)) {

                    win = false;
                    break;
                }
            }

            if(win) {

                return "O";
            }
        }
    }

    if(crossPos.size() == 3) {

        for(const auto& e : winningCombinations) {

            bool win = true;
            for(const auto& pos : e) {

                if(!crossPos.contains(pos)) {

                    win = false;
                    break;
                }
            }

            if(win) {

                return "X";
            }
        }
    }

    return "#";
}

std::set<std::pair<int, int>> Board::getUnselectedPos() {

    return m_UnselectedPos;
}


