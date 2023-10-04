#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respon�vel por cuidar das strings
int registro()
{
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("\tDigite seu CPF: \n");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores da string
	
	FILE *file; //Cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); // cria o arquivo 
	fprintf(file,cpf); //salvo  o valor da vari�vel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("\tDigite o nome a ser cadastrado: \n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("\tDigite o sobrenome a ser cadastrado:\n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("\tDigite o seu cargo:\n");
	scanf("%s", cargo);
	
	file=fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL,"portuguese"); // Linguagem em Portugues 
	char cpf[40]; //limite de caracteres
	char conteudo[200];
	
	printf("\tDigite o CPF a ser consultado:\n");
	scanf("%s",cpf); //armazenar a vari�vel "cpf"utilizando a fun��o string %s
	
	FILE *file;
	file = fopen(cpf,"r");//para abrir o arquivo na fun��o cpf e "R" de read(ler) a informa��o
	
	if(file == NULL)//se o numero n�o exitir traz a informa��o a seguir
{
	printf("\tCPF n�o localizado\n");//se o numero n�o exitir.
}	
	while(fgets(conteudo, 200, file) != NULL)//while(enquanto)tiver informa��o, armazene a informa��o em conte�do se for diferente de NULL
{
	printf("\tEssas s�o as informa��es dos usu�rio:\n");//aparecer antes dos dados
	printf("%s", conteudo);
	printf("\n\n"); 
			
}
	system("pause");
}
	
int deletar()
{
    char cpf[40];	
	
	printf("\tQual usu�rio deseja deletar?\n");
	scanf("%s",cpf);
	
	remove(cpf);//fun��o para deletar o usu�rio
	
	FILE *file;//acessar os arquivos da pasta file
	file = fopen(cpf,"r");//ver o arquivo na fun��o cpf e ler "r"= ler
	
	if(file == NULL)//If = SE, se o arquivo for = a nulo 
{
	printf("\tUsu�rio n�o se encontra no sistema\n");
	system("pause");
}
}



int main()
{
int opcao=0; //Definindo vari�vel
int laco=1;//Definindo sequencia 
for(laco=1;laco=1;)
{
	
         system("cls");

         setlocale(LC_ALL, "portuguese"); //Definindo linguagem

            printf("###Cart�rio da EBAC###\n\n"); // In�cio do menu
            printf("Escolha a op��o desejada do menu:\n\n");
            printf("\t1 - Registrar nomes\n");
            printf("\t2 - Consultar nomes\n");
            printf("\t3 - Excluir nomes\n\n\n");
            printf("\t4 - Sair do sistema\n\n");
            printf("\t  op��es:");//Fim do menu


         scanf("%d", &opcao);//Armazenando a escolha do usu�rio
         system("cls");//Comando para limpar a tela

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
    	printf("\tEsta op��o n�o esta disponivel\n\n");
    	system("pause");
    	break;    	
}
}









         system("pause");
}
