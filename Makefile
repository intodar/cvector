CC := gcc

TESTS := tests
SOURCES := sources
HEADERS := headers
BIN := bin

CFLAGS := -std=c99 -Wall -Werror -pedantic -I$(HEADERS)

all: $(BIN)/test.exe

run: $(BIN)/test.exe
	$(BIN)/test.exe

valgr: $(BIN)/test.exe
	valgrind --leak-check=full $(BIN)/test.exe

$(BIN)/test.exe: $(TESTS)/test.c $(SOURCES)/vector.c
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -rf $(BIN)/*