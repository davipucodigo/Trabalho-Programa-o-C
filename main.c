#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PESSOAS 100
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
Pessoa pessoas[MAX_PESSOAS];
int totalPessoas = 0; // Contagem de cadastrados

// Função para cadastrar uma nova pessoa
void cadastrarPessoa() {
    if (totalPessoas >= MAX_PESSOAS) { //Enquanto limite n atingido
        printf("Limite de pessoas atingido.\n");
        return; 
    }
    
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
    
    pessoas[totalPessoas++] = p;// Registra e parte pro próximo
    printf("Pessoa cadastrada com sucesso.\n");
}

// Função para salvar os dados em um arquivo
void salvarDados() {
    FILE *file = fopen("dados_pessoas.txt", "wb");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo para escrita.\n");
        return;
    }
    fwrite(&totalPessoas, sizeof(int), 1, file); 
    fwrite(pessoas, sizeof(Pessoa), totalPessoas, file); // Escreve a struct lá no arquivo
    fclose(file);
}

// Função para carregar os dados de um arquivo
void carregarDados() {
    FILE *file = fopen("dados_pessoas.txt", "rb");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo para leitura.\n");
        return;
    }
    fread(&totalPessoas, sizeof(int), 1, file);
    fread(pessoas, sizeof(Pessoa), totalPessoas, file);
    fclose(file);
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

// Função para pesquisar pessoas por um elemento
void pesquisarPessoa() {
    char pesquisa[MAX_STRING];
    printf("Digite o valor para pesquisa: ");
    fgets(pesquisa, MAX_STRING, stdin);
    strtok(pesquisa, "\n");
    
    for (int i = 0; i < totalPessoas; i++) {
        if (strstr(pessoas[i].nome, pesquisa) != NULL ||
            strstr(pessoas[i].email, pesquisa) != NULL ||
            strstr(pessoas[i].telefone, pesquisa) != NULL ||
            strstr(pessoas[i].time, pesquisa) != NULL ||
            strstr(pessoas[i].equipe, pesquisa) != NULL ||
            strstr(pessoas[i].esporte, pesquisa) != NULL ||
            strstr(pessoas[i].profissao, pesquisa) != NULL ||
            strstr(pessoas[i].cidade, pesquisa) != NULL ||
            strstr(pessoas[i].nacionalidade, pesquisa) != NULL ||
            strstr(pessoas[i].hobby, pesquisa) != NULL ||
            strstr(pessoas[i].musicaFavorita, pesquisa) != NULL ||
            strstr(pessoas[i].livroFavorito, pesquisa) != NULL ||
            strstr(pessoas[i].filmeFavorito, pesquisa) != NULL) {
            exibirPessoa(pessoas[i]);
            printf("\n");
            // strstr util para procurar substring em strings exelente para pesquisa.
        }
    }
}

// Função para calcular afinidade
void calcularAfinidade() {
    FILE *file = fopen("tabela_afinidade.txt", "wb");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo para escrita.\n");
        return;
    }
    
    for (int i = 0; i < totalPessoas; i++) {
        for (int j = i + 1; j < totalPessoas; j++) {
            // cálculo de afinidade
            int afinidade = 0;
            if (strcmp(pessoas[i].time, pessoas[j].time) == 0) afinidade++;
            if (strcmp(pessoas[i].equipe, pessoas[j].equipe) == 0) afinidade++;
            if (strcmp(pessoas[i].esporte, pessoas[j].esporte) == 0) afinidade++;
            if (strcmp(pessoas[i].profissao, pessoas[j].profissao) == 0) afinidade++;
            if (strcmp(pessoas[i].cidade, pessoas[j].cidade) == 0) afinidade++;
            if (strcmp(pessoas[i].nacionalidade, pessoas[j].nacionalidade) == 0) afinidade++;
            if (strcmp(pessoas[i].hobby, pessoas[j].hobby) == 0) afinidade++;
            if (strcmp(pessoas[i].musicaFavorita, pessoas[j].musicaFavorita) == 0) afinidade++;
            if (strcmp(pessoas[i].livroFavorito, pessoas[j].livroFavorito) == 0) afinidade++;
            if (strcmp(pessoas[i].filmeFavorito, pessoas[j].filmeFavorito) == 0) afinidade++;
            
            fprintf(file, "Afinidade entre %s e %s: %d\n", pessoas[i].nome, pessoas[j].nome, afinidade);
        }
    }
    
    fclose(file);
    printf("Tabela de afinidade gerada com sucesso.\n");
}

// Função para exibir o menu
void menu() {
    int opcao;
    
    while (1) {
        printf("Menu:\n");
        printf("1. Cadastrar Pessoa\n");
        printf("2. Pesquisar Pessoa\n");
        printf("3. Calcular Afinidade\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();  // Limpar o caractere de nova linha

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
    carregarDados();
    menu();
    return 0;
}
