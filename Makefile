CC = gcc
CFLAGS =-Wall
CLIBS =-lm
CUR_DIR = $(shell pwd)
FOLDERS = -I$(CUR_DIR)/src -I$(CUR_DIR)/include
OUT = client_first_assignment
SRC = $(CUR_DIR)/src/

all: src/read_configuration.c src/read_input.c src/printer.c src/dynamic_float_array.c src/impedance_calculator.c main.c
	$(CC) $(CFLAGS) $(SRC)read_configuration.c $(SRC)read_input.c $(SRC)printer.c $(SRC)dynamic_float_array.c $(SRC)impedance_calculator.c main.c $(FOLDERS) $(CLIBS) -o $(OUT)

clean:
	rm $(OUT)
