#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

int createContact(struct contact c1) {
	FILE *archive = fopen("contacts.txt","a");
	
	int result;
	if (archive != NULL) {
		c1.id = getID() + 1;
		int returnRegister = fprintf(archive, "%i %s %s %s\n", c1.id, c1.name, c1.phone, c1.email);

		if (returnRegister == EOF) {
			// retorna falha ao gravar
			result = 0;
		}
		else {
			// retorna sucesso ao gravar
			result = 1;
		}
		fclose(archive);
		
	} else {
		// retorna falha ao acessar o arquivo
		result = 0;
	}
	return result;
}


void listAll() {
	FILE *archive = fopen("contacts.txt","r");
	
	if (archive != NULL) {
		struct contact c1;
	    while(!feof(archive)){
	        fscanf(archive,"%i %s %s %s ", &c1.id, &c1.name, &c1.phone, &c1.email);
	        printf("ID: %i \nNome: %s \nTelefone: %s \nEmail: %s\n\n", c1.id, c1.name, c1.phone, c1.email);
	    }
	}
	else {
		printf("N?o existem contatos para listar!\n\n");
	}
    
    fclose(archive);
}


int deleteContact(int id){
	FILE *archive = fopen("contacts.txt","r");
	
    struct contact c1;
    int result;
    if (archive != NULL) {
    	FILE *auxArchive = fopen("contatos_aux.txt","a");
    	rewind(archive);
        
        while(!feof(archive)){
        	fscanf(archive,"%i %s %s %s ",&c1.id, &c1.name, &c1.phone, &c1.email);
        	if(c1.id == id){
        		result = 1;
         		continue;
			}
			fprintf(auxArchive, "%i %s %s %s \n",c1.id, c1.name, c1.phone, c1.email);
        }
        
    	fclose(auxArchive);
    	fclose(archive);
    	remove("contacts.txt");
    	rename("contatos_aux.txt", "contacts.txt");
	}
	else {
		fclose(archive);
		result = 0;
	}
	
	return result;
}


int editContact(int id){
	FILE *archive = fopen("contacts.txt","r");
	
    struct contact c1;
    int result;
    if (archive != NULL) {
    	FILE *auxArchive = fopen("contatos_aux.txt","a");
    	rewind(archive);
        
        while(!feof(archive)){
        	fscanf(archive,"%i %s %s %s ",&c1.id, &c1.name, &c1.phone, &c1.email);
        	
        	if(c1.id == id){
        		result = 1;
				printf("Qual informação gostaria de editar?\n1. Nome\n2. Telefone\n3. E-mail\n");
				char info;
				scanf("%c", &info);
				fflush(stdin);
				switch (info)
				{
				case '1':
					printf("Insira o nome atualizada!");
					scanf("%s", &c1.name);
					break;

				case '2':
					printf("Insira o telefone atualizado!");
					scanf("%s", &c1.phone);
					break;

				case '3':
					do{
						printf("Insira o e-mail!");
						scanf("%s", &c1.email);

						int is_email = 1;
						
						if(strchr(c1.email, '@') != NULL || strchr(c1.email, '.') != NULL){
							is_email = 0;
						}

						if(is_email==0){
							printf('Digite um e-mail válido!\n\n');
						}
					}while(is_email==0);

					break;
				}
			}
			fprintf(auxArchive, "%i %s %s %s \n",c1.id, c1.name, c1.phone, c1.email);
        }
        
    	fclose(auxArchive);
    	fclose(archive);
    	remove("contacts.txt");
    	rename("contatos_aux.txt", "contacts.txt");
	}
	else {
		fclose(archive);
		result = 0;
	}
	
	return result;
}


int getID() {
	FILE *archive = fopen("contacts.txt","r");
    
    struct contact c1;
    
	if (archive != NULL) {
		
		while(!feof(archive)){
			fscanf(archive,"%i %s %s %s ",&c1.id, &c1.name, &c1.phone, &c1.email);
		}
		
		if(feof(archive)){
			int greatestId = c1.id;
			fclose(archive);
			return greatestId;
		}
	}
	else {
		fclose(archive);
		return 0;
	}
}
