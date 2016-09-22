SOURCES=$(wildcard *.c)
CPPFLAGS=--std=gnu99
OUTPUT=out

all:
	gcc $(CPPFLAGS) $(LDFLAGS) $(SOURCES) -o $(OUTPUT)

debug: adddebug all

adddebug:
	$(eval CPPFLAGS=$(CPPFLAGS) -DDEBUG -g)

.PHONY: all debug adddebug
