
SUBDIRS=src test


.PHONY: all src test clean
all: test

clean:
	$(MAKE) -C src clean
	$(MAKE) -C test clean

src:
	$(MAKE) -C src

test: clean src
	$(MAKE) -C test

