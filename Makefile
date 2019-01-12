CC = gcc
CFLAGS = -c -Wall -g
LDFLAGS = -lncursesw -Lsrc/third_party/iniparser -liniparser
SOURCES = main.c ui_ncurses.c
OBJECTS = $(SOURCES:.c=.o)

vpath %.c ./src/

EXECUTABLE = ./ui_test

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) 

.c.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean 
clean:
	rm $(OBJECTS)

.PHONY: clean-all
clean-all:
	rm -rf *.o && rm $(EXECUTABLE)
