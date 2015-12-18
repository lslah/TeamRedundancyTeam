FLAGS = -g -O2 -static -std=gnu++11 -D_GLIBCXX_DEBUG
BUILD_DIR = build

all: $(BUILD_DIR)/A $(BUILD_DIR)/B $(BUILD_DIR)/C $(BUILD_DIR)/D $(BUILD_DIR)/E

build/%: %.cpp | $(BUILD_DIR)
	g++ -o $@ $(FLAGS) $^

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
