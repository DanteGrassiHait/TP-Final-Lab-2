#include "headers.h"

///Menu Interactivo
void nuevoMenuLogin()
{
    int colorNormal=15;
    int colorSobre=11;
    char cuentas[10];
    char asociados[10];
    char deportes[10];
    char pagos[10];
    int candado=-1;
    char control='s';
    char opcion, opcion2;
    int y=7;
    do
    {
        system("cls");
        color(10);///letra verde/ fondo negro
        printf("BIENVENIDO!!\n\n\n");
        color(colorNormal);///letra blanca/ fondo negro
        if(y==7)
            color(colorSobre);
        printf("Iniciar Sesion\n");
        color(colorNormal);
        if(y==10)
            color(colorSobre);
        printf("Cifrar Sistema\n");
        color(colorNormal);
        if(y==13)
            color(colorSobre);
        printf("Formatear Sistema\n");
        color(colorNormal);
        if(y==16)
            color(colorSobre);
        printf("Salir");
        ///-----------------------
        opcion=getch();///retorna el numero del codigo ascii de la tecla ingresada
        if(opcion==80)///tecla de abajo
        {
            if(y==16)
            {
                y=7;
            }
            else
            {
                y=y+3;
            }
        }
        if(opcion==72)///tecla de arriba
        {
            if(y==7)
            {
                y=16;
            }
            else
            {
                y=y-3;
            }
        }
        if(opcion==13)///tecla ENTER
        {
            system("cls");
            if(y==7)
            {
                candado=IniciarSesion(cuentas);
                if(candado==-1)
                {
                    system("cls");
                    system("color 0f");
                    printf("------------->Fin del programa<-------------\n\n");
                }
                else
                {
                    nuevoMenuCentralADM();
                }
            }
            if(y==10)
            {
                CrearCifrado(cuentas);
            }
            if(y==13)
            {
                FormatearSistema(cuentas,asociados,deportes,pagos);
            }
            if(y==16)
            {
                control='s';
                control=PreguntarSalida();
                if(control!='s')
                    nuevoMenuLogin();
                break;
            }
        }
    }
    while(1);

    return 0;
}
void nuevoMenuCentralADM()
{
    int colorNormal=15;
    int colorSobre=11; ///color con el que se va a mover
    ///----------Variables--para--gestion--de--socios--------------
    char asociados[10]; ///archivo de socios
    nodo* listaSocios;
    ///----------Variables--para--gestion--de--actividades---------
    char deportes[10]; ///archivo de actividades
    celda ArrayActs[100];
    ///----------Variables--para--gestion--contable----------------
    char pagos[10];
    int y=18, opcion2=0;
    char control='s';
    do
    {
        system("cls");
        color(colorNormal);
        if(y==18)
            color(colorSobre);
        printf("Gestionar Socios\n");
        color(colorNormal);
        if(y==21)
            color(colorSobre);
        printf("Gestionar Actividades\n");
        color(colorNormal);
        if(y==24)
            color(colorSobre);
        printf("Gestion Contable\n");
        color(colorNormal);
        if(y==27)
            color(colorSobre);
        printf("Cerrar Sesion\n");
        opcion2=getch();
        if(opcion2==80)///tecla de abajo
        {
            if(y==27)
            {
                y=18;
            }
            else
            {
                y=y+3;
            }
        }
        if(opcion2==72)///tecla de arriba
        {
            if(y==18)
            {
                y=27;
            }
            else
            {
                y=y-3;
            }
        }
        if(opcion2==13)///tecla enter
        {
            system("cls");
            if(y==18)/// Gestionar Socios
            {
                y=30;
                do
                {
                    system("cls");
                    color(colorNormal);
                    if(y==30)
                        color(colorSobre);
                    printf("Dar de Alta un Socio\n");
                    color(colorNormal);
                    if(y==33)
                        color(colorSobre);
                    printf("Modificar un Socio\n");
                    color(colorNormal);
                    if(y==36)
                        color(colorSobre);
                    printf("Dar de Baja un Socio\n");
                    color(colorNormal);
                    if(y==39)
                        color(colorSobre);
                    printf("Listar Socios\n");
                    color(colorNormal);
                    if(y==42)
                        color(colorSobre);
                    printf("Volver\n");
                    color(colorNormal);
                    if(y==45)
                        color(colorSobre);
                    printf("Cerrar Sesion\n");
                    opcion2=getch();
                    if(opcion2==80)///tecla de abajo
                    {
                        if(y==45)
                        {
                            y=30;
                        }
                        else
                        {
                            y=y+3;
                        }
                    }
                    if(opcion2==72)///tecla de arriba
                    {
                        if(y==30)
                        {
                            y=45;
                        }
                        else
                        {
                            y=y-3;
                        }
                    }
                    if(opcion2==13)
                    {
                        if(y==30)
                        {
                            system("cls");
                            CargarSocios(asociados,deportes);
                            nuevoMenuCentralADM();
                            break;
                        }
                        if(y==33)
                        {
                            system("cls");
                            ModificarSocio(asociados);
                            nuevoMenuCentralADM();
                            break;
                        }
                        if(y==36)
                        {
                            system("cls");
                            DarBajaSocio(asociados);
                            nuevoMenuCentralADM();
                            break;
                        }
                        if(y==39)
                        {
                            system("cls");
                            listaSocios=inicLista();
                            listaSocios=PasarAsociadosAlista(asociados,listaSocios);
                            printf("Lista de socios afiliados:\n\n\n");
                            mostrarListaRecursivo(listaSocios);
                            printf("\n\n");
                            system("pause");
                            system("cls");
                            nuevoMenuCentralADM();
                            break;
                        }
                        if(y==42)
                        {
                            system("cls");
                            nuevoMenuCentralADM();
                            break;
                        }
                        if(y==45)
                        {
                            system("cls");
                            control='s';
                            control=PreguntarSalida();
                            if(control=='s')
                                nuevoMenuLogin();
                            else
                                nuevoMenuCentralADM();
                            break;
                        }
                    }
                }
                while(1);
            }
            if(y==21)/// Gestionar Actividades
            {
                y=48;
                do
                {
                    system("cls");
                    color(colorNormal);
                    if(y==48)
                        color(colorSobre);
                    printf("Dar de Alta una Actividad\n");
                    color(colorNormal);
                    if(y==51)
                        color(colorSobre);
                    printf("Modificar una Actividad\n");
                    color(colorNormal);
                    if(y==54)
                        color(colorSobre);
                    printf("Dar de Baja una Actividad\n");
                    color(colorNormal);
                    if(y==57)
                        color(colorSobre);
                    printf("Listar Actividades\n");
                    color(colorNormal);
                    if(y==60)
                        color(colorSobre);
                    printf("Listar Socios por Actividad\n");
                    color(colorNormal);
                    if(y==63)
                        color(colorSobre);
                    printf("Volver\n");
                    color(colorNormal);
                    if(y==66)
                        color(colorSobre);
                    printf("Cerrar Sesion\n");
                    opcion2=getch();
                    if(opcion2==80)///tecla de abajo
                    {
                        if(y==66)
                        {
                            y=48;
                        }
                        else
                        {
                            y=y+3;
                        }
                    }
                    if(opcion2==72)///tecla de arriba
                    {
                        if(y==48)
                        {
                            y=66;
                        }
                        else
                        {
                            y=y-3;
                        }
                    }
                    if(opcion2==13)
                    {
                        if(y==48)
                        {
                            system("cls");
                            CargarActividadesNuevas(deportes);
                            nuevoMenuCentralADM();
                            break;
                        }
                        if(y==51)
                        {
                            system("cls");
                            ModificarActividad(deportes,ArrayActs);
                            nuevoMenuCentralADM();
                            break;
                        }
                        if(y==54)
                        {
                            DarBajaActividad(deportes,ArrayActs);
                            nuevoMenuCentralADM();
                            break;
                        }
                        if(y==57)
                        {
                            system("cls");
                            ListarActividades(deportes,ArrayActs);
                            nuevoMenuCentralADM();
                            break;
                        }
                        if(y==60)
                        {
                            system("cls");
                            ListarSociosPorActividades(asociados,deportes,ArrayActs);
                            nuevoMenuCentralADM();
                            break;
                        }
                        if(y==63)
                        {
                            system("cls");
                            nuevoMenuCentralADM();
                            break;
                        }
                        if(y==66)
                        {
                            system("cls");
                            control='s';
                            control=PreguntarSalida();
                            if(control=='s')
                                nuevoMenuLogin();
                            else
                                nuevoMenuCentralADM();
                            break;
                        }
                    }
                }
                while(1);
            }
            if(y==24)/// Gestion Contable
            {
                y=69;
                do
                {
                    system("cls");
                    color(colorNormal);
                    if(y==69)
                        color(colorSobre);
                    printf("Cobrar Cuotas\n");
                    color(colorNormal);
                    if(y==72)
                        color(colorSobre);
                    printf("Listar Pagos de un Socio\n");
                    color(colorNormal);
                    if(y==75)
                        color(colorSobre);
                    printf("Hacer\n");
                    color(colorNormal);
                    if(y==78)
                        color(colorSobre);
                    printf("Volver\n");
                    color(colorNormal);
                    if(y==81)
                        color(colorSobre);
                    printf("Cerrar Sesion\n");
                    opcion2=getch();
                    if(opcion2==80)///tecla de abajo
                    {
                        if(y==81)
                        {
                            y=69;
                        }
                        else
                        {
                            y=y+3;
                        }
                    }
                    if(opcion2==72)///tecla de arriba
                    {
                        if(y==69)
                        {
                            y=81;
                        }
                        else
                        {
                            y=y-3;
                        }
                    }
                    if(opcion2==13)
                    {
                        if(y==69)
                        {
                            system("cls");
                            CobrarCuotasDeSocios(pagos,asociados,deportes);
                            nuevoMenuCentralADM();
                            break;
                        }
                        if(y==72)
                        {
                            system("cls");
                            ListarPagosDeUnSocio(pagos,asociados);
                            nuevoMenuCentralADM();
                            break;
                        }
                        if(y==75)
                        {
                            system("cls");
                            break;
                        }
                        if(y==78)
                        {
                            system("cls");
                            nuevoMenuCentralADM();
                            break;
                        }
                        if(y==81)
                        {
                            system("cls");
                            control='s';
                            control=PreguntarSalida();
                            if(control=='s')
                                nuevoMenuLogin();
                            else
                                nuevoMenuCentralADM();
                            break;
                        }
                    }
                }
                while(1);
            }
            if(y==27)/// Cerrar Sesion
            {
                control='s';
                control=PreguntarSalida();
                if(control=='s')
                    nuevoMenuLogin();
                else
                    nuevoMenuCentralADM();
                break;
            }
        }
    }
    while(1);
}
void color(int x)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}

///Cuerpo de las funciones del menu login:
void CrearCifrado(char cuentas[10])
{
    FILE* archi;
    cuenta nueva;

    archi=fopen("cuentas","a+b");
    fseek(archi,0,SEEK_END);
    if(ftell(archi)/sizeof(cuenta)==0)
    {
        printf("Usuario: ");
        fflush(stdin);
        gets(nueva.usuario);
        printf("Clave: ");
        fflush(stdin);
        gets(nueva.clave);
        printf("Confirmacion de clave: ");
        fflush(stdin);
        gets(nueva.reclave);
        while(strcmp(nueva.clave,nueva.reclave)!=0)
        {
            system("cls");
            system("color 0c");
            printf("Error! Las claves ingresadas no coinciden.\n\n");
            system("pause");
            system("cls");
            system("color 07");
            printf("Usuario: %s\n",nueva.usuario);
            printf("Clave: ");
            fflush(stdin);
            gets(nueva.clave);
            printf("Confirmacion de clave: ");
            fflush(stdin);
            gets(nueva.reclave);
        }
        fwrite(&nueva,sizeof(cuenta),1,archi);
        system("cls");
        system("color 0a");
        printf("El sistema se ha cifrado correctamente!\n\n");
        system("pause");
        system("cls");
        system("color 07");
    }
    else
    {
        system("cls");
        system("color 0c");
        printf("Error! El sistema ya se encuentra cifrado.\n\n");
        system("pause");
        system("cls");
        system("color 07");
    }
    fclose(archi);
    nuevoMenuLogin();
}
void FormatearSistema(char cuentas[10],char asociados[10],char deportes[10],char pagos[10])
{
    FILE* archi;
    FILE* archiS;
    FILE* archiD;
    FILE* archiP;
    cuenta nueva;
    char control='s';
    int candado=1;

    printf("Requisito de Seguridad:\n\n");
    printf("Introduza los datos de cifrado del sistema actuales.\n\n");
    candado=IniciarSesion(cuentas);
    if(candado==1)
    {
        system("cls");
        system("color 0c");
        printf("Advertencia: usted va a restaurar el sistema.\n\n\n-Esta accion implica:\n\n-Perdida de la informacion almacenada.\n-Nuevo cifrado del programa.\n\n");
        printf("Desea continuar realmente?(S/N): ");
        fflush(stdin);
        scanf("%c",&control);
        system("cls");
        system("color 07");
        if(control=='s')
        {
            archi=fopen("cuentas","w+b");
            printf("A continuacion rellene los campos:\n\n");
            printf("Usuario: ");
            fflush(stdin);
            gets(nueva.usuario);
            printf("Clave: ");
            fflush(stdin);
            gets(nueva.clave);
            printf("Confirmacion de clave: ");
            fflush(stdin);
            gets(nueva.reclave);
            while(strcmp(nueva.clave,nueva.reclave)!=0)
            {
                system("cls");
                system("color 0c");
                printf("Error! Las claves ingresadas no coinciden.\n\n");
                system("pause");
                system("cls");
                system("color 07");
                printf("Usuario: %s\n",nueva.usuario);
                printf("Clave: ");
                fflush(stdin);
                gets(nueva.clave);
                printf("Confirmacion de clave: ");
                fflush(stdin);
                gets(nueva.reclave);
            }
            fwrite(&nueva,sizeof(cuenta),1,archi);
            fclose(archi);
            archiS=fopen("asociados","wb");
            fclose(archiS);
            archiD=fopen("deportes","wb");
            fclose(archiD);
            archiP=fopen("pagos","wb");
            fclose(archiP);
            system("cls");
            system("color 0a");
            printf("El sistema se ha restaurado correctamente!\n\n");
            system("pause");
            system("cls");
            system("color 07");
            nuevoMenuLogin();
        }
        else
        {
            nuevoMenuLogin();
        }
    }
    else
    {
        nuevoMenuLogin();
    }
}
int IniciarSesion(char cuentas[10])
{
    cuenta aux,aux2;
    FILE* archi;
    int intentos=1,rta=-1;

    printf("Nombre de usuario: ");
    fflush(stdin);
    gets(aux.usuario);
    printf("Clave: ");
    fflush(stdin);
    gets(aux.clave);
    archi=fopen("cuentas","rb");
    while((fread(&aux2,sizeof(cuenta),1,archi)>0)&&(intentos<4)&&(rta!=1))
    {
        if((strcmp(aux.usuario,aux2.usuario)==0)&&(strcmp(aux.clave,aux2.clave)==0))
        {
            rta=1;
        }
        else
        {
            system("cls");
            system("color 0c");
            printf("Error! El nombre de usuario y la clave no coinciden.\n\n");
            printf("Van %i/3 intentos!\n\n",intentos);
            intentos++;
            if(intentos==3)
            {
                printf("Advertencia: ultimo intento!\n\n");
            }
            if(intentos<=3)
            {
                system("pause");
                system("cls");
                system("color 07");
                printf("Nombre de usuario: ");
                fflush(stdin);
                gets(aux.usuario);
                printf("Clave: ");
                fflush(stdin);
                gets(aux.clave);
            }
        }
        fseek(archi,0,SEEK_SET);
    }
    fclose(archi);
    return rta;
}

///Cuerpo de las funciones de eleccion:
char Preguntar()
{
    char control='s';
    system("cls");
    printf("Desea continuar?(S/N): ");
    fflush(stdin);
    scanf("%c",&control);
    system("cls");
    return control;
}
char PreguntarSalida()
{
    char control='s';
    system("cls");
    system("color 0c");
    printf("Seguro desea salir?(S/N): ");
    fflush(stdin);
    scanf("%c",&control);
    system("cls");
    system("color 07");
    return control;
}
int SeleccionarOpcion()
{
    int opc;
    printf("\n\nSeleccione una opcion: ");
    scanf("%i",&opc);
    system("cls");
    return opc;
}
