
CFLAGS =  `pkg-config --cflags check`
LIBS = `pkg-config --libs check`
VPATH=../src

OBJECTS = RomanNumeralCalculator.o ArabicToRomanConverter.o RomanToArabicConverter.o
        

TEST_OBJECTS = check_RomanNumeralCalculator.o check_ArabicToRomanConverter.o \
                check_RomanToArabicConverter.o

test: test_roman
	./test_roman

test_roman: $(OBJECTS) $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f *.o
	rm -f test_roman
