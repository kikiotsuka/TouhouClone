all: touhouclone

touhouclone:
	clang++ -I includes/ src/*.cpp -lsfml-graphics -lsfml-window -lsfml-system -o TouhouClone

clean:
	rm TouhouClone
