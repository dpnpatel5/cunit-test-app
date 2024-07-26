# Compiler and flags
CC = gcc
CFLAGS = -Wall -I./tests -I./app -I/usr/local/include
LDFLAGS = -lcunit -L./

# Directories
APP_DIR = ./app
TEST_DIR = ./tests

# Source files
APP_SRCS = $(APP_DIR)/app.c 
TEST_SRCS = $(TEST_DIR)/test_main.c $(TEST_DIR)/test_add.c $(TEST_DIR)/test_book.c

# Output binary
OUTPUT_BIN = application

# Default target
ifdef CUNIT_ENABLE
all: $(OUTPUT_BIN)_test
else
all: $(OUTPUT_BIN)
endif

# Application binary without CUnit
$(OUTPUT_BIN): $(APP_SRCS)
	$(CC) $(CFLAGS) -o $(OUTPUT_BIN) $(APP_SRCS)

# Application binary with CUnit
$(OUTPUT_BIN)_test: $(APP_SRCS) $(TEST_SRCS)
	$(CC) $(CFLAGS) -DCUNIT_ENABLE -o $(OUTPUT_BIN)_test $(APP_SRCS) $(TEST_SRCS) $(LDFLAGS)

# Clean up generated files
clean:
	rm -f $(OUTPUT_BIN)

.PHONY: all clean

