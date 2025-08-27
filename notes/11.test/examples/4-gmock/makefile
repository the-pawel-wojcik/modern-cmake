.PHONY: all clean config build test

all: clean config build test

config:
	cmake -B build -S .
	mv build/compile_commands.json .

build:
	cmake --build build

test:
	cd build; ctest

clean:
	-rm -frv build
