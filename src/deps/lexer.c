#include "../libs/global.h"
int line = 1;

// int isInit(char* str) {
//     char* time[] = {
//          "programa_SOL", NULL
//     };
//     for (int i = 0; time[i] != NULL; i++) {
//         if (strcmp(str, time[i]) == 0) {
//             return 1;
//         }
//     }
//     return 0;
// }

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



Token getNextToken(FILE* inputFile) {
    Token token;
    int c;
    int index = 0;


    do {
        c = fgetc(inputFile);
        if(c == '\n')
        {
            line++;
        }
    } while (c == ' ' || c == '\t' || c == '\n');


    while (c == '/') {
            int nextChar = fgetc(inputFile);
            if (nextChar == '/') {
                
                while (c != '\n' ) {
                    c = fgetc(inputFile);
                    if(c == EOF) break;
                }
                if(c == '\n')
                {
                    line++;
                }
                c = fgetc(inputFile);

            }
            else {
                ungetc(nextChar, inputFile);
            }
    }
    token.line = line;
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
    
    // if (c == '\n') {
    //     token.type = NEWLINE;
    //     strcpy(token.lexeme, "\n");
    //     return token;
    // }


    while (c != ' ' && c != '\t' && c != ';' && c != '\n' && c != EOF && index < MAX_TOKEN_LENGTH - 1) {
        token.lexeme[index++] = c;
        c = fgetc(inputFile);
    }
    token.lexeme[index] = '\0';


    if(strcmp(token.lexeme,"link_pdf") == 0){
        token.type = LINK_PDF;
    }
    else if(strcmp(token.lexeme,"link_video") == 0){
        token.type = LINK_VIDEO;
    }
    else if(strcmp(token.lexeme,"link_whatsapp") == 0){
        token.type = LINK_WHATSAPP;
    }
    else if(strcmp(token.lexeme,"link_videoconferencia") == 0){
        token.type = LINK_VIDEOCONFERENCIA;
    }
    else if(strcmp(token.lexeme,"link_email") == 0){
        token.type = LINK_EMAIL;
    }
    else if (isTime(token.lexeme)) {
        token.type = TIME;
    }
    else if (!strcmp(token.lexeme, "programa_SOL")) {
        token.type = INIT;
    }
    else if(isNavigator(token.lexeme)){
        token.type = NAVIGATOR;
    }
    else if(!strcmp(token.lexeme, "loop"))
    {
        token.type = LOOP;
    }
    else {
       
        int isNumber = 1;
        for (size_t i = 0; i < strlen(token.lexeme); i++) {
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