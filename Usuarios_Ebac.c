#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel pela cria��o de strings

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
    //in�cio cria��o de vari�veis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome [40];
    char cargo [40];
    //final cria��o de vari�veis

    printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
    scanf("%s", cpf); //%s refere-se � strings

    strcpy(arquivo, cpf); //respons�vel por copiar valores das strings

    FILE *file; //cria o arquivo no banco de dados
    file = fopen(arquivo, "w"); //cria o arquivo na pasta e o "w" significa escrever
    fprintf(file, "CPF: ");
    fprintf(file, cpf); //salvo o valor da vari�vel
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
        printf("N�o foi poss�vel abrir o arquivo, n�o localizado \n");
        system("read -n1 -r");
        return 0;
    }

    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas s�o as informa��es do usu�rio: ");
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
       printf("O usu�rio n�o se encontra no sistema! \n");
       system("read -n1 -r");
   }

   if(file != NULL)
   {
       printf("Usu�rio deletado com sucesso \n");
       system("read -n1 -r");
   }


}

int main()
{
    int opcao=0; //definindo vari�veis
    int laco=1;

    for(laco=1;laco=1;)
    {

        system("clear");

        setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

        printf("### Cart�rio da EBAC ### \n\n"); //in�cio do menu
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar os nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do Sistema\n\n");
        printf("Op��o:   ");//final do menu

        scanf("%d", &opcao); //armazenando a escolha do usu�rio

        system("clear"); //usei "clear" ao inv�s de cls como orientado porque pelo CodeBlocks no MacBook estava dando erro


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
            printf("Esta op��o n�o est� dispon�vel! \n\n");
            system("read -n1 -r");
            break;

        }//fim da sele��o

    }
}
