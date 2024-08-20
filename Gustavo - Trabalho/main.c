
#include <stdio.h>
#include <string.h>
#include <locale.h>

//#define G 100

typedef struct {
    // Dados cadastrais.
    char nome[100];
    char email[100];
    int telefone;
    int dia;
    int mes;
    int ano;
    // Tabela de afinidades.
    char times[100];
    char equipes[100];
    char esportes[100];
    char profissao[100];
    char cidade[100];
    char comida[100];
    char hobbie[100];
    int altura;
    char estilo[100];
    char materia[100];
    int renda;
    char genero_literario[100];
    char genero_filme[100];
    char historico[100];
} Pessoa;

// Calcula a idade em questão da pessoa.
int idade(int dia, int mes, int ano)
{
    int refDia = 20, refMes = 8, refAno = 2024;
    int idade = refAno - ano;
    if (refMes < mes || (refMes == mes && refDia < dia)) {
        idade--;
    }
    return idade;
}

/*
*
* Manipulando arquivo para salvar os dados.
* 
void salvar(Pessoa p)
{
    FILE *file = fopen("dados_cadastrados.txt", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para salvar os dados.\n");
        return;
    }

    int idadeCalculada = idade(p.dia, p.mes, p.ano);
    fprintf(file, "%s,%s,%d,%d,%d,%s,%s,%s,%s,%s,%s,%d,%s,%s,%d,%s,%s\n",
            p.nome, p.email, p.telefone, p.dia, p.mes, p.ano,
            p.times, p.equipes, p.esportes, p.profissao, p.cidade, p.comida,
            p.hobbie, p.altura, p.estilo, p.materia, p.renda, p.genero_literario,
            p.genero_filme, p.historico);
    fclose(file);
}
*/

/*
*
* Pesquisa os dados no arquivo
*
void pesquisar(Pessoa p)
{
    char criterio[G];
    printf("Digite o crit�rio de busca: ");
    fgets(criterio, G, stdin);
    criterio[strcspn(criterio, "\n")] = '\0';

    int idadePessoa = idade(p.dia, p.mes, p.ano);

    if (strstr(p.nome, criterio) || strstr(p.cidade, criterio) ||
        strstr(p.profissao, criterio) || strstr(p.times, criterio) ||
        strstr(p.equipes, criterio) || strstr(p.esportes, criterio) ||
        strstr(p.comida, criterio) || strstr(p.hobbie, criterio) ||
        strstr(p.estilo, criterio) || strstr(p.materia, criterio) ||
        strstr(p.genero_literario, criterio) || strstr(p.genero_filme, criterio) ||
        strstr(p.historico, criterio)) {
        printf("Usu�rio encontrado:\n");
        printf("Nome: %s\n", p.nome);
        printf("Email: %s\n", p.email);
        printf("Telefone: %d\n", p.telefone);
        printf("Idade: %d\n", idadePessoa);
        printf("Time: %s\n", p.times);
        printf("Equipe da liberato: %s\n", p.equipes);
        printf("Esportes: %s\n", p.esportes);
        printf("Profiss�o: %s\n", p.profissao);
        printf("Cidade: %s\n", p.cidade);
        printf("Comida Favorita: %s\n", p.comida);
        printf("Hobbie: %s\n", p.hobbie);
        printf("Altura em cm: %d\n", p.altura);
        printf("Estilo Musical: %s\n", p.estilo);
        printf("Mat�ria Favorita: %s\n", p.materia);
        printf("Renda: %d\n", p.renda);
        printf("G�nero Liter�rio: %s\n", p.genero_literario);
        printf("G�nero de Filme: %s\n", p.genero_filme);
        printf("Hist�rico Criminal: %s\n", p.historico);
    } else {
        printf("Nenhum usu�rio encontrado com o crit�rio fornecido.\n");
    }
}
*/

/*
*
* Afinidade calculo
*
int afinidade(Pessoa p1, Pessoa p2)
{
    int afinidade = 0;
    if (strcmp(p1.times, p2.times) == 0) afinidade++;
    if (strcmp(p1.equipes, p2.equipes) == 0) afinidade++;
    if (strcmp(p1.esportes, p2.esportes) == 0) afinidade++;
    if (strcmp(p1.profissao, p2.profissao) == 0) afinidade++;
    if (strcmp(p1.cidade, p2.cidade) == 0) afinidade++;
    if (strcmp(p1.comida, p2.comida) == 0) afinidade++;
    if (strcmp(p1.hobbie, p2.hobbie) == 0) afinidade++;
    if (strcmp(p1.estilo, p2.estilo) == 0) afinidade++;
    if (strcmp(p1.materia, p2.materia) == 0) afinidade++;
    if (strcmp(p1.genero_literario, p2.genero_literario) == 0) afinidade++;
    if (strcmp(p1.genero_filme, p2.genero_filme) == 0) afinidade++;
    if (strcmp(p1.historico, p2.historico) == 0) afinidade++;
    return afinidade;
}
*/

/*
*
* Tabela
*
void Tabela()
{
    FILE *file = fopen("dados_cadastrados.txt", "r");
    FILE *tabela = fopen("tabela_afinidades.txt", "w");
    if (file == NULL || tabela == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    // C�digo para gerar a tabela de afinidades
    fclose(file);
    fclose(tabela);
}
*/

int main()
{
    setlocale(LC_ALL, "portuguese");

    Pessoa p;
    int valor_escolha;
    printf("- Digite o numero do que deseja -\n\n1) registrar usuarios\n\n2) pesquisar usuarios\n\n3) Comparar afinidades\n\n4) encerrar\n");
    scanf("%d", &valor_escolha);
    //getchar(); // Limpar o buffer de entrada

    do
    {
        if (valor_escolha == 1) // opção 1
        {
            // Registrar
            printf("\n- Preencha os itens de informação, para concluir o cadastro-\n");
            printf("1)Nome da pessoa: -> ");
            scanf("%[^\n]s",p.nome);
            fflush(stdin);

            //p.nome[strcspn(p.nome, "\n")] = '\0';

            /*
            printf("\n2)Data de nascimento\n");
            printf("Digite o dia:\n->");
            scanf("%d", &p.dia);
            getchar(); // Limpar o buffer de entrada
            printf("Digite o m�s:\n->");
            scanf("%d", &p.mes);
            getchar(); // Limpar o buffer de entrada
            printf("Digite o ano:\n->");
            scanf("%d", &p.ano);
            getchar(); // Limpar o buffer de entrada

            printf("\n3)Email:\n->");
            fgets(p.email, G, stdin);
            p.email[strcspn(p.email, "\n")] = '\0';

            printf("\n4)Telefone:\n->");
            scanf("%d", &p.telefone);
            getchar(); // Limpar o buffer de entrada

            printf("\n                          -Agora, responda o question�rio de afinidade-\n");

            printf("O time que a pessoa torce:\n->");
            fgets(p.times, G, stdin);
            p.times[strcspn(p.times, "\n")] = '\0';
            printf("A equipe da liberato que a pessoa torce:\n->");
            fgets(p.equipes, G, stdin);
            p.equipes[strcspn(p.equipes, "\n")] = '\0';
            printf("Esportes que pratica:\n->");
            fgets(p.esportes, G, stdin);
            p.esportes[strcspn(p.esportes, "\n")] = '\0';
            printf("Profiss�o:\n->");
            fgets(p.profissao, G, stdin);
            p.profissao[strcspn(p.profissao, "\n")] = '\0';
            printf("Cidade que mora:\n->");
            fgets(p.cidade, G, stdin);
            p.cidade[strcspn(p.cidade, "\n")] = '\0';
            printf("Comida favorita:\n->");
            fgets(p.comida, G, stdin);
            p.comida[strcspn(p.comida, "\n")] = '\0';
            printf("Hobbie:\n->");
            fgets(p.hobbie, G, stdin);
            p.hobbie[strcspn(p.hobbie, "\n")] = '\0';
            printf("Altura:\n->");
            scanf("%d", &p.altura);
            getchar(); // Limpar o buffer de entrada
            printf("Estilo musical favorito:\n->");
            fgets(p.estilo, G, stdin);
            p.estilo[strcspn(p.estilo, "\n")] = '\0';
            printf("Mat�ria escolar favorita:\n->");
            fgets(p.materia, G, stdin);
            p.materia[strcspn(p.materia, "\n")] = '\0';
            printf("Renda:\n->");
            scanf("%d", &p.renda);
            getchar(); // Limpar o buffer de entrada
            printf("G�nero liter�rio favorito:\n->");
            fgets(p.genero_literario, G, stdin);
            p.genero_literario[strcspn(p.genero_literario, "\n")] = '\0';
            printf("G�nero de filme favorito:\n->");
            fgets(p.genero_filme, G, stdin);
            p.genero_filme[strcspn(p.genero_filme, "\n")] = '\0';
            printf("Hist�rico criminal:\n->");
            fgets(p.historico, G, stdin);
            p.historico[strcspn(p.historico, "\n")] = '\0';
            */
            //salvar(p);

            printf("\nSe deseja continuar, disque 'x'\n");
            char continua = getchar();
            //r[strcspn(r, "\n")] = '\0';
            if (continua == 'x') {
                valor_escolha = 4;
                break;
            }
        } 
        else if (valor_escolha == 2) // opção 2
        {
            // Pesquisar usuarios
            //pesquisar(p);
        }
        else if (valor_escolha == 3) // opção 3
        {
            //Tabela();
            printf("Tabela de afinidades gerada com sucesso!\n");
        }
        else if (valor_escolha == 4) // opção 4
        {
            printf("Encerrando o programa...\n");
            break;
        }
        else // opção Invalida
        {
            printf("Opção invalida. Tente novamente.\n");
        }
    }while (valor_escolha != 4);

    return 0;
}