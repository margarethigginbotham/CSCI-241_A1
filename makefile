#
# PROGRAM:    assign1
# PROGRAMMER: Margaret Higginbotham   
# LOGON ID:   Z1793581
# DATE DUE:   September 14, 2017
#

# Complier Variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assign1: assign1.o
	g++ $(CCFLAGS) -o assign1 assign1.o

# Rule to compile source code file to object code
assign1.o: assign1.cpp
	g++ $(CCFLAGS) -c assign1.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign1
