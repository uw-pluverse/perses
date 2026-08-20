CC = gcc
CFLAGS = -Wall -O2
SRCS = main.c util.c io.c
OBJS = $(SRCS:.c=.o)
TARGET = app

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
