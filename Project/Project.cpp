/*
	Name: MAPA - ESTRUTURA DE DADOS 1
	Copyright:KEVIN VILLA
	Author: KEVIN VILLA
	Date: 08/06/21 11:38
	Description: MAPA UNICESUMAR - ESTRUTURA DE DADOS 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>

#define VERMELHO     "\x1b[31m"
#define RESET   "\x1b[37m"
#define tamanho 5
#define data 50
//Registros
struct cadastro{
	char ra[data];
	char matri[data];
	char ext[data];
	char arq[data];
};
struct tfila{
	struct cadastro dados[tamanho];
	int ini;
	int fim;
};
//Variaveis Globais
struct tfila fila;
int op;
//Prototipação
void excluir_fila();
void fila_mostrar();
void fila_sair();
void fila_entrar();
void menu_mostrar();
//Função Principal
int main(){
	setlocale(LC_ALL, "Portuguese");
	int x = 1;
	fila.fim = 0;
	fila.ini = 0;
	while (x != 0) {
		system("color 0F");
		system("cls");
		fflush(stdin);
		fila_mostrar();
		menu_mostrar();
		printf("OPÇÃO -> ");
		scanf("%d", &op);
		fflush(stdin);
		switch(op){
			case 1:
				fila_entrar();	
				op=0;
				break;
			case 2:
				fila_sair();
				op=0;
				break;
			case 3:
				excluir_fila();
				op=0;
				break;
			case(4):
				system("cls");
				system("color C");
				printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\tVOCÊ ESCOLHEU SAIR \n\n\t\t\t  VOLTE SEMPRE!\n\n\n\n\n\n\n\n\n\n\n\n");
				x=0;
				break;
			default:
				printf(VERMELHO "\nOPÇÃO INVÁLIDA\n\n" RESET);
				system("pause");
				system("cls");
				op=0;
			}
		}	
	return(0);
}
//Funções
void excluir_fila(){
	if (fila.ini == fila.fim) {
		printf(VERMELHO "\n\tUÉ PARECE QUE AINDA NÃO TEM NADA PARA REMOVER :(\n\t\tOU JÁ FOI REMOVIDO TUDO  \n\n\t\t\t FILA VÁZIA!\n\n" RESET);
		system("pause");
		system("cls");
	}
	else {
		int x=0;
		int i;
		do{
			fflush(stdin);
			for (i = 0; i < tamanho; i++) {
				strcpy(fila.dados[i].ra, fila.dados[i+1].ra);
				strcpy(fila.dados[i].matri, fila.dados[i+1].matri);
				strcpy(fila.dados[i].arq, fila.dados[i+1].arq);
				strcpy(fila.dados[i].ext, fila.dados[i+1].ext);
				fflush(stdin);
			}
			x++;
		}while(x<=5);
	}	
	fila.fim = 0;
	fila.ini = 0;
}

void fila_mostrar() {
	int i;
	for (i = 0; i < tamanho; i++) {
		printf("\n |RA = %s", fila.dados[i].ra);
		printf("|MATRÍCULA DO PROFESSOR = %s", fila.dados[i].matri);
		printf("|NOME E EXT. DO ARQUIVO = %s.%s", fila.dados[i].arq,fila.dados[i].ext);
	}
	printf("\n");
}

void fila_sair() {
	if (fila.ini == fila.fim) {
		printf(VERMELHO "\n\tPARCERO NÃO TEM NADA PRA TIRAR DA FILA  :(\n\n\t\t\t TA VÁZIA\n\n" RESET);
		system("pause");
		system("cls");
	}
	else {
		int i;
		for (i = 0; i < tamanho; i++) {
		strcpy(fila.dados[i].ra, fila.dados[i+1].ra);
		strcpy(fila.dados[i].matri, fila.dados[i+1].matri);
		strcpy(fila.dados[i].arq, fila.dados[i+1].arq);
		strcpy(fila.dados[i].ext, fila.dados[i+1].ext);
	}
	fila.fim--;
	}
}

void fila_entrar(){
	if (fila.fim == tamanho) {
		printf(VERMELHO "\n\tA FILA ESTÁ CHEIA! IMPOSSÍVEL ADICIONAR MAIS ITENS\n\n" RESET);
		system("pause");
		system("cls");
	}
	else {
		fflush(stdin);
		printf("\nDIGITE O RA DO ALUNO: ");
		scanf("%s", fila.dados[fila.fim].ra);
		printf("\nDIGITE O N° DA MATRÍCULA DO PROFESSOR: ");
		scanf("%s", fila.dados[fila.fim].matri);
		printf("\nDIGITE O NOME DO ARQUIVO DA ATIVIDADE: ");
		scanf("%s", fila.dados[fila.fim].arq);
		printf("\nDIGITE A EXTENSAO DO ARQUIVO: ");
		scanf("%s", fila.dados[fila.fim].ext);
		fila.fim++;
	}
}

void menu_mostrar() {
	printf("\n\nEscolha uma opção:\n");
	printf(" 1 - Inserir Dados\n");
	printf(" 2 - Excluír Dados\n");
	printf(" 3 - Esvaziar Fila\n");
	printf(" 4 - Sair\n\n");
}
