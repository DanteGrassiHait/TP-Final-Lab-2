#include "headers.h"

///Cuerpo de las funciones del Sub-menu 3 de Menu Central de Administracion - Gestion Contable:
void CobrarCuotasDeSocios(char pagos[10],char asociados[10],char deportes[10])
{
    FILE* archi;
    FILE* varchi;
    FILE* xarchi;
    pago nuevo;
    int senial=-1;
    int cantSocios=0;
    socio socar;
    int cantDep=0;
    celda depar;
    char* fecha;
    time_t tAct=time(NULL);
    char control='s';

    while(control=='s')
    {
        fecha=asctime(localtime(&tAct));
        archi=fopen("pagos","ab");
        strcpy(nuevo.fecha,fecha);
        printf("Fecha: %s",nuevo.fecha);
        printf("DNI: ");
        scanf("%ld",&nuevo.dni);
        varchi=fopen("asociados","rb");
        fseek(varchi,0,SEEK_END);
        cantSocios=ftell(varchi)/sizeof(socio);
        if(cantSocios==0)
        {
            system("cls");
            system("color 0c");
            printf("Error! No hay socios cargados en el sistema.\n\n");
            system("pause");
            system("cls");
            nuevoMenuCentralADM();
        }
        fseek(varchi,0,SEEK_SET);
        while((fread(&socar,sizeof(socio),1,varchi)>0)&&(senial==-1))
        {
            if(socar.dni==nuevo.dni)
            {
                senial=1;
            }
            if((ftell(varchi)/sizeof(socio)==cantSocios)&&(socar.dni!=nuevo.dni))
            {
                system("cls");
                system("color 0c");
                printf("Error! El DNI ingresado no corresponde a ningun socio.\n\n");
                system("pause");
                system("cls");
                system("color 07");
                printf("Fecha: %s",nuevo.fecha);
                printf("\nDNI: ");
                scanf("%ld",&nuevo.dni);
                fseek(varchi,0,SEEK_SET);
            }
        }
        fclose(varchi);
        senial=-1;
        printf("Actividad/Deporte: ");
        fflush(stdin);
        gets(nuevo.actividad);
        xarchi=fopen("deportes","rb");
        fseek(xarchi,0,SEEK_END);
        cantDep=ftell(xarchi)/sizeof(celda);
        fseek(xarchi,0,SEEK_SET);
        while((fread(&depar,sizeof(celda),1,xarchi)>0)&&(senial==-1))
        {
            if(strcmp(depar.actividad,nuevo.actividad)==0)
            {
                senial=1;
                printf("Monto a cobrar: %.3f",depar.tarifa);
                nuevo.monto=depar.tarifa;
                printf("\n\n");
                system("pause");
            }
            if((ftell(xarchi)/sizeof(celda)==cantDep)&&(strcmp(depar.actividad,nuevo.actividad)!=0))
            {
                system("cls");
                system("color 0c");
                printf("Error! La actividad indicada no existe.\n\n");
                system("pause");
                system("cls");
                system("color 07");
                printf("Fecha: %s",nuevo.fecha);
                printf("\nDNI: %ld\n",nuevo.dni);
                printf("Actividad/Deporte: ");
                fflush(stdin);
                gets(nuevo.actividad);
                fseek(xarchi,0,SEEK_SET);
            }
        }
        fclose(xarchi);
        senial=-1;
        fwrite(&nuevo,sizeof(pago),1,archi);
        fclose(archi);
        control=Preguntar();
    }
}
void ListarPagosDeUnSocio(char pagos[10],char asociados[10])
{
    FILE* varchi;
    socio socar;
    int cantSocios=0;
    int senial=-1;
    long dni;
    nodo* lista;
    nodo* buscado;

    printf("Ingrese el DNI del socio que desea consultar su registro de pagos.\n\n");
    printf("DNI: ");
    scanf("%ld",&dni);
    varchi=fopen("asociados","rb");
    fseek(varchi,0,SEEK_END);
    cantSocios=ftell(varchi)/sizeof(socio);
    if(cantSocios==0)
    {
        system("cls");
        system("color 0c");
        printf("Error! No hay socios cargados en el sistema.\n\n");
        system("pause");
        system("cls");
        nuevoMenuCentralADM();
    }
    fseek(varchi,0,SEEK_SET);
    while((fread(&socar,sizeof(socio),1,varchi)>0)&&(senial==-1))
    {
        if(socar.dni==dni)
        {
            senial=1;
        }
        if((ftell(varchi)/sizeof(socio)==cantSocios)&&(socar.dni!=dni))
        {
            system("cls");
            system("color 0c");
            printf("Error! El DNI ingresado no corresponde a ningun socio.\n\n");
            system("pause");
            system("cls");
            system("color 07");
            printf("DNI: ");
            scanf("%ld",&dni);
            fseek(varchi,0,SEEK_SET);
        }
    }
    fclose(varchi);
    senial=-1;
    lista=inicLista();
    lista=PasarAsociadosAlista(asociados,lista);
    lista=VincularPagosAlistaDeSocios(pagos,lista);
    buscado=buscarNodoLista(lista,dni);
    system("cls");
    printf("Nombre y Apellido: %s",buscado->dato.nombreYapellido);
    printf("\nDNI: %ld",buscado->dato.dni);
    printf("\nEdad: %i",buscado->dato.edad);
    printf("\nActividad/Deporte: %s",buscado->dato.actividad);
    printf("\n*********************************\n");
    printf("\nRegistro Contable:\n\n");
    mostrarListaRecursivo2(buscado->registro);
    printf("\n\n");
    system("pause");
}
nodo* VincularPagosAlistaDeSocios(char pagos[10],nodo* lista)
{
    FILE* archi;
    pago aux;
    nodo* seg=lista;
    nodo2* nuevoNodo;

    archi=fopen("pagos","rb");
    while(fread(&aux,sizeof(pago),1,archi)>0)
    {
        seg=lista;
        while(seg!=NULL)
        {
            if(aux.dni==seg->dato.dni)
            {
                nuevoNodo=crearNodo2(aux);
                seg->registro=agregarAlprincipio2(seg->registro,nuevoNodo);
            }
            seg=seg->siguiente;
        }
    }
    fclose(archi);
    return lista;
}

