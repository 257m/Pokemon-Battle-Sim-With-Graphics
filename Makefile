all: clean main

CC = clang
override CFLAGS += -g -Wno-everything -pthread -lm -I/nix/store/i8yhzspzcfhasp2drclzcx69ll764i4n-SDL2-2.0.14-dev/include/SDL2 -L/nix/store/nli3cgripsmk1fjabb81arsgz8437g54-SDL2-2.0.14/lib -Wl,-rpath,/nix/store/nli3cgripsmk1fjabb81arsgz8437g54-SDL2-2.0.14/lib -Wl,--enable-new-dtags -lSDL2 -lSDL2_image -lSDL2_ttf

main: $(SRCS)
	$(CC) $(CFLAGS) main.c -o "$@"

typechart:
	clang typechart.c -o typechart
	./typechart temptxt.txt output.txt

clean:
	rm -f main main-debug