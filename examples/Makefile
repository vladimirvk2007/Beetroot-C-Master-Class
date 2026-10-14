CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra
ETL_INC ?= ../lib/etl/include

NAMES := etl_vector_example etl_array_example etl_string_example etl_map_example \
         etl_vector_api_example etl_array_api_example etl_string_api_example etl_map_api_example
TARGETS := $(addsuffix .exe,$(NAMES))
SUBDIRS := Clock ETL_Versions/Ring_buffer_ETL ETL_Versions/Sort_ETL Ring_buffer_C Ring_buffer_C++ Sort_C Sort_C++

ifeq ($(OS),Windows_NT)
RM := cmd /C del /Q
else
RM := rm -f
endif

.PHONY: all clean subdirs $(SUBDIRS) clean-subdirs

all: $(TARGETS) subdirs

%.exe: %.cpp
	$(CXX) $(CXXFLAGS) $< -I $(ETL_INC) -o $@

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

clean: clean-subdirs
	-$(RM) $(TARGETS)

clean-subdirs:
	@for d in $(SUBDIRS); do $(MAKE) -C $$d clean; done
