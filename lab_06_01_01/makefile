CC := gcc
CFLAGS :=-std=c99 -c
LDFLAGS :=
SOURCES :=$(wildcard *.c)
OBJECTS :=$(SOURCES:.c=.o)
EXECUTABLE :=app.exe

gcov: CFLAGS += -fprofile-arcs -ftest-coverage
gcov: LDFLAGS += -fprofile-arcs -ftest-coverage
gcov: tests
gcov: $(EXECUTABLE)
		gcov *.gcno

debug: CFLAGS += -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla -g
debug: $(EXECUTABLE)

release: CFLAGS += -DNDEBUG -g0
release: $(EXECUTABLE)

$(EXECUTABLE): ${OBJECTS}
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

%.d : %.c
	$(CC) -M $< > $@

include $(SOURCES:.c=.d)

tests: $(EXECUTABLE)
	cd func_tests/scripts; ./func_tests.sh

.PHONY : debug release clean gcov_build
clean:
	$(RM) *.o *.exe *.d *.gcno *.gcda


