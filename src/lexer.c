#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 100


enum TokenType {
    INIT,
    TIME,
    NUMBER,
    SEMICOLON,
    END_OF_PROGRAM,
    NAVIGATOR,
    INVALID
};


struct Token {
    enum TokenType type;
    char lexeme[MAX_TOKEN_LENGTH];
};



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



struct Token getNextToken(FILE* inputFile) {
    struct Token token;
    int c;
    int index = 0;

    
    do {
        c = fgetc(inputFile);
    } while (c == ' ' || c == '\t');


    if (c == EOF) {
        token.type = END_OF_PROGRAM;
        strcpy(token.lexeme, "");
        return token;
    }

   
    if (c == ';') {
        token.type = SEMICOLON;
        strcpy(token.lexeme, ";");
        return token;
    }


    while (c != ' ' && c != '\t' && c != ';' && c != EOF && index < MAX_TOKEN_LENGTH - 1) {
        token.lexeme[index++] = c;
        c = fgetc(inputFile);
    }
    token.lexeme[index] = '\0';

  
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
       
        int isNumber = 1;
        for (int i = 0; i < strlen(token.lexeme); i++) {
            if (!isdigit(token.lexeme[i])) {
                isNumber = 0;
                break;
            }
        }
        token.type = isNumber ? NUMBER : INVALID;
    }

   
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
