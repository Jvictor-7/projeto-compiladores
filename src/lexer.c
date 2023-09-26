#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 100

// Token types
enum TokenType {
    INIT,
    TIME,
    NUMBER,
    SEMICOLON,
    END_OF_PROGRAM,
    NAVIGATOR,
    INVALID
};

// Structure to represent a token
struct Token {
    enum TokenType type;
    char lexeme[MAX_TOKEN_LENGTH];
};

// Function to check if a string is a keyword

int isInit(char* str) {
    char* time[] = {
         "programa_SOL", NULL
    };
    for (int i = 0; time[i] != NULL; i++) {
        if (strcmp(str, time[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isNavigator(char* str) {
    char* time[] = {
         "navegador", NULL
    };
    for (int i = 0; time[i] != NULL; i++) {
        if (strcmp(str, time[i]) == 0) {
            return 1;
        }
    }
    return 0;
}


int isTime(char* str) {
    char* time[] = {
         "20_min", "1_hora", "1_dia", "2_dias", "sem_limite", "15_min", NULL
    };
    for (int i = 0; time[i] != NULL; i++) {
        if (strcmp(str, time[i]) == 0) {
            return 1;
        }
    }
    return 0;
}


// Function to tokenize the input
struct Token getNextToken(FILE* inputFile) {
    struct Token token;
    int c;
    int index = 0;

    // Skip leading whitespace and tabulation
    do {
        c = fgetc(inputFile);
    } while (c == ' ' || c == '\t');

    // Handle end of file
    if (c == EOF) {
        token.type = END_OF_PROGRAM;
        strcpy(token.lexeme, "");
        return token;
    }

    // Check for a semicolon
    if (c == ';') {
        token.type = SEMICOLON;
        strcpy(token.lexeme, ";");
        return token;
    }

    // Read the token
    while (c != ' ' && c != '\t' && c != ';' && c != EOF && index < MAX_TOKEN_LENGTH - 1) {
        token.lexeme[index++] = c;
        c = fgetc(inputFile);
    }
    token.lexeme[index] = '\0';

    // Check if it's a keyword or a number
    if (isTime(token.lexeme)) {
        token.type = TIME;
    }
    else if(isInit(token.lexeme)){

        token.type = INIT;
    }

     else if(isNavigator(token.lexeme)){

        token.type = NAVIGATOR;
    }
    
    else {
        // Check if it's a number
        int isNumber = 1;
        for (int i = 0; i < strlen(token.lexeme); i++) {
            if (!isdigit(token.lexeme[i])) {
                isNumber = 0;
                break;
            }
        }
        token.type = isNumber ? NUMBER : INVALID;
    }

    // Unget the last character (not part of the token)
    ungetc(c, inputFile);

    return token;
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    struct Token token;

    while (1) {
        token = getNextToken(inputFile);

        if (token.type == END_OF_PROGRAM) {
            printf("End of program.\n");
            break;
        } else if (token.type == INVALID) {
            printf("Invalid token: %s\n", token.lexeme);
        } else {
            printf("Token type: %d, Lexeme: %s\n", token.type, token.lexeme);
        }
    }

    fclose(inputFile);
    return 0;
}
