CC=gcc
OUTPUT=bin/client

build:
	$(CC) src/*.c -o $(OUTPUT)

rebuild: clean build

run: clean build
	./$(OUTPUT)

clean:
	rm -f bin/*