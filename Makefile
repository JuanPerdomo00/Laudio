CC = cc 
CFLAGS = -O2 -Wall -fPIC `sdl2-config --cflags`
LIBS = `sdl2-config --libs` -lSDL2_mixer -llua
SRC = src/laudio.c src/binding.c
OUT = laudio.so

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -shared -o $(OUT) $(SRC) $(LIBS)

clean:
	rm -rf $(OUT)
