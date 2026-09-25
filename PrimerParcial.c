#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct enlaces //Declaramos la estructura que solicita el enunciado
	{
	int FrecuenciaGhz, PotenciaTx;
	char NombreEnlace[20];
	};
int main()
{
	int desicion,cantidad_enlaces,enlaces_agregados,salir; //Declaramos las variables que usaremos
	//Inicializamos en cero las variables
	salir=0;
	cantidad_enlaces=0;
	enlaces_agregados=0;
	//Declaramos e inicializamos en NULL el puntero, que será dinámico, cuyo tipo de dato es la struct que hicimos al comienzo
	struct enlaces *MisEnlaces = NULL; //Este puntero se comportará como un arreglo de estructuras dinámico, porque se van a ir agregando la cantidad de enlaces que el usuario quiera
	do{ //Comenzamos el bucle principal
		//Armamos el menú para el usuario
		printf("Bienvenido. Seleccione qué acción desea realizar:\n 1.Agregar Enlaces 2.Buscar enlaces por potencia 3.Salir\n");
		scanf("%d",&desicion);
		switch(desicion)
		{
		case 1:
			if(cantidad_enlaces==0) //Solo se ejecuta si es la primera vez que se inicia el programa
			{
				printf("Ingrese cuantos enlaces desea");
				scanf("%d",&cantidad_enlaces);
				MisEnlaces = (struct enlaces*)malloc(cantidad_enlaces * sizeof(struct enlaces)); //Reservamos la memoria para esa cantidad de enlaces
				//Llamamos a la función para agregar datos de dichos enlaces
			}
			else
			{
			//En caso de que el usuario desee seguir agregando enlaces	
			printf("Cuántos enlaces desea agregar?\n");
			scanf("%d",&enlaces_agregados);
			cantidad_enlaces=cantidad_enlaces+enlaces_agregados;
			//Vamos a declarar un arreglo dinámico auxiliar para evitar que perdamos los enlaces ya guardados en el arreglo original, en el supuesto caso de que no haya memoria suficiente
			struct enlaces *agregar = (struct enlaces*)realloc(MisEnlaces,cantidad_enlaces * sizeof(struct enlaces));
			if(agregar != NULL) //Validamos que haya memoria disponible para agrandar el arreglo dinamico de estructuras
				{
					MisEnlaces = agregar; //Agrandamos, oficilmente, la memoria disponible del arreglo dinamico
			//LLamar a la funcion para agregar datos de los enlaces, teniendo en cuenta que ya se agregaron los del comienzo
				}
			}
		break;
		case 2:
		break;
		case 3:
		printf("Ha decidido salir");
		salir = 1;
		break;	
		default:
		printf("Por favot, selecciona una de las opciones del menú");
		}
	} while(salir !=1);
free(MisEnlaces); //Liberamos la memoria del arreglo dinamico
return 0;
}
