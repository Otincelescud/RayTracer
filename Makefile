# Compiler
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Directories
SRC_DIR = src
BUILD_DIR = build
OUT = output
OUT_TARGET = image.ppm

# Target executable
TARGET = app

# Find all .cpp files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object files (stored in build/)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Default rule
all: $(TARGET)

# Link step
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile step
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET) > ./$(OUT)/$(OUT_TARGET)

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
	rm -rf $(OUT) $(OUT_TARGET)
