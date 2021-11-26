#include <stdio.h>
#include <stdlib.h>
#include "../src/LinkedList.h"
#include "Controller.h"
#include "inputs.h"
#include "Perrito.h"


int main()
{
	setbuf(stdout, NULL);
    int option;
    int banderaPrimerLista=0;

    LinkedList* listaPerritos=ll_newLinkedList();
    do{

    	pedirEntero(&option,  " _______________________________________________________________________________ \n"
    			              "|                                                                               |\n"
							  "|                                  MENU PERRITOS                                |\n"
    						  "|_______________________________________________________________________________|\n"
								"1.Cargar los datos de los perritos desde el archivo data.csv (modo texto).\n"
								"2.Listar Perritos por nombre ascendente.\n"
								"4.Ordenar empleados.\n"
    							"5.mostrar female.\n"
								"6.Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
								"7.Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
								"8.Mostrar mayores a 20.\n"
    							"9.Mostrar las personas que se llamen Kaile.\n"
								"10.Mostrar los perros Male y menores a cinco.\n"
    							"11.Salir.\n"
								"---------------------------------------------------------------------------------\n"
								"Ingrese una opcion: ",

								" _______________________________________________________________________________ \n"
							    "|                                                                               |\n"
							    "|                                  MENU PERRITOS                                |\n"
							    "|_______________________________________________________________________________|\n"
								"1.Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
								"2.Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n"
								"3.Listar empleados.\n"
    							"5.mostrar female.\n"
								"4.Ordenar empleados.\n"
								"6.Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
								"7.Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
								"8.Mostrar mayores a 20.\n"
								"9.Mostrar las personas que se llamen Kaile.\n"
								"10.Mostrar los perros Male y menores a cinco.\n"
								"11.Salir.\n"
								"---------------------------------------------------------------------------------\n"
								"Opcion invalida, reingrese: ",1, 11);



        switch(option)
        {
            case 1:
            	if(!banderaPrimerLista)
            	{
            		controller_loadFromText("perritos.csv",listaPerritos);
            		banderaPrimerLista=1;
            	}
            	else
            	{
            		printf("Ya se accedio a la lista...\n");
            	}
                option=0;
                break;
            case 2:
            	if(ll_len(listaPerritos)!=0)
            	{
            		controller_sortPerritoNombreAscendete(listaPerritos);
            	}
            	else
            	{
            		printf("No se ingreso ningun empleado a la lista...\n");
            	}
            	option=0;
            	break;
            case 3:
            	if(ll_len(listaPerritos)!=0)
            	{
            		controller_ListPerrito(listaPerritos);
            	}
            	else
            	{
            		printf("No se ingreso ningun empleado a la lista...\n");
            	}
            	option=0;
            	break;
            case 4:
            	if(ll_len(listaPerritos)!=0)
            	{
            		controller_sortPerrito(listaPerritos);
            	}
            	else
            	{
            		printf("No se ingreso ningun empleado a la lista...\n");
            	}
            	option=0;
            	break;
            case 5:
            	/*if(ll_len(listaPerritos)!=0)
            	{
            		LinkedList* female=ll_filter(listaPerritos, Perrito_filtroHembra);
            		controller_ListPerrito(female);
            	}
            	else
            	{
            		printf("No se ingreso ningun empleado a la lista...\n");
            	}*/
            	option=0;
            	break;
            case 6:
            	/*if(ll_len(listaPerritos)!=0)
            	{
            		controller_saveAsText("data.csv", listaPerritos);
            	}
            	else
            	{
            		printf("No se accedio a la lista...\n");
            	}
            	option=0;*/
            	break;
            case 7:

            case 8:
            	if(ll_len(listaPerritos)!=0)
            	{
            		LinkedList* Mayores20=ll_filter(listaPerritos, Perrito_filtroPorEdad);
            		controller_ListPerrito(Mayores20);
            	}
            	else
            	{
            		printf("No se ingreso ningun empleado a la lista...\n");
            	}
            	option=0;
            	break;
            case 9:
            	if(ll_len(listaPerritos)!=0)
            	{
            		LinkedList* Kaile=ll_filter(listaPerritos, Perrito_filtroSeLLamaKaile);
            		controller_ListPerrito(Kaile);
            	}
            	else
            	{
            		printf("No se ingreso ningun empleado a la lista...\n");
            	}
            	option=0;
            	break;
            case 10:
            	/*if(ll_len(listaPerritos)!=0)
            	{
            		LinkedList* MaleMenorCinco=ll_filter(listaPerritos, Perrito_filtroMaleMenorCinco);
            		controller_ListPerrito(MaleMenorCinco);

            	}
            	else
            	{
            		printf("No se ingreso ningun empleado a la lista...\n");
            	}
            	option=0;*/
            	break;
            case 11:
            	ll_deleteLinkedList(listaPerritos);
            	printf("Saliendo del sistema...");
            	option=0;
            	break;
        }
        system("pause");
    }while(option != 10);
    return 0;
}



