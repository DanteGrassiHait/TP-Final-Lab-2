#include "headers.h"

///Cuerpo de las funciones para listas dobles:
nodo2* inicLista2()
{
    return NULL;
}
nodo2* inicNodo2()
{
    return NULL;
}
nodo2* crearNodo2(pago dato)
{
    nodo2* aux=(nodo2*)malloc(sizeof(nodo2));
    aux->dato=dato;
    aux->anterior=inicNodo2();
    aux->siguiente=inicNodo2();

    return aux;
}
nodo2* agregarAlprincipio2(nodo2* lista,nodo2* nuevoNodo)
{
    nuevoNodo->siguiente=lista;
    if(lista!=NULL)
    {
        lista->anterior=nuevoNodo;
    }
    return nuevoNodo;
}
nodo2* buscarUltimo2(nodo2* lista)
{
    nodo2* seg=lista;
    if(seg!=NULL)
    {
        while(seg->siguiente!=NULL)
        {
            seg=seg->siguiente;
        }
    }
    return seg;
}
nodo2* agregarAlfinal2(nodo2* lista,nodo2* nuevoNodo)
{
    nodo2* ultimo;
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        ultimo=buscarUltimo2(lista);
        ultimo->siguiente=nuevoNodo;
        nuevoNodo->anterior=ultimo;
    }
    return lista;
}
void mostrarListaRecursivo2(nodo2* lista)
{
    nodo2* seg=lista;
    if(seg!=NULL)
    {
        printf("\nFecha: %s",seg->dato.fecha);
        printf("DNI: %ld",seg->dato.dni);
        printf("\nActividad/Deporte: %s",seg->dato.actividad);
        printf("\nMonto cobrado: %.3f",seg->dato.monto);
        printf("\n-----------------------------\n");
        mostrarListaRecursivo2(seg->siguiente);
    }
}
