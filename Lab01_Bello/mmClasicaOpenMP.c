/*#######################################################################################
 #* Fecha: 15 de agosto de 2025 
 #* Autor: Juan Esteban Bello Durango
 #* Tema: 
 #* 	- Programa Multiplicación de Matrices algoritmo clásico
 #* 	- Paralelismo con OpenMP
######################################################################################*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>  // Libreria para medición de tiempo
#include <omp.h>       // Libreria para paralelismo con OpenMP

// Estructuras para medir el tiempo de ejecucion
struct timeval inicio, fin; 

// Funcion que inicia el cronometro
void InicioMuestra(){
	gettimeofday(&inicio, (void *)0);  							// Obtiene el tiempo actual
}

// Funcion que detiene el cronometro y calcula el tiempo transcurrido
void FinMuestra(){
	gettimeofday(&fin, (void *)0);     							// Obtiene el tiempo final
	fin.tv_usec -= inicio.tv_usec;     							// Calcula microsegundos transcurridos
	fin.tv_sec  -= inicio.tv_sec;      							// Calcula segundos transcurridos
	double tiempo = (double) (fin.tv_sec*1000000 + fin.tv_usec); 	// Convierte a microsegundos
	printf("%9.0f \n", tiempo);        							// Imprime el tiempo en microsegundos
}

// Funcion para imprimir matrices (solo si es de tamaño menor a 9)
void impMatrix(double *matrix, int D){							// El tipo de dato utilizado fue cambiado de int a double
	printf("\n");
	if(D < 9){  												// Solo imprime si el tamaño es menor a 9
		for(int i=0; i<D*D; i++){
			if(i%D==0) printf("\n");  							
			printf("%f ", matrix[i]); 							// Imprime elemento de la matriz
		}
		printf("\n**-----------------------------**\n");
	}
}

// Funcion para inicializar matrices con valores aleatorios
void iniMatrix(double *m1, double *m2, int D){
	for(int i=0; i<D*D; i++, m1++, m2++){
		*m1 = rand()%100;										// Valor aleatorio entre 0.0-99.0
		*m2 = rand()%100;										// Valor aleatorio entre 0.0-99.0
	}
}

// Funcion principal de multiplicacion de matrices (paralelizada)
void multiMatrix(double *mA, double *mB, double *mC, int D){
	double Suma, *pA, *pB;
	#pragma omp parallel  										// Inicia región paralela
	{
	#pragma omp for       										// Distribuye el bucle entre los hilos
	for(int i=0; i<D; i++){
		for(int j=0; j<D; j++){
			pA = mA+i*D;	      								
			pB = mB+j;            								
			Suma = 0.0;
			// Multiplica fila i de A por columna j de B
			for(int k=0; k<D; k++, pA++, pB+=D){
				Suma += *pA * *pB;  							// Acumula el producto
			}
			mC[i*D+j] = Suma;     								// Almacena resultado en matriz C
		}
	}
	}
}

// Funcion principal del programa
int main(int argc, char *argv[]){
	// Verifica numero de argumentos
	if(argc < 3){
		printf("\n Use: $./clasicaOpenMP SIZE Hilos \n\n");
		exit(0);
	}

	// Convierte argumentos a enteros
	int N = atoi(argv[1]);  									// Tamaño de la matriz
	int TH = atoi(argv[2]); 									// Numero de hilos
	
	// Reserva memoria para las matrices
	double *matrixA  = (double *)calloc(N*N, sizeof(double));
	double *matrixB  = (double *)calloc(N*N, sizeof(double));
	double *matrixC  = (double *)calloc(N*N, sizeof(double));
	
	srand(time(NULL));  										// Inicializa semilla para numeros aleatorios

	omp_set_num_threads(TH);  									// Configura numero de hilos OpenMP

	// Inicializa matrices A y B con valores aleatorios
	iniMatrix(matrixA, matrixB, N);

	// Imprime matrices (solo si es de tamaño menor a 9)
	impMatrix(matrixA, N);
	impMatrix(matrixB, N);

	// Mide tiempo de la multiplicación
	InicioMuestra();
	multiMatrix(matrixA, matrixB, matrixC, N);
	FinMuestra();

	// Imprime matriz resultado (solo si es de tamaño menor a 9)
	impMatrix(matrixC, N);

	// Liberación de Memoria
	free(matrixA);
	free(matrixB);
	free(matrixC);
	
	return 0;
}