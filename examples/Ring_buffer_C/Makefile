CC := gcc
CFLAGS ?= -Wall -Wextra

TARGET := ring_c.exe

ifeq ($(OS),Windows_NT)
RM := cmd /C del /Q
else
RM := rm -f
endif

.PHONY: all clean

all: $(TARGET)

# main.cpp is intentionally compiled as C
$(TARGET): main.cpp ring_buffer.c ring_buffer.h
	$(CC) $(CFLAGS) -x c main.cpp ring_buffer.c -o $@

clean:
	-$(RM) $(TARGET)
