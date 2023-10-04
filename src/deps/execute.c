#include "../libs/global.h"

Token lookahead2;
Token *tokens2;

char *link_pdf = "https://bu.ufsc.br/ArtigoCientifico.pdf";
char *link_video = "https://www.youtube.com/";
char *link_videoconferencia = "https://meet.google.com/";
char *link_whatsapp = "https://web.whatsapp.com/";
char *link_email = "https://mail.google.com/mail/u/0/#inbox?compose=new";

const char *endChrome = "taskkill /F /IM chrome.exe";

char command[256];

int indexToken2 = -1;

Token getToken2()
{
    indexToken2++;
    return tokens2[indexToken2];
}

void recognize2(int element)
{
    if(lookahead2.type == element)
    {

        lookahead2 = getToken2();
    }
}

Token timeNosso()
{
    if(lookahead2.type == TIME){
        Token aux = lookahead2;
        lookahead2 = getToken2();
        return aux;
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

void verificaTempo(Token tempo) {
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
}



void browser2()
{
    if(lookahead2.type == NAVIGATOR)
    {
        lookahead2 = getToken2();
    }
}

void present2()
{
    browser2();

    if(lookahead2.type == LINK_PDF){

        lookahead2 = getToken2();
        recognize2(SEMICOLON);

        snprintf(command, sizeof(command), "start chrome %s", link_pdf);
        system(command);
    }
    else if(lookahead2.type == LINK_VIDEO){

        lookahead2 = getToken2();
        recognize2(SEMICOLON);

        snprintf(command, sizeof(command), "start chrome %s", link_video);
        system(command);
    }
    else if(lookahead2.type == LINK_VIDEOCONFERENCIA){
        lookahead2 = getToken2();

        Token tempo = timeNosso();

        verificaTempo(tempo);

        recognize2(SEMICOLON);
    }
}
void interact2()
{
    browser2();

    if(lookahead2.type == LINK_WHATSAPP){

        lookahead2 = getToken2();
        recognize2(SEMICOLON);

        snprintf(command, sizeof(command), "start chrome %s", link_whatsapp);
        system(command);
    }
    else if(lookahead2.type == LINK_EMAIL){

        lookahead2 = getToken2();
        recognize2(SEMICOLON);

        snprintf(command, sizeof(command), "start chrome %s", link_email);
        system(command);
    }
    else if(lookahead2.type == LINK_VIDEOCONFERENCIA){
        lookahead2 = getToken2();

        Token tempo = timeNosso();

        verificaTempo(tempo);

        recognize2(SEMICOLON);
    }
}
void critique2()
{
    browser2();

    if(lookahead2.type == LINK_WHATSAPP){

        lookahead2 = getToken2();
        recognize2(SEMICOLON);

        snprintf(command, sizeof(command), "start chrome %s", link_whatsapp);
        system(command);
    }
    else if(lookahead2.type == LINK_EMAIL){

        lookahead2 = getToken2();
        recognize2(SEMICOLON);

        snprintf(command, sizeof(command), "start chrome %s", link_email);
        system(command);
    }
    else if(lookahead2.type == LINK_VIDEOCONFERENCIA){
        lookahead2 = getToken2();

        Token tempo = timeNosso();

        verificaTempo(tempo);

        recognize2(SEMICOLON);
    }
}

void sequence2()
{
    browser2();

    if(lookahead2.type == LINK_PDF){
        lookahead2 = getToken2();
        recognize2(SEMICOLON);

        snprintf(command, sizeof(command), "start chrome %s", link_pdf);
        system(command);
    }
    else if(lookahead2.type == LINK_VIDEO){

        lookahead2 = getToken2();
        recognize2(SEMICOLON);

        snprintf(command, sizeof(command), "start chrome %s", link_video);
        system(command);
    }
    else if(lookahead2.type == LINK_WHATSAPP){

        lookahead2 = getToken2();
        recognize2(SEMICOLON);

        snprintf(command, sizeof(command), "start chrome %s", link_whatsapp);
        system(command);
    }
    else if(lookahead2.type == LINK_VIDEOCONFERENCIA){
        lookahead2 = getToken2();

        Token tempo = timeNosso();

        verificaTempo(tempo);

        recognize2(SEMICOLON);
    }
    else if(lookahead2.type == TIME){
        Token tempo = timeNosso();

        verificaTempo(tempo);

        recognize2(SEMICOLON);
        present2();

        interact2();

        critique2();
    }
}

void repeat2()
{
    if(lookahead2.type == NUMBER)
    {
        lookahead2 = getToken2();
        sequence2();
    }
}

void loop2(){
    if(lookahead2.type == LOOP)
    {
        lookahead2 = getToken2();
        repeat2();
    }
}

void programa_SOL2(){
    if(lookahead2.type == INIT)
    {
        lookahead2 = getToken2();
        loop2();
    }
}

void execute(Token *c)
{
    tokens2 = c;
    lookahead2 = getToken2();
    
    programa_SOL2();

}