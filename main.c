#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 11

typedef struct elemento {
    char username[50];
    long hash_senha;
    struct elemento *prox;
} Elem;

typedef struct hash {
    Elem **tabela;
} *Hash;

int valorString(char *str) {
    int i, valor = 7;
    int tam = strlen(str);
    for(i = 0; i < tam; i++) {
        valor = 31 * valor + (int) str[i];
    }
    return valor;
}

Hash criaHash() {
    Hash h = malloc(sizeof(struct hash));
    if (h != NULL) {
        h->tabela = malloc(TABLE_SIZE * sizeof(Elem*));
        for(int i = 0; i < TABLE_SIZE; i++) {
            h->tabela[i] = NULL;
        }
    }
    return h;
}
