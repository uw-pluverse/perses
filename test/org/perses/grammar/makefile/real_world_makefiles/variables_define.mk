IMMEDIATE := value
LAZY = $(IMMEDIATE)/sub
COND ?= default
APPEND := a
APPEND += b c
export PATH := /opt/bin:$(PATH)
override VERBOSE = 1

define GREETING
  echo "hello"
  echo "world"
endef

greet:
	$(GREETING)
