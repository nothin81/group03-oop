# ===============================
# Generic Makefile
# ===============================

# Compiler & flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I./src

# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := build
TARGET := $(BIN_DIR)/booking_app

# Find all .cpp files recursively
SRC_FILES := $(shell find $(SRC_DIR) -name "*.cpp")
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Default target
all: $(TARGET)

# Link all object files into final executable
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJ_FILES) -o $(TARGET)
	@echo "Build complete: $(TARGET)"

# Compile each .cpp into .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: all
	@echo "Running program..."
	@./$(TARGET)

# Clean build files
clean:
	@echo "Cleaning build files..."
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Rebuild everything
rebuild: clean all

# Show help
help:
	@echo "Available commands:"
	@echo "  make            - build the project"
	@echo "  make run        - build and run"
	@echo "  make clean      - remove build files"
	@echo "  make rebuild    - clean and rebuild"
	@echo "  make help       - show this message"
