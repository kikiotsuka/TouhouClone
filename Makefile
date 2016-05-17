all: touhouclone

touhouclone:
	clang++ src/*.cpp -lsfml-graphics -lsfml-window -lsfml-system -o TouhouClone

clean:
	rm TouhouClone
