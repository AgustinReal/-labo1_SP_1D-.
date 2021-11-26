#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this=NULL;

    this=(LinkedList*)malloc(sizeof(LinkedList));

    if(this!=NULL)
    {
    	this->size=0;
    	this->pFirstNode=NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux=-1;

    if(this!=NULL)
    {
    	returnAux=this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode=NULL;


	if(this!=NULL && nodeIndex>-1 && nodeIndex<ll_len(this))
	{
		pNode=(this->pFirstNode);

		for(int i=0;i<nodeIndex;i++)
		{
			pNode=pNode->pNextNode;
		}
	}

	return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux=-1;
    Node* auxNodeAnterior;
    Node* auxNodeAgregarNuevo;

    if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this)+1)
    {
    	auxNodeAgregarNuevo=(Node*)malloc(sizeof(Node));

		if(auxNodeAgregarNuevo!=NULL)
		{
			auxNodeAgregarNuevo->pElement=pElement;
			auxNodeAgregarNuevo->pNextNode=NULL;

			if(nodeIndex==0)
			{
				auxNodeAgregarNuevo->pNextNode=this->pFirstNode;
				this->pFirstNode=auxNodeAgregarNuevo;
			}
			else
			{
				auxNodeAnterior=getNode(this, nodeIndex-1);// no va
				auxNodeAgregarNuevo->pNextNode=auxNodeAnterior->pNextNode;
				auxNodeAnterior->pNextNode=auxNodeAgregarNuevo;
			}
			this->size++;
		}
		returnAux=0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this, nodeIndex, pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux=-1;

    if(this!=NULL)
    {
    	addNode(this, ll_len(this), pElement);

    	returnAux=0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* pElementReturn=NULL;
    Node* auxNode;

    if(this!=NULL && index>-1 && index<ll_len(this))
	{
    	auxNode=getNode(this, index);
    	pElementReturn=auxNode->pElement;
	}

    return pElementReturn;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index, void* pElement)
{
    int returnAux=-1;
    Node* auxNodeModificar;

    if(this!=NULL && index>-1 && index<ll_len(this))
    {
    	for(int i=0;i<ll_len(this);i++)
    	{
    		auxNodeModificar=getNode(this, index);
    		auxNodeModificar->pElement=pElement;
    		returnAux=0;
    	}
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this, int index)
{
    int returnAux=-1;
    Node* auxNodeElminar;
    Node* auxNodeAnterior;

    if(this!=NULL && index>-1 && index<ll_len(this))
    {
    	auxNodeElminar=getNode(this, index);
    	auxNodeAnterior=getNode(this, index-1);
    	if(auxNodeElminar!=NULL)
    	{
    		if(index==0)
    		{
    			this->pFirstNode=auxNodeElminar->pNextNode;
    		}
    		else
    		{
    			auxNodeAnterior->pNextNode=auxNodeElminar->pNextNode;
    		}
    		auxNodeElminar->pElement=NULL;
    		free(auxNodeElminar);
    		returnAux=0;
    		this->size--;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux=-1;


    if(this!=NULL)
    {
    	for(int i=0;i<ll_len(this);i++)
    	{
    		ll_remove(this, 0);
    	}

    	returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux=-1;

    if(this!=NULL)
    {
    	ll_clear(this);
    	this->pFirstNode=NULL;
    	free(this);
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux=-1;


    if(this!=NULL)
    {
    	for(int i=0;i<ll_len(this);i++)
    	{
    		if(pElement==ll_get(this,i))
    		{
    			returnAux=i;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux=-1;

    if(this!=NULL)
    {

    	if(ll_len(this)==0 && this->pFirstNode==NULL)
    	{
    		returnAux=1;
    	}
    	else
    	{
    		returnAux=0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux=-1;


    if(this!=NULL && index>-1 && index<ll_len(this)+1)
    {
    	addNode(this, index ,pElement);

    	returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this, int index)
{
    void* returnAux=NULL;

    Node* auxNodeEliminar;

    if(this!=NULL && index>-1 && index<ll_len(this))
    {
    	auxNodeEliminar=getNode(this, index);
    	returnAux=auxNodeEliminar->pElement;
    	ll_remove(this, index);

    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux=-1;
    void* pActualElement;

    if(this!=NULL)
    {
    	returnAux=0;
    	for(int i=0;i<ll_len(this);i++)
    	{
    		pActualElement=ll_get(this,i);
    		if(pElement==pActualElement)
    		{
    			returnAux=1;
    			break;//cuando encuentra el elemento deja de interar.
    		}

    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    int returnAux=-1;
    void* pElementListaUno;
    void* pElementListaDos;
    int cantidadElementosContenidos=0;

    if(this!=NULL && this2!=NULL)
    {
		returnAux=0;
		if(this2==this)
		{
			returnAux=1;
		}
		else if(this2>this)
		{
			returnAux=0;
		}
		else
		{
			for(int i=0;i<ll_len(this2);i++)
			{
				pElementListaUno=ll_get(this2,i);
				for(int j=0;j<ll_len(this);j++)
				{
					pElementListaDos=ll_get(this,j);
					if(pElementListaDos==pElementListaUno)
					{
						cantidadElementosContenidos++;
						break;
					}
				}
			}
			if(cantidadElementosContenidos==ll_len(this2))
			{
				returnAux=1;
			}
		}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this, int from, int to)
{
    LinkedList* cloneArray=NULL;
    void* pElementAux;


    if(this!=NULL && from>=0 && from<=ll_len(this) && to>=from && to<=ll_len(this))
    {
    	cloneArray=(LinkedList*)malloc(sizeof(LinkedList));

    	for(int i=from; i<=to;i++)
    	{
    		pElementAux=ll_get(this, i);
    		ll_add(cloneArray, pElementAux);
		}

    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray=NULL;

    if(this!=NULL)
    {
    	cloneArray=ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux =-1;
	    void* cosaUno;
	    void* cosaDos;
	    int len=ll_len(this);

		if (this!=NULL && pFunc!=NULL && order>=0 && order<=1)
	    {
			for (int i=0; i<len-1; i++)
	        {
	            //profe el proyecto que tenemos que hacer en el tp4 para utilizar todas las funciones de la linkedlist tiene que tener controller, parser y eso? o ya con utilizar las funciones en el main alcanza?

				for (int j=i+1; j<len; j++)
	            {
	                cosaUno=ll_get(this,i);
					cosaDos=ll_get(this,j);

					//si el orden es 1 es xq es ascendernte (el menor primero) y si la funcion retorna 1 es xq el primer elemnto es mayor al segundo
					// por lo que se debe ordenar, es decir lo que esta en la cosa uno debe ir en la cosa dos
					if (pFunc(cosaUno,cosaDos)==1 && order==1)
	                {
						ll_set(this,i,cosaDos); //lo que esta en el coso dos va al nodo uno
						ll_set(this,j,cosaUno);
					}
					else
	                {
	                    if (pFunc(cosaUno,cosaDos)==-1 && order==0)
	                    {
	                        ll_set(this,i,cosaDos);
	                        ll_set(this,j,cosaUno);
	                    }

					}
				}
			}
			 returnAux=0;
		}
	    return returnAux;

}
LinkedList* ll_map(LinkedList* miLista, int(*pFunc)(void*))
{
	void* pElement = NULL;

	int tam = ll_len(miLista);

	if(miLista != NULL && pFunc != NULL)
	{
		for(int i=0; i<tam; i++)
		{
			pElement = ll_get(miLista, i);
			pFunc(pElement); // setea los datos randoms
		}
	}
	return ll_clone(miLista);  // quiero mi lista nueva pero no quiero la lista vieja, es como si se copiaran todos los elementos
}
/**
 * @fn LinkedList ll_filter*(LinkedList*, int(*)(void*))
 * @brief Devuelve un nuevo Linkedlist cargado con los elementos que pasan la funcion filtro.
 *
 * @param LinkedList* this Linkedlist a filtrar.
 * @param int(*pFunc)(void*) puntero a la funcion que filtra.
 * @return nuevo puntero a LinkedList con los elementos que pasaron la funcion.
 */
LinkedList* ll_filter (LinkedList* this, int(*pFunc)(void*))
{
	LinkedList* filterlist=NULL;
	int tam;
	void* aux=NULL;
	if(this!=NULL && pFunc!=NULL)
	{
		filterlist=ll_newLinkedList();
		if(filterlist!=NULL)
		{
			tam=ll_len(this);
			for(int i=0;i<tam;i++)
			{
				aux=ll_get(this, i);
				if(pFunc(ll_get(this, i)))
				{
					if(ll_add(filterlist,  aux))
					{
						ll_deleteLinkedList(filterlist);
						filterlist=NULL;
						break;
					}
				}
			}
		}
	}

	return filterlist;
}
LinkedList* ll_filterString(LinkedList* this, char* string, int(*pFunc)(void*,char*))
{
	LinkedList* filterlist=NULL;
	    int tam;
	    void* aux=NULL;
	    if(this!=NULL && pFunc!=NULL)
	    {
	        filterlist=ll_newLinkedList();
	        if(filterlist!=NULL)
	        {
	            tam=ll_len(this);
	            for(int i=0;i<tam-1;i++)
	            {
	                aux=ll_get(this, i);
	                if(pFunc(ll_get(this, i),string))
	                {
	                    if(ll_add(filterlist,  aux))
	                    {
	                        ll_deleteLinkedList(filterlist);
	                        filterlist=NULL;
	                        break;
	                    }
	                }
	            }
	        }
	    }
	    return filterlist;
}

LinkedList* ll_filterInt(LinkedList* this, int entero, int(*pFunc)(void*,int))
{
	LinkedList* filterlist=NULL;
	    int tam;
	    void* aux=NULL;
	    if(this!=NULL && pFunc!=NULL)
	    {
	        filterlist=ll_newLinkedList();
	        if(filterlist!=NULL)
	        {
	            tam=ll_len(this);
	            for(int i=0;i<tam-1;i++)
	            {
	                aux=ll_get(this, i);
	                if(pFunc((ll_get(this, i)),entero))
	                {
	                    if(ll_add(filterlist,  aux))
	                    {
	                        ll_deleteLinkedList(filterlist);
	                        filterlist=NULL;
	                        break;
	                    }
	                }
	            }
	        }
	    }
	    return filterlist;
}

LinkedList* ll_filterFloat(LinkedList* this, float flotante , int(*pFunc)(void*,float))
{
	LinkedList* filterlist=NULL;
	    int tam;
	    void* aux=NULL;
	    if(this!=NULL && pFunc!=NULL)
	    {
	        filterlist=ll_newLinkedList();
	        if(filterlist!=NULL)
	        {
	            tam=ll_len(this);
	            for(int i=0;i<tam-1;i++)
	            {
	                aux=ll_get(this, i);
	                if(pFunc((ll_get(this, i)),flotante))
	                {
	                    if(ll_add(filterlist,  aux))
	                    {
	                        ll_deleteLinkedList(filterlist);
	                        filterlist=NULL;
	                        break;
	                    }
	                }
	            }
	        }
	    }
	    return filterlist;
}

LinkedList* ll_filterDosEstructuras(LinkedList* this, void* estructuraGuia , int(*pFunc)(void*,void*))
{
	LinkedList* filterlist=NULL;
	    int tam;
	    void* aux=NULL;
	    if(this!=NULL && pFunc!=NULL)
	    {
	        filterlist=ll_newLinkedList();
	        if(filterlist!=NULL)
	        {
	            tam=ll_len(this);
	            for(int i=0;i<tam-1;i++)
	            {
	                aux=ll_get(this, i);
	                if(pFunc((ll_get(this, i)),estructuraGuia))
	                {
	                    if(ll_add(filterlist,  aux))
	                    {
	                        ll_deleteLinkedList(filterlist);
	                        filterlist=NULL;
	                        break;
	                    }
	                }
	            }
	        }
	    }
	    return filterlist;
}
