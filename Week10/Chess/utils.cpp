#include "utils.hpp"

int sign(int x) {
    return (x > 0) - (x < 0);
}

bool between(int value, int min, int max) {
    return value >= min && value <= max;
}
