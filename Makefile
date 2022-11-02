all: clean main

CC = clang
override CFLAGS += -g -Wno-everything -pthread -lm -I/nix/store/i8yhzspzcfhasp2drclzcx69ll764i4n-SDL2-2.0.14-dev/include/SDL2 -L/nix/store/nli3cgripsmk1fjabb81arsgz8437g54-SDL2-2.0.14/lib -Wl,-rpath,/nix/store/nli3cgripsmk1fjabb81arsgz8437g54-SDL2-2.0.14/lib -Wl,--enable-new-dtags -lSDL2 -lSDL2_image -lSDL2_ttf

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)

main: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o "$@"

main-debug: $(SRCS)
	$(CC) $(CFLAGS) -O0 $(SRCS) -o "$@"

clean:
	rm -f main main-debug