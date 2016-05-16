all: touhouclone

touhouclone:
	clang++ *.cpp -lsfml-graphics -lsfml-window -lsfml-system -o TouhouClone

clean:
	rm TouhouClone
