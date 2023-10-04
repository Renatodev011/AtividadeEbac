#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responável por cuidar das strings
int registro()
{
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("\tDigite seu CPF: \n");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores da string
	
	FILE *file; //Cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); // cria o arquivo 
	fprintf(file,cpf); //salvo  o valor da variável
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
	scanf("%s",cpf); //armazenar a variável "cpf"utilizando a função string %s
	
	FILE *file;
	file = fopen(cpf,"r");//para abrir o arquivo na função cpf e "R" de read(ler) a informação
	
	if(file == NULL)//se o numero não exitir traz a informação a seguir
{
	printf("\tCPF não localizado\n");//se o numero não exitir.
}	
	while(fgets(conteudo, 200, file) != NULL)//while(enquanto)tiver informação, armazene a informação em conteúdo se for diferente de NULL
{
	printf("\tEssas são as informações dos usuário:\n");//aparecer antes dos dados
	printf("%s", conteudo);
	printf("\n\n"); 
			
}
	system("pause");
}
	
int deletar()
{
    char cpf[40];	
	
	printf("\tQual usuário deseja deletar?\n");
	scanf("%s",cpf);
	
	remove(cpf);//função para deletar o usuário
	
	FILE *file;//acessar os arquivos da pasta file
	file = fopen(cpf,"r");//ver o arquivo na função cpf e ler "r"= ler
	
	if(file == NULL)//If = SE, se o arquivo for = a nulo 
{
	printf("\tUsuário não se encontra no sistema\n");
	system("pause");
}
}



int main()
{
int opcao=0; //Definindo variável
int laco=1;//Definindo sequencia 
for(laco=1;laco=1;)
{
	
         system("cls");

         setlocale(LC_ALL, "portuguese"); //Definindo linguagem

            printf("###Cartório da EBAC###\n\n"); // Início do menu
            printf("Escolha a opção desejada do menu:\n\n");
            printf("\t1 - Registrar nomes\n");
            printf("\t2 - Consultar nomes\n");
            printf("\t3 - Excluir nomes\n\n\n");
            printf("\t4 - Sair do sistema\n\n");
            printf("\t  opções:");//Fim do menu


         scanf("%d", &opcao);//Armazenando a escolha do usuário
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
    	printf("\tEsta opção não esta disponivel\n\n");
    	system("pause");
    	break;    	
}
}









         system("pause");
}
