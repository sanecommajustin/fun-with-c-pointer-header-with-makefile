#
# Makefile for pointer operations
# Author: Justin Walrath <walrathjaw@gmail.com>
# Since: 2/14/2013
#

#This are script-wide variables used to easily name the necessary ingredients.
#External applications
CC = gcc
DBG = gdb

#IO
BIN = List.exe
OUT_DIR = bin/
OUT_OBJ = obj/
IN_DIR = src/
INC = -I include/
SOURCE = \
$(IN_DIR)pointer.c \
$(IN_DIR)nodeOperations.c
OBJ = $(OUT_OBJ)*.o

#options for external applications
CFLAGS = -std=c99
DFLAGS = -g

#This will compile the source code. To run: "make test"
list: clean build
	@echo "+----------------------------------------------+"
	@echo "| Compiling $(BIN) objects......."
	@echo "+----------------------------------------------+"
	$(CC) $(SOURCE) -c $(INC)
	@mv *.o $(OUT_OBJ)
	@echo "+----------------------------------------------+"
	@echo "| Linking $(BIN) objects......."
	@echo "+----------------------------------------------+"
	$(CC) -o $(OUT_DIR)$(BIN) $(OBJ) $(CFLAGS)

#This will compile the source code in debug mode. To run: "make test-debug"
#This also doubles as a shortened compile as well.
debug:
	@echo "+----------------------------------------------+"	
	@echo "| Compiling $(BIN)......."
	@echo "+----------------------------------------------+"
	$(CC) $(DFLAGS) -o $(BIN).debug $(SOURCE) $(INC) $(CFLAGS)
	@echo "+----------------------------------------------+"	
	@echo "|   Starting debugger - type quit to exit      |"
	@echo "+----------------------------------------------+"
	$(DBG) $(BIN).debug
	@echo "+----------------------------------------------+"	
	@echo "|          Cleaning debug instance             |"
	@echo "+----------------------------------------------+"
	@rm $(BIN).debug


#This will clean out all the executables and objects. To run: "make clean"
clean:
	@echo "+----------------------------------------------+"
	@echo "| Removing $(BIN) executable"
	@echo "+----------------------------------------------+"
	@rm -rf $(OUT_DIR)
	@make clean-objects

#This will clean out just the objects. To run: "make clean-objects"
clean-objects:
	@echo "+----------------------------------------------+"
	@echo "|              Removing objects                |"
	@echo "+----------------------------------------------+"
	@rm -rf ./obj/

#This verifies that the directories needed are made
build:
	@mkdir $(OUT_DIR)
	@mkdir $(OUT_OBJ)

#This will run the executable
run: list
	@$(OUT_DIR)$(BIN)
