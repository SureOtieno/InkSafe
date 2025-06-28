cmake_minimum_required(VERSION 3.5)

project(InkSafe VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Required Qt components
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Gui Widgets Sql Multimedia MultimediaWidgets)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Sql Multimedia MultimediaWidgets)

# Your source files
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    dbConnection.cpp

)

qt_add_executable(InkSafe
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

# Link required Qt libraries
target_link_libraries(InkSafe PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Sql
    Qt6::Multimedia
    Qt6::MultimediaWidgets
)

# Optional macOS/iOS specific stuff
set_target_properties(InkSafe PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

qt_finalize_executable(InkSafe)
