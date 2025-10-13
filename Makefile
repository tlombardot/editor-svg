CC      := gcc
CFLAGS  := -std=c99 -Wall -Werror -Wextra -g -O0
TARGET  := bin/main
SRC     := main.c \
			components/create.c \
			components/get.c \
			components/list.c \
			utils/windows_user.c \
			config/allocate.c \
			utils/interface_path.c \
			config/path.c \
			config/style.c \


OBJ     := $(SRC:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ) | bin
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bin:
	mkdir -p bin

run: $(TARGET)
	./$(TARGET)

# Lance le programme avec gdb pour voir les segfaults
debug: $(TARGET)
	gdb ./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
