#include "headers.h"

///Cuerpo de las funciones del Sub-menu 1 de Menu Central de Administracion - Gestion de Socios:
void CargarSocios(char asociados[10],char deportes[10])
{
    FILE* archi;
    FILE* xarchi;
    socio nuevo;
    socio aux;
    celda aux2;
    int senial=-1;
    int cantDep=0;
    char control='s';


    while(control=='s')
    {
        archi=fopen("asociados","a+b");
        printf("A continuacion rellene los campos:\n\n");
        printf("Nombre y Apellido: ");
        fflush(stdin);
        gets(nuevo.nombreYapellido);
        printf("DNI: ");
        scanf("%ld",&nuevo.dni);
        while(fread(&aux,sizeof(socio),1,archi)>0)
        {
            while(aux.dni==nuevo.dni)
            {
                system("cls");
                system("color 0c");
                printf("Error! DNI ya en uso.\n\n");
                system("pause");
                system("cls");
                system("color 07");
                printf("Nombre y Apellido: %s\n",nuevo.nombreYapellido);
                printf("DNI: ");
                scanf("%ld",&nuevo.dni);
                fseek(archi,0,SEEK_SET);
            }
        }
        printf("Edad: ");
        scanf("%i",&nuevo.edad);
        printf("Actividad/Deporte: ");
        fflush(stdin);
        gets(nuevo.actividad);
        xarchi=fopen("deportes","rb");
        fseek(xarchi,0,SEEK_END);
        cantDep=ftell(xarchi)/sizeof(celda);
        if(cantDep==0)
        {
            system("cls");
            system("color 0c");
            printf("Error! No hay actividades/deportes cargados en el sistema.\n\n");
            system("pause");
            system("cls");
            nuevoMenuCentralADM();
        }
        fseek(xarchi,0,SEEK_SET);
        while((fread(&aux2,sizeof(celda),1,xarchi)>0)&&(senial==-1))
        {
            if(strcmp(aux2.actividad,nuevo.actividad)==0)
            {
                senial=1;
            }
            if((ftell(xarchi)/sizeof(celda)==cantDep)&&(strcmp(aux2.actividad,nuevo.actividad)!=0))
            {
                system("cls");
                system("color 0c");
                printf("Error! La actividad indicada no existe.\n\n");
                system("pause");
                system("cls");
                system("color 07");
                printf("Nombre y Apellido: %s\n",nuevo.nombreYapellido);
                printf("DNI: %ld\n",nuevo.dni);
                printf("Edad: %i\n",nuevo.edad);
                printf("Actividad/Deporte: ");
                fflush(stdin);
                gets(nuevo.actividad);
                fseek(xarchi,0,SEEK_SET);
            }
        }
        fclose(xarchi);
        fwrite(&nuevo,sizeof(socio),1,archi);
        fclose(archi);
        control=Preguntar();
        senial=-1;
    }
}
void ModificarSocio(char asociados[10])
{
    nodo* lista;
    long dni;
    nodo* buscado;

    lista=inicLista();
    lista=PasarAsociadosAlista(asociados,lista);
    printf("Ingrese el DNI del socio que desea modificar.\n\n");
    printf("DNI: ");
    scanf("%ld",&dni);
    buscado=buscarNodoLista(lista,dni);
    if(buscado==NULL)
    {
        system("cls");
        system("color 0c");
        printf("El socio no ha sido encontrado!\n\n");
        system("pause");
        system("cls");
        system("color 07");
        nuevoMenuCentralADM();
    }
    else
    {
        system("cls");
        printf("Nombre y Apellido: ");
        fflush(stdin);
        gets(buscado->dato.nombreYapellido);
        printf("Edad: ");
        scanf("%i",&buscado->dato.edad);
        printf("Actividad/Deporte: ");
        fflush(stdin);
        gets(buscado->dato.actividad);
        system("cls");
        system("color 0a");
        printf("El socio se ha modificado correctamente!\n\n");
        system("pause");
        system("cls");
        system("color 07");
    }
    PasarDeListaAasociados(asociados,lista);
}
nodo* PasarAsociadosAlista(char asociados[10],nodo* lista)
{
    FILE* archi;
    nodo* nuevoNodo;
    socio aux;

    archi=fopen("asociados","rb");
    while(fread(&aux,sizeof(socio),1,archi)>0)
    {
        nuevoNodo=crearNodoLista(aux);
        lista=agregarEnordenLista(lista,nuevoNodo);
    }
    fclose(archi);
    return lista;
}
void PasarDeListaAasociados(char asociados[10],nodo* lista)
{
    FILE* archi;
    socio aux;

    archi=fopen("asociados","wb");
    while(lista!=NULL)
    {
        aux=lista->dato;
        fwrite(&aux,sizeof(socio),1,archi);
        lista=lista->siguiente;
    }
    fclose(archi);
}
void DarBajaSocio(char asociados[10])
{
    nodo* lista;
    long dni;
    nodo* buscado;

    lista=inicLista();
    lista=PasarAsociadosAlista(asociados,lista);
    printf("Ingrese el DNI del socio que desea dar de baja.\n\n");
    printf("DNI: ");
    scanf("%ld",&dni);
    buscado=buscarNodoLista(lista,dni);
    if(buscado==NULL)
    {
        system("cls");
        system("color 0c");
        printf("El socio ha dar de baja no ha sido encontrado!\n\n");
        system("pause");
        system("cls");
        system("color 07");
        nuevoMenuCentralADM();
    }
    else
    {
        lista=borrarNodo(lista,dni);
        system("cls");
        system("color 0a");
        printf("El socio se ha dado de baja correctamente!\n\n");
        system("pause");
        system("cls");
        system("color 07");
    }
    PasarDeListaAasociados(asociados,lista);
}
