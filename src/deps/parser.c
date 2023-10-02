#include "../libs/global.h"

typedef struct tree
{
    Token *token;
    struct tree *children;
    struct tree *brother;
} tree;

tree* alocNode()
{
    return (tree *)malloc(sizeof(tree));
}

tree *newNode(Token *token)
{
    tree *node = alocNode();
    strcpy(node->token->lexeme, token->lexeme);
    node->token->type = token->type;
    node->children = NULL;
    node->brother = NULL;

    return node;
}

void parser(Token *tokens)
{
    printf("%s\n", tokens[1].lexeme);
}