#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biliteoca de aloca��es de texto por regi�o
#include <string.h> //biblieoteca para uso de strings

int registra() //registra usu�rios
{
	char arquivo[40]; //cria��o das variaveis 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; 
	//final da cria��o de variaveis
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //armazena a variavel que o usu�rio digitar
	
	strcpy(arquivo, cpf); //Copia os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //abre o arquivo e o "w" escreve 
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system ("Pause");
	
}

int consulta() //consulta usu�rios existes
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //abre o arquivo e o "r" l� o que tem na var cpf

	if (file == NULL) //valida��o para quando n�o existir um cpf no sistema de consultas
	{
		printf("N�o Localizado");
	}
	
	while(fgets(conteudo, 200, file) != NULL); // um la�o para mostrar as informa��es do usu�rio
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deleta() //deleta usu�rios 
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //remove o cpf do usu�rio
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL) //a valida��o mostra a mensagem de deleta��o do usu�rio
	{
	printf("Usu�rio Deletado!\n");
	system("pause");
	}
	
}

int main()
	{	
	int opcao=0; //Definindo a vari�vel
	
	int laco=1;
	for(laco=1; laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");//defindo a linguagem 
	
		printf("\tCart�rio da Ebac\n\n");//inicio do menu
	
		printf("Escolha a op��o desejada do menu:\n\n");
	
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: ");//fim do menu
	
		scanf("%d", &opcao);//armazenando a escolha do usu�rio
		
		system("cls"); //limpa para o inicio da valida��o
	
		switch (opcao)//inicio da sele��o
	{
		case 1:
		registra(); //chama as fun��es
		break;
				
		case 2:
		consulta();
		break;
		
		case 3:
		deleta();
		break;
		
		default:
		printf("Essa op��o n�o est� dispon�vel!\n");
		system("Pause");
		break;
		
	}//fim da sele��o
	}
			
	printf("Esse Software � de livre uso");
	}

