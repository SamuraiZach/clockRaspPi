INCLUDE := -I ~/include
LDFLAGS := -L ~/lib -lsense -lm
# If you are compiling this to run on CISC210,
# uncomment the below line
#LDFLAGS := $(LDFLAGS) -lncurses

all: clock
clock: main.o display.o
        cc -o clock main.o display.o  $(INCLUDE) $(LDFLAGS) -lncurses


run: all
        ./clock.sh | ./clock

clean:
        rm -f *.o clock
main.o: main.c display.h
        cc -c main.c -I ~/include $(LDFLAGS) -lncurses
display.o: display.c display.h
        cc -c display.c -I ~/include $(LDFLAGS) -lncurses
