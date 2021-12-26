# -----------------------------------------------------------------
# SOURCE: https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html#creating
# -----------------------------------------------------------------

# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

# -----------------------------------------------------------------
# DECLARATION (Make your modifications here)
# -----------------------------------------------------------------

# define the C compiler to use
#
CC = gcc

# define any compile-time flags
#
CFLAGS = -Wall -g #-fno-stack-protector

# define any directories containing header files other than /usr/include
#
INCLUDES = -I../includes

# define the C source files
#
SRCS = main.c hash_table.c

# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.c=.o)

# define the executable file 
#
MAIN = Hash

# -----------------------------------------------------------------
# GENERIC PART (You can leave it as it is)
# -----------------------------------------------------------------

# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#
.PHONY: clean

all:    $(MAIN)
	@echo  $(MAIN) has been compiled \--\> \./$(MAIN)

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
#
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

