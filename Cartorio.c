#include <stdio.h>//biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço em memória
#include <locale.h>//biblioteca de alocação de texto por região
#include <string.h>//biblioteca de uso de string

int registro()//função responsável por cadastrar usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");//definindo idioma
	
	int continuar;//variável para função de continuar registrando
	
	do
	{
		
	//início da criação de variáveis/string
	char arquivo[100];
	char cpf[100];
	char nome[100];
	char sobrenome[100];
	char cargo[100];
	//início da criação de variáveis/string
	
	printf ("Digite o CPF a ser cadastrado: \n");//coletando informação do usuário
	scanf ("%s", cpf);
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string para nomear o arquivo
	
	FILE *file;//cria o arquivo

	file = fopen(arquivo, "w");//cria o arquivo nomeado e o "w" significa escrever
	fprintf(file,cpf);//salva o valor da varíavel definindo o nome do arquivo
	fclose(file);//fecha o arquivo 
	
	file = fopen(arquivo, "a");//abrir o arquivo para atualizar o registro
	fprintf(file,"\n");//inserir uma linha no arquivo de texto
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: \n");//coletando informação do usuário
	scanf ("%s", nome);//%s refere-se ao armazenamento de string
	
	file = fopen(arquivo, "a");//abrir o arquivo para atualizar o registro
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n");//coletando informação do usuário
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n");//coletando informação do usuário
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	printf("\nRegistro concluído com sucesso.Deseja cadastrar outro aluno?\n\n(1-Sim/2-Não): ");
	scanf("%d", &continuar);
	system("cls");//limpa o texto da tela para o próximo registro
}while (continuar == 1);//a fimção registro deve continuar enquanto a opção do usuário for 1

	system("pause");
}

int consulta()//função responsável por buscar e exibir dados de um registro pelo CPF
{
	setlocale(LC_ALL, "Portuguese");//definindo idioma
	
	char cpf[100];
	char conteudo[400];
	
	printf("Digite o CPF a ser consultado: \n");
	scanf ("%s", cpf);
		
	FILE *file;
	file = fopen(cpf,"r");//abrir o arquivo para leitura
	
	system("cls");
	
	if(file==NULL)//verifica se o arquivo existe
	{
		printf("Não foi possível localizar o CPF.\n");
	}
	
	while(fgets(conteudo, 400, file) != NULL)
	{
		printf("%s",conteudo);
	}
	
	system("pause");
}

int deletar()//função para remover o arquivo correspondente ao CPF informado
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[100];
		
	printf("Digite o CPF do que deseja deletar do registro: \n");
	scanf("%s",cpf);
	
	remove(cpf);//função da biblioteca que apaga o arquivo
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system ("pause");
	}
	
	else
	{
		printf ("Usuário deletado!\n");
		system ("pause");
	}
}

int sair()//função de encerramento do programa
{
	printf("Fim do Programa\n\n");
	system("pause");
}

int main ()//início da função principal
	{
	
	int opcao=0;//declara uma variável do tipo inteira chamada opcao e a inicia com o valor 0 
	int x=1;x>=1;
	char senhadigitada[10]="a";//criando variáveis para a senha
	int comparacao;//comparação de igualdade dentro da memória
	
	setlocale(LC_ALL, "Portuguese");
	printf("\tCartório da EBAC\n\n");
	printf("Login de administrador\n\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");//comparação de memória para a entrada admin
	
	if(comparacao == 0)//pois esse é o resultado zero quando a memória da entrada for igual a de admin salvo no sistema
	{
	
	
		for (x=1;x>=1;x++)//laço para manter o menu ativo até que o usuário escolha encerrar
	
		{
	
		system ("cls");
		
		setlocale(LC_ALL, "Portuguese");//definindo idioma
	
		printf("\tCartório da EBAC\n\n");//início do menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1-Registrar Alunos\n");
		printf("\t2-Consultar Alunos\n");
		printf("\t3-Deletar Registro\n");
		printf("\t4-Sair do Programa\n\n");
		printf("Opção: ");//fim do menu e local de definição de opção

		scanf("%d" ,&opcao);//armazenamento da escolha do usuário
	
		system ("cls");//responsável por limpar a tela
	
		switch(opcao)//responsável por chamar as funções criadas anteriormente com base na entrada inserida pelo usuário
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
				sair();
				break;
			
				default://opção caso a escolha do usuário seja diferente das programadas anteriormente
				printf("Essa opção não está disponível\n");
				printf("Retorne ao Menu de opções\n\n");
				system ("pause");
				break;	
			}
	
		if (opcao==4)// responsável por ativar a quebra do laço anterior se a entrada for 4 e para o usuário encerrar o sistema
			{
		
			system("cls");
			printf("Criado por Fabrício Muniz Torres de Oliveira\n");
			printf("Todos os direitos reservados ao criador\n");
			system("pause");
			break;
			}
	
		}//fim do laço
	}
	else
	system("cls");
	printf("Senha incorreta!");
}
