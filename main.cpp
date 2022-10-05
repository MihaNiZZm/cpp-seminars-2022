#include "vector.h"

#include <array>
#include <cstdlib>
#include <iostream>

int main(int argc, char** argv) {
    vector v1 = vector();
    v1.pushBack(34);
    v1.pushBack(28);
    vector v2 = vector(v1);
    return 0;
}