//
// Created by mgoetze on 6/01/2024.
//

#ifndef SERVOPOSITIONPROVIDER_H
#define SERVOPOSITIONPROVIDER_H

/*
 * This provides an interface to use to implement various different types of servo control mechanisms
 * Each separate API simply needs to accept a deltaTime input and return an angle.
 */

class ServoPositionProvider {
public:
    virtual ~ServoPositionProvider() = default;

    /// \brief Ticks the provider and returns the new desired angle for the servo.
    /// \param deltaTime The time since the last tick
    /// \param outIsFinished Out variable: Whether or not the position provider has finished
    /// \return The angle we want the servo to turn to immediately.
    virtual int Tick(int deltaTime, bool &outIsFinished) = 0;
};

#endif //SERVOPOSITIONPROVIDER_H
