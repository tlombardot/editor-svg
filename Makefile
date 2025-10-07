CC      := gcc
CFLAGS  := -std=c99 -Wall -Werror -Wextra
TARGET  := bin/main
SRC     := main.c \
			components/create.c \
			components/get.c \
			components/list.c \
			utils/windows_user.c \

OBJ     := $(SRC:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ) | bin
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bin:
	mkdir -p bin

clean:
	rm -f $(OBJ) $(TARGET)
