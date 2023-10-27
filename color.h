#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

using color = vec3;

// used to evenly map a floating point representation in [0, 1] to [0, 255] for 8 bit colors
const double COLOR_SCALE_FACTOR = 255.999;

void write_color(std::ostream& out, color pixel_color) {
    // Write the translated [0, 255] value fo each color component.

    out << static_cast<int>(COLOR_SCALE_FACTOR * pixel_color.x()) << ' '
        << static_cast<int>(COLOR_SCALE_FACTOR * pixel_color.y()) << ' '
        << static_cast<int>(COLOR_SCALE_FACTOR * pixel_color.z()) << '\n';
}

#endif
