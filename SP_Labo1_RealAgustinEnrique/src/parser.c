#include <stdio.h>
#include <stdlib.h>
#include "../src/LinkedList.h"
#include "Perrito.h"

int parser_PerritoFromText(FILE* pFile , LinkedList* pArrayListPerrito)
{
	char id[10];
	char nombre[31];
	char edad[10];
	char raza[10];
	char peso[10];
	sPerrito* auxPerrito;
	int retorno=-1;

	if(pFile!=NULL && pArrayListPerrito!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", id, nombre, peso, edad, raza);
		while(!feof(pFile))
		{

			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", id, nombre, peso, edad, raza);

			auxPerrito=Perrito_newParametros(id, nombre, peso, edad, raza);
			ll_add(pArrayListPerrito, auxPerrito);
			retorno=1;
		}
		fclose(pFile);
		retorno=1;
		if(ll_len(pArrayListPerrito)==0)
		{
			retorno=-2;
		}

	}
	return retorno;
}
int parser_PerritoFromBinary(FILE* pFile , LinkedList* pArrayListPerrito)
{
	printf("Cargando datos del archivo binario\n");
	int retorno=0;

	if(pFile!=NULL && pArrayListPerrito!=NULL)
	{

		int fin =1;
		sPerrito* auxPerrito=Perrito_new();
		do
		{
			fin =fread(auxPerrito, sizeof(sPerrito), 1, pFile);
			if(fin)
			{
				ll_add(pArrayListPerrito, auxPerrito);
				auxPerrito=Perrito_new();
			}
		}while(fin);
		free(auxPerrito);

		fclose(pFile);
		retorno=1;
	}

	return retorno;
}
/*int guardarComoTexto(char* path, LinkedList* pLista)
{
	FILE* pFile;
	sPerrito* pPerrito;

	int id;
	char nombre[31];
	int edad;
	char raza[31];
	char sexo[10];
	float peso;
	int retorno = 0;

	if(pLista!=NULL && path!=NULL)
	{
		pFile= fopen(path, "w");
		if(pFile!=NULL)
		{
			retorno = 1;
			for(int i = 0; i < ll_len(pLista); i++)
			{
				pPerrito = (sPerrito*)ll_get(pLista, i);
				Perrito_getId(pPerrito, &id); //Obtengo el Id del empleado
				Perrito_getNombre(pPerrito, nombre); //Obtengo el nombre del empleado
				Perrito_getEdad(pPerrito, &edad); //Obtengo las horas trabajadas del empelado
				Perrito_getRaza(pPerrito, raza); //Obtengo el sueldo del empleado
				Perrito_getSexo(pPerrito, sexo);
				Perrito_getPeso(pPerrito, &peso);

				fprintf(pFile, "%d,%s,%d,%s,%.2f,%s\n", id, nombre, edad, raza, peso, sexo);


			}

			fclose(pFile);

			printf("Archivo guardado correctamente\n");
		}
		else if(retorno == 0)
		{
			printf("Error\n");
		}
	}

	return retorno;
}*/
int cargarTexto(char* path , LinkedList* pLista)
{
	FILE* pFile;
	int retorno = 1;

	pFile = fopen(path, "r"); //Abre el archivo para leerlo de texto, si es que existe.

	if(pFile != NULL)
	{
		if(parser_PerritoFromText(pFile, pLista) == 1)
		{
			//Si todo salio bien cambia a 0
			retorno = 0;
			printf("\nLos datos de los perros en modo texto fueron cargados corretamente\n\n");
		}
	}

	fclose(pFile);

	return retorno;

}
