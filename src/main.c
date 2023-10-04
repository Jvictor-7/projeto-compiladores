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

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    printf("filename : %s\n", filename);
    strcat(filename, ".txt");
    FILE* inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    Token tokens[SYMMAX];

    int tokenSize = 0;

    while (1) {
        tokens[tokenSize] = getNextToken(inputFile);
        printf("Line : %d \t", tokens[tokenSize].line);

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