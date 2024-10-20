CC = gcc

TARGET = main
OUTPUT = run

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(TARGET).c -o $(OUTPUT) 
clean: 
	$(RM) $(OUTPUT)
