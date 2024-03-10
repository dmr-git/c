# Sample makefile

CC=clang 
CFLAGS=-I.

# define the executable file
TARGET = cards

OBJ= $(TARGET).o 

DEPS = drutils.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	$(RM) $(TARGET) *.o
