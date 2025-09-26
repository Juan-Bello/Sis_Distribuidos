/**************************************************************
#                         Pontificia Universidad Javeriana
#     Autor: Juan Bello
#     Fecha: 26 de Septiembre 2025
#     Materia: Sistemas Distribuidos
#     Tema: MPI
#**************************************************************/

#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv){
    // Inicializacion del entorno MPI
    MPI_Init(NULL, NULL);

    // Obtener numero de procesos
    int word_size;
    MPI_Comm_size(MPI_COMM_WORLD, &word_size);

    // Obtener rank del proceso
    int word_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &word_rank);

    // Obtener nombre del proceso
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    // Mostrar mensaje de Hola Mundo
    printf("Hola Mundo desde el proceso %s, rank %d de %d procesos\n",processor_name,word_rank,word_size);

    // Finalizar entorno MPI
    MPI_Finalize();
    
}
