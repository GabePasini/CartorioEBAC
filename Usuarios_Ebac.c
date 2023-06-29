#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pela criação de strings

int registro() //função responsável por cadastrar os usuários no sistema
{
    //início criação de variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome [40];
    char cargo [40];
    //final criação de variáveis

    printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
    scanf("%s", cpf); //%s refere-se à strings

    strcpy(arquivo, cpf); //responsável por copiar valores das strings

    FILE *file; //cria o arquivo no banco de dados
    file = fopen(arquivo, "w"); //cria o arquivo na pasta e o "w" significa escrever
    fprintf(file, "CPF: ");
    fprintf(file, cpf); //salvo o valor da variável
    fclose(file); //fechar o arquivo


    printf("Digite o Nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo,"a"); //abre o arquivo na pasta e o "a" significa adicionar
    fprintf(file, "\nNOME: ");
    fprintf(file, nome);
    fclose(file);

    printf("Digite o Sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo,"a");
    fprintf(file, "\nSOBRENOME: ");
    fprintf(file, sobrenome);
    fclose(file);


    printf("Digite o Cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo,"a");
    fprintf(file, "\nCARGO: ");
    fprintf(file, cargo);
    fclose(file);

    system("read -n1 -r");


}

int consulta()
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if(file == NULL)
    {
        printf("Não foi possível abrir o arquivo, não localizado \n");
        system("read -n1 -r");
        return 0;
    }

    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("read -n1 -r");
}

int deletar()
{
   char cpf[40];

   printf("Digite o CPF a ser deletado: ");
   scanf("%s", cpf);

   remove (cpf);

   FILE *file;
   file = fopen(cpf, "r");

   if(file == NULL)
   {
       printf("O usuário não se encontra no sistema! \n");
       system("read -n1 -r");
   }

   if(file != NULL)
   {
       printf("Usuário deletado com sucesso \n");
       system("read -n1 -r");
   }


}

int main()
{
    int opcao=0; //definindo variáveis
    int laco=1;

    for(laco=1;laco=1;)
    {

        system("clear");

        setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

        printf("### Cartório da EBAC ### \n\n"); //início do menu
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar os nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do Sistema\n\n");
        printf("Opção:   ");//final do menu

        scanf("%d", &opcao); //armazenando a escolha do usuário

        system("clear"); //usei "clear" ao invés de cls como orientado porque pelo CodeBlocks no MacBook estava dando erro


        switch(opcao)
        {
            case 1:
            registro();
            break;

            case 2:
            consulta();
            break;

            case 3:
            deletar();
            break;

            case 4:
            printf("Obrigado por utilizar o sistema\n");
            return 0;
            break;

            default:
            printf("Esta opção não está disponível! \n\n");
            system("read -n1 -r");
            break;

        }//fim da seleção

    }
}
