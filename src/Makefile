
OBJECTS = ArabicToRoman.o RomanToArabicConverter.o ArabicToRomanConverter.o RomanNumeralValidator.o RomanNumeralCalculator.o UpperCaseConverter.o App.o main.o

CFLAGS = -g

.PHONY: all clean

all: roman_calculator

clean:
	rm -f *.o
	rm -f ../roman_calculator

roman_calculator: $(OBJECTS)
	$(CC) $(CFLAGS) -o ../$@ $^ $(LIBS)

