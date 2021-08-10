#include <stdio.h>
#include <string.h>

void main(){
    char email[] = "teste@gmail.com";
    // char email[] = "nao_eh_email";
	int x;
	int arroba, ponto, valido, maior, c_P, c_S, i;
	int tam = strlen(email);
	
	for (i = 0; i < tam; i++) {
        if(email[i] > 3){   
		    maior=1;	
	    }
	    
	    if(email[i] == '@'){
	   	    arroba=1;
	   	}
	   	
	   	if(arroba == 1 &&  email[i] >= 3){
	  	    c_P=1;
	    }
	    
	    if(email[i]=='.'){
	   	    ponto=1;
        }
        
        if(ponto=1 && email[i] >=2){
            c_S=1;
        }
	
    	if(maior==1 && arroba == 1 && c_P==1 && c_S ==1){
        	valido=1;
    	}else{
    		valido=0;
    	}
	}  
	
	if(valido==1){
		printf("Válido");
	}else{
		printf("Inválido");
	}
}
	
