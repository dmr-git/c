# Sample makefile

CC=clang 
CFLAGS=-I.

# define the executable file
TARGET = sql_lite

OBJ= $(TARGET).o drutils.o sqlite3.o

DEPS = drutils.h sqlite3.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	$(RM) $(TARGET) *.o
