#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    fgets(fulano.nome,50,stdin);

    printf("Idade:");
    scanf("%d",&fulano.idade);
    fflush(stdin);

    printf("Email:");
    fgets(fulano.email,50,stdin);
    
    printf("Telefone:");
    scanf("%d",&fulano.fone);
    fflush(stdin);
    
    printf("Time:");
    fgets(fulano.time,50,stdin);
    
    printf("Equipe:");
    fgets(fulano.equipe,50,stdin);
    
    printf("Esporte:");
    fgets(fulano.esportes,50,stdin);

    printf("Profissão:");
    fgets(fulano.profissao,50,stdin);
    
    printf("Cidade:");
    fgets(fulano.cidade,50,stdin);

    printf("Musica:");
    fgets(fulano.musica,50,stdin);
    
    printf("Livro:");
    fgets(fulano.livro,50,stdin);
    
    printf("Filme:");
    fgets(fulano.filme,50,stdin); 

    printf("Comida:");
    fgets(fulano.comida,50,stdin);

    printf("Hobbie:");
    fgets(fulano.hobbie,50,stdin);

    printf("Personalidade:");
    fgets(fulano.personalidade,50,stdin);
    
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