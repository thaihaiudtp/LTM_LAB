CC = gcc
CFLAGS = -Wall -g -I./model -I./service -I./repository -I./controller -I./util

# Source và Object files
SRC = main.c \
      service/auth_service.c \
      repository/account_repository.c \
      controller/menu.c \
	  util/log.c
OBJ = $(SRC:.c=.o)

# Tên chương trình
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
