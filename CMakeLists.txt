cmake_minimum_required(VERSION 3.27)
project(ServoAnimator)

set(CMAKE_CXX_STANDARD 17)

add_executable(ServoAnimator main.cpp
        ServoController.cpp
        ServoController.h
        Servo.cpp
        Servo.h
        ServoAnimator.cpp
        ServoAnimator.h
        ServoAnimationFrame.cpp
        ServoAnimationFrame.h
        ServoPositionProvider.h)
