#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define Filas 6
#define Columnas 10
#define N 3

struct compu {
    int velocidad; //entre 1 y 3 Ghz
    int anio; //entre 2015 y 2023
    int cantidad; //entre 1 y 8
    char *tipo_cpu; //valores del arreglo tipos
} typedef caracteristicas ;

void listaPcs (caracteristicas *a, char *puntero);
void velocidad (caracteristicas *a);
void antigua (caracteristicas *a);

int main () {
    
    char tipo_cpu[Filas][Columnas] = {{"Intel"}, {"AMD"},{"Celeron"}, {"Athlon"}, {"Core"}, {"Pentium"},};
    char *ptro = &tipo_cpu[0][0];
    caracteristicas pcs[5];

    puts("-------CARACTERISTICAS PC-------");
    for (int k = 0; k < N; k++)
    {
        printf("-------PC N %d------\n", k+1);
        printf("Velocidad pc: ");
        scanf("%d", &pcs[k].velocidad);
        fflush(stdin);
        printf("anio fabricacion pc: ");
        scanf("%d", &pcs[k].anio);
        fflush(stdin);
        printf("cantidad de nucleos pc: ");
        scanf("%d", &pcs[k].cantidad);
        fflush(stdin);
        //El tipo de procesador sera generado aleatoriamente 
         
        
    }


    listaPcs(pcs, ptro);
    antigua(pcs);
    velocidad (pcs);

     
    
    
    

    /*for (int i = 0; i < Filas; i++)
    {
        for (int j = 0; j < Columnas; j++)
        {
            printf("%c", *(ptro + i *Columnas +j)); 
        }        
        printf("\n");
    }*/

    
    return 0;
}


void listaPcs (caracteristicas *a, char *puntero)
{
    srand(time(NULL));
    int aux;
    
    for (int i = 0; i < N; i++)
    {
        printf("\n\n------Caracteristicas PC %d------\n", i+1);
        printf("Velocidad: %d\n", a[i].velocidad);
        printf("Anio: %d\n", a[i].anio);
        printf("Cantidad: %d\n", a[i].cantidad);   
        printf("Procesador: ");
        aux = rand()%6;
        for (int j = 0; j < Columnas; j++)
        {
            printf("%c", *(puntero + aux *Columnas +j));            
        }  
        
    }
}

void antigua (caracteristicas *a)
{
    int vejez = 2023, aux;
    for (int i = 0; i < N; i++)
    {
        if (a[i].anio < vejez)
        {
            vejez = a[i].anio;
            aux = i;
        }
        
    }

    printf("\n\nLa PC mas vieja es la N %d y es del anio %d\n\n", aux+1, vejez);
}

void velocidad (caracteristicas *a)
{
    int medidor=0, aux;
    for (int i = 0; i < N; i++)
    {
        if (a[i].velocidad>medidor)
        {
            medidor = a[i].velocidad;
            aux = i;
        }
        
    }

    printf("\n\nLa PC mas rapida es la N %d y su velocidad es de %d GHz\n\n", aux+1, medidor);

    
}