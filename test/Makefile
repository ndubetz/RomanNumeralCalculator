
CFLAGS =  `pkg-config --cflags check`
LIBS = `pkg-config --libs check`
VPATH=../src
        
TEST_OBJECTS = check_RomanNumeralCalculator.o check_ArabicToRomanConverter.o \
               check_RomanToArabicConverter.o check_RomanNumeralValidator.o \
               check_UpperCaseConverter.o check_App.o

OBJECTS = ArabicToRoman.o ArabicToRomanConverter.o RomanToArabicConverter.o RomanNumeralValidator.o RomanNumeralCalculator.o UpperCaseConverter.o App.o

.PHONY: clean test 

test: run_all_tests
	./run_all_tests

run_all_tests: $(OBJECTS) $(TEST_OBJECTS) AllTests.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

AllTests.o: $(TEST_OBJECTS)

clean:
	rm -f *.o
	rm -f run_all_tests

