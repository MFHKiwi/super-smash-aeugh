export CXX_COMPILER = clang++

build: src/main.cpp
	$(CXX_COMPILER) src/main.cpp -o super-smash-aeugh -lsfml-graphics -lsfml-window -lsfml-system
