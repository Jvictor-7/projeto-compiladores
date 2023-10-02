#include "./libs/global.h"


char* tokenName[] = {
    "INIT",
    "TIME",
    "NUMBER",
    "SEMICOLON",
    "END_OF_PROGRAM",
    "NAVIGATOR",
    "NEWLINE",
    "INVALID",
    "LOOP",
    "LINK_VIDEO",
    "LINK_VIDEOCONFERENCIA",
    "LINK_PDF",
    "LINK_WHATSAPP",
    "LINK_EMAIL"
};

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    Token tokens[SYMMAX];

    int tokenSize = 0;

    strcpy(tokens[tokenSize].lexeme, "programa_SOL");
    tokens[tokenSize].type = INIT;

    tokenSize++;
    while (1) {
        tokens[tokenSize] = getNextToken(inputFile);

        if (tokens[tokenSize].type == END_OF_PROGRAM) {
            printf("End of program.\n");
            break;
        }
        else if(tokens[tokenSize].type == NEWLINE){
            printf("breakline\n");
        }
        else if (tokens[tokenSize].type == INVALID) {
            printf("Invalid token: %s\n", tokens[tokenSize].lexeme);
        } else {
            printf("Token type: %s, Lexeme: %s\n", tokenName[tokens[tokenSize].type], tokens[tokenSize].lexeme);
        }

        tokenSize++;
    }
    
    fclose(inputFile);

    // --- PARSER --- 
    
    parser(tokens);
    
    // --- END PARSER ---

    return 0;
}