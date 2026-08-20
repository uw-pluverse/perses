CC = cc
SRCS = main.c
SRCS += f1.c
SRCS += f2.c
SRCS += f3.c
SRCS += f4.c
OBJS = $(SRCS:.c=.o)

prog: $(OBJS)
	$(CC) -o prog $(OBJS)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS) prog
