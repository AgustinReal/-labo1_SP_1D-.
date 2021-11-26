#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Perrito.h"



sPerrito* Perrito_new()
{
	sPerrito* perritoRetorno=NULL;
	perritoRetorno=(sPerrito*)malloc(sizeof(sPerrito));
	return perritoRetorno;
}
sPerrito* Perrito_newParametros(char* idStr, char* nombreStr, char* pesoStr, char* edadStr, char* razaStr, char* cantidadComidaRacionStr)
{
	sPerrito* perritoRetorno = NULL;
	perritoRetorno = Perrito_new();

	if(perritoRetorno != NULL)
	{
		Perrito_setId(perritoRetorno, atoi(idStr));
		Perrito_setNombre(perritoRetorno, nombreStr);
		Perrito_setEdad(perritoRetorno, atoi(edadStr));
		Perrito_setRaza(perritoRetorno, razaStr);
		Perrito_setPeso(perritoRetorno, atof(pesoStr));
		Perrito_setcantidadComidaRacion(perritoRetorno, atof(cantidadComidaRacionStr));
	}
	return perritoRetorno;
}
void Perrito_delete(sPerrito* this)
{
	if(this != NULL)
	{
		free(this);
		this=NULL;
	}
}
int Perrito_setId(sPerrito* this, int id)
{
	int seCargo=0;
	if(this!=NULL)
	{
		this->id=id;
		seCargo=1;
	}
	return seCargo;
}
int Perrito_getId(sPerrito* this,int* id)
{
	int retorno=-1;

	if(this != NULL )
	{
		*id=this->id;
		retorno=1;
	}
	return retorno;
}
int Perrito_setNombre(sPerrito* this, char* nombre)
{
	int seCargo = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		seCargo = 1;
	}
	return seCargo;
}
int Perrito_getNombre(sPerrito* this, char* nombre)
{

	int retorno=-1;

	if(this != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno=1;
	}
	return retorno;
}
int Perrito_setEdad(sPerrito* this, int edad)
{
	int seCargo = 0;
	if(this != NULL )
	{
		this->edad=edad;
		seCargo = 1;
	}
	return seCargo;
}
int Perrito_getEdad(sPerrito* this,int* edad)
{
	int retorno=-1;

	if(this != NULL )
	{
		*edad=this->edad;
		retorno=1;
	}
	return retorno;
}
int Perrito_setRaza(sPerrito* this, char* raza)
{
	int seCargo = 0;
	if(this != NULL )
	{
		strcpy(this->raza, raza);
		seCargo = 1;
	}
	return seCargo;
}
int Perrito_getRaza(sPerrito* this, char* raza)
{
	int retorno=-1;

	if(this != NULL && raza!=NULL)
	{
		strcpy(raza, this->raza);
		retorno=1;
	}
	return retorno;
}
int Perrito_setPeso(sPerrito* this, float peso)
{
	int seCargo = 0;
		if(this != NULL )
		{
			this->peso=peso;
			seCargo = 1;
		}
		return seCargo;
}
int Perrito_getPeso(sPerrito* this, float* peso)
{
	int retorno=-1;

		if(this != NULL )
		{
			*peso=this->peso;
			retorno=1;
		}
		return retorno;
}
int Perrito_setcantidadComidaRacion(sPerrito* this, float cantidadComidaRacion)
{
	int seCargo = 0;
		if(this != NULL )
		{
			this->cantidadComidaRacion=cantidadComidaRacion;
			seCargo = 1;
		}
		return seCargo;
}
int Perrito_getcantidadComidaRacion(sPerrito* this, float* cantidadComidaRacion)
{
	int retorno=-1;

		if(this != NULL )
		{
			*cantidadComidaRacion=this->cantidadComidaRacion;
			retorno=1;
		}
		return retorno;
}
/*int Perrito_setSexo(sPerrito* this,char* sexo)
{
	int seCargo = 0;
	if(this != NULL )
	{
		strcpy(this->sexo, sexo);
		seCargo = 1;
	}
	return seCargo;
}
int Perrito_getSexo(sPerrito* this,char* sexo)
{
	int retorno=-1;

		if(this != NULL && sexo!=NULL)
		{
			strcpy(sexo, this->sexo);
			retorno=1;
		}
		return retorno;
}*/
void Perrito_printDatacantidadComidaRacion(sPerrito* this)
{
    int id; //Variable donde se almacena el id utilizando getId();
    char nombre[35]; //Variable donde se almacena el nombre utilizando getNobre();
    int edad; //Variable donde se almacenan las horas trabajadas utilizando getHorasTrabajadas();
    char raza[35]; //Variable donde se almacena el sueldo utilizando getId();
    float peso;
    float cantidadComidaRacion;
	Perrito_getId(this, &id); //Obtengo el Id del empleado
    Perrito_getNombre(this, nombre); //Obtengo el nombre del empleado
    Perrito_getEdad(this, &edad); //Obtengo las horas trabajadas del empelado
    Perrito_getRaza(this, raza); //Obtengo el sueldo del empleado
    Perrito_getPeso(this, &peso);
    Perrito_getcantidadComidaRacion(this, &cantidadComidaRacion);

    printf("%d %15s %15.2f %15d %15s %15.2f\n", id, nombre, peso, edad, raza, cantidadComidaRacion); //Muestro los datos del empleado
}
void Perrito_printData(sPerrito* this)
{
    int id; //Variable donde se almacena el id utilizando getId();
    char nombre[35]; //Variable donde se almacena el nombre utilizando getNobre();
    int edad; //Variable donde se almacenan las horas trabajadas utilizando getHorasTrabajadas();
    char raza[35]; //Variable donde se almacena el sueldo utilizando getId();
    float peso;
	Perrito_getId(this, &id); //Obtengo el Id del empleado
    Perrito_getNombre(this, nombre); //Obtengo el nombre del empleado
    Perrito_getEdad(this, &edad); //Obtengo las horas trabajadas del empelado
    Perrito_getRaza(this, raza); //Obtengo el sueldo del empleado
    Perrito_getPeso(this, &peso);

    printf("%d %15s %15.2f %15d %15s \n", id, nombre, peso, edad, raza); //Muestro los datos del empleado
}
int Perrito_ordenarPorNombre(void* punteroUno, void* punteroDos)
{

	    int retorno=-2;
	    if(punteroUno!=NULL&&punteroDos!=NULL)
	    {
	        retorno=0;
	        char auxNombreUno[128];
	        char auxNombreDos[128];
	        sPerrito* this = (sPerrito*)punteroUno;
	        sPerrito* this2 = (sPerrito*)punteroDos;
	        Perrito_getNombre(this,auxNombreUno);
	        Perrito_getNombre(this2,auxNombreDos);

	        retorno=stricmp(auxNombreUno,auxNombreDos);

	        this =NULL;
	        this2=NULL;
	    }

	    return retorno;


}
int Perrito_ordenarEdad(void* punteroUno, void* punteroDos)
{
    int retorno=0;
    int horasUno;
    int horasDos;
    sPerrito* auxPerrito = (sPerrito*)punteroUno;
    sPerrito* auxPerritoDos = (sPerrito*)punteroDos;
    Perrito_getEdad(auxPerrito,&horasUno);
    Perrito_getEdad(auxPerritoDos,&horasDos);

    if(horasUno>horasDos)
    {
        retorno=1;
    }
    else if(horasUno<horasDos)
    {
        retorno=-1;
    }
    auxPerrito =NULL;
    auxPerritoDos=NULL;
    return retorno;
}
int Perrito_ordenarPorId(void* punteroUno, void* punteroDos)
{
    int retorno=0;
    int idUno;
    int idDos;
    sPerrito* auxPerrito = (sPerrito*)punteroUno;
    sPerrito* auxPerritoDos = (sPerrito*)punteroDos;
    Perrito_getId(auxPerrito,&idUno);
    Perrito_getId(auxPerritoDos,&idDos);

    if(idUno>idDos)
    {
        retorno=1;
    }
    else if(idUno<idDos)
    {
        retorno=-1;
    }
    auxPerrito=NULL;
    auxPerritoDos=NULL;
    return retorno;
}

int Perrito_ordenarRaza(void* punteroUno, void* punteroDos)
{
	int retorno=-2;
	if(punteroUno!=NULL&&punteroDos!=NULL)
	{
		retorno=0;
		char auxNombreUno[128];
		char auxNombreDos[128];
		sPerrito* auxPerrito = (sPerrito*)punteroUno;
		sPerrito* auxPerritoDos = (sPerrito*)punteroDos;
		Perrito_getRaza(auxPerrito,auxNombreUno);
		Perrito_getRaza(auxPerritoDos,auxNombreDos);

		retorno=stricmp(auxNombreUno,auxNombreDos);

		auxPerrito =NULL;
		auxPerritoDos=NULL;
	}

	return retorno;
}
int Perrito_ordenarPeso(void* punteroUno, void* punteroDos)
{
	int retorno=0;
	float idUno;
	float idDos;
	sPerrito* auxPerrito = (sPerrito*)punteroUno;
	sPerrito* auxPerritoDos = (sPerrito*)punteroDos;
	Perrito_getPeso(auxPerrito,&idUno);
	Perrito_getPeso(auxPerritoDos,&idDos);

	if(idUno>idDos)
	{
		retorno=1;
	}
	else if(idUno<idDos)
	{
		retorno=-1;
	}
	auxPerrito=NULL;
	auxPerritoDos=NULL;
	return retorno;
}
/*int Perrito_ordenarSexo(void* punteroUno, void* punteroDos)
{
	int retorno=-2;
	if(punteroUno!=NULL&&punteroDos!=NULL)
	{
		retorno=0;
		char auxNombreUno[128];
		char auxNombreDos[128];
		sPerrito* auxPerrito = (sPerrito*)punteroUno;
		sPerrito* auxPerritoDos = (sPerrito*)punteroDos;
		Perrito_getSexo(auxPerrito,auxNombreUno);
		Perrito_getSexo(auxPerritoDos,auxNombreDos);

		retorno=stricmp(auxNombreUno,auxNombreDos);

		auxPerrito=NULL;
		auxPerritoDos=NULL;

	}
	return retorno;
}*/
///////// Filtros

int Perrito_filtro_PerroMasPesados(void* this)
{
    int retorno=-1;

    float pesoActual;
    float pesoPesadoGuia=80;

    if(this!=NULL)
    {
        this = (sPerrito*) this;
        Perrito_getPeso(this, &pesoActual);
        if(pesoActual>=pesoPesadoGuia)
        {
            retorno= 0;
        }
    }

    return retorno;
}

int Perrito_filtro_PerroPeso(void* this, float pesoGuia)
{
    int retorno=-1;

    float pesoActual;

    if(this!=NULL)
    {
        this = (sPerrito*) this;
        Perrito_getPeso(this, &pesoActual);
        if(pesoActual>=pesoGuia)
        {
            retorno= 0;
        }
    }

    return retorno;
}

int Perrito_filtro_Comparacion(void* this, void* guia)
{
    int retorno=-1;

    if(this!=NULL&& guia!=NULL)
    {
        this = (sPerrito*) this;
        guia = (sPerrito*) guia;
        if(this==guia)
        {
            retorno= 0;
        }
    }

    return retorno;
}

/*int Perrito_filtroHembra(void* this)// guarda a todos los que sean hembras
{
	int retorno=0;
	char auxSexo[35];


	if(this!=NULL)
	{

		Perrito_getSexo((sPerrito*)this , auxSexo);
		if(!stricmp(auxSexo, "female"))
		{
			retorno=1;
		}
	}

	return retorno;
}*/
int Perrito_filtroSeLLamaKaile(void* this)// guarda a todos los que sean hembras
{
	int retorno=0;
	char auxNombre[35];


	if(this!=NULL)
	{

		Perrito_getNombre((sPerrito*)this , auxNombre);
		if(!stricmp(auxNombre, "Kaile"))
		{
			retorno=1;
		}
	}

	return retorno;
}
int Perrito_filtroRazaRiver(void* this)// guarda a todos los que sean Raza River.
{
	int retorno=0;
	char auxRaza[35];
	sPerrito* auxPerrito=NULL;

	if(this!=NULL)
	{
		auxPerrito=(sPerrito*) this;
		Perrito_getRaza(auxPerrito, auxRaza);
		if(!stricmp(auxRaza, "River"))
		{
			retorno=1;
		}
	}

	return retorno;
}
int Perrito_filtroPorEdad(void* this) //muestra los perros mayores a 20
{
	int retorno=0;
	if(this!=NULL)
	{
		sPerrito* auxPerrito=NULL;
		auxPerrito=(sPerrito*) this;
		if(auxPerrito->edad>20)
		{
			retorno=1;
		}
	}
	 return retorno;
}
int Perrito_laQueMapea(void* this)
{
	int retorno=0;
	float cantidadComidaRacion;
	if(this!=NULL)
	{
		this=(sPerrito*) this;

		cantidadComidaRacion=generarIntRandom(1, 320);

		Perrito_setcantidadComidaRacion(this, cantidadComidaRacion);

		retorno =1;
	}
	return retorno;

}
int ePerrito_laQueFiltra(void* this)
{
	int retorno=0;
		char auxRaza[35];

		if(this!=NULL)
		{

			Perrito_getRaza((sPerrito*)this , auxRaza);
			sPerrito* auxPerrito=NULL;
			auxPerrito=(sPerrito*) this;
			if(!stricmp(auxRaza, "Galgo") && auxPerrito->edad>=10 && auxPerrito->cantidadComidaRacion<200)
			{
				retorno=1;
			}
		}
		return retorno;

}
/*int Perrito_filtroMaleMenorCinco(void* this)
{
	int retorno=0;
	char auxSexo[35];

	if(this!=NULL)
	{

		Perrito_getSexo((sPerrito*)this , auxSexo);
		sPerrito* auxPerrito=NULL;
		auxPerrito=(sPerrito*) this;
		if(!stricmp(auxSexo, "male") && auxPerrito->edad<5)
		{
			retorno=1;
		}
	}
	return retorno;
}*/
