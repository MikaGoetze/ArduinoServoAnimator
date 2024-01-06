//TODO: Comment this out for arduino
#include <thread>

#include "ServoAnimationFrame.h"
#include "ServoAnimator.h"
#include "ServoController.h"

/// \brief Fixed delta time in ms.
constexpr int FIXED_DELTA_TIME = 15;

ServoAnimationFrame animation[] =
{
    {2000, 60},
    {4000, 30},
    {1000, 180},
    {3000, 90}
};

ServoController controller;
ServoAnimator animator(animation, 4);

void SetupAnimation()
{
    controller.Attach(1);
    controller.SetPositionProvider(&animator);
}

void setup()
{
    //Swap this out for other control methods.
    SetupAnimation();
}

void loop()
{
    while (true)
    {
        auto start = std::chrono::high_resolution_clock::now();
        if( ServoController::TickControllers(FIXED_DELTA_TIME) )
        {
            break;
        }
        auto end = std::chrono::high_resolution_clock::now();
        const auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        // delay( 15 ); // NOTE: Do we need to poll arduino execution time here as well? Or is this deterministic enough that its not needed?
        std::this_thread::sleep_for(std::chrono::milliseconds(FIXED_DELTA_TIME - ms));
    }
}

//TODO: Remove on arduino
int main()
{
    setup();
    loop();
}
