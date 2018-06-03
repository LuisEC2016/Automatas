#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char tokensimbolo(char llavetokensimbolo,int posicion);
char tokenoperador(char llavetokenoperador,int posicion);
char detectarnumero(char numerorec);
void lexico();
void sintaxis();
//lexico 
FILE *archivo;
char simbolodebug[30],operadordebug[30],array[50];
int numerodebug[30];
int matrizA[30],matrizB[30],matrizC[30];
int count;
    int simbolocont=0,simbolocont2=0;
    int operadorcont=0,operadorcont2=0;
    int numcont=0,numcont2=0;
    int original=0;
int main(){
    archivo = fopen("program.txt","r");
    
    if(archivo == NULL){
        printf("Error mientras se abria el archivo\n");
        exit(0);
    }
    lexico();
    //sintaxis();
    fclose(archivo);
	return 0;
}
void lexico(){
	char ch,buffer[40];
	char nuevosimbolo[30],simbolo[]="[,;]";
	char nuevooperador[30],operadores[] = ".+-~^>";
	int nuevonumero[30];	
    

	while((ch = fgetc(archivo)) != EOF){
		array[original]=ch;
    	nuevosimbolo[simbolocont]=tokensimbolo(ch,simbolocont);
    	nuevooperador[operadorcont]=tokenoperador(ch,operadorcont);
    	nuevonumero[numcont]=detectarnumero(ch);
    	if(nuevosimbolo[simbolocont]!=0){
    		simbolodebug[simbolocont2]=nuevosimbolo[simbolocont];
    		//printf("simbolos [%d] =%c\n",simbolocont2,simbolodebug[simbolocont2]);
    		simbolocont2++;
    	}
    	if(nuevooperador[operadorcont]!=0){
    		operadordebug[operadorcont2]=nuevooperador[operadorcont];
    		//printf("operador [%d] =%c\n",operadorcont2,operadordebug[operadorcont2]);
    		operadorcont2++;
    	}
    	if(nuevonumero[numcont]!=0){
    		numerodebug[numcont2]=nuevonumero[numcont];
    		//printf("numero [%d] =  %d \n",numcont2,numerodebug[numcont2]);
    		numcont2++;
    	}
    	original++;
    	numcont++;
        simbolocont++;
        operadorcont++;
    }
    count=numcont;

}
char tokensimbolo(char llavetokensimbolo,int posicion){
	char simbolo[posicion];
	if(llavetokensimbolo=='['||llavetokensimbolo==','||llavetokensimbolo==';'||llavetokensimbolo==']'){
        return simbolo[posicion]=llavetokensimbolo;
	}else{
		return 0;
	}
}
char tokenoperador(char llavetokenoperador, int posicion){
	char operador[posicion];
	if(llavetokenoperador=='.'||llavetokenoperador=='+'||llavetokenoperador=='-'||llavetokenoperador=='~'||llavetokenoperador=='^'||llavetokenoperador=='>'){
		return operador[posicion]=llavetokenoperador;
	}else{
		return 0;
	}
}
char detectarnumero(char numerorec){
	if(isdigit(numerorec)==2048){ //isdigit Comprueba sin un carácter es un dígito decimal.
		char *lnum=&numerorec;
		return atoi(lnum); //atoi convierte el char en int 
	}else{
		return 0;
	}
}
/*
//sintaxis
void sintaxis(){
	if(array[0]=='['){
		printf("hola\n");
		for (int i = 1; i < original; ++i){
			if(isdigit(array[i])==2048){
				printf("array %c\n", array[i]);
			}
		}
	}else{
		printf("error\n");
	}
}
char coma(char coma)*/
//semantica
