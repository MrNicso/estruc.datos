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

//#ifndef entero_largo_arreglo_h
//#define entero_largo_arreglo_h
//#include "entero_largo_arreglo.h"
//#endif /* entero_largo_arreglo_h */

#ifndef entero_largo_lista_h
#define entero_largo_lista_h
#include "entero_largo_lista.h"
#endif /* entero_largo_lista_h */

int main(int argc, const char * argv[]) {
	printf("\nCreaciones de entero largos y eliminacion con copia \n");
	EnteroLargo *numero = creaEnteroLargo();
	printf("el numero debe estar vacio : ");
	muestraEnteroLargo(numero);
	numero = creaEnteroLargoInt(456);
	printf("el numero vacio ahora es 456 : ");
	muestraEnteroLargo(numero);
	//numeros positivos creaEnteroLargoInt
	EnteroLargo *numero45678 = creaEnteroLargoInt(45678);
	printf("el numero es 45678 : ");
	muestraEnteroLargo(numero45678);
	EnteroLargo *numero8923 = creaEnteroLargoInt(8923);
	printf("el numero es 8923 : ");
	muestraEnteroLargo(numero8923);

	// numeros positivos creaEnteroLargoStr
	EnteroLargo *numero87654 = creaEnteroLargoStr("87654");
	printf("el numero es 87654 : ");
	muestraEnteroLargo(numero87654);
	EnteroLargo *numero3298 = creaEnteroLargoStr("3298");
	printf("el numero es 3298 : ");
	muestraEnteroLargo(numero3298);

	//numeros negativos creaEnteroLargoInt
	EnteroLargo *numero45678n = creaEnteroLargoInt(-45678);
	printf("el numero es -45678 : ");
	muestraEnteroLargo(numero45678n);
	EnteroLargo *numero8923n = creaEnteroLargoInt(-8923);
	printf("el numero es 8923 : ");
	muestraEnteroLargo(numero8923);

	//numeros negativos creaEnteroLargoStr
	EnteroLargo *numero87654n = creaEnteroLargoStr("-87654");
	printf("el numero es -87654 : ");
	muestraEnteroLargo(numero87654n);
	EnteroLargo *numero3298n = creaEnteroLargoStr("-3298");
	printf("el numero es -3298 : ");
	muestraEnteroLargo(numero3298n);

	//Copia
	printf("La copia es : ");
	EnteroLargo *fuente = creaEnteroLargoInt(32);
	EnteroLargo *destino = creaEnteroLargo();
	copiaEnteroLargo(destino,fuente);
	muestraEnteroLargo(destino);

   // copiaEnteroLargo
	EnteroLargo *copian45678 = creaEnteroLargo();
	EnteroLargo *copiansE45678 = creaEnteroLargo();
	copiaEnteroLargo(copian45678,numero45678);
	copiaEnteroLargo(copiansE45678,numero45678n);
	printf("el numero copiado es 45678, la copia es : ");
	muestraEnteroLargo(copian45678);
	printf("el numero copiado es  -45678, la copia es : ");
	muestraEnteroLargo(copiansE45678);  

	// elimina Entero Largo
	printf("se procede a eliminar el numero 45678, el numero no deberia existir : ");
	eliminaEnteroLargo(numero45678);
	muestraEnteroLargo(numero45678);
	printf("se procede a eliminar el numero -45678, el numero no deberia existir : ");
	eliminaEnteroLargo(numero45678n);
	muestraEnteroLargo(numero45678n);
    
    printf("\n Archivos \n");
	//archivos positivos y negativos
	FILE *archivoEscritura = fopen("enteroLargo.bin","wb");
	escribeEnteroLargo(archivoEscritura,numero8923);
	FILE *archivoLectura = fopen("enteroLargo.bin","rb");
	EnteroLargo *numeroArchivo8923 = leeEnteroLargo(archivoLectura);
	printf("se procede a escribir el numero 8923 , el numero del archivo es : ");
	muestraEnteroLargo(numeroArchivo8923);
	 
	escribeEnteroLargo(archivoEscritura,numero3298n);
	EnteroLargo *numeroArchivo3298n = leeEnteroLargo(archivoLectura);
	printf("se procede a escribir el numero -3298 , el numero del archivo es : ");
	muestraEnteroLargo(numeroArchivo3298n);

	// suma y resta
	printf("\n Operadores \n");
	EnteroLargo *numero2060 = creaEnteroLargoInt(-2060);
	EnteroLargo *numero630 = creaEnteroLargoInt(2060);
	EnteroLargo *sumaEntLargo = sumaEnteroLargo(numero2060,numero630);
	printf("la suma entre -2060 + 2060 es : ");
	muestraEnteroLargo(sumaEntLargo);
	EnteroLargo *restaEntLargo = restaEnteroLargo(numero2060,numero630);
	printf("la resta entre -2060 - (+2060) es : ");
	muestraEnteroLargo(restaEntLargo);

 return 0;
}