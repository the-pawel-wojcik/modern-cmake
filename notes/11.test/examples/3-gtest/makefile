.PHONY: all clean config build test

all: clean config build test

test:
	cd build; ctest

build:
	cmake --build build

config:
	cmake -B build -S .
	mv build/compile_commands.json .

clean:
	-rm -frv build
