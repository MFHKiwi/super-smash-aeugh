CXX_COMPILER=clang++

build: src/main.cpp
	 xxd -i assets/pufferfish.png | sed 's/assets_//g' > src/pufferfish_data.hpp
	 xxd -i assets/carrot.png | sed 's/assets_//g' > src/food_data.hpp
	 xxd -i assets/enemy.png | sed 's/assets_//g' > src/enemy_data.hpp
	 xxd -i assets/icon.png | sed 's/assets_//g' > src/icon_data.hpp
	 xxd -i assets/silkscreen.ttf | sed 's/assets_//g' > src/font_data.hpp
	 xxd -i assets/death.wav | sed 's/assets_//g' > src/death_sound.hpp
	 xxd -i assets/eat.wav | sed 's/assets_//g' > src/eat_sound.hpp
	 $(CXX_COMPILER) -c src/main.cpp
	 $(CXX_COMPILER) main.o -o super-smash-aeugh -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -I src/
	 rm *.o

install: ./super-smash-aeugh
	cp ./super-smash-aeugh /usr/bin/ 
