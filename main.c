#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 100

// Estrutura para armazenar informações de uma pessoa
typedef struct {
    char nome[MAX_STRING];
    char dataNascimento[MAX_STRING];
    char email[MAX_STRING];
    char telefone[MAX_STRING];
    char time[MAX_STRING];
    char equipe[MAX_STRING];
    char esporte[MAX_STRING];
    char profissao[MAX_STRING];
    char cidade[MAX_STRING];
    char nacionalidade[MAX_STRING];
    char hobby[MAX_STRING];
    char musicaFavorita[MAX_STRING];
    char livroFavorito[MAX_STRING];
    char filmeFavorito[MAX_STRING];
} Pessoa;

// Array para armazenar as pessoas cadastradas
Pessoa pessoas;
int totalPessoas = 0; // Contagem de cadastrados

// Função para cadastrar uma nova pessoa
void cadastrarPessoa() {

    Pessoa p;// cria uma struct temporaria para salvar os dados
    printf("Digite o nome: ");
    fgets(p.nome, MAX_STRING, stdin);
    strtok(p.nome, "\n");  // Remove a nova linha, funciona como um fflush(stdin) na situação.
    
    printf("Digite a data de nascimento (dd/mm/aaaa): ");
    fgets(p.dataNascimento, MAX_STRING, stdin);
    strtok(p.dataNascimento, "\n");
    
    printf("Digite o email: ");
    fgets(p.email, MAX_STRING, stdin);
    strtok(p.email, "\n");
    
    printf("Digite o telefone: ");
    fgets(p.telefone, MAX_STRING, stdin);
    strtok(p.telefone, "\n");
    
    printf("Digite o time: ");
    fgets(p.time, MAX_STRING, stdin);
    strtok(p.time, "\n");
    
    printf("Digite a equipe: ");
    fgets(p.equipe, MAX_STRING, stdin);
    strtok(p.equipe, "\n");
    
    printf("Digite o esporte: ");
    fgets(p.esporte, MAX_STRING, stdin);
    strtok(p.esporte, "\n");
    
    printf("Digite a profissão: ");
    fgets(p.profissao, MAX_STRING, stdin);
    strtok(p.profissao, "\n");
    
    printf("Digite a cidade: ");
    fgets(p.cidade, MAX_STRING, stdin);
    strtok(p.cidade, "\n");
    
    printf("Digite a nacionalidade: ");
    fgets(p.nacionalidade, MAX_STRING, stdin);
    strtok(p.nacionalidade, "\n");
    
    printf("Digite o hobby: ");
    fgets(p.hobby, MAX_STRING, stdin);
    strtok(p.hobby, "\n");
    
    printf("Digite a música favorita: ");
    fgets(p.musicaFavorita, MAX_STRING, stdin);
    strtok(p.musicaFavorita, "\n");
    
    printf("Digite o livro favorito: ");
    fgets(p.livroFavorito, MAX_STRING, stdin);
    strtok(p.livroFavorito, "\n");
    
    printf("Digite o filme favorito: ");
    fgets(p.filmeFavorito, MAX_STRING, stdin);
    strtok(p.filmeFavorito, "\n");
    
    pessoas = p; // Repassa p(struct temporaria) para pessoas (struct principal)
    printf("Pessoa cadastrada com sucesso.\n");
}

// Função para exibir uma pessoa
void exibirPessoa(Pessoa p) {
    printf("Nome: %s\n", p.nome);
    printf("Data de Nascimento: %s\n", p.dataNascimento);
    printf("Email: %s\n", p.email);
    printf("Telefone: %s\n", p.telefone);
    printf("Time: %s\n", p.time);
    printf("Equipe: %s\n", p.equipe);
    printf("Esporte: %s\n", p.esporte);
    printf("Profissão: %s\n", p.profissao);
    printf("Cidade: %s\n", p.cidade);
    printf("Nacionalidade: %s\n", p.nacionalidade);
    printf("Hobby: %s\n", p.hobby);
    printf("Música Favorita: %s\n", p.musicaFavorita);
    printf("Livro Favorito: %s\n", p.livroFavorito);
    printf("Filme Favorito: %s\n", p.filmeFavorito);
}

// Função para salvar os dados em um arquivo
void salvarDados() {
    FILE *file = fopen("dados_pessoas.txt", "ab");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo para escrita.\n");
        return;
    }
    fwrite(&pessoas, sizeof(Pessoa), 1, file); // Escreve a struct lá no arquivo
    fclose(file);
}

// Função para atualizar numero de pessoas
void carregarTotal() {
    FILE *file = fopen("dados_pessoas.txt", "rb");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo para leitura.\n");
        return;
    }
    while (fread(&pessoas, sizeof(Pessoa), 1, file)) {
        totalPessoas++;
    }
    
    fclose(file); 
}

// Função para pesquisar pessoas por um elemento
void pesquisarPessoa() {
    
    FILE *file = fopen("dados_pessoas.txt", "rb");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo para leitura.\n");
        return;
    }
    char pesquisa[MAX_STRING];
    printf("Digite o valor para pesquisa: ");
    fgets(pesquisa, MAX_STRING, stdin);
    strtok(pesquisa, "\n");

    while (fread(&pessoas, sizeof(Pessoa), 1, file)) {

        if (strstr(pessoas.nome, pesquisa) != NULL ||
            strstr(pessoas.email, pesquisa) != NULL ||
            strstr(pessoas.telefone, pesquisa) != NULL ||
            strstr(pessoas.time, pesquisa) != NULL ||
            strstr(pessoas.equipe, pesquisa) != NULL ||
            strstr(pessoas.esporte, pesquisa) != NULL ||
            strstr(pessoas.profissao, pesquisa) != NULL ||
            strstr(pessoas.cidade, pesquisa) != NULL ||
            strstr(pessoas.nacionalidade, pesquisa) != NULL ||
            strstr(pessoas.hobby, pesquisa) != NULL ||
            strstr(pessoas.musicaFavorita, pesquisa) != NULL ||
            strstr(pessoas.livroFavorito, pesquisa) != NULL ||
            strstr(pessoas.filmeFavorito, pesquisa) != NULL) {
            exibirPessoa(pessoas);
            printf("\n");
            // strstr util para procurar substring em strings exelente para pesquisa.
        }
    }
    fclose(file);     
}

// Função para calcular afinidade

void calcularAfinidade() {
    FILE *file = fopen("tabela_afinidade.txt", "wb");
    FILE *file2 = fopen("tabela_afinidade.txt", "wb");

    if (file == NULL) {
        printf("Não foi possível abrir o arquivo para escrita.\n");
        return;
    }
    // cálculo de afinidade
    int afinidade = 0;

    Pessoa compara;

    for (int i = 0; i < totalPessoas; i++) {
        fread(&compara, sizeof(compara), 1, file2);

        for (int j = 0; j < totalPessoas; j++) {
            fread(&pessoas, sizeof(pessoas), 1, file);

            if (strcmp(compara.time           ,   pessoas.time) == 0) afinidade+=1;
            if (strcmp(compara.equipe         ,   pessoas.equipe) == 0) afinidade+=2;
            if (strcmp(compara.esporte        ,   pessoas.esporte) == 0) afinidade+=1;
            if (strcmp(compara.profissao      ,   pessoas.profissao) == 0) afinidade+=4;
            if (strcmp(compara.cidade         ,   pessoas.cidade) == 0) afinidade+=7;
            if (strcmp(compara.nacionalidade  ,   pessoas.nacionalidade) == 0) afinidade+=9;
            if (strcmp(compara.hobby          ,   pessoas.hobby) == 0) afinidade+=5;
            if (strcmp(compara.musicaFavorita ,   pessoas.musicaFavorita) == 0) afinidade+=8;
            if (strcmp(compara.livroFavorito  ,   pessoas.livroFavorito) == 0) afinidade+=8;
            if (strcmp(compara.filmeFavorito  ,   pessoas.filmeFavorito) == 0) afinidade+=3;
            
            fprintf(file, "Afinidade entre %s e %s: %d\n", pessoas.nome, pessoas.nome, afinidade);
        }
    }
    
    fclose(file);
    fclose(file2);
    printf("Tabela de afinidade gerada com sucesso.\n");
}

// Função para exibir o menu
void menu() {
    int opcao;
    
    while (1) {
        printf("Menu:\n");
        printf("1. Cadastrar Pessoa | Total Cad.: %d \n", totalPessoas);
        printf("2. Pesquisar Pessoa\n");
        printf("3. Calcular Afinidade\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();// Sem isso fica um \n pra atrapalhar.

        system("cls");
        system("clear");
        switch (opcao) {
            case 1:
                cadastrarPessoa();
                salvarDados();
                break;
            case 2:
                pesquisarPessoa();
                break;
            case 3:
                calcularAfinidade();
                break;
            case 4:
                printf("Saindo...\n");
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

// Função principal
int main() {
    carregarTotal();
    menu();
    return 0;
}
