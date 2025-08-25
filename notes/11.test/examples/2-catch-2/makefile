.PHONY: all clean config build test

all: clean config build test

test:
	cd build; ctest

build:
	cmake --build build

config:
	cmake -B build -S .

clean:
	-rm -frv build
