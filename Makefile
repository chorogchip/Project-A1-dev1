all: main

CXX = clang++
override CXXFLAGS += -g -Wno-everything -std=c++2b -lSDL2{,_{image,ttf,gfx,sound,mixer}} -lpthread -Ofast -Wmost

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

main: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o "$@"
main-debug: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -O0 $(SRCS) -o "$@"

clean:
	rm -f main main-debug