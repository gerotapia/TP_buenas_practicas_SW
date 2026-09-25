#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct enlaces //Declaramos la estructura que solicita el enunciado
	{
	int FrecuenciaGhz, PotenciaTx;
	char NombreEnlace[20];
	};
void nuevos_datos(struct enlaces *MisEnlaces) //La funcion recibe la direccion de memoria de la posicion i que determina el main
{
	char nombre_temp[20];
	printf("Ingrese los datos a guardar en el enlace correspondiente, en el siguiente orden:\n-Frecuencia(en Ghz) -Potencia(en Watts) -Nombre del enlace(sin espacios)\n");
	//Recibimos los datos del usuario y los gardamos en variables temporales
	//En los tres casos usamos operador flecha porque estamos utilizando un puntero a una estructura, y queremos entrar en ella para guardar los datos correspondientes
	scanf("%d",&MisEnlaces->FrecuenciaGhz);
	scanf("%d",&MisEnlaces->PotenciaTx);
	scanf("%s",nombre_temp);
	strcpy(MisEnlaces->NombreEnlace,nombre_temp);
	
}
void potencia_cercana(struct enlaces *MisEnlaces,float potencia_central,int i)
{
	float rango_cercania,cercania_menor,cercania_mayor;
	rango_cercania=((10*potencia_central)/100.0);
	cercania_menor=potencia_central-rango_cercania;
	cercania_mayor=potencia_central+rango_cercania;
	if(MisEnlaces->PotenciaTx>=cercania_menor && MisEnlaces->PotenciaTx<=cercania_mayor)
	{
		printf("Datos del enlace: Nombre: %s\t Potencia: %d\t Frecuencia: %d\n",MisEnlaces->NombreEnlace,MisEnlaces->PotenciaTx,MisEnlaces->FrecuenciaGhz); 
	}
}
int main()
{
	printf("Bienvenido\n");
	int i,desicion,cantidad_enlaces,enlaces_agregados,enlaces_realizados,salir; //Declaramos las variables que usaremos
	float potencia_central;
	//Inicializamos en cero las variables
	salir=0;
	cantidad_enlaces=0;
	enlaces_agregados=0;
	//Declaramos e inicializamos en NULL el puntero, que será dinámico, cuyo tipo de dato es la struct que hicimos al comienzo
	struct enlaces *MisEnlaces = NULL; //Este puntero se comportará como un arreglo de estructuras dinámico, porque se van a ir agregando la cantidad de enlaces que el usuario quiera
	do{ //Comenzamos el bucle principal
		//Armamos el menú para el usuario
		printf("Seleccione qué acción desea realizar:\n 1.Agregar Enlaces 2.Buscar enlaces por potencia 3.Salir\n");
		scanf("%d",&desicion);
		switch(desicion)
		{
		case 1:
			if(cantidad_enlaces==0) //Solo se ejecuta si es la primera vez que se inicia el programa
			{
				printf("Ingrese cuantos enlaces desea: ");
				scanf("%d",&cantidad_enlaces);
				MisEnlaces = (struct enlaces*)malloc(cantidad_enlaces * sizeof(struct enlaces)); //Reservamos la memoria para esa cantidad de enlaces
				//Con el siguiente for lo que haremos es pasarle a la función la direccion de memoria de cada enlace en el arreglo dinámico 
				for(i=0;i<cantidad_enlaces;i++)
				{
					nuevos_datos(&MisEnlaces[i]); //Que con aritmetica de punteros seria MisEnlaces+i
				}
				enlaces_realizados=cantidad_enlaces;
			}
			else
			{
			//En caso de que el usuario desee seguir agregando enlaces	
			printf("Cuántos enlaces desea agregar?\n");
			scanf("%d",&enlaces_agregados);
			//Vamos a declarar un arreglo dinámico auxiliar para evitar que perdamos los enlaces ya guardados en el arreglo original, en el supuesto caso de que no haya memoria suficiente
			struct enlaces *agregar = (struct enlaces*)realloc(MisEnlaces,(cantidad_enlaces + enlaces_agregados) * sizeof(struct enlaces));
			if(agregar != NULL) //Validamos que haya memoria disponible para agrandar el arreglo dinamico de estructuras
				{
					cantidad_enlaces = cantidad_enlaces + enlaces_agregados;
					MisEnlaces = agregar; //Agrandamos, oficilmente, la memoria disponible del arreglo dinamico
					for(i=enlaces_realizados;i<cantidad_enlaces;i++)
					{
						nuevos_datos(&MisEnlaces[i]);
						enlaces_realizados++;
					}
				}
			}
		break;
		case 2:
		printf("Seleccione la potencia central\n");
		scanf("%f",&potencia_central);
		printf("El rango de cercanía será de +-10 porciento a la potencia seleccionada\nA continuacion se mostraran los enlaces cercanos\n");
		for(i=0;i<cantidad_enlaces;i++)
		{
			potencia_cercana(&MisEnlaces[i],potencia_central,i);
		}
		break;
		case 3:
		printf("Ha decidido salir");
		salir = 1;
		break;	
		default:
		printf("Por favor, selecciona una de las opciones del menú");
		}
	} while(salir !=1);
free(MisEnlaces); //Liberamos la memoria del arreglo dinamico
return 0;
}
