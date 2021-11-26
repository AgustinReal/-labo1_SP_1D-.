#include <stdio.h>
#include <stdlib.h>
#include "../src/LinkedList.h"
#include "parser.h"
#include "inputs.h"
#include "Perrito.h"


int controller_loadFromText(char* path , LinkedList* pArrayListPerrito)
{
	int retorno=-1;
	FILE* pFile=fopen(path, "r");

	if(pArrayListPerrito!=NULL && path!=NULL)
	{
		parser_PerritoFromText(pFile, pArrayListPerrito);
		retorno=1;
	}
    return retorno;
}
int controller_loadFromBinary(char* path , LinkedList* pArrayListPerrito)
{
	int retorno=-1;

	if(pArrayListPerrito!=NULL && path!=NULL)
	{
		printf("Invoco al controller binario\n");
		FILE* pFile = fopen(path, "rb");
		if(pFile!=NULL)
		{
			parser_PerritoFromBinary(pFile , pArrayListPerrito);
			retorno=1;
		}
	}

    return retorno;
}
/*
int controller_addPerrito(LinkedList* pArrayListPerrito)
{
	int retorno=-1;
	int idMayor=1001;
	int idEmpleadoActual;
	char auxNombre[31];
	int auxHorasTrabajadas;
	int auxSueldo;
	char id[2000];
	char horasTrabajadas[1000];
	char sueldo[1000];
	char afirmacion;
	int listaLargo;
	Employee* pEmploy;
	Employee* empleado;



	if(pArrayListPerrito!=NULL)
	{
		listaLargo = ll_len(pArrayListPerrito);
		pEmploy=(Employee*) ll_get(pArrayListPerrito, 0);
		employee_getId(pEmploy, &idMayor);
		for (int i=0; i < listaLargo; i++)
		{
			pEmploy=(Employee*) ll_get(pArrayListPerrito, i);
			employee_getId(pEmploy, &idEmpleadoActual);
			if(idMayor<idEmpleadoActual)
			{
				employee_getId(pEmploy, &idMayor);
			}
		}
		idMayor+=1;
		itoa(idMayor,id,10);
		pedirCadena(auxNombre,"Ingrese el nombre del empleado: ","Error.Ingrese el nombre del empleado: ",31);
		ingresoEntero(&auxHorasTrabajadas, "Ingrese las horas trabajadas para el empleado: ", "Error.Ingrese las horas trabajadas para el empleado: ", 1, 360);
		ingresoEntero(&auxSueldo, "Ingrese el sueldo para el empleado(10000-50000): ", "Error.Ingrese el sueldo para el empleadoIngrese el sueldo para el empleado: : ", 10000, 50000);


		itoa(auxHorasTrabajadas, horasTrabajadas, 10);
		itoa(auxSueldo, sueldo, 10);

		empleado=employee_newParametros(id, auxNombre, horasTrabajadas, sueldo);
		printf("%s %15s %15s %15s \n","ID","NOMBRE","HORAS","Sueldo");
		employee_printData(empleado);

		pedirCaracter(&afirmacion, "Ingrese s para comfirmar el empleado y guardar los datos... ");

		if(afirmacion=='s' || afirmacion=='S')
		{

			ll_add(pArrayListPerrito, empleado);
			printf("Empleado dado de alto correctamente...\n");
			retorno=1;
		}
		else
		{
			printf("El empleado no fue dado de alto correctamente...\n");
		}
	}
		return retorno;
}
int controller_editPerrito(LinkedList* pArrayListPerrito)
{

	int retorno=-1;
	int option;
	int idEmpleadoActual;
	int IdEncontrado=-1;
	char antesNombre[31];
	char nuevoNombre[31];
	int antesHorasTrabajadas;
	int nuevaHorasTrabajadas;
	int nuevoSueldo;
	int antesSueldo;
	char afirmacion;
	int listaLargo;
	int almacenarAuxIdModificar;
	sPerrito* pEmploy;

	ingresoEntero(&almacenarAuxIdModificar, "Cual es id que desea modifcar: ", "Error. Cual es id que desea modifcar: ", 1, 2000);
	if(pArrayListPerrito!=NULL)
	{
		listaLargo = ll_len(pArrayListPerrito);
		for (int i=0; i < listaLargo; i++)
		{
			pEmploy=(Employee*) ll_get(pArrayListPerrito, i);
			employee_getId(pEmploy, &idEmpleadoActual);
			if(almacenarAuxIdModificar==idEmpleadoActual)
			{
				IdEncontrado=i;
				break;
			}
			else
			{
				printf("No se encontro ese empleado...\n");
			}
		}
		if(IdEncontrado>0)
		{
			printf("%s %15s %15s %15s \n","ID","NOMBRE","HORAS","Sueldo");
			pEmploy=(Employee*) ll_get(pArrayListPerrito, IdEncontrado);
			employee_printData(pEmploy);
			pedirCaracter(&afirmacion, "Ingrese s para comfirmar el empleado y guardar los datos... ");

			if(afirmacion=='s' || afirmacion=='S')
			{
				do
				{

					ingresoEntero(&option,"--------------------------------------------------------------------------------\n"
							"1-MODIFICAR El NOMBRE.\n"
							"2-MODIFICAR El HORAS TRABAJADAS.\n"
							"3-MODIFICAR El SUELDO.\n"
							"4-SALIR.\n"
							"--------------------------------------------------------------------------------\n"
							"Ingrese una opcion: ",

							"1-MODIFICAR El NOMBRE.\n"
							"2-MODIFICAR El HORAS TRABAJADAS.\n"
							"3-MODIFICAR El SUELDO.\n"
							"4-SALIR.\n"
							"--------------------------------------------------------------------------------\n"
							"Opcion invalida, reingrese: ", 1, 4);
					switch(option)
					{
					case 1:
						pedirCadena(nuevoNombre, "Ingrese el nuevo nombre del empleado: ", "Error.Ingrese el nuevo nombre del empleado: ", 31);

						employee_getNombre(pEmploy, antesNombre);
						employee_setNombre(pEmploy, nuevoNombre);

						printf("%s %15s %15s %15s \n","ID","NOMBRE","HORAS","Sueldo");
						pEmploy=(Employee*) ll_get(pArrayListPerrito, IdEncontrado);

						printf("Sea realizado la modificacion del nombre...\n");

						break;
					case 2:
						ingresoEntero(&nuevaHorasTrabajadas, "Ingrese las nuevas horas trabajadas del empleado: ", "Error.Ingrese las nuevas horas trabajadas del empleado: ", 1, 360);

						employee_getHorasTrabajadas(pEmploy, &antesHorasTrabajadas);
						employee_setHorasTrabajadas(pEmploy, nuevaHorasTrabajadas);

						printf("%s %15s %15s %15s \n","ID","NOMBRE","HORAS","Sueldo");
						pEmploy=(Employee*) ll_get(pArrayListPerrito, IdEncontrado);

						printf("Sea realizado la modificacion de la horas trabajadas...\n");
						break;
					case 3:
						ingresoEntero(&nuevoSueldo, "Ingrese el nuevo sueldo del empleado: ", "Error.Ingrese el nuevo sueldo del empleado: ", 10000, 50000);

						employee_getSueldo(pEmploy, &antesSueldo);
						employee_setSueldo(pEmploy, nuevoSueldo);

						printf("%s %15s %15s %15s \n","ID","NOMBRE","HORAS","Sueldo");
						pEmploy=(Employee*) ll_get(pArrayListPerrito, IdEncontrado);

						printf("Sea realizado la modificacion del sueldo...\n");
						break;
					case 4:
						printf("Saliendo de las modificaciones...\n");
						break;
					}
					printf("%s %15s %15s %15s \n","ID","NOMBRE","HORAS","Sueldo");
					pEmploy=(Employee*) ll_get(pArrayListPerrito, IdEncontrado);
					employee_printData(pEmploy);

				}while(option!=4);
				option=0;
				retorno=1;
			}
			else
			{
				printf("El empleado no fue modificado correctamente...\n\n");
			}
		}
	}

    return retorno;
}
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	char afirmacion;
	int idEmpleadoActual;
	int IdEncontrado;
	int listaLargo;
	int almacenarAuxIdModificar;
	Employee* pEmploy;

	ingresoEntero(&almacenarAuxIdModificar, "Cual es id que desea del empleado que desea dar de baja: ", "Error. Cual es id que desea del empleado que desea dar de baja: ", 1, 2000);
	if(pArrayListEmployee!=NULL)
	{
		listaLargo = ll_len(pArrayListEmployee);
		for (int i=0;i<listaLargo;i++)
		{
			pEmploy=(Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(pEmploy, &idEmpleadoActual);
			if(almacenarAuxIdModificar==idEmpleadoActual)
			{
				IdEncontrado=i;
				break;
			}
		}
		if(IdEncontrado>0)
		{
			printf("%s %15s %15s %15s \n","ID","NOMBRE","HORAS","Sueldo");
			pEmploy=(Employee*) ll_get(pArrayListEmployee, IdEncontrado);
			employee_printData(pEmploy);
			pedirCaracter(&afirmacion, "Ingrese s para comfirmar el empleado y darlo de baja...");

			if(afirmacion=='s' || afirmacion=='S')
			{
				ll_remove(pArrayListEmployee, IdEncontrado);
				printf("\nEl empleado %d fue eliminado correctamente!\n\n", IdEncontrado);
				retorno=1;
			}
			else
			{
				printf("\nSe cancelo la eliminacion...\n\n");
			}
		}
		else
		{
			printf("No se encontro esa Id del empleado...\n\n");
		}
	}
    return retorno;
}
*/
int controller_ListPerrito(LinkedList* pArrayListPerrito)
{
	int retorno = 0;
	int i=0;
	int lenList = ll_len(pArrayListPerrito);
	sPerrito* this;
	printf(" %-10s %-15s %-15s %-15s %-15s \n","Id","Nombre","peso","Edad","raza");
	for (i = 0; i < lenList; ++i)
	{
		this = (sPerrito*)ll_get(pArrayListPerrito, i);
		Perrito_printData(this);
		retorno = 1;
	}
	printf("\n");
	return retorno;
}
int controller_sortPerrito(LinkedList* pArrayListPerrito)
{
	int retorno=-1;
	int option;



	if(pArrayListPerrito!=NULL)
	{
		int(*pFuncionOrdenar)(void*,void*);

			ingresoEntero(&option,"--------------------------------------------------------------------------------\n"
					"1-ORDENAR POR El ID ASCENDENTE.\n"
					"2-ORDENAR POR El ID DESCENDENTE.\n"
					"3-ORDENAR POR El NOMBRE ASCENDENTE.\n"
					"4-ORDENAR POR El NOMBRE DESCENDENTE.\n"
					"5-ORDENAR POR EDAD ASCENDENTE.\n"
					"6-ORDENAR POR EDAD DESCENDENTE.\n"
					"7-ORDENAR POR RAZA ASCENDENTE.\n"
					"8-ORDENAR POR RAZA DESCENDENTE.\n"
					"9-ORDENAR POR RAZA ASCENDENTE.\n"
					"10-ORDENAR POR RAZA DESCENDENTE.\n"
					"11-ORDENAR POR RAZA ASCENDENTE.\n"
					"13-ORDENAR POR RAZA DESCENDENTE.\n"
					"13-SALIR.\n"
					"--------------------------------------------------------------------------------\n"
					"Ingrese una opcion: ",

					"1-ORDENAR POR El ID ASCENDENTE.\n"
					"2-ORDENAR POR El ID DESCENDENTE.\n"
					"3-ORDENAR POR El NOMBRE ASCENDENTE.\n"
					"4-ORDENAR POR El NOMBRE DESCENDENTE.\n"
					"5-ORDENAR POR EDAD ASCENDENTE.\n"
					"6-ORDENAR POR EDAD DESCENDENTE.\n"
					"7-ORDENAR POR RAZA ASCENDENTE.\n"
					"8-ORDENAR POR RAZA DESCENDENTE.\n"
					"9-ORDENAR POR PESO ASCENDENTE.\n"
					"10-ORDENAR POR PESO DESCENDENTE.\n"
					"11-ORDENAR POR SEXO ASCENDENTE.\n"
					"13-ORDENAR POR SEXO DESCENDENTE.\n"
					"13-SALIR.\n"
					"--------------------------------------------------------------------------------\n"
					"Opcion invalida, reingrese: ", 1, 13);


			switch(option)
			{
				case 1:
					pFuncionOrdenar=Perrito_ordenarPorId;
					ll_sort(pArrayListPerrito, pFuncionOrdenar, 1);
					break;
				case 2:
					pFuncionOrdenar=Perrito_ordenarPorId;
					ll_sort(pArrayListPerrito, pFuncionOrdenar, 0);
					break;
				case 3:
					pFuncionOrdenar=Perrito_ordenarPorNombre;
					ll_sort(pArrayListPerrito, pFuncionOrdenar, 1);
					break;
				case 4:
					pFuncionOrdenar=Perrito_ordenarPorNombre;
					ll_sort(pArrayListPerrito, pFuncionOrdenar, 0);
					break;
				case 5:
					pFuncionOrdenar=Perrito_ordenarEdad;
					ll_sort(pArrayListPerrito, pFuncionOrdenar, 1);
					break;
				case 6:
					pFuncionOrdenar=Perrito_ordenarEdad;
					ll_sort(pArrayListPerrito, pFuncionOrdenar, 0);
					break;
				case 7:
					pFuncionOrdenar=Perrito_ordenarRaza;
					ll_sort(pArrayListPerrito, pFuncionOrdenar, 1);
					break;
				case 8:
					pFuncionOrdenar=Perrito_ordenarRaza;
					ll_sort(pArrayListPerrito, pFuncionOrdenar, 0);
					break;
				case 9:
					pFuncionOrdenar=Perrito_ordenarPeso;
					ll_sort(pArrayListPerrito, pFuncionOrdenar, 1);
					break;
				case 10:
					pFuncionOrdenar=Perrito_ordenarPeso;
					ll_sort(pArrayListPerrito, pFuncionOrdenar, 0);
					break;
				case 12:
					/*pFuncionOrdenar=Perrito_ordenarSexo;
					ll_sort(pArrayListPerrito, pFuncionOrdenar, 1);*/
					break;
				case 11:
					/*pFuncionOrdenar=Perrito_ordenarSexo;
					ll_sort(pArrayListPerrito, pFuncionOrdenar, 0);**/
					break;
				case 13:
					printf("Volviendo al menu...\n");
					break;
			}
			retorno=1;
	}

    return retorno;
}
int controller_sortPerritoNombreAscendete(LinkedList* pArrayListPerrito)
{
	int retorno=-1;
	int(*pFuncionOrdenar)(void*,void*);

	if(pArrayListPerrito!=NULL)
	{
		printf("Perdon espere unos minutos...\n");
		pFuncionOrdenar=Perrito_ordenarPorNombre;
		ll_sort(pArrayListPerrito, pFuncionOrdenar, 1);
		retorno=1;
	}
	return retorno;
}
int controller_ListPerritoConRacion(LinkedList* pArrayListPerrito)
{
	int retorno = 0;
	int i=0;
	int lenList = ll_len(pArrayListPerrito);
	sPerrito* this;
	printf(" %-10s %-15s %-15s %-15s %-15s %-15\n","Id","Nombre","peso","Edad","raza","cantidadComidaRacion");
	for (i = 0; i < lenList; ++i)
	{
		this = (sPerrito*)ll_get(pArrayListPerrito, i);
		Perrito_printDatacantidadComidaRacion(this);
		retorno = 1;
	}
	printf("\n");
	return retorno;
}
/*int controller_saveAsText(char* path , LinkedList* pArrayListPerrito)
{
	int retorno=-1;
	int id;
	char nombre[31];
	int edad;
	char raza[31];
	char sexo[10];
	    float peso;
	sPerrito* pPerrito;
	int largo=ll_len(pArrayListPerrito);

	FILE* pFile;
	pFile=fopen(path, "w");

	if(pArrayListPerrito!=NULL && path!=NULL)
	{
		fprintf(pFile, "id, nombre, edad, raza, peso, sexo\n");

		for(int i=0;i<largo;i++)
		{
			pPerrito=(sPerrito*)ll_get(pArrayListPerrito, i);

			Perrito_getId(pPerrito, &id); //Obtengo el Id del empleado
			Perrito_getNombre(pPerrito, nombre); //Obtengo el nombre del empleado
			Perrito_getEdad(pPerrito, &edad); //Obtengo las horas trabajadas del empelado
			Perrito_getRaza(pPerrito, raza); //Obtengo el sueldo del empleado
			Perrito_getSexo(pPerrito, sexo);
			Perrito_getPeso(pPerrito, &peso);

			fprintf(pFile, "%d,%s,%d,%s,%.2f,%s\n", id, nombre, edad, raza, peso, sexo);

		}
		retorno=1;
	}
	fclose(pFile);
    return retorno;
}*/
int controller_saveAsBinary(char* path , LinkedList* pArrayListPerrito)
{
	printf("Guardando... archivo binario\n");
	int retorno=0;
	int tamArray;

	tamArray= ll_len(pArrayListPerrito);

	FILE* pFile;
	pFile = fopen(path, "wb");

	if(pFile!=NULL&& path!=NULL)
	{
		for (int var=0;var<tamArray;++var)
		{
			sPerrito* pAuxPerrito = ll_get(pArrayListPerrito,var);
			fwrite(pAuxPerrito, sizeof(sPerrito), 1, pFile);
		}
		printf("Archivo escrito con exito!\n");
		retorno=1;
	}
	fclose(pFile);
	return retorno;
}
int perro_MasPesado(LinkedList* pArrayList, void* pPerroMasPesado)
{
	int i=0;
	int retorno=0;
	float pesoActual;
	float pesoMayor;
	sPerrito* pPerrito;

	if(pArrayList!=NULL)
	{
		int lenList = ll_len(pArrayList);

		for (i = 0; i < lenList; ++i)
		{
			pPerrito =(sPerrito*) ll_get(pArrayList, i);
			pesoActual= Perrito_getPeso(pPerrito, &pesoMayor);
			if(i==0)
			{
				pesoMayor= Perrito_getPeso(pPerrito, &pesoMayor);
			}
			else if(pesoMayor<pesoActual)
			{
				pesoMayor=pesoActual;
				pPerroMasPesado= (void*) pPerrito;

			}
		}
		retorno=1;
	}

	return retorno;
}
