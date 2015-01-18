# ---- Terminal Output legend ----
# [C] - Compile and Assemble.
# [L] - Linking objects.
# [G] - Generating/Creating.
# [R] - Removing/Deleting.

CC=@gcc
CFLAGS=-c

all: normal

static: buildcheck main.o string.o interpreter.o
	$(CC) -static -o ./build/drill ./obj/main.o ./obj/string.o ./obj/interpreter.o

normal: buildcheck main.o string.o interpreter.o
	$(CC) -o ./build/main ./obj/main.o ./obj/string.o ./obj/interpreter.o

######################################
# Compile each source to object files.
######################################
# main.c
main.o: objcheck
	@echo "[C] main.c"
	$(CC) $(CFLAGS) ./src/main.c -o ./obj/main.o

# string.h
string.o: objcheck
	@echo "[C] string.c"
	$(CC) $(CFLAGS) ./src/string.c -o ./obj/string.o

# interpreter.h
interpreter.o: objcheck
	@echo "[C] interpreter.c"
	$(CC) $(CFLAGS) ./src/interpreter.c -o ./obj/string.o

###############################
# Checking functions for build.
###############################
# Check for obj directory and make it if it doesn't exist.
objcheck:
	@if !(test -d ./obj); \
	then echo "[G] ./obj"; mkdir ./obj; fi

# Check for build directory and make it if it doesn't exist.
buildcheck:
	@if !(test -d ./build); \
	then echo "[G] ./build"; mkdir ./build; fi


#####################
# Cleaning functions.
#####################
cleanobj:
	@if (test -d ./obj); \
	then echo "[R] ./obj"; rm -r ./obj; fi

cleanbuild:
	@if (test -d ./build); \
	then echo "[R] ./build"; rm -r ./build; fi

clean: cleanobj cleanbuild

############################
# Testing/Running functions.
############################
# Test/Run the program
run:
	./build/main

# Build & Run the program
brun: normal run
