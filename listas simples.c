#include "headers.h"

///Cuerpo de las funciones para listas simples:
nodo* inicLista()
{
    return NULL;
}
nodo* inicNodoLista()
{
    return NULL;
}
nodo* crearNodoLista(socio dato)
{
    nodo* aux=(nodo*)malloc(sizeof(nodo));
    aux->dato=dato;
    aux->siguiente=inicNodoLista();
    aux->registro=inicLista2();
    return aux;
}
nodo* buscarUltimoLista(nodo* lista)
{
    nodo* seg=lista;
    if(seg!=NULL)
    {
        while(seg->siguiente!=NULL)
        {
            seg=seg->siguiente;
        }
    }
    return seg;
}
nodo* agregarAlprincipioLista(nodo* lista,nodo* nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente=lista;
        lista=nuevoNodo;
    }
    return lista;
}
nodo* buscarNodoLista(nodo* lista,long dni)
{
    nodo* seg=lista;
    while((seg!=NULL)&&(dni!=seg->dato.dni))
    {
        seg=seg->siguiente;
    }
    return seg;
}
nodo* agregarAlfinalLista(nodo* lista,nodo* nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        nodo* ultimo=buscarUltimoLista(lista);
        ultimo->siguiente=nuevoNodo;
    }
    return lista;
}
nodo* agregarEnordenLista(nodo* lista,nodo* nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        if(nuevoNodo->dato.edad<lista->dato.edad)
        {
            lista=agregarAlprincipioLista(lista,nuevoNodo);
        }
        else
        {
            nodo* ante=lista;
            nodo* aux=lista;
            while((aux!=NULL)&&(nuevoNodo->dato.edad>aux->dato.edad))
            {
                ante=aux;
                aux=ante->siguiente;
            }
            ante->siguiente=nuevoNodo;
            nuevoNodo->siguiente=aux;
        }
    }
    return lista;
}
nodo* borrarNodo(nodo* lista,long dni)
{
    nodo* seg;
    nodo* ante;
    if((lista!=NULL)&&(dni==lista->dato.dni))
    {
        nodo* aux=lista;
        lista=lista->siguiente;
        free(aux);
    }
    else
    {
        seg=lista;
        while((seg!=NULL)&&(dni!=seg->dato.dni))
        {
            ante=seg;
            seg=seg->siguiente;
        }
        if(seg!=NULL)
        {
            ante->siguiente=seg->siguiente;
            free(seg);
        }
    }
    return lista;
}
void mostrarListaRecursivo(nodo* lista)
{
    nodo* seg=lista;
    if(seg!=NULL)
    {
        printf("Nombre y Apellido: %s",seg->dato.nombreYapellido);
        printf("\nDNI: %ld",seg->dato.dni);
        printf("\nEdad: %i",seg->dato.edad);
        printf("\nActividad: %s",seg->dato.actividad);
        printf("\n-----------------------------\n");
        mostrarListaRecursivo(seg->siguiente);
    }
}
