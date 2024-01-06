//
// Created by mgoetze on 6/01/2024.
//

#include "ServoController.h"

ServoController::ServoController()
{
    controllers[numControllers] = this;
    numControllers++;
}

void ServoController::Attach(int pin)
{
    servo.attach( pin );
}

void ServoController::SetPositionProvider(ServoPositionProvider *provider)
{
    positionProvider = provider;
}

bool ServoController::Tick(const int deltaTime) const
{
    const int angle = positionProvider->Tick( deltaTime, TODO);
    servo.write( angle );
}

bool ServoController::TickControllers(const int deltaTime)
{
    bool allAreFinished = true;
    for (size_t controllerIndex = 0; controllerIndex < numControllers; controllerIndex++)
    {
        if( !controllers[controllerIndex]->Tick( deltaTime ) )
        {
            allAreFinished = false;
        }
    }

    return allAreFinished;
}

ServoController* ServoController::controllers[];
uint8_t ServoController::numControllers;
