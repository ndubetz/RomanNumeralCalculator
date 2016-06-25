
CFLAGS =  `pkg-config --cflags check`
LIBS = `pkg-config --libs check`
VPATH=../src

OBJECTS = RomanNumeralCalculator.o Converter.o RomanNumeralValidator.o
        
TEST_OBJECTS = check_RomanNumeralCalculator.o check_Converter.o \
                check_RomanNumeralValidator.o AllTests.o

test: run_all_tests
	./run_all_tests

run_all_tests: $(OBJECTS) $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

AllTests.o: $(TEST_OBJECTS)

clean:
	rm -f *.o
	rm -f run_all_tests
