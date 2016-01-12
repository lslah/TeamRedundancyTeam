FLAGS = -g -O2 -static -std=gnu++11 -D_GLIBCXX_DEBUG
BUILD_DIR = build

all: $(BUILD_DIR)/solve $(BUILD_DIR)/A

build/%: %.cpp | $(BUILD_DIR)
	g++ -o $@ $(FLAGS) $^

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
