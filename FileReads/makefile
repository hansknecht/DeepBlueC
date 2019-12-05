### If you wish to use extra libraries (math.h for instance),
### add their flags here (-lm in our case) in the "LIBS" variable.

LIBS = -lm

###
CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror
CFLAGS += -Wmissing-declarations
CFLAGS += -DUNITY_SUPPORT_64

test: test.out
	@./test.out

clean:
	rm -rf *.o *.out *.out.dSYM

test.out : src/*.c src/*.h
	@echo Compiling $@
	@$(CC) $(CFLAGS) src/*.c -o test.out $(LIBS)

