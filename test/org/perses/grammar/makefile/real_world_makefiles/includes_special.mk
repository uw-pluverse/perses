-include config.mk
include rules/common.mk

.SUFFIXES:
.SUFFIXES: .c .o
.DEFAULT_GOAL := all

OBJS = a.o b.o c.o

$(OBJS): %.o: %.c
	$(CC) -c $< -o $@

all: $(OBJS)
	@echo done
