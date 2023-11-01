#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

using color = vec3;

// used to evenly map a floating point representation in [0, 1] to [0, 255] for 8 bit colors
const double COLOR_SCALE_FACTOR = 256;

inline double linear_to_gamma(double linear_component) {
    return sqrt(linear_component);
}

void write_color(std::ostream& out, color pixel_color, int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Divide the color by the number of samples.
    auto scale = 1.0 / samples_per_pixel;

    r *= scale;
    g *= scale;
    b *= scale;

    // Apply the linear to gamma transform.
    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);

    // Write the translated [0, 255] value fo each color component.
    static const interval intensity(0.000, 0.999);
    out << static_cast<int>(COLOR_SCALE_FACTOR * intensity.clamp(r)) << ' '
        << static_cast<int>(COLOR_SCALE_FACTOR * intensity.clamp(g)) << ' '
        << static_cast<int>(COLOR_SCALE_FACTOR * intensity.clamp(b)) << '\n';
}

#endif
