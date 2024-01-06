//
// Created by mgoetze on 6/01/2024.
//

#ifndef SERVOANIMATIONFRAME_H
#define SERVOANIMATIONFRAME_H

class ServoAnimationFrame {
public:
    /// \brief The time over which to move to this frame in ms.
    int time;

    /// \brief The angle to move to in degrees.
    int angle;

    /// \brief Interpolates between two frames based on t and returns the resulting angle.
    /// \param first The first frame we want to interpolate from
    /// \param second The second frame we want to interpolate to
    /// \param t The normalised time to use for interpolation
    /// \return The interpolated angle
    static int Interp( const ServoAnimationFrame* first, const ServoAnimationFrame* second, float t );
};



#endif //SERVOANIMATIONFRAME_H
