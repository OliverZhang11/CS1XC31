CC = gcc
CFLAGS = -Wall
BuILD_DIR = build
SRC_DIR = src
TEST_DATA = test_data
all_targets = max multiply square
lib = library
all: $(all_targets)
$(all_targets): library.o

  mkdir -p $(BUILD_DIR)
  $(CC) $(CFLAGS) -o ./$(BUILD_DIR)/$(@) ./$(SRC_DIR)/$(@).c $(BUILD_DIR/library.o
library.o:
  mkdir -p $(BUILD_DIR)
  $(CC) $(CFLAGS) -c -o ./$(BUILD_DIR)/$(lib).o $(SRC_DIR)/$lib).c
  
clean:
  rm -f -r $(BUILD_DIR)
