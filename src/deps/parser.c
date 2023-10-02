#include "../libs/global.h"

#define NUMBER1 2

Token lookahead;
Token *tokens;

char *link_pdf[] = {"https://bu.ufsc.br/ArtigoCientifico.pdf"};
char *link_video[] = {"https://www.youtube.com/"};
char *link_videoconferencia[] = {"https://meet.google.com/"};
char *link_whatsapp[] = {"https://web.whatsapp.com/"};
char *link_email[] = {"https://mail.google.com/mail/u/0/#inbox"};

int indexToken = -1;

Token getToken()
{
    indexToken++;
    return tokens[indexToken];
}


void recognize(int element)
{
    if(lookahead.type == element)
    {
        lookahead = getToken();
    }
}

void time()
{
    if(lookahead.type == TIME){
        lookahead = getToken();
    }
    else
    {
        error("erro de síntaxe");
    }
}

void browser()
{
    if(lookahead.type == NAVIGATOR)
    {
        printf("%s\n", lookahead.lexeme);
        lookahead = getToken();
    }
    else
    {
        error("erro de síntaxe");
    }
}

void present()
{
    browser();


    if(lookahead.type == LINK_PDF){
        printf("%s\n", lookahead.lexeme);
        
        lookahead = getToken();
        recognize(SEMICOLON);
    }
    else if(lookahead.type == LINK_VIDEO){
        printf("%s\n", lookahead.lexeme);

        lookahead = getToken();
        recognize(SEMICOLON);
    }
    else if(lookahead.type == LINK_VIDEOCONFERENCIA){
        printf("%s\n", lookahead.lexeme);

        lookahead = getToken();
        time();
        recognize(SEMICOLON);
    }
}
void interact()
{
    browser();

    printf("teste: %s\n", lookahead.lexeme);

    if(lookahead.type == LINK_WHATSAPP){
        printf("%s\n", lookahead.lexeme);

        lookahead = getToken();
        recognize(SEMICOLON);
    }
    else if(lookahead.type == LINK_EMAIL){
        printf("%s\n", lookahead.lexeme);

        lookahead = getToken();
        recognize(SEMICOLON);
    }
    else if(lookahead.type == LINK_VIDEOCONFERENCIA){
        printf("%s\n", lookahead.lexeme);

        lookahead = getToken();
        time();
        recognize(SEMICOLON);
    }
}
void critique()
{
    browser();

    if(lookahead.type == LINK_WHATSAPP){
        printf("%s\n", lookahead.lexeme);

        lookahead = getToken();
        recognize(SEMICOLON);
    }
    else if(lookahead.type == LINK_EMAIL){
        printf("%s\n", lookahead.lexeme);

        lookahead = getToken();
        recognize(SEMICOLON);
    }
    else if(lookahead.type == LINK_VIDEOCONFERENCIA){
        printf("%s\n", lookahead.lexeme);

        lookahead = getToken();
        time();
        recognize(SEMICOLON);
    }
}

void sequence()
{
    browser();

    if(lookahead.type == LINK_PDF){
        printf("%s\n", lookahead.lexeme);
        lookahead = getToken();
        recognize(SEMICOLON);
    }
    else if(lookahead.type == LINK_VIDEO){
        printf("%s\n", lookahead.lexeme);

        lookahead = getToken();
        recognize(SEMICOLON);
    }
    else if(lookahead.type == LINK_WHATSAPP){
    printf("%s\n", lookahead.lexeme);

        lookahead = getToken();
        recognize(SEMICOLON);
    }
    else if(lookahead.type == LINK_VIDEOCONFERENCIA){
    printf("%s\n", lookahead.lexeme);

        lookahead = getToken();
        time();
        recognize(SEMICOLON);
    }
    else if(lookahead.type == TIME){
    printf("%s\n", lookahead.lexeme);

        time();
        recognize(SEMICOLON);
        present();

        interact();

        critique();
    }
}

void repeat()
{
    if(lookahead.type == NUMBER)
    {
        printf("%s\n", lookahead.lexeme);
        lookahead = getToken();
        sequence();
    }
    else
    {
        error("erro de síntaxe");
    }
}


void parser(Token *c)
{
    tokens = c;

    lookahead = getToken();

    while (lookahead.type != END_OF_PROGRAM)
    {
        switch (lookahead.type)
        {
        case INIT:
            printf("%s\n", lookahead.lexeme);
            lookahead = getToken();
            break;
        case LOOP:
            printf("%s\n", lookahead.lexeme);
            lookahead = getToken();
            repeat();
            break;
        
        default:
            break;
        }

    }
}