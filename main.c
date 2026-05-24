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

int insereHash(Hash h, char *user, char *pass) {
    if (h == NULL) return 1;

    int pos = valorString(user) % TABLE_SIZE;

    Elem *no = malloc(sizeof(Elem));
    if (no != NULL) {
        strcpy(no->username, user);
        no->hash_senha = valorString(pass);

        no->prox = h->tabela[pos];
        h->tabela[pos] = no;

        printf("\nUsuario '%s' cadastrado com sucesso!\n", user);
        return 0;
    }
    return 1;
}

int buscaHash(Hash h, char *user, char *pass) {
    if (h == NULL) return 1;

    int pos = valorString(user) % TABLE_SIZE;
    Elem *aux = h->tabela[pos];
    long senhaDigitada = valorString(pass);

    while (aux != NULL) {
        if (strcmp(aux->username, user) == 0) {
            if (aux->hash_senha == senhaDigitada) {
                return 0;
            } else {
                return 1;
            }
        }
        aux = aux->prox;
    }
    return 1;
}

