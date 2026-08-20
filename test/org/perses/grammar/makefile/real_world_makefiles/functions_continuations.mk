SOURCES := $(wildcard src/*.c) \
           $(wildcard lib/*.c)
OBJECTS := $(patsubst %.c,%.o,$(SOURCES))
HEADERS := $(shell find . -name "*.h")
UPPER := $(foreach d,$(DIRS),$(d)/include)

INCLUDES = -Iinc \
           -Ivendor/inc \
           -Ithird_party

compile:
	gcc $(INCLUDES) \
	    $(SOURCES) \
	    -o out
