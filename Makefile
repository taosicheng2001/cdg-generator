CXX = g++
OBJFILES = main.o 
TARGET = cdg-generator

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CXX) -o $(TARGET) $(OBJFILES)

main.o: main.cpp graph.h readTopology.h drawCDG.h
	$(CXX) -c main.cpp

clean:
	rm -f $(TARGET) $(OBJFILES)
