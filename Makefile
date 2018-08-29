CC = gcc

CFLAGS = -std=c99
CFLAGS += -O3 -march=native
CFLAGS += -Wall -Wextra -Wpedantic -Winline

SRC_FILES = $(wildcard *.c)
DEP_FILES = $(wildcard *.c *.h *.inc Makefile)
EXE = a.out

$(EXE): $(DEP_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(EXE)

.PHONY: clean
clean:
	$(RM) $(EXE)
