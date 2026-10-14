CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra

TARGET := main.exe

ifeq ($(OS),Windows_NT)
RM := cmd /C del /Q
else
RM := rm -f
endif

.PHONY: all run clean

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	-$(RM) $(TARGET) main.o
