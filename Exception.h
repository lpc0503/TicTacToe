//
// Created by ICEJJ on 2024/11/11.
//
#pragma once
#ifndef TICTACTOE_EXCEPTION_H
#define TICTACTOE_EXCEPTION_H
#include "pch.h"

class Exception {

public:

    static Exception* getGameExceptionInstance() {

        return m_GameInstance;
    }

    static Exception* getAppExceptionInstance() {

        return m_AppInstance;
    }

    static void Init();

    static void setGameException(const std::string& message="");

    static std::string getGameExceptionMessage();

    static void resetGameException();

    static bool hasGameException();

    static void setAppException(const std::string& message="");

    static std::string getAppExceptionMessage();

    static void resetAppException();

    static bool hasAppException();

private:

    Exception() = default;

    // Delete copy constructor and assignment operator to ensure singleton property
    Exception(const Exception&) = delete;
    Exception& operator=(const Exception&) = delete;

    static std::string m_GameExceptionMessage;
    static bool m_GameException;
    static Exception *m_GameInstance;

    static std::string m_AppExceptionMessage;
    static bool m_AppException;
    static Exception *m_AppInstance;
};


#endif //TIKTACKTOE_EXCEPTION_H
