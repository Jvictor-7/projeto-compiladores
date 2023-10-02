# Nome do programa de saída
TARGET = teste

# Compilador
CC = gcc

# Flags do compilador
CFLAGS = -Wall -Wextra -Ideps

# Arquivos fonte
SRCS = src/main.c \
       src/deps/lexer.c \
       src/deps/parser.c

# Objetos gerados
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
	rm -f $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
