#include "transform.hpp"
#include <cstdint>
#include <iostream>
#include <vector>

int main() {
    for (std::size_t size : {0u, 1u, 257u, 100000u}) {
        std::vector<std::uint8_t> pixels(size);
        for (std::size_t i = 0; i < size; ++i) pixels[i] = static_cast<std::uint8_t>(i % 251);
        const auto baseline = transform_image(pixels, 1, false);
        for (int workers : {1, 2, 4, 8}) {
            const auto actual = transform_image(pixels, workers, true);
            if (actual.pixels != baseline.pixels || actual.checksum != baseline.checksum) {
                std::cerr << "mismatch at size " << size << ", workers " << workers << '\n';
                return 1;
            }
            if (size == 100000 && workers == 4) {
                if (actual.workers_observed <= 1) {
                    std::cerr << "parallel TODO remains incomplete\n";
                    return 1;
                }
            }
        }
    }
    std::cout << "transform checks passed\n";
}
