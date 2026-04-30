CC = g++
CFLAGS = -Wall -Wextra
TARGET = Build/program


OBJ = main.o Triangle.o


$(TARGET): $(OBJ)
	@mkdir -p Build
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)


main.o: main.cpp Triangle.h
	$(CC) $(CFLAGS) -c main.cpp

Triangle.o: Triangle.cpp Triangle.h
	$(CC) $(CFLAGS) -c Triangle.cpp



clean:
	rm -f *.o $(TARGET)