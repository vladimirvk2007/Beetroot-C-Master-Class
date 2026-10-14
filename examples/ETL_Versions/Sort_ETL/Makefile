CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra
ETL_INC ?= ../../../lib/etl/include

TARGET := sort_etl.exe

ifeq ($(OS),Windows_NT)
RM := cmd /C del /Q
else
RM := rm -f
endif

.PHONY: all clean

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -I $(ETL_INC) -o $@

clean:
	-$(RM) $(TARGET)
