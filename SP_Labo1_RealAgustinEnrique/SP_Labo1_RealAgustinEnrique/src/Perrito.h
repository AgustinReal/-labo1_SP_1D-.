

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED



typedef struct
{
    int id;
    char nombre[35];
    float peso;
    int edad;
    char raza[35];
    float cantidadComidaRacion;
   // char sexo[10];
    //char duenio[35];

}sPerrito;

/**
 * @fn Employee employee_new*()
 * @brief Esta funcion: Se encarga de agregar un nuevo empleado y guardarlo en
 * la memoria dinamica, es un contructor sin parametros.
 *
 * @return Retorna el puntero del empleado asignado en la memoria.
 */
sPerrito* Perrito_new();
/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief Esta funcion: Se encarga de agregar un nuevo empleado y guardarlo en
 * la memoria dinamica, es un contructor con parametros.
 *
 * @param idStr: En este apartado se le asigna la Id del empleado en forma de array de chars
 * y la transformas mediante la funcion atoi.
 * @param nombreStr: En este apartado se le asigna el Nombre del empleado en forma de array de chars
 * y la transformas mediante la funcion atoi.
 * @param horasTrabajadasStr: En este apartado se le asigna las horas trabajadas del empleado en forma de array de chars
 * y la tranformas mediante la funcion atoi.
 * @param sueldoStr: En este apartado se le asigna el sueldo del empleado en forma de array de chars
 * y la tranformas mediante la funcion atoi.
 *
 * @return Retorna el puntero del empleado asignado en la memoria.
 */
sPerrito* Perrito_newParametros(char* idStr, char* nombreStr, char* edadStr, char* razaStr, char* pesoStr);
/**
 * @fn void employee_delete(Employee*)
 * @brief Esta funcion: Se encarga de eliminar a un	empleado en la memoria dinamica.
 *
 *
 * @param this: Es el empleado a eliminar.
 */
void Perrito_delete();
/**
 * @fn int employee_setId(Employee*, int)
 * @brief Esta funcion: Se encarga de colocar el Id del empleado en la lista general.
 *
 * @param this: Esta es  la lista.
 * @param id: El id a colocar en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Perrito_setId(sPerrito* this,int id);
/**
 * @fn int employee_getId(Employee*, int)
 * @brief Esta funcion: Se encarga de obtener el Id del empleado en la lista general.
 *
 * @param this: Esta es  la lista.
 * @param id: El id a obtener en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Perrito_getId(sPerrito* this,int* id);
/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief Esta funcion: Se encarga de colocar el nombre del empleado en la lista general.
 *
 * @param this: Esta es la lista.
 * @param nombre: El nombre a colocar en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Perrito_setNombre(sPerrito* this,char* nombre);
/**
 * @fn int employee_getNombre(Employee*, char*)
 * @brief Esta funcion: Se encarga de obtener el nombre del empleado en la lista general.
 *
 * @param this: Esta es la lista.
 * @param nombre: El nombre a obtener en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Perrito_getNombre(sPerrito* this,char* nombre);
/**
 * @fn int employee_setHorasTrabajadas(Employee*, int)
 * @brief Esta funcion: Se encarga de colocar las horas trabajadas del empleado en la lista general.
 *
 * @param this: Esta es la lista.
 * @param horasTrabajadas: Las horas trabajadas a colocar en la lista.
 * @return Retorna 1 o -1: 1 si se puedo cargar o -1 si no se pudo cargar.
 */
int Perrito_setEdad(sPerrito* this,int edad);
/**
 * @fn int employee_getHorasTrabajadas(Employee*, int*)
 * @brief Esta funcion: Se encarga de obtener las horas trabajadas del empleado en la lista general.
 *
 * @param this: Esta es la lista.
 * @param horasTrabajadas: Las horas trabajadas a obtener en la lista.
 * @return Retorna 1 o -1: 1 si se puedo cargar o -1 si no se pudo cargar.
 */
int Perrito_getEdad(sPerrito* this,int* edad);
/**
 * @fn int employee_setSueldo(Employee*, int)
 * @brief Esta funcion: Se encarga de colocar el sueldo del empleado en la lista general.
 *
 * @param this: Esta es la lista.
 * @param sueldo: El sueldo a colocar en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Perrito_setRaza(sPerrito* this, char* raza);
/**
 * @fn int employee_getSueldo(Employee*, int*)
 * @brief Esta funcion: Se encarga de obtener el sueldo del empleado en la lista general.
 *
 * @param this: Esta es la lista.
 * @param sueldo: El sueldo a obtener en la lista.
 * @return Retorna 1 o 0: 1 si se puedo cargar o 0 si no se pudo cargar.
 */
int Perrito_getRaza(sPerrito* this, char* raza);
/**
 * @fn void employee_printData(Employee*)
 * @brief Esta funcion: Se encarga de mostrar los datos de un empleado.
 *
 * @param this: El empleado a mostrar los datos.
 */
int Perrito_setPeso(sPerrito* this, float peso);
int Perrito_getPeso(sPerrito* this, float* peso);
int Perrito_setSexo(sPerrito* this,char* sexo);
int Perrito_getSexo(sPerrito* this,char* sexo);
int Perrito_setcantidadComidaRacion(sPerrito* this, float cantidadComidaRacion);
int Perrito_getcantidadComidaRacion(sPerrito* this, float* cantidadComidaRacion);
void Perrito_printData(sPerrito* this);
/**
 * @fn int employee_ordenarPorNombre(void*, void*)
 * @brief Esta funciones obtiene 2 direcciones de memoria y los compara
 * devuelve 2 tipos de ordenamiento por nombre.
 *
 * @param punteroUno: El puntero que apunta a la direccion de memomoria del 1er direccion.
 * @param punteroDos: El puntero que apunta a la direccion de memomoria del 2da direccion.
 *
 * @return retorna: -2 si algun puntero es NULL, 0 si son iguales los nombres, -1 si el el segundo es mayor. 1 si el primero es mayor
 */
int Perrito_ordenarPorNombre(void* punteroUno, void* punteroDos);
/**
 * @fn int employee_ordenarPorHoras(void*, void*)
 * @brief Esta funciones obtiene 2 direcciones de memoria y los compara
 * devuelve 2 tipos de ordenamiento por horas trabajadas.
 *
 * @param punteroUno: El puntero que apunta a la direccion de memomoria del 1er direccion.
 * @param punteroDos: El puntero que apunta a la direccion de memomoria del 2da direccion.
 *
 * @return Esta funcion retorna 1 si la la variable que fue asiganada "horasUno" es mayor a "horasDos" o -1 si la la variable que fue asiganada "horasUno" es menor a "horasDos"
 */
int Perrito_ordenarEdad(void* punteroUno, void* punteroDos);
/**
 * @fn int employee_ordenarPorId(void*, void*)
 * @brief Esta funciones obtiene 2 direcciones de memoria y los compara
 * devuelve 2 tipos de ordenamiento por id.
 *
 * @param punteroUno: El puntero que apunta a la direccion de memomoria del 1er direccion.
 * @param punteroDos: El puntero que apunta a la direccion de memomoria del 2da direccion.
 *
 * @return Esta funcion retorna 1 si la la variable que fue asiganada "IdUno" es mayor a "IdDos" o -1 si la la variable que fue asiganada "IdUno" es menor a "IdDos"
 */
int Perrito_ordenarPorId(void* punteroUno, void* punteroDos);
/**
 * @fn int employee_ordenarSueldo(void*, void*)
 * @brief Esta funciones obtiene 2 direcciones de memoria y los compara
 * devuelve 2 tipos de ordenamiento por Sueldo.
 *
 * @param punteroUno: El puntero que apunta a la direccion de memomoria del 1er direccion.
 * @param punteroDos: El puntero que apunta a la direccion de memomoria del 2da direccion.
 *
 * @return Esta funcion retorna 1 si la la variable que fue asiganada "ueldoUno" es mayor a "sueldoDos" o -1 si la la variable que fue asiganada "sueldoUno" es menor a "sueldoDos"
 */
int Perrito_ordenarRaza(void* punteroUno, void* punteroDos);
int Perrito_ordenarPeso(void* punteroUno, void* punteroDos);
int Perrito_ordenarSexo(void* punteroUno, void* punteroDos);
int Perrito_ordenarPeso(void* punteroUno, void* punteroDos);

int Perrito_filtro_PerroPeso(void* this, float pesoGuia);

int Perrito_filtro_Comparacion(void* this, void* guia);
//int Perrito_filtroHembra(void* this);
int Perrito_filtroRazaRiver(void* this);
int Perrito_filtroPorEdad(void* this);
int Perrito_filtroSeLLamaKaile(void* this);
int Perrito_laQueMapea(void*);
int ePerrito_laQueFiltra(void*);
void Perrito_printDatacantidadComidaRacion(sPerrito* this);
//int Perrito_filtroMaleMenorCinco(void* this);
#endif // employee_H_INCLUDED
