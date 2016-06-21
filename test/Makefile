CFLAGS != pkg-config --cflags check
LIBS != pkg-config --libs check
VPATH=../src

TEST_OBJECTS = check_RomanNumeralCalculator.o

test: test_roman
	./test_roman

test_roman: RomanNumeralCalculator.o $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f *.o
	rm -f test_roman
