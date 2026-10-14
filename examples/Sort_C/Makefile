CC := gcc
CFLAGS ?= -Wall -Wextra

TARGET := sort_c.exe

ifeq ($(OS),Windows_NT)
RM := cmd /C del /Q
else
RM := rm -f
endif

.PHONY: all clean

all: $(TARGET)

# main.cpp is intentionally compiled as C
$(TARGET): main.cpp sort.c sort.h
	$(CC) $(CFLAGS) -x c main.cpp sort.c -o $@

clean:
	-$(RM) $(TARGET) sort.o
