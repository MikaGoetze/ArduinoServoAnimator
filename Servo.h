//
// Created by mgoetze on 6/01/2024.
//

#ifndef SERVO_H
#define SERVO_H
#include <chrono>

class Servo {
public:
    /// \brief Stub in replacement for arduino servo API.
    /// \param value The angle to turn the servo to in degrees
    void write( int value ) const;

    /// \brief Stub in replacement for arduino servo API.
    /// \param pin The pin to attach this servo to
    void attach( int pin );
private:
    int pin = -1;

    std::chrono::system_clock::time_point start;
};



#endif //SERVO_H
