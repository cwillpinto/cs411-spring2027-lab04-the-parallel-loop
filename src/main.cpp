#include "transform.hpp"
#include <chrono>
#include <cstdint>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::uint8_t> image(4'000'000);
    for (std::size_t i = 0; i < image.size(); ++i) image[i] = static_cast<std::uint8_t>(i % 256);
    const auto baseline = transform_image(image, 1, false);
    std::cout << "workers,elapsed_ms,checksum,workers_observed\n";
    for (int workers : {1, 2, 4, 8}) {
        const auto start = std::chrono::steady_clock::now();
        const auto result = transform_image(image, workers, true);
        const auto ms = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start).count();
        if (result.pixels != baseline.pixels || result.checksum != baseline.checksum) {
            std::cerr << "parallel mismatch at " << workers << " workers\n";
            return 1;
        }
        std::cout << workers << ',' << ms << ',' << result.checksum << ',' << result.workers_observed << '\n';
    }
}
