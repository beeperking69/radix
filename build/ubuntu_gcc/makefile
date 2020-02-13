TARGET = ubuntu_gcc
PRJ_DIR = ../..
TST_DIR = $(PRJ_DIR)/test_assert
OUT_DIR = $(PRJ_DIR)/build/$(TARGET)

CC = gcc
CC_FLAGS = -std=c99 -coverage -O0 -Wall

TESTS = base64

.PHONY: test

test: $(TESTS)

$(TESTS):
	@$(CC) $(CC_FLAGS) $(PRJ_DIR)/$@.c $(PRJ_DIR)/$@_test.c $(TST_DIR)/test_assert.c $(TST_DIR)/main.c -o $(OUT_DIR)/$@_test.out
	@$(OUT_DIR)/$@_test.out
	@gcov $@.c
	@rm -f $(OUT_DIR)/*_test.* $(OUT_DIR)/test_assert.* $(OUT_DIR)/main.*

clean:
	@rm -f *.gcda *.gcno *.gcov *.out