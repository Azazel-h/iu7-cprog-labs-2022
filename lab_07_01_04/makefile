EXECUTABLE := app.exe

INC_DIRS := ./inc
OUT_DIRS := ./out
SRC_DIRS := ./src
UNIT_DIRS := ./unit_tests
BUILD_DIRS := .

SOURCES := $(shell find $(SRC_DIRS) $(UNIT_DIRS) -name '*.c' -exec basename {} \;)

OBJECTS := $(SOURCES:%.c=$(OUT_DIRS)/%.o)
DEPS := $(OBJECTS:.o=.d)

CC := gcc
CFLAGS :=-I $(INC_DIRS) -std=c99 -c
LDFLAGS :=

unit: LDFLAGS += -lcheck -lpthread -lrt
unit: $(EXECUTABLE)

debug: CFLAGS += -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -g
debug: $(EXECUTABLE)

release: CFLAGS += -DNDEBUG -g0
release: $(EXECUTABLE)

gcov: CFLAGS += -fprofile-arcs -ftest-coverage
gcov: LDFLAGS += -fprofile-arcs -ftest-coverage
gcov: tests
gcov: $(EXECUTABLE)
	gcov $(OUT_DIRS)/*.gcno

$(BUILD_DIRS)/$(EXECUTABLE): ${OBJECTS}
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

$(OUT_DIRS)/%.o : $(SRC_DIRS)/%.c
	$(CC) $(CFLAGS) $< -o $@

$(OUT_DIRS)/%.o : $(UNIT_DIRS)/%.c
	$(CC) $(CFLAGS) $< -o $@

$(OUT_DIRS)/%.d : $(SRC_DIRS)/%.c
	$(CC) -I $(INC_DIRS) -M $< > $@

-include $(DEPS)

func: $(EXECUTABLE)
	cd func_tests/scripts; ./func_tests.sh

.PHONY : debug release clean gcov func unit
clean:
	$(RM) -r out/*

