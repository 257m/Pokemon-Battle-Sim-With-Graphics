# This is the makefile for our project

# This defines the compiler we are using
CC = clang

# These are the flags we are going to pass to the compiler
CFLAGS = -c -Wall -g -Wno-everything -pthread -D_REENTRANT -I/nix/store/i8yhzspzcfhasp2drclzcx69ll764i4n-SDL2-2.0.14-dev/include/SDL2
LFLAGS = -lm -L/nix/store/nli3cgripsmk1fjabb81arsgz8437g54-SDL2-2.0.14/lib -Wl,-rpath,/nix/store/nli3cgripsmk1fjabb81arsgz8437g54-SDL2-2.0.14/lib -Wl,--enable-new-dtags -lSDL2 -lSDL2_image -lSDL2_ttf

# This is the name of the executable we are going to create
EXE = main

# This is the directory where our object files will be stored
OBJ_DIR = obj

# This is the list of all source files
SRC = $(wildcard src/*.c)

# This is the list of object files that we need to create
OBJ = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRC))

# This is the default target that is going to be built when we run 'make'
all: $(EXE) run

# This is the rule to build the executable
$(EXE): $(OBJ)
		$(CC) $(LFLAGS) $^ -o $@

# This is the rule to build the object files
$(OBJ_DIR)/%.o: src/%.c
		$(CC) $(CFLAGS) $< -o $@

# This is used to run the program
run:
	./$(EXE)

# This target is used to clean up the project directory
clean:
		rm -f $(OBJ_DIR)/*.o $(EXE)

format:
		clang-format -i -style=file $(SRC)