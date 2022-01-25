#include <iostream>

#include "src/main/cpp/config/TestConfig.h"

int main(int argc, char *argv[]) {

    std::cout << "Version "
              << Test_VERSION_MAJOR << "."
              << Test_VERSION_MINOR << "."
              << Test_VERSION_PATCH << std::endl;

    return 0;
}

/* SOLUTION */

