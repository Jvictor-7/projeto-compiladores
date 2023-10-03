#include "../libs/global.h"

#define NUMBER1 2

Token lookahead;
Token *tokens;

char *link_pdf = "https://bu.ufsc.br/ArtigoCientifico.pdf";
char *link_video = "https://www.youtube.com/";
char *link_videoconferencia = "https://meet.google.com/";
char *link_whatsapp = "https://web.whatsapp.com/";
char *link_email = "https://mail.google.com/mail/u/0/#inbox?compose=new";

const char *endChrome = "taskkill /F /IM chrome.exe";

char command[256];

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

Token timeNosso()
{
    if(lookahead.type == TIME){
        Token aux = lookahead;
        lookahead = getToken();
        return aux;
    }
    else
    {
        error("erro de síntaxe");
    }
}

void calcularTime(int limite) {
        time_t startTime = time(NULL); // Obter a hora atual
        int minutos = 0;

        while (minutos < limite) { // Contador de minutos até o limite de tempo
            time_t currentTime = time(NULL);
            int segundosPassados = difftime(currentTime, startTime);

            if (segundosPassados >= 60) {
                startTime = currentTime;
                minutos++;
                printf("Ja se passaram %d Minutos...\n", minutos);

                if (minutos == limite - 5) {
                    const char *message = "Em 5 minutos sua reuniao sera encerrada automaticamente.";
                    const char *title = "Alerta";
                    
                    MessageBox(NULL, message, title, MB_ICONWARNING | MB_OK);
                }
                if (minutos == limite - 1) {
                    const char *message = "Em 1 minuto sua reuniao sera encerrada automaticamente.";
                    const char *title = "Alerta";
                    
                    MessageBox(NULL, message, title, MB_ICONWARNING | MB_OK);
                }
                if (minutos == limite) {
                    const char *message = "Reuniao encerrada!.";
                    const char *title = "Alerta";
                    
                    MessageBox(NULL, message, title, MB_ICONWARNING | MB_OK);

                    snprintf(command, sizeof(command), "%s", endChrome);
                    system(command);
                }
            }
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

        snprintf(command, sizeof(command), "start chrome %s", link_pdf);
        system(command);
    }
    else if(lookahead.type == LINK_VIDEO){
        printf("%s\n", lookahead.lexeme);

        lookahead = getToken();
        recognize(SEMICOLON);

        snprintf(command, sizeof(command), "start chrome %s", link_video);
        system(command);
    }
    else if(lookahead.type == LINK_VIDEOCONFERENCIA){
        printf("%s\n", lookahead.lexeme);

        lookahead = getToken();

        Token tempo = timeNosso();

        if (strcmp(tempo.lexeme, "15_min") == 0) {
            snprintf(command, sizeof(command), "start chrome %s", link_videoconferencia);
            system(command);

            calcularTime(0.3);
        }
        else if (strcmp(tempo.lexeme, "20_min") == 0) {
            snprintf(command, sizeof(command), "start chrome %s", link_videoconferencia);
            system(command);

            calcularTime(20);
        }
        else if (strcmp(tempo.lexeme, "1_dia") == 0) {
            snprintf(command, sizeof(command), "start chrome %s", link_videoconferencia);
            system(command);

            calcularTime(1440);
        }
        else if (strcmp(tempo.lexeme, "2_dias") == 0) {
            snprintf(command, sizeof(command), "start chrome %s", link_videoconferencia);
            system(command);

            calcularTime(2880);
        }
        else if (strcmp(tempo.lexeme, "sem_limite") == 0) {
            snprintf(command, sizeof(command), "start chrome %s", link_videoconferencia);
            system(command);
        }

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

        snprintf(command, sizeof(command), "start chrome %s", link_whatsapp);
        system(command);
    }
    else if(lookahead.type == LINK_EMAIL){
        printf("%s\n", lookahead.lexeme);

        lookahead = getToken();
        recognize(SEMICOLON);

        snprintf(command, sizeof(command), "start chrome %s", link_email);
        system(command);
    }
    else if(lookahead.type == LINK_VIDEOCONFERENCIA){
        printf("%s\n", lookahead.lexeme);

        lookahead = getToken();

        Token tempo = timeNosso();

        if (strcmp(tempo.lexeme, "15_min") == 0) {
            snprintf(command, sizeof(command), "start chrome %s", link_videoconferencia);
            system(command);

            calcularTime(15);
        }
        else if (strcmp(tempo.lexeme, "20_min") == 0) {
            snprintf(command, sizeof(command), "start chrome %s", link_videoconferencia);
            system(command);

            calcularTime(20);
        }
        else if (strcmp(tempo.lexeme, "1_dia") == 0) {
            snprintf(command, sizeof(command), "start chrome %s", link_videoconferencia);
            system(command);

            calcularTime(1440);
        }
        else if (strcmp(tempo.lexeme, "2_dias") == 0) {
            snprintf(command, sizeof(command), "start chrome %s", link_videoconferencia);
            system(command);

            calcularTime(2880);
        }
        else if (strcmp(tempo.lexeme, "sem_limite") == 0) {
            snprintf(command, sizeof(command), "start chrome %s", link_videoconferencia);
            system(command);
        }

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

        snprintf(command, sizeof(command), "start chrome %s", link_whatsapp);
        system(command);
    }
    else if(lookahead.type == LINK_EMAIL){
        printf("%s\n", lookahead.lexeme);

        lookahead = getToken();
        recognize(SEMICOLON);

        snprintf(command, sizeof(command), "start chrome %s", link_email);
        system(command);
    }
    else if(lookahead.type == LINK_VIDEOCONFERENCIA){
        printf("%s\n", lookahead.lexeme);

        lookahead = getToken();

        Token tempo = timeNosso();

        if (strcmp(tempo.lexeme, "15_min") == 0) {
            snprintf(command, sizeof(command), "start chrome %s", link_videoconferencia);
            system(command);

            calcularTime(15);
        }
        else if (strcmp(tempo.lexeme, "20_min") == 0) {
            snprintf(command, sizeof(command), "start chrome %s", link_videoconferencia);
            system(command);

            calcularTime(20);
        }
        else if (strcmp(tempo.lexeme, "1_dia") == 0) {
            snprintf(command, sizeof(command), "start chrome %s", link_videoconferencia);
            system(command);

            calcularTime(1440);
        }
        else if (strcmp(tempo.lexeme, "2_dias") == 0) {
            snprintf(command, sizeof(command), "start chrome %s", link_videoconferencia);
            system(command);

            calcularTime(2880);
        }
        else if (strcmp(tempo.lexeme, "sem_limite") == 0) {
            snprintf(command, sizeof(command), "start chrome %s", link_videoconferencia);
            system(command);
        }

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

        snprintf(command, sizeof(command), "start chrome %s", link_pdf);
        system(command);
    }
    else if(lookahead.type == LINK_VIDEO){
        printf("%s\n", lookahead.lexeme);

        lookahead = getToken();
        recognize(SEMICOLON);

        snprintf(command, sizeof(command), "start chrome %s", link_video);
        system(command);
    }
    else if(lookahead.type == LINK_WHATSAPP){
    printf("%s\n", lookahead.lexeme);

        lookahead = getToken();
        recognize(SEMICOLON);

        snprintf(command, sizeof(command), "start chrome %s", link_whatsapp);
        system(command);
    }
    else if(lookahead.type == LINK_VIDEOCONFERENCIA){
        printf("%s\n", lookahead.lexeme);

        lookahead = getToken();

        Token tempo = timeNosso();

        if (strcmp(tempo.lexeme, "15_min") == 0) {
            snprintf(command, sizeof(command), "start chrome %s", link_videoconferencia);
            system(command);

            calcularTime(15);
        }
        else if (strcmp(tempo.lexeme, "20_min") == 0) {
            snprintf(command, sizeof(command), "start chrome %s", link_videoconferencia);
            system(command);

            calcularTime(20);
        }
        else if (strcmp(tempo.lexeme, "1_dia") == 0) {
            snprintf(command, sizeof(command), "start chrome %s", link_videoconferencia);
            system(command);

            calcularTime(1440);
        }
        else if (strcmp(tempo.lexeme, "2_dias") == 0) {
            snprintf(command, sizeof(command), "start chrome %s", link_videoconferencia);
            system(command);

            calcularTime(2880);
        }
        else if (strcmp(tempo.lexeme, "sem_limite") == 0) {
            snprintf(command, sizeof(command), "start chrome %s", link_videoconferencia);
            system(command);
        }

        recognize(SEMICOLON);
    }
    else if(lookahead.type == TIME){
        printf("%s\n", lookahead.lexeme);

        Token tempo = timeNosso();

        if (strcmp(tempo.lexeme, "15_min") == 0) {
            snprintf(command, sizeof(command), "start chrome");
            system(command);

            calcularTime(15);
        }
        else if (strcmp(tempo.lexeme, "20_min") == 0) {
            snprintf(command, sizeof(command), "start chrome");
            system(command);

            calcularTime(20);
        }
        else if (strcmp(tempo.lexeme, "1_dia") == 0) {
            snprintf(command, sizeof(command), "start chrome");
            system(command);

            calcularTime(1440);
        }
        else if (strcmp(tempo.lexeme, "2_dias") == 0) {
            snprintf(command, sizeof(command), "start chrome");
            system(command);

            calcularTime(2880);
        }
        else if (strcmp(tempo.lexeme, "sem_limite") == 0) {
            snprintf(command, sizeof(command), "start chrome");
            system(command);
        }

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