CC = g++
CFLAGS = -O2 -Wall
SRC = main.cpp ising.cpp
EXEC = ising

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

clean:
    rm -f $(EXEC)