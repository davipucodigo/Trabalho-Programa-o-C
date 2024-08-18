#include <stdio.h>
#include <stdlib.h>

int op;
// Struct De coleta
struct pessoa {
    char    nome[50];
    int     idade;
    char    email[50];
    int     fone;
    char    time[50];
    char    equipe[50];
    char    esportes[50];
    char    profissao[50];
    char    cidade[50];
    char    musica[50];
    char    livro[50];
    char    filme[50];
    char    comida[50];
    char    hobbie[50];
    char    personalidade[50];
};

struct pessoa fulano;

void Cadastrar() {
    printf("\nCadastrar\n");
    printf("\nNome:");
    gets(fulano.nome);
    printf("Idade:");
    fflush(stdin);
    scanf("%d",&fulano.idade);
    printf("Email:");
    fflush(stdin);
    scanf("%[^\n]s",fulano.email);
    printf("Telefone:");
    fflush(stdin);
    scanf("%d",&fulano.fone);
    printf("Time:");
    fflush(stdin);
    scanf("%[^\n]s",fulano.time);
    printf("Equipe:");
    fflush(stdin);
    scanf("%[^\n]s",fulano.equipe);
    printf("Esporte:");
    fflush(stdin);
    scanf("%[^\n]s",fulano.esportes);
    printf("Profissão:");
    fflush(stdin);
    scanf("%[^\n]s",fulano.profissao);
    printf("Cidade:");
    fflush(stdin);
    scanf("%[^\n]s",fulano.cidade);
    printf("Musica:");
    fflush(stdin);
    scanf("%[^\n]s",fulano.musica);
    printf("Livro:");
    fflush(stdin);
    scanf("%[^\n]s",fulano.livro);
    printf("Filme:");
    fflush(stdin);
    scanf("%[^\n]s",fulano.filme);
    printf("Comida:");
    fflush(stdin);
    scanf("%[^\n]s",fulano.comida);
    printf("Hobbie:");
    fflush(stdin);
    scanf("%[^\n]s",fulano.hobbie);
    printf("Personalidade:");
    fflush(stdin);
    scanf("%[^\n]s",fulano.personalidade);
    
}

void Pesquisar() {
    printf("\nPesquisar\n");
}

void Afinidade() {
    printf("\nAfinidade\n");
}

int main () {
    // Menu
    do {
        printf("\nDAVI SANT ANNA VIEIRA --- TRABALHO SAUER --- TURMA 4324\n");
        printf("---------------------------------------------------- \n");
        printf("|  1) Cadastrar                                    | \n");
        printf("|  2) Pesquisar                                    | \n");
        printf("|  3) Gerar Tabela de afinidade                    | \n");
        printf("|  4) Sair                                         | \n");
        printf("---------------------------------------------------- \n");
        printf("Digite o N° da op:");
        fflush(stdin);
        scanf("%d",&op);
        switch (op) {
            case 1:
                Cadastrar();
            break;
            case 2:
                Pesquisar();
            break;
            case 3:
                Afinidade();
            break;
        }
    }while(op != 4);
    return 0;
}