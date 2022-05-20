CC = gcc
CFLAGS = -Wall -Wextra -pedantic -ggdb
OBJ = $(patsubst src/%.c,build/%.o,$(wildcard src/*.c))
PREQ = $(patsubst src/%.c,build/%.d,$(wildcard src/*.c))

include $(PREQ)

trut: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

build/%.o: src/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

build/%.d: src/%.c
	@mkdir -p build
	$(CC) -MM -MT build/%.o $< > $@

test/%: test/src/%.c
	$(CC) -o $@ $^ $(CFLAGS)

build/%.d: src/%.c
	@mkdir -p build
	$(CC) -MM -MT build/%.o $< > $@

clean:
	find test -maxdepth 1 -type f | xargs rm -f
	rm -f trut
