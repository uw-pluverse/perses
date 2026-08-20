# Top-level Makefile
# Build the widget

PREFIX ?= /usr/local

all: widget

widget: widget.o
	@echo "Linking $@"
	-$(CC) -o $@ $<
	+$(MAKE) -C sub

install: all
	install -d $(PREFIX)/bin
	install widget $(PREFIX)/bin

# end
