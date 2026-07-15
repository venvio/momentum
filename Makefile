### cosmetic
GREEN := \033[32m
RESET := \033[0m
###

TARGET = momentum

SRC_DIR = src
OBJ_DIR = bin

CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = $(wildcard $(SRC_DIR)/*.c)
OUT = $(OBJ_DIR)/$(TARGET)

PREFIX = $(HOME)/.local
BINDIR = $(PREFIX)/bin

all:
	@echo "Building Momentum..."
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)
	@echo "$(GREEN)✓$(RESET) Momentum successfully built at $(OBJ_DIR)/$(TARGET)"

run: all
	./$(OUT)

install: all
	@echo "Installing Momentum..."
	mkdir -p $(BINDIR)
	install -Dm755 $(OUT) $(BINDIR)/$(TARGET)
	@echo "$(GREEN)✓$(RESET) Momentum successfully installed to $(BINDIR)/$(TARGET)"

uninstall:
	@echo "Uninstalling Momentum..."
	rm -rf $(BINDIR)/$(TARGET)
	@echo "$(GREEN)✓$(RESET) Momentum successfully uninstalled."

clean:
	rm -f $(OUT)

.PHONY: all run install uninstall clean
