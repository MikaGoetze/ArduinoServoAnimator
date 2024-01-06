//
// Created by mgoetze on 6/01/2024.
//

#ifndef SERVOCONTROLLER_H
#define SERVOCONTROLLER_H
#include <cstdint>
#include "Servo.h"
#include "ServoPositionProvider.h"

class ServoController
{
private:
    // ====== Static fields ======
    static constexpr size_t MAX_SERVO_CONTROLLERS = 16;
    static ServoController *controllers[MAX_SERVO_CONTROLLERS];
    static uint8_t numControllers;

    // ====== Member fields ======

    /// \brief The arduino servo we're controlling
    Servo servo;

    /// \brief The position provider (virtual) that tells us where to turn.
    ServoPositionProvider *positionProvider = nullptr;

    /// \brief Ticks this servo once.
    /// \param deltaTime The time since the last tick in ms.
    /// \return Whether or not this controller is finished.
    bool Tick(int deltaTime) const;

public:
    ServoController();

    /// \brief Intitalises the servo controller and attaches it to a physical pin.
    /// \param pin The pin to attach the servo to
    void Attach(int pin);

    /// \brief Sets the position provider for this controller (i.e what dictates how the servo moves over time).
    /// \param provider The provider to set for this controller
    void SetPositionProvider(ServoPositionProvider *provider);

    /// \brief Ticks all controllers once.
    /// \param deltaTime The delta time since the last tick
    /// \return Whether or not all controllers are finished.
    static bool TickControllers(int deltaTime);
};


#endif //SERVOCONTROLLER_H
