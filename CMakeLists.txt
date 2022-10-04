cmake_minimum_required(VERSION 3.0.0)

project(tcpClient)

add_executable(${PROJECT_NAME}
    ./src/main.cpp
    ./src/hw/tcpClient/tcpClient.cpp
    ./src/hw/Button/Button.cpp
    ./src/hw/Led/Led.cpp
    ./src/app/Listener/Listener.cpp
    ./src/app/Controller/Controller.cpp
    ./src/app/View/View.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ./src/hw/Button
    ./src/hw/Led
    ./src/hw/tcpClient
    ./src/app/Listener
    ./src/app/Controller
    ./src/app/View
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    -lwiringPi
)

target_compile_options(${PROJECT_NAME} PUBLIC
    -Wall
)
