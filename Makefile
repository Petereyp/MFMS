CC      = gcc
CFLAGS  = -std=c99 -Wall -Wextra -pedantic
TARGET  = mfms
SRCS    = main.c employees.c budget.c suppliers.c assets.c reports.c utils.c
OBJS    = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) $(TARGET).exe

.PHONY: all clean
