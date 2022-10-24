CC := gcc

C_FILES := $(wildcard *.c)
H_FILES := $(wildcard *.h)
OBJ_FILES := $(C_FILES:%.c=%.o)

C_FLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion

APP := app.exe
release: $(APP)

$(APP): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $^ -o $@


%.o: %.c $(H_FILES)
	$(CC) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r *.o *.exe