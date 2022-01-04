cmake_minimum_required(VERSION 3.5)

project(ChessPoint LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS
    quen.h
    knight.h
    pawn.h
    processtext.h
    scanchessboard.h
    pieces.h
    chessboard.h
    king.h 
    bishop.h
    rook.h 
    calculatepoints.h)
set(SOURCES
    main.cpp
    quen.cpp
    knight.cpp
    pawn.cpp
    processtext.cpp
    scanchessboard.cpp
    pieces.cpp
    chessboard.cpp
    king.cpp
    bishop.cpp
    rook.cpp
    calculatepoints.cpp )

add_executable(ChessPoint ${SOURCES} ${HEADERS})

target_include_directories(ChessPoint
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

