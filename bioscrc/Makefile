CFLAGS=-za99 -oahnxs -ei -zp8 -0 -mt
CC=wcl

src = $(wildcard *.c)
obj = $(src:.c=.o)

TARGETS=bioscrc.com

.PHONY: all clean
all: $(TARGETS)
clean:
	rm -f $(TARGETS) $(obj)

bioscrc.com: bioscrc.c
	$(CC) $(CFLAGS) $^ -fe=$@
	wdis bioscrc.o -l=bioscrc.s
