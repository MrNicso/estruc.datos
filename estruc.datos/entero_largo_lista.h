#ifndef stdlib_h
#define stdlib_h
#include <stdlib.h>
#endif /* stdlid_h */

#ifndef stdio_h
#define stdio_h
#include <stdio.h>
#endif /* stdio_h */

#ifndef string_h
#define string_h
#include <string.h>
#endif /* string_h */

#ifndef math_h
#define math_h
#include <math.h>
#endif /* math_h */

typedef struct nodo{
      int digito;
      struct nodo *next;
      struct nodo *prev;
}Nodo;

typedef struct enteroLargo{
      int cantidadDigitos;
      char signo;
      Nodo *first;
      Nodo *last;
}EnteroLargo;      

void agregarDigito(int digito,EnteroLargo *nuevoEnteroLargo){
	
Nodo *newDigito = malloc(sizeof(Nodo));
newDigito -> digito = digito;
newDigito -> next = NULL;
newDigito -> prev = NULL;
EnteroLargo *Nodo = nuevoEnteroLargo;

if(Nodo -> first==NULL){

Nodo -> first = newDigito;
Nodo -> last = newDigito;

}else{

newDigito -> next = Nodo -> first;
Nodo -> first -> prev = newDigito;
Nodo -> first = newDigito;
  }
}

EnteroLargo *creaEnteroLargo(){
	EnteroLargo *nuevoEnteroLargo = malloc(sizeof(EnteroLargo));
	nuevoEnteroLargo->first = NULL;
	nuevoEnteroLargo->last = NULL;
	nuevoEnteroLargo->signo='+';
	nuevoEnteroLargo->cantidadDigitos = 0;
	return(nuevoEnteroLargo);
}

EnteroLargo *creaEnteroLargoInt(int numero){
    EnteroLargo *nuevoEnteroLargo = creaEnteroLargo();
    if (numero<0){
    	nuevoEnteroLargo->signo = '-';
  	}else{
    	nuevoEnteroLargo->signo ='+';
  	}
    int n =0;
    while(numero<0 || numero>0){
      int digitos;
      digitos = fabs(numero%10);
      agregarDigito(digitos,nuevoEnteroLargo);
      n++;
      numero = numero/10;
    }
    nuevoEnteroLargo->cantidadDigitos = n;
 
    return (nuevoEnteroLargo);
}

EnteroLargo *creaEnteroLargoStr(char creaStrEnteroLargo[]){//retornar referencia a un string
	EnteroLargo *nuevoEnteroLargo = malloc(sizeof(EnteroLargo));
	nuevoEnteroLargo->cantidadDigitos = 0;
	nuevoEnteroLargo->last=NULL;
	nuevoEnteroLargo->first=NULL;
	nuevoEnteroLargo->signo='+';
	
	int digito;
	for(int n=strlen(creaStrEnteroLargo)-1;n>=0;--n){ //comenzamos analizando desde el último dígito hasta el primero.
		if(creaStrEnteroLargo[n]=='-')/*entonces*/nuevoEnteroLargo->signo=creaStrEnteroLargo[n]; //pregunto si nuevoenterolargo  apuntando al signo es negativo
		else{
		    digito=creaStrEnteroLargo[n]-'0'; //digito = string en posición i, menos caracter cero ('0')
		    nuevoEnteroLargo->cantidadDigitos++; //recorremos posición
		    agregarDigito(digito,nuevoEnteroLargo);
		}
	}
	return(nuevoEnteroLargo);

}

void copiaEnteroLargo(EnteroLargo *destino,EnteroLargo *fuente){

Nodo *actual = fuente -> last;
destino -> cantidadDigitos = fuente -> cantidadDigitos;
destino -> signo = fuente -> signo;

for(int n = 0; n < fuente -> cantidadDigitos; n++){
agregarDigito(actual -> digito, destino);
actual = actual -> prev;
 }
}

void eliminaEnteroLargo(EnteroLargo *numero){

if (numero != NULL){
numero -> first = NULL;
numero -> last = NULL;
free(numero);
 }
}

void muestraEnteroLargo(EnteroLargo *enteroLargo){
	if(enteroLargo->first!= NULL){
		printf("[%d]",enteroLargo->cantidadDigitos);
		printf("%c",enteroLargo->signo);
		Nodo *Nodo = enteroLargo->first;
		for (int n=0;n<enteroLargo->cantidadDigitos;n++){
			printf("%d",Nodo->digito);
			Nodo = Nodo ->next;
		}
		printf("\n");
	}else printf("No existe el numero \n");
}

EnteroLargo *leeEnteroLargo(FILE *archivo){                                             //Archivos leer //
	EnteroLargo *nuevoEnteroLargo = malloc(sizeof(EnteroLargo));
	nuevoEnteroLargo->first = NULL;
	nuevoEnteroLargo->last = NULL;
	if(archivo == NULL) return NULL;
	fread(&nuevoEnteroLargo->cantidadDigitos,sizeof(nuevoEnteroLargo->cantidadDigitos),1,archivo);
	fread(&nuevoEnteroLargo->signo,sizeof(nuevoEnteroLargo->signo),1,archivo);
	for(int n=0;n<nuevoEnteroLargo->cantidadDigitos;n++){
		int digito = 0;
		fread(&digito,sizeof(digito),1,archivo);
		agregarDigito(digito,nuevoEnteroLargo);
	}
	return (nuevoEnteroLargo);
}

int escribeEnteroLargo(FILE *archivo,EnteroLargo *numero){                              //Escribir archivos//      

if(archivo == NULL) return (-1);

fwrite(&numero -> cantidadDigitos, sizeof(numero -> cantidadDigitos),1,archivo);
fwrite(&numero -> signo, sizeof(numero -> signo),1,archivo);

Nodo *actual = numero -> last;
for(int n = 0; n < numero -> cantidadDigitos; n++){
fwrite(&actual -> digito,sizeof(numero),1,archivo);
actual = actual -> prev;
}

fflush(archivo);
return 0;
}

EnteroLargo *sumaEnteroLargo(EnteroLargo*,EnteroLargo*);
EnteroLargo *restaEnteroLargo(EnteroLargo*,EnteroLargo*);
int MayoMen(EnteroLargo*,EnteroLargo*);

EnteroLargo *sumaEnteroLargo(EnteroLargo *numero1,EnteroLargo *numero2){
  EnteroLargo *sumaEnteroLargo = malloc(sizeof(EnteroLargo));
  sumaEnteroLargo->cantidadDigitos = 0;
  sumaEnteroLargo->first = NULL;
  sumaEnteroLargo->last = NULL;
	int suma = 0;
    int sum1 = 0;
    
  if(numero1->signo == numero2->signo){
		sumaEnteroLargo->signo = numero1->signo;
		int digito1,digito2;
		Nodo *Nodo1 = numero1->last;
		Nodo *Nodo2 = numero2->last;
		int n = 0;
		while(numero1->cantidadDigitos > n || numero2->cantidadDigitos > n){
			digito1 = 0;
			digito2 = 0;
			if(numero1->cantidadDigitos > n) digito1 = Nodo1->digito;
			if(numero2->cantidadDigitos > n) digito2 = Nodo2->digito;
			suma = sum1 + digito1 + digito2;
			if(suma > 9) agregarDigito(suma%10,sumaEnteroLargo);
			else agregarDigito(suma,sumaEnteroLargo);
			sumaEnteroLargo->cantidadDigitos++;
			sum1 = suma/10;
			if(Nodo1->prev != NULL) Nodo1 = Nodo1->prev;
			if(Nodo2->prev != NULL) Nodo2 = Nodo2->prev;
			n++;
		}
		if(sum1 > 0){
			agregarDigito(sum1,sumaEnteroLargo);
			sumaEnteroLargo->cantidadDigitos++;
		}
	}else{
		EnteroLargo *aux = creaEnteroLargo();
		copiaEnteroLargo(aux,numero2);
		if(numero2->signo == '+') aux->signo = '-';
		else aux->signo = '+';
		sumaEnteroLargo = restaEnteroLargo(numero1,aux);
		if(MayoMen(numero1,numero2) == 1) sumaEnteroLargo->signo = numero1->signo;
		else{if(MayoMen(numero1,numero2) == -1) sumaEnteroLargo->signo = numero2->signo;}
	}  
  return (sumaEnteroLargo);
}

int MayoMen(EnteroLargo *numero1,EnteroLargo *numero2){
	if(numero1->cantidadDigitos == numero2->cantidadDigitos){
		int mayor1 = 0;
		int mayor2 = 0;
		int n = numero1->cantidadDigitos-1;
		Nodo *Nodo1 = numero1->first;
		Nodo *Nodo2 = numero2->first;
		while(mayor1 == 0 && mayor2 == 0 && n >=0){
			if(Nodo1->digito > Nodo2->digito) mayor1 = 1;
			else{
				if(Nodo2->digito > Nodo1->digito) mayor2 = 1;
			}
			n--;
		}
		if(mayor1 == 1) return 1;
		else if(mayor2 == 1) return -1;
		if(n < 0) return 0;
	}else{
		if(numero1->cantidadDigitos > numero2->cantidadDigitos) return 1;
		else return -1;
	}
}

EnteroLargo *restaEnteroLargo(EnteroLargo *numero1,EnteroLargo *numero2){
  	EnteroLargo *restaEnteroLargo = malloc(sizeof(EnteroLargo));
	restaEnteroLargo->cantidadDigitos = 0;
	EnteroLargo *aux = malloc(sizeof(EnteroLargo));
	aux->cantidadDigitos = 0;
	restaEnteroLargo->first = NULL;
	restaEnteroLargo->last = NULL;
  
  	if(numero1->signo != numero2->signo){
		copiaEnteroLargo(aux,numero2);
		if(numero2->signo == '+') aux->signo = '-';
		else aux->signo = '+';
		restaEnteroLargo = sumaEnteroLargo(numero1,aux);
	}else{
		int digito1 = 0;
		int digito2 = 0;
		int resta = 0;
		int transp = 0;
   		Nodo *Nodo1 = numero1->last;
		Nodo *Nodo2 = numero2->last;
		if(MayoMen(numero1,numero2) == 1){
			restaEnteroLargo->signo = numero1->signo;
			for(int n=0;n<numero1->cantidadDigitos;n++){
				if(n>numero2->cantidadDigitos) digito1 = 0;
				else digito2 = Nodo1->digito;
				digito1 = Nodo1->digito;
				if(digito1 < digito2) {
					resta = (10+digito1) - (digito2+transp);
					transp = 1;
				}else{
					resta = digito1 - (digito2+transp);
					transp = 0;
				} 
				agregarDigito(resta,restaEnteroLargo);
				restaEnteroLargo->cantidadDigitos++;
			}
			int i = restaEnteroLargo->cantidadDigitos-1;
			while(Nodo2 == 0){
				restaEnteroLargo->cantidadDigitos--;
				i--;
			}
			
		}else{
			if(MayoMen(numero1,numero2) == -1){
				restaEnteroLargo->signo = numero2->signo;
				for(int n=0;n<numero2->cantidadDigitos;n++){
					if(n>numero1->cantidadDigitos) digito2 = 0;
					else digito2 = Nodo1->digito;
					digito1 = Nodo1->digito;
					if(digito1 < digito2) {
						resta = (10+digito1) - (digito2+transp);
						transp = 1;
					}else{
						resta = digito1 - (digito2+transp);
						transp = 0;
					} 
					agregarDigito(resta,restaEnteroLargo);
					restaEnteroLargo->cantidadDigitos++;
				}
			}else{
				agregarDigito(0,restaEnteroLargo);
				restaEnteroLargo->cantidadDigitos++;
				restaEnteroLargo->signo = '+';
			}
		}
	}
	return (restaEnteroLargo);
}

/*EnteroLargo *restaEnteroLargo(EnteroLargo *numero1,EnteroLargo *numero2){
  EnteroLargo *restaEnteroLargo = malloc(sizeof(EnteroLargo));
  restaEnteroLargo->cantidadDigitos = 0;
  restaEnteroLargo->first = NULL;
  restaEnteroLargo->last = NULL;
  int resta = 0;
  int resta1 = 0;
  int digito1= 0;
  int digito2= 0;
  int resto;
  if(numero1->signo == numero2->signo){
		restaEnteroLargo->signo = numero1->signo;
		int dig1,dig2;
		Nodo *tmp1 = numero1->last;
		Nodo *tmp2 = numero2->last;
		int n = 0;
		while(numero1->cantidadDigitos > n || numero2->cantidadDigitos > n){
			dig1 = 0;
			dig2 = 0;
			if(numero1->cantidadDigitos > n) dig1 = tmp1->digito;
			if(numero2->cantidadDigitos > n) dig2 = tmp2->digito;
			resta = resta1 + digito1 - digito2;
			if(resta > 9) agregarDigito(resta%10,restaEnteroLargo);
			else agregarDigito(resta,restaEnteroLargo);
			restaEnteroLargo->cantidadDigitos++;
			resto = resta/10;
			if(tmp1->prev != NULL) tmp1 = tmp1->prev;
			if(tmp2->prev != NULL) tmp2 = tmp2->prev;
			n++;
		}
		if(resta1 > 0){
			agregarDigito(resta1,restaEnteroLargo);
			restaEnteroLargo->cantidadDigitos++;
		}
	}else{
		EnteroLargo *aux = creaEnteroLargo();
		copiaEnteroLargo(aux,numero2);
		if(numero2->signo == '+') aux->signo = '-';
		else aux->signo = '+';
		restaEnteroLargo = sumaEnteroLargo(numero1,aux);
		if(MayoMen(numero1,numero2) == 1) restaEnteroLargo->signo = numero1->signo;
		else{if(MayoMen(numero1,numero2) == -1) restaEnteroLargo->signo = numero2->signo;}
	}  
  return (restaEnteroLargo);
}*/
