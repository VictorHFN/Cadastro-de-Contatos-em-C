#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 5

typedef struct
{
    int codigo;
    char nome[50];
    char telefone[15];
} Contato;

Contato agenda[MAX_CONTATOS];
int numContatos = 0;
void cadastrar();
void listar();
void ordenar();
void consultar();
int main()
{
    int opcao = 0;
    while (opcao != 5)
    {
        printf("\n-- AGENDA --\n");
        printf("1. Cadastrar\n");
        printf("2. Listar\n");
        printf("3. Ordenar\n");
        printf("4. Consultar\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            cadastrar();
            break;
        case 2:
            listar();
            break;
        case 3:
            ordenar();
            break;
        case 4:
            consultar();
            break;
        case 5:
            printf("Encerrando o programa...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    }
}

void cadastrar()
{
    if (numContatos >= MAX_CONTATOS)
    {
        printf("Agenda cheia! Nao e possivel cadastrar novos contatos.\n");
        return;
    }

    Contato novoContato;
    printf("Digite o codigo do contato: ");
    scanf("%d", &novoContato.codigo);
    printf("Digite o nome do contato: ");
    scanf("%s", novoContato.nome);
    printf("Digite o telefone do contato: ");
    scanf("%s", novoContato.telefone);

    agenda[numContatos] = novoContato;
    numContatos++;

    printf("Contato cadastrado com sucesso!\n");
}

void listar()
{
    if (numContatos == 0)
    {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    printf("Codigo  |  Nome                |  Telefone          \n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < numContatos; i++)
    {
        printf("%-7d | %-20s | %-15s\n", agenda[i].codigo, agenda[i].nome, agenda[i].telefone);
    }
}

void ordenar()
{
    printf("Indisponivel.\n");
}

void consultar()
{
    if (numContatos == 0)
    {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    char nomeConsulta[50];
    printf("Digite o nome do contato que deseja consultar: ");
    scanf("%s", nomeConsulta);

    int encontrado = 0;
    for (int i = 0; i < numContatos; i++)
    {
        if (strcmp(agenda[i].nome, nomeConsulta) == 0)
        {
            printf("Codigo: %d\nNome: %s\nTelefone: %s\n", agenda[i].codigo, agenda[i].nome, agenda[i].telefone);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Nenhum contato encontrado com esse nome.\n");
    }
}
