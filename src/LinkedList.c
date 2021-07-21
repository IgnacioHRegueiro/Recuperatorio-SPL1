#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"





static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);


LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}



int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}



static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    if(this != NULL && ll_len(this) > 0 && nodeIndex < ll_len(this) && nodeIndex >= 0)
    {
        pNode = this->pFirstNode;
        for(int i=0;i< nodeIndex;i++)
        {
            pNode = pNode -> pNextNode;
        }
    }
    return pNode;
}


Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}



static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux;
    int len;
    Node* newNode;
    Node* prevNode;
    Node* nextNode;

    len = ll_len(this);
    prevNode = NULL;
    nextNode = NULL;

    returnAux = -1;

    if (this != NULL && nodeIndex <= len && nodeIndex >= 0)
    {
		newNode = (Node*)malloc(sizeof(Node));
		if (newNode != NULL)
		{
			newNode->pElement = pElement;
			newNode->pNextNode = NULL;
			if (nodeIndex == 0)
			{
				newNode->pNextNode = this->pFirstNode;
				this->pFirstNode = newNode; //
			}
			else
			{
				prevNode = getNode(this, nodeIndex-1);
				nextNode = prevNode->pNextNode;
				prevNode->pNextNode = newNode;
				newNode->pNextNode = nextNode;
			}
			this->size++;
			returnAux = 0;
		}
    }
    return returnAux;
}



int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}



int ll_add(LinkedList* this, void* pElement)
{
    int returnAux;
    int len;
	returnAux = -1;

    if(this!= NULL)
    {
    	len = ll_len(this);
        addNode(this,len,pElement);
        returnAux = 0;
    }
    return returnAux;
}



void* ll_get(LinkedList* this, int index)
{
	void* returnAux;
    Node* auxNode;
    int len;
	len = ll_len(this);
	returnAux = NULL;


    if(this != NULL && index >= 0 && index < len && len > 0)
    {
        auxNode = getNode(this,index);
        returnAux = auxNode->pElement;
    }
    return returnAux;
}



int ll_set(LinkedList* this, int index,void* pElement)
{
    int len;
    int returnAux;

	returnAux = -1;
    Node* auxNode;
    len = ll_len(this);

    if(this != NULL && index >= 0 && index < len && len > 0)
    {
        auxNode = getNode(this,index);
        auxNode->pElement = pElement;
        returnAux = 0;
    }

    return returnAux;
}



int ll_remove(LinkedList* this,int index)
{
    int len;
    int returnAux = -1;
    Node* auxNode;
    Node* prev;
    Node* next;
    len = ll_len(this);
    if(this != NULL && index >= 0 && index < len && len > 0)
    {
    	auxNode = getNode(this, index);

        if (index == 0)
        {
            this->pFirstNode = auxNode->pNextNode;
        }
        else
        {
			prev = getNode(this,index-1);
			next = getNode(this,index+1);
			prev->pNextNode = next;
        }

		free(auxNode);
		this->size--;
		returnAux = 0;
    }
    return returnAux;
}


int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
	int len;

    len = ll_len(this);
    if (this!=NULL)
    {
        for(i=0;i<len;i++)
        {
            ll_remove(this,0);
        }
        returnAux = 0;
    }
    return returnAux;
}


int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux;
	returnAux = -1;
    if (this!=NULL)
    {
        ll_clear(this);
        free(this);
        returnAux = 0;
    }
    return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
	int len;
	void* pElementAux;
    len = ll_len(this);

    if(this!=NULL)
    {
    	for(int i = 0; i<len; i++)
    	{
    		pElementAux = ll_get(this, i);
    		if(pElementAux == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }

    return returnAux;
}


int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len;


    if (this != NULL)
    {
    	len = ll_len(this);
    	returnAux = 0;
    	if(len == 0)
    	{
            returnAux = 1;
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
    int returnAux = -1;
    int len;
    len = ll_len(this);
    if (this != NULL && index>=0 && index <=len)
    {
    	addNode(this, index, pElement);
        returnAux = 0;
    }

    return returnAux;
}

void* ll_pop(LinkedList* this,int index)
{
    void* returnAux;
    void* auxElement;
    int len;
    len = ll_len(this);
    if (this != NULL && index>=0 && index <=len)
    {
        auxElement = ll_get(this,index);
        ll_remove(this,index);
        returnAux = auxElement;
    }
    return returnAux;
}



int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux;
    int i;
    int len;
    Node* current;

    returnAux = -1;
    len = ll_len(this);

    if (this != NULL)
    {
    	returnAux = 0;
        for (i=0;i<len;i++)
        {
            current = ll_get(this,i);
            if (current == pElement)
            {
                returnAux = 1;
            }
        }
    }
    return returnAux;
}


int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux;
    int i;
    void* auxElement;
    int len2;

    returnAux = -1;
    len2 = ll_len(this2);

    if (this != NULL && this2 != NULL)
    {
    	returnAux = 1;
        for(i=0;i<len2;i++)
        {
            auxElement = ll_get(this2,i);
            if(ll_contains(this,auxElement)==0)
            {
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}


LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneSubList;

    int i;
    void* auxElement;
    int len;
    len = ll_len(this);

    cloneSubList = NULL;

    if (this != NULL && from >= 0 && from <= len && this->size >= to && to<=len)
    {
        cloneSubList = ll_newLinkedList();
        for(i=from;i<to;i++)
        {
            auxElement = ll_get(this,i);
            ll_add(cloneSubList,auxElement);
        }
    }
    return cloneSubList;
}




LinkedList* ll_clone(LinkedList* this)
{

    LinkedList* cloneList;
    int len;
    len = ll_len(this);
    cloneList = NULL;

    if (this!=NULL)
    {
    	cloneList = ll_subList(this, 0, len);
    }
    return cloneList;
}


int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =  -1;
    int i;
    void* pElement1;
    void* pElement2;
    int bandera;
    int len;

    if(this!=NULL && (order == 0 || order == 1) && pFunc != NULL)
    {
        len = ll_len(this);
        do
        {
            bandera=0;
            for (i = 0; i < len-1; i++)
            {
                pElement1 = ll_get(this, i);
                pElement2 = ll_get(this, i + 1);
                if( ((pFunc(pElement1, pElement2) < 0) && order == 0) ||
                    ((pFunc(pElement1, pElement2) > 0) && order == 1) )
                {
                    bandera=1;
                    ll_set(this, i, pElement2);
                    ll_set(this, i + 1, pElement1);
                }
            }
        }while(bandera == 1);
        returnAux=0;
    }
    return returnAux;
}

int ll_count(LinkedList* this, int (*pFunc)(void*))
{
	int contador = 0;

	if(this!=NULL && pFunc != NULL)
	{
		int len = ll_len(this);
		void* pElement;


		for(int i = 0; i<len; i++)
		{
			pElement = ll_get(this, i);

			contador+=pFunc(pElement);
		}
	}
	return contador;

}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
	LinkedList* FilteredList = NULL;

	if(this!=NULL && pFunc != NULL)
	{
		FilteredList = ll_newLinkedList();
		int len = ll_len(this);
		void* pElement;

		for(int i = 0; i<len; i++)
		{
			pElement = ll_get(this, i);
			if(pFunc(pElement) == 1)
			{
				ll_add(FilteredList, pElement);
			}
		}
	}


	return FilteredList;
}


