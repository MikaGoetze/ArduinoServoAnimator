//
// Created by mgoetze on 6/01/2024.
//

#ifndef SERVOANIMATION_H
#define SERVOANIMATION_H
#include "ServoAnimationFrame.h"
#include "ServoPositionProvider.h"

class ServoAnimator : public ServoPositionProvider {
private:
    ServoAnimationFrame *frames = nullptr;
    int numFrames = 0;

    int currentFrame = 0;
    int accumulatedTime = 0;

public:
    ServoAnimator() = default;
    ServoAnimator( ServoAnimationFrame* frames, int numFrames );

    /// \brief Ticks the animation by time and returns the new desired angle for the servo
    /// \param time The time to progress the animation
    /// \param outIsFinished Whether or not the animation is finished
    /// \return The angle to turn to
    int Tick(int time, bool &outIsFinished) override;
};



#endif //SERVOANIMATION_H
