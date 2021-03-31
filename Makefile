### 
## Makefile skeleton
## INFO0030: Projet 3
## 
### 

## Variables

# Tools & flags
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes -g `pkg-config --cflags --libs gtk+-2.0`
LD=gcc
LDFLAGS= `pkg-config --cflags --libs gtk+-2.0`

# Files
EXEC=oxo doc

## Rules

all: $(EXEC)

oxo: main.o model.o vue.o controller.o
	$(LD) -o oxo main.o model.o vue.o controller.o $(LDFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

model.o: model.c
	$(CC) -c model.c -o model.o $(CFLAGS)

vue.o: vue.c
	$(CC) -c vue.c -o vue.o $(CFLAGS)

controller.o: controller.c
	$(CC) -c controller.c -o controller.o $(CFLAGS)

clean:
	rm -f *.o oxo *~

archive:
	tar -zcvf oxo.tar.gz *.h *.c Makefile Doxyfile doxygen-bootstrapped-master

.PHONY: doc
doc:
	@doxygen Doxyfile


