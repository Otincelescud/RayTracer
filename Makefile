# Compiler
CXX = g++
CXXFLAGS = -Wall -std=c++20

# Directories
SRC_DIR = src
BUILD_DIR = build

# Target executable
TARGET = $(BUILD_DIR)/app

OUT = output
OUT_TARGET = image.ppm

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Default rule
all: $(TARGET)

# Link step
$(TARGET): $(OBJS)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile step
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	mkdir -p $(OUT)
	./$(TARGET) > ./$(OUT)/$(OUT_TARGET)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(OUT)