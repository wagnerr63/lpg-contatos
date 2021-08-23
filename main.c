#include <stdlib.h>
#include <stdio.h>
#include "contact.h"
#include "repository.h"
#include <string.h>

void cleanScreen();
void cleanBuffer();
void pausa();

int main() {
	char optMenu;
	
	while (1) {
		printf("--- Agenda de contatos ---\n\n");
		printf("1. Listar contatos\n");
		printf("2. Criar contato\n");
		printf("3. Deletar contato\n");
		printf("4. Editar contato\n");
		printf("5. Sair\n\n");
		cleanBuffer();
		scanf("%c", &optMenu);
		cleanScreen();
		
		// Listagem de contatos
		if (optMenu == '1') {
			listAll();

			printf("Pressione Enter para continuar ");
			pausa();
			cleanScreen();
		}
		
		// Cria��o de contato - E-mail sem @ n�o ser�o aceitos
		else if (optMenu == '2') {
			cleanScreen();
			
			printf("Informe os dados do novo contato:\n");
			struct contact c1;

			printf("Nome: ");
			cleanBuffer();
			scanf("%s", &c1.name);

			printf("Telefone: ");
			cleanBuffer();
			scanf("%s", &c1.phone);
			

  			int is_email = 1;

			do{
				printf("Email: ");
				cleanBuffer();
				scanf("%s", &c1.email);
				is_email = 0;
				
				if(strchr(c1.email, '@') != NULL || strchr(c1.email, '.') != NULL){
					is_email = 0;
				}

				if(is_email==0){
					printf('Digite um e-mail válido!\n\n');
				}

			}while(is_email==0);
			
			int success = createContact(c1);
			//Valida��o se a inser��o de contatos foi bem sucedida
			
			cleanScreen();
		}
		
		// Dele��o de contatos
		else if (optMenu == '3') {
			cleanScreen();
			
			listAll();
			
			int id;
        	printf("\nInforme o ID do contato que quer excluir: \n");
        	scanf("%i",&id);
        	
        	cleanScreen();
        	
			int success = deleteContact(id);
			//Valida se a dele��o foi bem sucedida
			
			if (success == 1) {
				printf("Contato deletado com sucesso!\n\n");
			}
			else {
				printf("ID incorreto! Nenhum contato foi excluído.\n\n");
			}
			
			printf("Pressione Enter para continuar ");
			pausa();
			cleanScreen();
		}
		
		// Edi��o de contatos
		else if (optMenu == '4') {
			listAll();
			printf("\nInforme o ID do contato que quer editar: \n");
			int id;
			scanf("%i",&id);
			cleanBuffer();
        	cleanScreen();
        	
			int success = editContact(id);
			
			if (success == 1) {
				printf("Contato editado com sucesso!\n\n");
			}
			else {
				printf("ID incorreto! Nenhum contato foi editado.\n\n");
			}
			
			printf("Pressione Enter para continuar ");
			pausa();
			cleanScreen();
		}
		else if (optMenu == '5') {
			cleanScreen();
			exit(0);
		}
	}
	
	return 0;
}


void cleanScreen() {
	#ifdef __WIN32__
    	system("cls");
	#endif

	#ifdef __linux__
		system("clear");
	#endif
}


void cleanBuffer() {
   #ifdef __WIN32__
    	fflush(stdin);
   #endif

   #ifdef __linux__
    	__fpurge(stdin);
   #endif
}


void pausa() {
	cleanBuffer();
	char pausa = getchar();
}
