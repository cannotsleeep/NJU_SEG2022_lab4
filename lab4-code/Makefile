CC = g++
CFLAGS = -std=c99

CFILES = $(shell find ./ -name "*.cc")
OBJS = $(CFILES:.c=.o)
LFO = $(LFC:.c=.o)

parser: $(filter-out $(LFO),$(OBJS))
	$(CC) $(filter-out $(LFO),$(OBJS)) -o Judger