#include <iostream>
#include <thread>

#include "src/main/cpp/config/TestConfig.h"

void hello(std::string s) {
    std::cout << "==> " << s << std::endl;
}


int main(int argc, char *argv[]) {

    std::cout << "Version "
              << Test_VERSION_MAJOR << "."
              << Test_VERSION_MINOR << "."
              << Test_VERSION_PATCH << std::endl;


    std::thread t1(hello, "1");
    std::thread t2(hello, "2");
    t1.join();
    t2.join();

    std::cout << "After join" << std::endl;

    return 0;
}

/* SOLUTION */

