#include "transform.hpp"
#include <algorithm>
#include <omp.h>

namespace {
std::uint8_t transform_pixel(std::uint8_t value) {
    return static_cast<std::uint8_t>((static_cast<unsigned>(value) * 3u + 17u) % 256u);
}
}

TransformResult transform_image(const std::vector<std::uint8_t>& input, int workers, bool parallel) {
    TransformResult result{std::vector<std::uint8_t>(input.size()), 0, 1};
    // TODO: give the parallel path an OpenMP parallel-for over independent
    // pixels, use a reduction for checksum, and report the workers observed.
    // Preserve the sequential reference path and the public API.
    (void)workers;
    (void)parallel;
    for (std::size_t i = 0; i < input.size(); ++i) {
        result.pixels[i] = transform_pixel(input[i]);
        result.checksum += result.pixels[i];
    }
    return result;
}
