#include "../libs/global.h"

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(TRUE);
}