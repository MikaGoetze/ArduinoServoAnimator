//
// Created by mgoetze on 6/01/2024.
//

#include "ServoAnimator.h"

ServoAnimator::ServoAnimator(ServoAnimationFrame *frames, int numFrames)
{
    this->frames = frames;
    this->numFrames = numFrames;
}

int ServoAnimator::Tick(int time, bool &outIsFinished)
{
    if (numFrames == 0)
    {
        outIsFinished = true;
        return 0;
    }

    if( currentFrame >= numFrames )
    {
        // Let the animation hang on the last frame.
        outIsFinished = true;
        return frames[numFrames - 1].angle;
    }

    const auto &frame = frames[currentFrame];
    accumulatedTime += time;

    if (accumulatedTime > frame.time)
    {
        accumulatedTime -= frame.time;
        currentFrame++;
        return Tick(0, outIsFinished); // Subsequent ticks don't need to increment accumulatedTime.
    }

    const float t = static_cast<float>(accumulatedTime) / frame.time;
    outIsFinished = false;
    return ServoAnimationFrame::Interp(currentFrame == 0 ? nullptr : &frames[currentFrame - 1], &frames[currentFrame], t);
}
