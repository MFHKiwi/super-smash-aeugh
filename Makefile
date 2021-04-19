CXX_COMPILER=clang++

build: src/main.cpp src/pufferfish.cpp src/food.cpp src/enemy.cpp
	 xxd -i textures/pufferfish.png | sed 's/textures_//g' > src/pufferfish_data.hpp
	 xxd -i textures/carrot.png | sed 's/textures_//g' > src/food_data.hpp
	 xxd -i textures/enemy.png | sed 's/textures_//g' > src/enemy_data.hpp
	 xxd -i textures/silkscreen.ttf | sed 's/textures_//g' > src/font_data.hpp
	 $(CXX_COMPILER) -c src/main.cpp
	 $(CXX_COMPILER) -c src/pufferfish.cpp
	 $(CXX_COMPILER) -c src/food.cpp
	 $(CXX_COMPILER) -c src/enemy.cpp
	 $(CXX_COMPILER) main.o pufferfish.o food.o enemy.o -o super-smash-aeugh -lsfml-graphics -lsfml-window -lsfml-system -I src/
	 rm *.o
