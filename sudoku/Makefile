SOURCES=$(wildcard *.c)
CFLAGS=--std=gnu99
OUTPUT=out

all:
	gcc $(CFLAGS) $(LDFLAGS) $(SOURCES) -o $(OUTPUT)

debug: adddebug all

adddebug:
	$(eval CFLAGS=$(CFLAGS) -DDEBUG -g)

.PHONY: all debug adddebug
