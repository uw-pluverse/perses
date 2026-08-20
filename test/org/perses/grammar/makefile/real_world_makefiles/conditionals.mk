DEBUG ?= 0

ifeq ($(DEBUG),1)
  CFLAGS += -g -O0
else
  CFLAGS += -O2
endif

ifdef VERBOSE
  Q =
else
  Q = @
endif

ifneq ($(OS),Windows_NT)
  RM = rm -f
endif

build:
	$(Q)echo building with $(CFLAGS)
