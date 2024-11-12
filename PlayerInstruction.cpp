//
// Created by ICEJJ on 2024/11/11.
//

#include "PlayerInstruction.h"

PlayerInstruction::PlayerInstruction()
    : m_PrevRowIndex(0), m_PrevColIndex(0), m_NewRowIndex(0),
    m_NewColIndex(0), m_Symbol("#"), m_CurrentPieces(0) {

    m_ToBeUpdateData = std::make_shared<ToBeUpdateData>();
}

PlayerInstruction::~PlayerInstruction() {

}

void PlayerInstruction::processInput() {

    if(m_CurrentPieces == 3) {

        std::cout << "Please select a previous cell in the 3*3 grid to be move!\n";
        std::cout << "The index should be in range 1~3\n";
        std::cout << "Please enter row and column index separate by blank: ";
        std::cin >> m_PrevRowIndex >> m_PrevColIndex;
        while((m_PrevRowIndex < 1 || m_PrevRowIndex > 3) || (m_PrevColIndex < 1 || m_PrevColIndex > 3)) {

            std::cout << "The index should be in range 1~3\n";
            std::cout << "Please enter row index separate by blank again: ";
            std::cin >> m_PrevRowIndex;
        }
    }

    std::cout << "Please select a cell in the 3*3 grid!\n";
    std::cout << "The index should be in range 1~3\n";
    std::cout << "Please enter row and column separate by blank: ";
    std::cin >> m_NewRowIndex >> m_NewColIndex;
    while((m_NewRowIndex < 1 || m_NewRowIndex > 3) || (m_NewColIndex < 1 || m_NewColIndex > 3)) {

        std::cout << "The index should be in range 1~3\n";
        std::cout << "Please enter row and column separate by blank again: ";
        std::cin >> m_NewRowIndex >> m_NewColIndex;
    }

    m_CurrentPieces = m_CurrentPieces == 3 ? 3 : m_CurrentPieces+1;

}

void PlayerInstruction::onUpdate() {

    setData();
}

std::shared_ptr<ToBeUpdateData>& PlayerInstruction::getToBeUpdateData() {

    return m_ToBeUpdateData;
}

void PlayerInstruction::setData() {

    m_ToBeUpdateData->prevPos = std::make_pair(m_PrevRowIndex-1, m_PrevColIndex-1);
    m_ToBeUpdateData->afterPos = std::make_pair(m_NewRowIndex-1, m_NewColIndex-1);
    m_ToBeUpdateData->symbol = m_Symbol;
}

void PlayerInstruction::setSymbol(const std::string& symbol) {

    m_Symbol = symbol;
}

int PlayerInstruction::getCurrentPieces() {

    return m_CurrentPieces;
}
