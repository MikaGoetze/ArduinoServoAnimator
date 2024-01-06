//
// Created by mgoetze on 6/01/2024.
//

#include "Servo.h"
#include <iostream>

void Servo::write(const int value) const
{
    const auto now = std::chrono::high_resolution_clock::now();
    const float diff = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count() / 1000.0f;
    std::cout << "[" << pin << "] " << value << " @ " << diff << std::endl;
}

void Servo::attach(const int pin)
{
    this->pin = pin;
    start = std::chrono::high_resolution_clock::now();
}
