#include "random.h"

std::mt19937& prng() {
    static std::mt19937 instance(std::random_device{}());
    return instance;
}
