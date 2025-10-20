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
			components/edit.c \
			components/remove.c \
			svg/svg.c \
			svg/load_svg.c \


OBJ     := $(SRC:.c=.o)

.PHONY: all clean run debug rebuild

all: $(TARGET)

$(TARGET): $(OBJ) | bin
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

leaks: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
		--error-exitcode=1 ./$(TARGET)

bin:
	mkdir -p bin

run: all
	@echo "Running program..."
	./$(TARGET)

debug: all
	@echo "Starting GDB..."
	gdb ./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)