#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
FILE *archivo;
int matrizA[50][50],matrizB[50][50],matrizC[50][50];
int puntocoma,contadorcoma=1,contadorcomaB=1,numerosA[100],numerosB[100];
int coma[50],columnasA,comaB[50],columnasB; //coma y punto coma
char refposoperacion[2];
float ainversa[25][25],kinversa,d;
int contadorinicio=0,contadorfin=0,contadorptcom=0, cont=0;
int matrizinicio[2],matrizfin[2],matrizptcomA[10],matrizptcomB[10];
int matrizA2[20][20];
char MA(char text[],int tam);
char tamB(char text[],int tam);
char tamA(char text[],int tam);
int determinant(int det[20][20],int rec);
float determinanteinversa(float [][25], float);
void cofactor(float [][25], float);
void transpose(float [][25], float [][25], float);
int V(char numerorec[],int tam,char id);
int main(int argc, char const *argv[]){
	archivo = fopen("program.txt","r");
	char ch;
	char entrada[100];
	if(archivo == NULL){
        printf("Archivo NULL\n");
        exit(0);
    }
    int contentrada=0,contoper=0;
    while((ch = fgetc(archivo)) != EOF){
    	if(ch>=97 && ch <=122 || ch>=65 && ch <=90){ //rango de valores ascii para las letras  minusculas y mayusculas 
    		printf("error no se admite  %c\n",ch);
    		return 0;
    	}
    	if(ch=='+'||ch=='_'||ch=='.'||ch=='~' ||ch=='^'||ch=='>'){
    		refposoperacion[contoper++]=ch;  //referecia a la posicion de la operacion

    	}
    	if(ch=='*' || ch=='!' || ch=='@'||ch=='}'||ch=='{'){
    		printf("error\n");
    		return 0;
    	}
    	entrada[contentrada]=ch; //almacen los caracteres en la matriz entrada 
    	contentrada++;
    }
    if(refposoperacion[1]=='+'||refposoperacion[1]=='_'||refposoperacion[1]=='.'||refposoperacion[1]=='~'||refposoperacion[1]=='^'||refposoperacion[1]=='>'){
    	printf("error tienes de mas un %c\n",refposoperacion[1]);
    	return 0;
    }
    char estado;
    estado=MA(entrada,contentrada);
    if(estado==0){ //sale del programa si el primer caracter no es un [
    	return 0;
    }
    //aqui almacenamos la matriz A
    int valoresdeA=0;
	for (int i = 0; i < columnasA; i++){//columnas
		for (int j = 0; j <coma[1]+1; j++){ //filas
			matrizA[i][j]=numerosA[valoresdeA++];
		}
	} 
	int valoresdeA2=0;
	for (int i = 1; i < columnasA+1; i++){//columnas
		for (int j = 1; j <columnasA+1; j++){ //filas
			matrizA2[i][j]=numerosA[valoresdeA2++];
		}
	} 
    switch(refposoperacion[0]){
    	case '+':
    		if(columnasA==columnasB && coma[1]==comaB[1]){
    			printf("\t\t\tSUMA\n");
				//aqui almacenamos la matriz B
				int valoresdeB=0;
				for (int i = 0; i < columnasA; i++){//columnas
	    			for (int j = 0; j <coma[1]+1; j++){ //filas
	    				matrizB[i][j]=numerosB[valoresdeB++];
	    			}
				}
				for (int i = 0; i < columnasA; i++){//columnas
	    			for (int j = 0; j <coma[1]+1; j++){ //filas
	    				matrizC[i][j]=matrizA[i][j]+matrizB[i][j];
	    			}
				}
				
				printf("\n\t\tMATRIZ A\n");
				for (int i = 0; i < columnasA; i++){//columnas
					for (int j = 0; j <coma[1]+1; j++){ //tRESULTADO
						printf("[%d][%d]=%d\t",i,j,matrizA[i][j]);
					}
					printf("\n");
				}	 
				printf("\n\t\tMATRIZ B\n");
				for (int i = 0; i < columnasA; i++){//columnas
					for (int j = 0; j <coma[1]+1; j++){ //filas
						printf("[%d][%d]=%d\t",i,j,matrizB[i][j]);
					}
					printf("\n");
				}	
				printf("\n\n");
				printf("\t\tRESULTADO \n\n");
				for (int i = 0; i < columnasA; i++){//columnas
	  				for (int j = 0; j <coma[1]+1; j++){ //filas
	  					printf("[%d][%d]=%d\t",i,j,matrizC[i][j] );
	   				}
	   				printf("\n");
				}
    		}else{
    			printf("imposibles sumar estas matrices una de ellas es mas grande\n");
    		}
    		break;
    	case '_':
    	    if(columnasA==columnasB && coma[1]==comaB[1]){
    			printf("\t\t\tRESTA\n");
				//aqui almacenamos la matriz B
				int valoresdeB=0;
				for (int i = 0; i < columnasA; i++){//columnas
	    			for (int j = 0; j <coma[1]+1; j++){ //filas
	    				matrizB[i][j]=numerosB[valoresdeB++];
	    			}
				}
				for (int i = 0; i < columnasA; i++){//columnas
	    			for (int j = 0; j <coma[1]+1; j++){ //filas
	    				matrizC[i][j]=matrizA[i][j]-matrizB[i][j];
	    			}
				}
				printf("\n\t\tMATRIZ A\n");
				for (int i = 0; i < columnasA; i++){//columnas
					for (int j = 0; j <coma[1]+1; j++){ //filas
						printf("[%d][%d]=%d\t",i,j,matrizA[i][j]);
					}
					printf("\n");
				}	 
				printf("\n\t\tMATRIZ B\n");
				for (int i = 0; i < columnasA; i++){//columnas
					for (int j = 0; j <coma[1]+1; j++){ //filas
						printf("[%d][%d]=%d\t",i,j,matrizB[i][j]);
					}
					printf("\n");
				}	
				printf("\t\tRESULTADO\n\n");
				for (int i = 0; i < columnasA; i++){//columnas
	  				for (int j = 0; j <coma[1]+1; j++){ //filas
	  					printf("[%d][%d]=%d\t",i,j,matrizC[i][j] );
	   				}
	   				printf("\n");
				}
    		}else{
    			printf("error\n");
    			return 0;
    		}
    		break;
    	case '.':
    	
    		if(columnasA<=columnasB && coma[1]<=comaB[1]){
    			printf("\t\t\tMULTIPLICACION\n");
				//aqui almacenamos la matriz B si tuvieramos
				int valoresdeB=0;
				for (int i = 0; i < columnasB; i++){//columnas
	    			for (int j = 0; j <comaB[1]+1; j++){ //filas
	    				matrizB[i][j]=numerosB[valoresdeB++];
	    			}
				}
				int k;
				for (int i = 0; i < columnasB; i++){//columnas
	    			for (int j = 0; j <comaB[1]+1; j++){ //filas
	    				for(k=0;k<comaB[1]+1;k++){
	    					matrizC[i][j]=(matrizC[i][j])+(matrizA[i][k]*matrizB[k][j]);
	    				}
	    			}
				}
				printf("\n\t\tMATRIZ A\n");
				for (int i = 0; i < columnasA; i++){//columnas
					for (int j = 0; j <coma[1]+1; j++){ //filas
						printf("[%d][%d]=%d\t",i,j,matrizA[i][j]);
					}
					printf("\n");
				}	 
				printf("\n\t\tMATRIZ B\n");
				for (int i = 0; i < columnasB; i++){//columnas
					for (int j = 0; j <comaB[1]+1; j++){ //filas
						printf("[%d][%d]=%d\t",i,j,matrizB[i][j]);
					}
					printf("\n");
				}	
				printf("\t\tRESULTADO\n\n");
				for (int i = 0; i < columnasB; i++){//columnas
	  				for (int j = 0; j <comaB[1]+1; j++){ //filas
	  					printf("[%d][%d]=%d\t",i,j,matrizC[i][j] );
	   				}
	   				printf("\n");
				}
    		}else{
    			printf("imposibles multiplicar estas matrices una de ellas es mas grande\n");
    		}
    		break;
    	case '~':
    		printf("\t\tMATRIZ TRANSPUESTA\n");
    		printf("\n\t\tMATRIZ A\n");
			for (int i = 0; i < columnasA; i++){//columnas
				for (int j = 0; j <columnasA; j++){ //filas
					printf("[%d][%d]=%d\t",i,j,matrizA[i][j]);
				}
				printf("\n");
			}	
			printf("\n\t\tTRANSPUESTA\n");
			for (int i = 0; i < coma[1]+1; i++){//columnas
				for (int j = 0; j <columnasA; j++){ //filas
					printf("[%d][%d]=%d\t",j,i,matrizA[j][i]);
				}
				printf("\n");
			}
    		break;
    	case '^':
    		printf("es una inversa\n");
    		int i,j;
    		break;
    	case '>':
    		printf("\t\tDETERMINANTE\n");
    		printf("\n\t\tMATRIZ A\n");
			for (int i = 1; i < columnasA+1; i++){//columnas
				for (int j = 1; j <columnasA+1; j++){ //filas
					printf("[%d][%d]=%d\t",i,j,matrizA2[i][j]);
				}
				printf("\n");
			}
    		printf("\n \n");
  			printf("\nLA DETERMINANTE ES: %d ",determinant(matrizA2,columnasA));
  			printf("\n");
    		break;
    	default:
    		printf("no existe\n");
    }
	return 0;
}


char MA(char text[],int tam){
	char estado;
	while(cont<=tam){
		if(text[0]!='['){ //verfica si el primer caracter es un [
			printf("error\n");
			return 0;
		}
		if(text[cont]=='['){ //encuentra las posiciones de [
			matrizinicio[contadorinicio]=cont;
			contadorinicio++;
		}
		if(text[matrizinicio[contadorinicio]+1]=='['){ //vemos si existe [[ lo cual es un error
			printf("error\n");
			return 0;
		}
		if(text[cont]==']'){//encuentra las posiciones de ]
			matrizfin[contadorfin]=cont;
			contadorfin++;
		}
		// if(text[matrizfin[0]+2]=='1'||text[matrizfin[0]+2]=='2'||text[matrizfin[0]+2]=='3'||text[matrizfin[0]+2]=='4'||text[matrizfin[0]+2]=='5'||text[matrizfin[0]+2]=='6'||text[matrizfin[0]+2]=='7'||text[matrizfin[0]+2]=='8'||text[matrizfin[0]+2]=='9'){
		// 	printf("error\n");
		// 	return 0;
		// }
		// if(text[matrizfin[0]+1]=='1'||text[matrizfin[0]+1]=='2'||text[matrizfin[0]+1]=='3'||text[matrizfin[0]+1]=='4'||text[matrizfin[0]+1]=='5'||text[matrizfin[0]+1]=='6'||text[matrizfin[0]+1]=='7'||text[matrizfin[0]+1]=='8'||text[matrizfin[0]+1]=='9'){
		// 	printf("error\n");
		// 	return 0;
		// }
		cont++;
	}
	estado=tamA(text,tam);
	if(refposoperacion[0]=='+' || refposoperacion[0]=='_' ||refposoperacion[0]=='.')
		estado=tamB(text,tam);
	if(estado==0){ 
    	return 0;
    }
	// printf("columnas A=%d\n",columnasA );
	// printf("columnas B=%d\n",columnasB );
	// printf("filas A=%d\n",coma[1]+1 );
	// printf("filas B=%d\n",comaB[1]+1 );
	printf("\n\n");
}
char tamA(char text[],int tam){
	//printf("tamaño A\n");
	char verfica[50];
	int ptcoma=1,max;
	matrizptcomA[0]=matrizinicio[0]+1;
	int contdeta=0;
	for (int i = matrizinicio[0]+1; i <= matrizfin[0]; ++i){
		verfica[contdeta]=text[i]; //vertical recibe los valores [] antes de la operacion
		if(text[i]==';'){
			matrizptcomA[ptcoma]=i; //guardo las posiciones de los ;
			//printf("[%d]%d=%c\n",ptcoma,matrizptcomA[ptcoma],text[i]);
			max=ptcoma; //max dice cuantos ; hay 
			ptcoma++;
		}
		contdeta++;
	}
	matrizptcomA[max+1]=matrizfin[0];//especio del ultimo ; y agrega un espacio mas para el ]
	for(int i=1;i<=max+1;i++){
		columnasA=i;
	}
	//printf("numero de columnasA %d\n",columnasA );
	for (int i = 0; i < columnasA; ++i){
		if(text[matrizptcomA[i]+1]==';'){ //marca error si ocurre esto ;;
			printf("error ;;\n");
			return 0;
		}
	}
	for (int i = 1; i <= columnasA; ++i){ //aqui determinamos cuantas columnas tenemos 
		//comenzamos desde 0 por que la primera posicion de matrizptcom contiene [
		//printf("numero[%d]\n",i);
		for (int j = matrizptcomA[i-1]; j < matrizptcomA[i]; ++j){ //comenzamos definiendo a j como [ y decimos que es menor a matriz i que seria la  siguiente pisicion ; hasta llegar a ]
			//printf("%c\n",text[j] );
			if(text[j]==','){
				coma[i]=contadorcoma; //almacena cuantas , hay en entre cada ;
				//printf("%d\n",j);
				//printf("%d\n",contadorcoma );
				//printf("%c\n",text[j]);
				contadorcoma=contadorcoma+1; //contador de comas 
			}
		}
		contadorcoma=1;
		if(coma[1]==coma[i]){
		}else{  //en caso de que el numero de filas no sea igual en cada columna
			printf("error \n");
			exit(0);
		}
	}

	int tamresol=(columnasA*(coma[1]+1))-1;
	V(verfica,tamresol,'A');
}
char tamB(char text[],int tam){
	//printf("tamaño B\n");
	char verfica[50];
	int ptcomaB=1,maxB;
	matrizptcomB[0]=matrizinicio[1]+1;
	int contdeta=0;
	for (int i = matrizinicio[1]+1; i <= matrizfin[1]; ++i){
		verfica[contdeta]=text[i];
		if(text[i]==';'){
			matrizptcomB[ptcomaB]=i; //guardo las posiciones de los ;
			//printf("[%d]%d=%c\n",ptcomaB,matrizptcomB[ptcomaB],text[i]);
			maxB=ptcomaB; //max dice cuantos ; hay 
			ptcomaB++;
		}
		contdeta++;
	}
	matrizptcomB[maxB+1]=matrizfin[1];//especio del ultimo ; y agrega un espacio mas para el ]
	for(int i=1;i<=maxB+1;i++){
		columnasB=i;
	}
	//printf("numero de columnasB %d\n",columnasB );
	for (int i = 0; i < columnasB; ++i){
		if(text[matrizptcomB[i]+1]==';'){ //marca error si ocurre esto ;;
			printf("error ;;\n");
			return 0;
		}
	}
	for (int i = 1; i <= columnasB; ++i){ //aqui determinamos cuantas columnas tenemos 
		//comenzamos desde 0 por que la primera posicion de matrizptcom contiene [
		//printf("numero[%d]\n",i);
		for (int j = matrizptcomB[i-1]; j < matrizptcomB[i]; ++j){ //comenzamos definiendo a j como [ y decimos que es menor a matriz i que seria la  siguiente pisicion ; hasta llegar a ]
			//printf("%c\n",text[j] );
			if(text[j]==','){
				comaB[i]=contadorcomaB; //almacena cuantas , hay en cada espacio entre ;
				// printf("%d\n",contadorcomaB );
				// printf("%c\n",text[j]);
				contadorcomaB=contadorcomaB+1;
			}
		}
		contadorcomaB=1;
		if(comaB[1]==comaB[i]){
		}else{
			printf("error\n");
			exit(0);
		}
	}
	int tamresol=(columnasB*(comaB[1]+1))-1;
	V(verfica,tamresol,'B');
}
int V(char numerorec[],int tam,char id){
	char *ptr;
	int nuevo;
	int i=0;
	if(id=='A'){
		ptr=strtok(numerorec,",;");
		nuevo=atoi(ptr);
		numerosA[0]=nuevo;
		//printf("numero %d\n",nuevo);
		int contdectnum=1;
		while(i<tam){
			ptr=strtok(NULL,",;");
			nuevo=atoi(ptr);
			//printf("numero %d\n",nuevo);
			numerosA[contdectnum]=nuevo;
			contdectnum++;
			i++;
		}
	}
	if(id=='B'){
		ptr=strtok(numerorec,",;");
		nuevo=atoi(ptr);
		numerosB[0]=nuevo;
		//printf("numero %d\n",nuevo);
		int contdectnum=1;
		while(i<tam){
			ptr=strtok(NULL,",;");
			nuevo=atoi(ptr);
			//printf("numero %d\n",nuevo);
			numerosB[contdectnum]=nuevo;
			contdectnum++;
			i++;
		}
	}
}

int determinant(int f[20][20],int x){
	int pr,c[20],d=0,b[20][20],j,p,q,t;
  	if(x==2){
    	d=0;
    	d=(f[1][1]*f[2][2])-(f[1][2]*f[2][1]);
    	return(d);
   	}
  	else{
    	for(j=1;j<=x;j++){       
      		int r=1,s=1;
      		for(p=1;p<=x;p++){
          		for(q=1;q<=x;q++){
              		if(p!=1&&q!=j){
                		b[r][s]=f[p][q];
                		s++;
                		if(s>x-1){
                   			r++;
                   			s=1;
                  		}
               		}
             	}
         	}
     		for(t=1,pr=1;t<=(1+j);t++)
     		pr=(-1)*pr;
     		c[j]=pr*determinant(b,x-1);
     	}
     	for(j=1,d=0;j<=x;j++){
       		d=d+(f[1][j]*c[j]);
      	}
     	return(d);
   	}
}
