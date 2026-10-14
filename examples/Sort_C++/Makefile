CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra

TARGET := sort_cpp.exe

ifeq ($(OS),Windows_NT)
RM := cmd /C del /Q
else
RM := rm -f
endif

.PHONY: all clean

all: $(TARGET)

$(TARGET): main.cpp sort.h
	$(CXX) $(CXXFLAGS) main.cpp -o $@

clean:
	-$(RM) $(TARGET)
