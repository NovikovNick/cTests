```
git clone --recurse-submodules git@github.com:NovikovNick/cTests.git
```

Don't forget to update enviroment:
```
sudo apt-get update
sudo apt-get install --reinstall build-essential
sudo apt install valgrind
```

Compile and run with profiler:
```
c++ -std=c++17 ./src/main/cpp/RemoveLinkedListElements.cpp -o solution.out
c++ -std=c++17 ./src/main/cpp/RomanToInteger.cpp -o solution.out
c++ -std=c++17 ./src/main/cpp/LemonadeChange.cpp -o solution.out
c++ -std=c++17 ./src/main/cpp/InterchangeableRectangles.cpp -o solution.out
c++ -std=c++17 ./src/main/cpp/InterchangeableRectanglesUpd.cpp -o solution.out
c++ -std=c++17 ./src/main/cpp/CountingBits.cpp -o solution.out
c++ -std=c++17 ./src/main/cpp/empty.cpp -o solution.out

time ./solution.out
valgrind ./solution.out
```

For [opengl-tutorial](https://www.opengl-tutorial.org/beginners-tutorials/tutorial-1-opening-a-window/) add several libs
External dependencies
```
git submodule add git@github.com:glfw/glfw.git external_dependencies/glfw/
```
