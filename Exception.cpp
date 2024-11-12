//
// Created by ICEJJ on 2024/11/11.
//

#include "Exception.h"

Exception *Exception::m_GameInstance = nullptr;
std::string Exception::m_GameExceptionMessage;
bool Exception::m_GameException;

std::string Exception::m_AppExceptionMessage;
bool Exception::m_AppException;
Exception Exception::*m_AppInstance = nullptr;

void Exception::Init() {

    m_GameExceptionMessage = "";
    m_GameException = false;

    m_GameExceptionMessage = "";
    m_AppException = false;
}

void Exception::setGameException(const std::string& message) {

    m_GameException = true;
    m_GameExceptionMessage = message;
}

std::string Exception::getGameExceptionMessage() {

    return m_GameExceptionMessage;
}

void Exception::resetGameException() {

    m_GameException = false;
    m_GameExceptionMessage = "";
}

bool Exception::hasGameException() {

    return m_GameException;
}

void Exception::setAppException(const std::string& message) {

    m_AppException = true;
    m_AppExceptionMessage = message;
}

std::string Exception::getAppExceptionMessage() {

    return m_AppExceptionMessage;
}

void Exception::resetAppException() {

    m_AppException = false;
    m_AppExceptionMessage = "";
}

bool Exception::hasAppException() {

    return m_AppException;
}


