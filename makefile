# ██████╗ ██████╗ ▀▄╗██╗     ██╗
# ██╔══██╗██╔══██╗▀▄║██║     ██║
# ██║  ██║██████╔╝██║██║     ██║
# ██║  ██║██╔══██╗██║██║     ██║
# ██████╔╝██║  ██║██║███████╗███████╗
# ╚═════╝ ╚═╝  ╚═╝╚═╝╚══════╝╚══════╝
# Drill Chuck (Shell) - Alpha V0.0.1

# Our compiler.
CC=@gcc

# Flags for compile/assemble.
CFLAGS=-c

# Output name
COUT=drill

######################
# Main build commands.
######################

#Default make command.
all: norm

# Static build (All libraries are compiled in).
static: fullstatic # Compiling using full only temp, till I fix linking

# Normal build.
norm: fullnorm # Compiling using full only temp, till I fix linking


#########################################################
# Full build (Compiles and Links everything all at once).
#########################################################
# Static link (All libraries are compiled in).
fullstatic: buildcheck
	@echo "[FCL] Compiling all"
	$(CC) -static ./src/main.c -o ./build/$(COUT)

# Normal link.
fullnorm: buildcheck
	@echo "[FCL] Compiling all"
	$(CC) ./src/main.c -o ./build/$(COUT)


############################
# Link all the source files.
############################
# Static link (All libraries are compiled in).
staticlink: buildcheck main.o string.o interpreter.o
	@echo "[L] - Linking..."
	$(CC) -static -o ./build/$(COUT) \
		./obj/string.o \
		./obj/interpreter.o \
		./obj/main.o

# Normal link.
normlink: buildcheck main.o string.o interpreter.o
	@echo "[L] - Linking..."
	$(CC) -o ./build/$(COUT) \
		./obj/string.o \
		./obj/interpreter.o \
		./obj/main.o


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
	@echo "[E] Running \"$(COUT)\""
	@./build/$(COUT)

# Build & Run the program (compile then link).
brun: norm run

# Build & Run the program (compile/link all files at once.).
fullbrun: fullnorm run

###########
# MAKE HELP
###########
help:
	@echo
	@echo
	@echo "██████╗ ██████╗ ██╗██╗     ██╗     "
	@echo "██╔══██╗██╔══██╗██║██║     ██║     "
	@echo "██║  ██║██████╔╝██║██║     ██║     "
	@echo "██║  ██║██╔══██╗██║██║     ██║     "
	@echo "██████╔╝██║  ██║██║███████╗███████╗"
	@echo "╚═════╝ ╚═╝  ╚═╝╚═╝╚══════╝╚══════╝"
	@echo "Drill Chuck (Shell) - Alpha V0.0.1 "
	@echo
	@echo "###################"
	@echo "#### CORE TEAM ####"
	@echo "###################"
	@echo
	@echo "Timothy Peacock - staticinteger <staticinteger@gmail.com>"
	@echo "Tanner Steele   - tjsteele"
	@echo
	@echo "############ Terminal Output legend #############"
	@echo "# [C]    - Compile and Assemble.                #"
	@echo "# [L]    - Linking objects.                     #"
	@echo "# [FCL]  - Compile/Link all files at once.      #"
	@echo "# [G]    - Generating/Creating.                 #"
	@echo "# [R]    - Removing/Deleting.                   #"
	@echo "# [E]    - Executing a script.                  #"
	@echo "#################################################"
	@echo
	@echo
	@echo "########################"
	@echo "#### Build Commands ####"
	@echo "########################"
	@echo
	@echo "MAKE            - Compiles all source."
	@echo
	@echo "MAKE NORM       - Same as MAKE."
	@echo "MAKE STATIC     - Same as MAKE NORM but compiles statically."
	@echo
	@echo "MAKE FULLNORM   - Compiles/Links all source at once (No object files)."
	@echo "MAKE FULLSTATIC - Same as MAKE FULLNORM but compiles statically."
	@echo
	@echo
	@echo "###############################"
	@echo "#### Housekeeping Commands ####"
	@echo "###############################"
	@echo
	@echo "MAKE CLEAN      - Removes \"obj\" & \"build\" folder and all contents."
	@echo
	@echo "MAKE CLEANOBJ   - Removes the \"obj\" folder and all contents."
	@echo "MAKE CLEANBUILD - Removes the \"build\" folder and all contents."
	@echo
	@echo
	@echo "###################################"
	@echo "#### Testing/Running Functions ####"
	@echo "###################################"
	@echo
	@echo "MAKE RUN - Runs Drill."
	@echo "MAKE BRUN - Builds and runs Drill."
	@echo "MAKE FULLBRUN - Builds using FULLNORM and runs Drill."
	@echo
	@echo
