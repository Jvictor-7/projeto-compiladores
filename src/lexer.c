#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int line = 1;
// Token types
enum TokenType {
    TOKEN_INT,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_IDENTIFIER,
    TOKEN_LOOP,
    TOKEN_INIT,
    TOKEN_EOF
};

// Token structure
struct Token {
    enum TokenType type;
    int value; // Only used for TOKEN_INT
    char identifier[256]; // Only used for TOKEN_IDENTIFIER
};

// Global variables
char *input;
int current_pos = 0;

// Function to initialize the lexer
void init_lexer(char *text) {
    input = text;
}

// Function to get the next token from the input
struct Token get_next_token() {
    struct Token token;
    char current_char;

    // Skip whitespace
    while (isspace(input[current_pos])) {
         if (input[current_pos] == '\n') {
            line ++;
        } else if (input[current_pos] == '\t') {
            
        }
        current_pos++;
    }

    current_char = input[current_pos];

    if (current_char == '\0') {
        token.type = TOKEN_EOF;
    } else if (isdigit(current_char)) {
        // Parse an integer
        int value = 0;
        while (isdigit(input[current_pos])) {
            value = value * 10 + (input[current_pos] - '0');
            current_pos++;
        }
        token.type = TOKEN_INT;
        token.value = value;
    } else if (current_char == '+') {
        token.type = TOKEN_PLUS;
        current_pos++;
    } else if (current_char == '-') {
        token.type = TOKEN_MINUS;
        current_pos++;
    } else if (isalpha(current_char)) {
        // Parse an identifier or keyword
        int i = 0;
        while (isalnum(current_char)  || current_char == '_') {
            token.identifier[i] = current_char;
            i++;
            current_pos++;
            current_char = input[current_pos];
        }
        token.identifier[i] = '\0';

        // Check if it's a keyword (e.g., "if" or "while")
        if (strcmp(token.identifier, "if") == 0) {
            // It's a keyword
            token.type = TOKEN_IDENTIFIER;
        } else if (strcmp(token.identifier, "loop") == 0) {
            // It's a keyword
            token.type = TOKEN_LOOP;


        } 
        else if (strcmp(token.identifier, "programa_SOL") == 0) {
            // It's a keyword
            token.type = TOKEN_INIT;
        }

        else {
            // It's an identifier
            token.type = TOKEN_IDENTIFIER;
        }
    } else {
        // Invalid character
        printf("Error: Invalid character '%c'\n", current_char);
        exit(1);
    }

    return token;
}

int main() {
    char input_text[] = "12 \n loop programa_SOL";

    init_lexer(input_text);

    struct Token token;
    do {
        token = get_next_token();
        switch (token.type) {
            case TOKEN_INT:
                printf("TOKEN_INT: %d   %d \n", token.value, line);
                break;
            case TOKEN_IDENTIFIER:
                printf("TOKEN_IDENTIFIER: %s   line: %d\n ", token.identifier, line);
                break;
            case TOKEN_LOOP:
                printf("TOKEN_LOOP: %s   line: %d\n ", token.identifier, line);
                break;
             case TOKEN_INIT:
                printf("TOKEN_INIT: %s   line: %d\n ", token.identifier, line);
                break;
            case TOKEN_EOF:
                printf("TOKEN_EOF\n");
                break;
        }
    } while (token.type != TOKEN_EOF);

    return 0;
}
