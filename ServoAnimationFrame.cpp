//
// Created by mgoetze on 6/01/2024.
//

#include "ServoAnimationFrame.h"

int ServoAnimationFrame::Interp(const ServoAnimationFrame *first, const ServoAnimationFrame *second, float t)
{
    if( !first )
    {
        return second->angle * t;
    }

    return first->angle + ( second->angle - first->angle ) * t;
}
