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

#define MAX_DIGITOS 200

typedef struct enterolargo{
    int cantDigitos;
    char signo;
    int arrayDigitos[MAX_DIGITOS];
} EnteroLargo;

void inicializar(EnteroLargo *enteroLargo){

int n;
for(n=0; n < MAX_DIGITOS ; n++){
    enteroLargo->arrayDigitos[n] = 0;
 }
}                                                                   //P1

EnteroLargo *creaEnteroLargo(){
  EnteroLargo *nuevoEnteroLargo = malloc(sizeof(EnteroLargo));
  nuevoEnteroLargo->signo = '+';
  nuevoEnteroLargo->cantDigitos = 0;
  inicializar(nuevoEnteroLargo);
  return (nuevoEnteroLargo);
}

EnteroLargo *creaEnteroLargoInt(int numero){
  EnteroLargo *nuevoEnteroLargo = creaEnteroLargo();
    if (numero<0){
      nuevoEnteroLargo->signo = '-';
    }else{
      nuevoEnteroLargo->signo ='+';
    }
  int n=0;
  while(numero>0 || numero<0){
    int digitos = 0;
    digitos = fabs(numero%10);
    nuevoEnteroLargo->arrayDigitos[n] = digitos;
      n++;
      numero = numero/10;
    }
    nuevoEnteroLargo->cantDigitos = n;
    return nuevoEnteroLargo;
}


EnteroLargo *creaEnteroLargoStr(char creaStrEnteroLargo[]){
  EnteroLargo *nuevoEnteroLargo = malloc(sizeof(EnteroLargo));
  nuevoEnteroLargo->cantDigitos = 0;
  nuevoEnteroLargo->signo = '+';
  inicializar(nuevoEnteroLargo);
  int digito;
  int n;
    for(n=strlen(creaStrEnteroLargo)-1;n>=0;n--){
      if(creaStrEnteroLargo[n] == '-'){
      nuevoEnteroLargo->signo =creaStrEnteroLargo[n];
    }else{
        digito = creaStrEnteroLargo[n] - '0';
        nuevoEnteroLargo->arrayDigitos[nuevoEnteroLargo->cantDigitos] = digito;
        nuevoEnteroLargo->cantDigitos++;
      }
    }
    return (nuevoEnteroLargo);
}

void copiaEnteroLargo(EnteroLargo *destino, EnteroLargo *fuente){

destino -> cantDigitos = fuente->cantDigitos;
destino -> signo = fuente -> signo;

for(int n = fuente->cantDigitos; n >= 0; n--)
   
destino -> arrayDigitos[n] = fuente -> arrayDigitos[n];
   }
   
void eliminaEnteroLargo(EnteroLargo *numero){
	if(numero != NULL){
		numero->cantDigitos=0;
		numero->signo='+';
		numero->cantDigitos=0;
		numero->signo='+';
		inicializar(numero);
	}
}

void muestraEnteroLargo(EnteroLargo *enteroLargo){
    
    if (enteroLargo->cantDigitos !=0){
    printf("[%d]",enteroLargo->cantDigitos);
    printf("%c",enteroLargo->signo);
    for(int n = enteroLargo->cantDigitos-1; n>=0; n--){
    printf("%d",enteroLargo->arrayDigitos[n]);
    }
    printf("\n");
  }else printf("no existe el numero\n");
}


                                                                                      //P2

//archivos//
   
  EnteroLargo *leeEnteroLargo( FILE *archivo){
	
  EnteroLargo *nuevoEnteroLargo = malloc(sizeof(EnteroLargo));
	if(archivo == NULL) return NULL;
  fread(&nuevoEnteroLargo->cantDigitos,sizeof(nuevoEnteroLargo->cantDigitos),1,archivo);
	fread(&nuevoEnteroLargo->signo,sizeof(nuevoEnteroLargo->signo),1,archivo);
	fread(&nuevoEnteroLargo->arrayDigitos,sizeof(nuevoEnteroLargo->arrayDigitos),1,archivo);
	return (nuevoEnteroLargo);

}

int escribeEnteroLargo(FILE *archivo,EnteroLargo *numero){

if(archivo == NULL) return (-1); 

fwrite(&numero->cantDigitos,sizeof(numero->cantDigitos),1,archivo);
fwrite(&numero->signo,sizeof(numero->signo),1,archivo);
fwrite(&numero->arrayDigitos,sizeof(numero->arrayDigitos),1,archivo);
 
fflush(archivo);
return 0; 
}

//archivos//

//suma y resta entero largo//

EnteroLargo *sumaEnteroLargo(EnteroLargo*,EnteroLargo*);
EnteroLargo *restaEnteroLargo(EnteroLargo*,EnteroLargo*);
int MayoMen(EnteroLargo*,EnteroLargo*);

EnteroLargo *sumaEnteroLargo(EnteroLargo *numero1, EnteroLargo *numero2){
  EnteroLargo *sumaEnteroLargo = malloc(sizeof(EnteroLargo));
  sumaEnteroLargo->cantDigitos=0;
  int suma= 0;
  int sum1= 0;
  //preguntar si ambos n�meros son de igual signo
  if(numero1->signo = numero2->signo){        //saber si ambos son +  -
    sumaEnteroLargo->signo= numero1->signo;                                             //declarar que quiero conservar el signo        
    int n=0;                                   //condicionante
    int dig1;
    int dig2;
    while(numero1->cantDigitos > n  || numero2->cantDigitos >n){
      dig1=0;
      dig2=0;
      if(numero1->cantDigitos > n) /*entonces */dig1=numero1->arrayDigitos[n];
      if(numero2->cantDigitos > n) dig2=numero2-> arrayDigitos[n];
      suma = sum1 + dig1 + dig2;
      if(suma > 9) sumaEnteroLargo->arrayDigitos[sumaEnteroLargo->cantDigitos] = (suma%10);
      else sumaEnteroLargo->arrayDigitos[sumaEnteroLargo->cantDigitos] = suma;
      sumaEnteroLargo->cantDigitos++;
      sum1= suma/10;
      n++;
    }
     if(sum1>0){
        sumaEnteroLargo->arrayDigitos[sumaEnteroLargo->cantDigitos] = sum1;
        sumaEnteroLargo->cantDigitos++;
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
  return(sumaEnteroLargo);
}
        
int MayoMen(EnteroLargo *numero1,EnteroLargo *numero2){
  if(numero1->cantDigitos == numero2->cantDigitos){
    int mayor1 = 0;
    int mayor2 = 0;
    int n = numero1->cantDigitos-1;
    while(mayor1 == 0 && mayor2 == 0 && n >=0){
      if(numero1->arrayDigitos[n] > numero2->arrayDigitos[n]) mayor1 = 1;
      else{
        if(numero2->arrayDigitos[n] > numero1->arrayDigitos[n]) mayor2 = 1;
      }
      n--;
    }
    if(mayor1 == 1) return 1;
    else if(mayor2 == 1) return -1;
    if(n < 0) return 0;
  }else{
    if(numero1->cantDigitos > numero2->cantDigitos) return 1;
    else return -1;
  }
}

 EnteroLargo *restaEnteroLargo(EnteroLargo *numero1,EnteroLargo *numero2){
  EnteroLargo *restaEnteroLargo = malloc(sizeof(EnteroLargo));
  restaEnteroLargo->cantDigitos = 0;
  EnteroLargo *aux = malloc(sizeof(EnteroLargo));
  aux->cantDigitos = 0;
  if(numero1->signo != numero2->signo){
    copiaEnteroLargo(aux,numero2);
    if(numero2->signo == '+') aux->signo = '-';
    else aux->signo = '+';
    restaEnteroLargo = sumaEnteroLargo(numero1,aux);
  }else{
    int dig1 = 0;
    int dig2 = 0;
    int resta = 0;
    int transp = 0;
    if(MayoMen(numero1,numero2) == 1){
      restaEnteroLargo->signo = numero1->signo;
      for(int n=0;n<numero1->cantDigitos;n++){
        if(n>numero2->cantDigitos) dig2 = 0;
        else dig2 = numero2->arrayDigitos[n];
        dig1 = numero1->arrayDigitos[n];
        if(dig1 < dig2) {
          resta= (10+dig1) - (dig2+transp);
          transp = 1;
        }else{
          resta = dig1 - (dig2+transp);
          transp = 0;
        } 
        restaEnteroLargo->arrayDigitos[restaEnteroLargo->cantDigitos] = resta;
        restaEnteroLargo->cantDigitos++;
      }
      int j = restaEnteroLargo->cantDigitos-1;
      while(restaEnteroLargo->arrayDigitos[j] == 0){
        restaEnteroLargo->cantDigitos--;
        j--;
      }
      
    }else{
      if(MayoMen(numero1,numero2) == -1){
        restaEnteroLargo->signo = numero2->signo;
        for(int n=0;n<numero2->cantDigitos;n++){
          if(n>numero1->cantDigitos) dig2 = 0;
          else dig2 = numero1->arrayDigitos[n];
          dig1 = numero2->arrayDigitos[n];
          if(dig1 < dig2) {
            resta = (10+dig1) - (dig2+transp);
            transp = 1;
          }else{
            resta = dig1 - (dig2+transp);
            transp = 0;
          } 
          restaEnteroLargo->arrayDigitos[restaEnteroLargo->cantDigitos] = resta;
          restaEnteroLargo->cantDigitos++;
        }
        int j = restaEnteroLargo->cantDigitos-1;
        while(restaEnteroLargo->arrayDigitos[j] == 0){
          restaEnteroLargo->cantDigitos--;
          j--;
        }
      }else{
        restaEnteroLargo->arrayDigitos[restaEnteroLargo->cantDigitos] = 0;
        restaEnteroLargo->cantDigitos++;
        restaEnteroLargo->signo = '+';
      }
    }
  }
  return (restaEnteroLargo);
}