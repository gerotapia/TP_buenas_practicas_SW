#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct NOMBRE
{
	char nombreEnlace[40];
};
struct PotenciaTx
{
	int Potencia;
};
struct FrecuenciaGHz
{
	int Frecuencia;
};
struct Enlaces
{
	struct FrecuenciaGHz *lista_frecuencias;
	struct PotenciaTx *lista_potencias;
	struct NOMBRE *nombre_enlace;
};
void enlacesTrabajando(struct Enlaces *MisEnlaces,char *nombre_nuevo,int frecuencia_nuevo,int potencia_nueva,int cant_enlaces)
{
	MisEnlaces->lista_frecuencias=(struct FrecuenciaGHz*)realloc(MisEnlaces->lista_frecuencias,cant_enlaces*sizeof(struct FrecuenciaGHz));
	MisEnlaces->lista_frecuencias[cant_enlaces-1].Frecuencia=frecuencia_nuevo;
	MisEnlaces->lista_potencias=(struct PotenciaTx*)realloc(MisEnlaces->lista_potencias,cant_enlaces*sizeof(struct PotenciaTx));
	MisEnlaces->lista_potencias[cant_enlaces-1].Potencia=potencia_nueva;
	MisEnlaces->nombre_enlace=(struct NOMBRE*)realloc(MisEnlaces->nombre_enlace,cant_enlaces*sizeof(struct NOMBRE));
	strcpy(MisEnlaces->nombre_enlace[cant_enlaces-1].nombreEnlace, nombre_nuevo);
	for(i=0;i<cant_enlaces;i++)
	{
		printf( //ME QUEDE SIN TIEMPO, QUERIA MOSTRAR LAS FRECUENCIAS, POTENCIAS Y NOMBRES
	}
}
int main()
{
	int max_enlaces,cant_enlaces,agregar_enlaces,nuevos_enlaces,frecuencia_temp,potencia_temp;
	char nombre_temp[40];
	printf("Cuantos enlaces desea tener\n");
	scanf("%d",&max_enlaces);
	cant_enlaces=0;
	agregar_enlaces=0;
	struct Enlaces MisEnlaces;
	do
	{
		cant_enlaces++;
		printf("Desea agregar mas enlaces? 1.SI - 2.NO\n");
		scanf("%d",&agregar_enlaces);
		if(agregar_enlaces == 1)
		{
			printf("cuantos enlaces desea agregar?\n");
			scanf("%d",&nuevos_enlaces);
			max_enlaces=max_enlaces+nuevos_enlaces;
		}
		printf("Escriba el nombre del enlace, la frecuencia (Hz) y la potenia, es ese orden\n");
		scanf("%s",nombre_temp);
		scanf("%d",&frecuencia_temp);
		scanf("%d",&potencia_temp);
		enlacesTrabajando(&MisEnlaces,nombre_temp,frecuencia_temp,potencia_temp,cant_enlaces);
	} while(cant_enlaces>0 && cant_enlaces<=max_enlaces);
	free(Enlaces.lista_frecuencias);
	free(Enlaces.lista_potencias);
	free(Enlaces.nombre_enlace);
}
