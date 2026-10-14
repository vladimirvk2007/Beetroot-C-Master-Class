CXX ?= g++
CXXFLAGS ?= -std=c++11 -Wall -Wextra -Werror

TARGET := clock.exe
SOURCES := clock.cpp real_time_ticker.cpp console_clock_display.cpp main.cpp
HEADERS := clock.h clock_display.h clock_ticker.h real_time_ticker.h console_clock_display.h

ifeq ($(OS),Windows_NT)
RM := cmd /C del /Q
else
RM := rm -f
endif

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $@

clean:
	$(RM) $(TARGET)
