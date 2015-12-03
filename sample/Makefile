FLAGS = -g -O2 -static -std=gnu++11 -D_GLIBCXX_DEBUG

all: build/solve

build/%: %.cpp | $(BUILD_DIR)
	g++ -o $@ $(FLAGS) $^

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
