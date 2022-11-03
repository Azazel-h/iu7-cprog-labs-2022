CC := gcc
C_FILES := $(wildcard *.c)
H_FILES := $(wildcard *.h)
OBJ_FILES := $(C_FILES:%.c=%.o)

C_FLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -gv

APP := app.exe
build: $(APP)

$(APP): $(OBJ_FILES)
	$(CC) $^ -o $@

%.o: %.c $(H_FILES)
	$(CC) -c $< -o $@

clean:
	$(RM) *.o *.exe

.PHONY: clean build