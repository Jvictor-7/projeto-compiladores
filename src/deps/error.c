#include "../libs/global.h"

void error(char *message, int line)
{
    fprintf(stderr, "%s (LINHA : %d)\n", message, line);
    exit(TRUE);
}