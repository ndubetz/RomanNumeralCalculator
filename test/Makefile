
CFLAGS =  `pkg-config --cflags check`
LIBS = `pkg-config --libs check`
VPATH=../src

OBJECTS = RomanNumeralCalculator.o Converter.o
        

TEST_OBJECTS = check_RomanNumeralCalculator.o check_Converter.o

test: test_roman
	./test_roman

test_roman: $(OBJECTS) $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f *.o
	rm -f test_roman
