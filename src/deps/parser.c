#include "../libs/global.h"

Token lookahead;
Token *tokens;

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
    else{
        if(element == SEMICOLON){
            error("erro de sintaxe", lookahead.line - 1);
        }
        error("erro de sintaxe", lookahead.line);
    }
}

void checkTime()
{
    if(lookahead.type == TIME){
        lookahead = getToken();
    }
    else
    {
        error("erro de sintaxe", lookahead.line);
    }
}

void browser()
{
    if(lookahead.type == NAVIGATOR)
    {
        lookahead = getToken();
    }
    else
    {
        error("erro de sintaxe", lookahead.line);
    }
}

void present()
{
    browser();

    if(lookahead.type == LINK_PDF){

        lookahead = getToken();
        recognize(SEMICOLON);
    }
    else if(lookahead.type == LINK_VIDEO){

        lookahead = getToken();
        recognize(SEMICOLON);
    }
    else if(lookahead.type == LINK_VIDEOCONFERENCIA){

        lookahead = getToken();
        checkTime();
        recognize(SEMICOLON);
    }
    else{
        error("erro de sintaxe", lookahead.line);
    }
}
void interact()
{
    browser();

    if(lookahead.type == LINK_WHATSAPP){

        lookahead = getToken();
        recognize(SEMICOLON);
    }
    else if(lookahead.type == LINK_EMAIL){

        lookahead = getToken();
        recognize(SEMICOLON);
    }
    else if(lookahead.type == LINK_VIDEOCONFERENCIA){

        lookahead = getToken();

        checkTime();

        recognize(SEMICOLON);
    }
    else{
        error("erro de sintaxe", lookahead.line);
    }
}
void critique()
{
    browser();

    if(lookahead.type == LINK_WHATSAPP){

        lookahead = getToken();
        recognize(SEMICOLON);
    }
    else if(lookahead.type == LINK_EMAIL){

        lookahead = getToken();
        recognize(SEMICOLON);
    }
    else if(lookahead.type == LINK_VIDEOCONFERENCIA){

        lookahead = getToken();

        checkTime();
        recognize(SEMICOLON);
    }
    else{
        error("erro de sintaxe", lookahead.line);
    }
}

void sequence()
{
    browser();

    if(lookahead.type == LINK_PDF){
        lookahead = getToken();
        recognize(SEMICOLON);
    }
    else if(lookahead.type == LINK_VIDEO){

        lookahead = getToken();
        recognize(SEMICOLON);
    }
    else if(lookahead.type == LINK_WHATSAPP){

        lookahead = getToken();
        recognize(SEMICOLON);
    }
    else if(lookahead.type == LINK_VIDEOCONFERENCIA){

        lookahead = getToken();

        checkTime();

        recognize(SEMICOLON);
    }
    else if(lookahead.type == TIME){

        checkTime();

        recognize(SEMICOLON);
        present();

        interact();

        critique();
    }
    else{
        error("erro de sintaxe", lookahead.line);
    }
}

void repeat()
{
    if(lookahead.type == NUMBER)
    {
        lookahead = getToken();
        sequence();
    }
    else
    {
        error("erro de sintaxe", lookahead.line);
    }
}

void loop(){
    if(lookahead.type == LOOP)
    {
        lookahead = getToken();
        repeat();
    }
    else
    {
        error("erro de sintaxe", lookahead.line);
    }
}

void programa_SOL(){
    if(lookahead.type == INIT)
    {
        lookahead = getToken();
        loop();
    }
    else
    {
        error("erro de sintaxe", lookahead.line);
    }
}

void parser(Token *c)
{
    tokens = c;

    lookahead = getToken();
    programa_SOL();

    execute();
}