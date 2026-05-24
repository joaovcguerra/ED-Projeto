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

int removeHash(Hash h, char *user) {
    if (h == NULL) return 1;

    int pos = valorString(user) % TABLE_SIZE;
    Elem *aux = h->tabela[pos];
    Elem *ant = NULL;

    while (aux != NULL) {
        if (strcmp(aux->username, user) == 0) {
            if (ant == NULL) {
                h->tabela[pos] = aux->prox;
            } else {
                ant->prox = aux->prox;
            }
            free(aux);
            printf("\nUsuario '%s' removido!\n", user);
            return 0;
        }
        ant = aux;
        aux = aux->prox;
    }
    printf("\nUsuario nao encontrado.\n");
    return 1;
}

void imprimeHash(Hash h) {
    if (h == NULL) return;

    printf("\n--- TABELA HASH ---\n");
    for(int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        Elem *aux = h->tabela[i];

        while(aux != NULL) {
            printf("{%s, hash:%ld} -> ", aux->username, aux->hash_senha);
            aux = aux->prox;
        }
        printf("NULL\n");
    }
    printf("-------------------\n");
}

void liberaHash(Hash h) {
    if (h != NULL) {
        for(int i = 0; i < TABLE_SIZE; i++) {
            Elem *no = h->tabela[i];
            while (no != NULL) {
                Elem *prox = no->prox;
                free(no);
                no = prox;
            }
        }
        free(h->tabela);
        free(h);
    }
}