TARGET=test

$(TARGET): main.cpp imath.o
	g++ -o $(TARGET) main.cpp imath.o

imath.o: ../../mathematics/imath.cpp ../../mathematics/imath.h
	g++ -c ../../mathematics/imath.cpp

clean:
	rm *.o $(TARGET) -rf


