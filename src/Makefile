
OBJECTS = Converter.o RomanNumeralValidator.o RomanNumeralCalculator.o App.o main.o

CFLAGS = -g

.PHONY: all clean

all: roman_calculator

clean:
	rm -f *.o
	rm -f ../roman_calculator

roman_calculator: $(OBJECTS)
	$(CC) $(CFLAGS) -o ../$@ $^ $(LIBS)

App.c: App.h

Converter.c: Converter.h

RomanNumeralValidator.c: RomanNumeralValidator.h

RomanNumeralCalculator.c: RomanNumeralCalculator.h 

