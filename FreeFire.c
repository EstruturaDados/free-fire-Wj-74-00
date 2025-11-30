#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
  Sistema de Inventário - Mochila Inicial do Jogador
- struct Item: armazena nome, tipo e quantidade
- Permite inserir (até 10), remover por nome, listar e buscar (busca sequencial)
- Após cada operação os itens são listados
*/

#define MAX_ITENS 10
#define MAX_NOME 30
#define MAX_TIPO 20


// Definição da struct Item
typedef struct {
char nome[MAX_NOME]; // nome do item (ex: "Pistola", "Bandagem")
char tipo[MAX_TIPO]; // tipo do item (ex: "arma", "municao", "cura")
int quantidade; // quantidade disponível
} Item;


// Vetor que representa a mochila (inventário)
Item mochila[MAX_ITENS];
int totalItens = 0; // quantidade atual de itens cadastrados


// Função utilitária: remove o '\n' deixado por fgets
void remover_newline(char *str) {
size_t len = strlen(str);
if (len > 0 && str[len - 1] == '\n') str[len - 1] = '\0';
}


// Lista todos os itens registrados na mochila
void listarItens() {
printf("\n--- Itens na mochila (%d/%d) ---\n", totalItens, MAX_ITENS);
if (totalItens == 0) {
printf("Mochila vazia.\n");
return;
}
for (int i = 0; i < totalItens; i++) {
printf("%d) Nome: %s | Tipo: %s | Quantidade: %d\n", i + 1,
mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
}
}


// Busca sequencial pelo nome do item; retorna índice ou -1 se não encontrado
int buscarItem(const char *nomeBusca) {
for (int i = 0; i < totalItens; i++) {
if (strcmp(mochila[i].nome, nomeBusca) == 0) {
return i;
}
}
return -1;
}


// Insere um novo item (se houver espaço). Se já existir item com mesmo nome, soma quantidades.
void inserirItem() {
if (totalItens >= MAX_ITENS) {
printf("Mochila cheia. Remova um item antes de inserir outro.\n");
return;
}


Item novo;


printf("Informe o nome do item (max %d chars): ", MAX_NOME - 1);
fgets(novo.nome, MAX_NOME, stdin);
remover_newline(novo.nome);
if (strlen(novo.nome) == 0) {
printf("Nome inválido. Operação cancelada.\n");
return;
}


printf("Informe o tipo do item (ex: arma, municao, cura) (max %d chars): ", MAX_TIPO - 1);
fgets(novo.tipo, MAX_TIPO, stdin);
remover_newline(novo.tipo);
if (strlen(novo.tipo) == 0) {
printf("Tipo inválido. Operação cancelada.\n");
return;
}
}