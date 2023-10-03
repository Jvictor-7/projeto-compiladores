#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>

#define MAX_TOKEN_LENGTH 999
#define SYMMAX 100

#define TRUE 1
#define FALSE 0

enum TokenType {
    INIT,
    TIME,
    NUMBER,
    SEMICOLON,
    END_OF_PROGRAM,
    NAVIGATOR,
    NEWLINE,
    INVALID,
    LOOP,
    LINK_VIDEO,
    LINK_VIDEOCONFERENCIA,
    LINK_PDF,
    LINK_WHATSAPP,
    LINK_EMAIL,
};

typedef struct Token {
    enum TokenType type;
    char lexeme[MAX_TOKEN_LENGTH];
} Token;


Token getNextToken(FILE* inputFile);


#endif