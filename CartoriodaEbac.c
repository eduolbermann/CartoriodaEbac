#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biliteoca de alocações de texto por região
#include <string.h> //biblieoteca para uso de strings

int registra() //registra usuários
{
	char arquivo[40]; //criação das variaveis 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; 
	//final da criação de variaveis
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //armazena a variavel que o usuário digitar
	
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

int consulta() //consulta usuários existes
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //abre o arquivo e o "r" lê o que tem na var cpf

	if (file == NULL) //validação para quando não existir um cpf no sistema de consultas
	{
		printf("Não Localizado");
	}
	
	while(fgets(conteudo, 200, file) != NULL); // um laço para mostrar as informações do usuário
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deleta() //deleta usuários 
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //remove o cpf do usuário
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL) //a validação mostra a mensagem de deletação do usuário
	{
	printf("Usuário Deletado!\n");
	system("pause");
	}
	
}

int main()
	{	
	int opcao=0; //Definindo a variável
	
	int laco=1;
	for(laco=1; laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");//defindo a linguagem 
	
		printf("\tCartório da Ebac\n\n");//inicio do menu
	
		printf("Escolha a opção desejada do menu:\n\n");
	
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: ");//fim do menu
	
		scanf("%d", &opcao);//armazenando a escolha do usuário
		
		system("cls"); //limpa para o inicio da validação
	
		switch (opcao)//inicio da seleção
	{
		case 1:
		registra(); //chama as funções
		break;
				
		case 2:
		consulta();
		break;
		
		case 3:
		deleta();
		break;
		
		default:
		printf("Essa opção não está disponível!\n");
		system("Pause");
		break;
		
	}//fim da seleção
	}
			
	printf("Esse Software é de livre uso");
	}

