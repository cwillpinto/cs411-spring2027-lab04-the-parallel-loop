#pragma once
#include <cstdint>
#include <vector>

struct TransformResult {
    std::vector<std::uint8_t> pixels;
    std::uint64_t checksum;
    int workers_observed;
};

TransformResult transform_image(const std::vector<std::uint8_t>& input, int workers, bool parallel);
