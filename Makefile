### 
## Makefile skeleton
## INFO0030: Projet 3
## 
### 

## Variables

# Tools & flags
CC=gcc
LD=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes -g
LDFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes -g
GTKFLAGS=`pkg-config --cflags --libs gtk+-2.0`

# Files
EXEC=oxo

## Rules

all: $(EXEC)

oxo: main.o model.o vue.o controller.o
	$(LD) -o oxo main.o model.o vue.o controller.o $(LDFLAGS) $(GTKFLAGS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS) $(GTKFLAGS)

model.o: model.c
	$(CC) -c model.c -o model.o $(CFLAGS) $(GTKFLAGS)

vue.o: vue.c
	$(CC) -c vue.c -o vue.o $(CFLAGS) $(GTKFLAGS)

controller.o: controller.c
	$(CC) -c controller.c -o controller.o $(CFLAGS) $(GTKFLAGS)

clean:
	rm -f *.o oxo *~

archive:
	tar -zcvf oxo.tar.gz *.h *.c Makefile Doxyfile images doxygen-bootstrapped-master

.PHONY: doc
doc:
	@doxygen Doxyfile


