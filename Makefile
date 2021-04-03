CXX_COMPILER=clang++

build: src/main.cpp src/pufferfish.cpp
	 $(CXX_COMPILER) -c src/main.cpp
	 $(CXX_COMPILER) -c src/pufferfish.cpp
	 $(CXX_COMPILER) main.o pufferfish.o -o super-smash-aeugh -lsfml-graphics -lsfml-window -lsfml-system -I src/
	 rm *.o
