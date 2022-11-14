EXECUTABLE := app.exe
UNIT_EXECUTABLE := unit_tests.exe

INC_DIR := ./inc
OUT_DIR := ./out
SRC_DIR := ./src
UNIT_DIR := ./unit_tests

CC := gcc
CFLAGS := -I $(INC_DIR) -std=c99
LDFLAGS :=

vpath %.c $(SRC_DIR) $(UNIT_DIR)
vpath %.h $(INC_DIR)

SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(SOURCES:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)

UNIT_SOURCES := $(wildcard $(UNIT_DIR)/*.c)
UNIT_OBJECTS := $(OBJECTS) $(UNIT_SOURCES:$(UNIT_DIR)/%.c=$(OUT_DIR)/%.o)
ALL_DEPS := $(UNIT_OBJECTS:.o=.d)

UNIT_OBJECTS := $(filter-out ./out/main.o, $(UNIT_OBJECTS))


OS := $(shell uname -s)

.PHONY : unit
ifeq ($(OS), Darwin)
unit: CFLAGS += -I /opt/homebrew/opt/check/include
unit: LDFLAGS += -L /opt/homebrew/opt/check/lib -lcheck -lpthread
unit: $(UNIT_EXECUTABLE)
unit:
	./$(UNIT_EXECUTABLE)
else
unit: LDFLAGS += -lcheck -lpthread -lsubunit -lrt -lm
unit: $(UNIT_EXECUTABLE)
unit:
	 ./$(UNIT_EXECUTABLE)
endif

.PHONY : debug
debug: CFLAGS += -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -g
debug: $(EXECUTABLE) $(ALL_DEPS)


.PHONY : release
release: CFLAGS += -DNDEBUG -g0
release: $(EXECUTABLE) $(ALL_DEPS)


.PHONY : gcov
gcov: CFLAGS += -fprofile-arcs -ftest-coverage
gcov: LDFLAGS += --coverage
gcov: func
gcov: $(OUT_DIR) $(ALL_DEPS) $(EXECUTABLE)
	gcov $(OUT_DIR)/*.gcno; mv *.gcov $(OUT_DIR)


$(EXECUTABLE): $(OUT_DIR) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)


$(UNIT_EXECUTABLE): $(OUT_DIR) $(UNIT_OBJECTS)
	$(CC) $(CFLAGS) $(UNIT_OBJECTS) -o $@ $(LDFLAGS)

$(OUT_DIR)/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/%.d : %.c
	$(CC) -I $(INC_DIR) -M $< > $@

$(OUT_DIR):
	@mkdir -p $(OUT_DIR)

.PHONY : func
func: debug
ifeq ($(OS), Darwin)
	@printf "\e[0;33mDARWIN DOES NOT SUPPORT MEMLEAKS TESTS!\n\e[0m"; cd func_tests/scripts; ./func_tests.sh
else
	cd func_tests/scripts; export USE_VALGRIND=1; ./func_tests.sh
endif

.PHONY : clean
clean:
	$(RM) *.exe out/*
