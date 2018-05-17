#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "persona.h"
#include "utn.h"

#define DEFINE_DEL_ARCHIVO  "hola"

//Funciones privadas
static int proximoId(void);
static int buscarLugarLibre(Persona* array,int limite);
//__________________



/** \brief inicializa un array
 * \param array Persona*
 * \param limite int
 * \return int
 *
 */
int persona_init(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}
/** \brief imprime por pantalla el array de personas con debug
 * \param array Persona*
 * \param limite int
 * \return int
 *
 */
int persona_mostrarDebug(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %s - %s- %s - %d\n",array[i].idPersona, array[i].nombre,array[i].apellido,array[i].elCuit, array[i].isEmpty);
        }
    }
    return retorno;
}
/** \brief imprime por pantalla el array de personas
 * \param array Persona*
 * \param limite int
 * \return int
 *
 */
int persona_mostrar(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - ID cliente: %d - Nombre: %s- Apellido: %s- Cuit: %s - Is empty:%d\n",array[i].idPersona, array[i].nombre,array[i].apellido,array[i].elCuit,array[i].isEmpty);
        }
    }
    return retorno;
}
/** \brief da de alta a una persona
 * \param array Persona*
 * \param limite int
 * \return int
 *
 */
int persona_alta(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char apellido[50];
    char elCuit[50];


        if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nIngrese el nombre: ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                if(!getValidString("\nIngrese el apellido: ","\nEso no es un apellido","El maximo es 40",apellido,40,2))
                {
                  getString("\nIngrese el cuit: ",elCuit);
                        {
                            retorno = 0;
                            strcpy(array[i].nombre,nombre);
                            strcpy(array[i].apellido,apellido);
                            strcpy(array[i].elCuit,elCuit);
                            array[i].idPersona = proximoId();
                            printf("\nID DE USUARIO ES: %d",array[i].idPersona);
                            array[i].isEmpty = 0;
                        }
                }
            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}
/** \brief da de baja a una persona
 * \param array Persona*
 * \param limite int
 * \return int
 *
 */

int persona_baja(Persona* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = persona_buscarPorId(array,limite,id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}
/** \brief modifica a una personas
 * \param array Persona*
 * \param limite int
  * \param Id
 * \return int
 *
 */
int persona_modificacion(Persona* array,int limite, int id)
{

    int indiceAModificar;
    int retorno = -1;
    int i;
    char nombre[50];
    char apellido[50];
    char elCuit[50];



    indiceAModificar = persona_buscarPorId(array,limite,id);
    if(indiceAModificar>=0)
    {

            if(!getValidString("\nIngrese el nuevo nombre ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                if(!getValidString("\nIngrese el nuevo apellido? ","\nEso no es un apellido","El maximo es 40",apellido,40,2))
                 {
                    getString("\nIngrese el nuevo cuit?",elCuit);

                        {
                            retorno = 0;
                            strcpy(array[i].nombre,nombre);
                            strcpy(array[i].apellido,apellido);
                            strcpy(array[i].elCuit,elCuit);
                             array[i].idPersona = proximoId();
                            array[i].isEmpty = 0;
                        }

                }
            }


        else
        {
            retorno = -3;
        }
    }
    return retorno;
}
/** \brief recibe un array y lo ordena a una persona
 * \param array Persona*
 * \param limite int
  * \param numero de orden
 * \return int
 *
 */
int persona_ordenar(Persona* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Persona auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}
/** \brief recibe un array y busca el primer lugar libre
 * \param array Persona*
 * \param limite int
 * \return int
 *
 */

static int buscarLugarLibre(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief genera el proximo id
 * \param no recibe nada
 * \return int
 *
 */

static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

/** \brief recibe un id y encuentra a la persona
 * \param array Persona*
 * \param limite int
 * \param limite id
 * \return int
 *
 */
int persona_buscarPorId(Persona* array,int limite, int id)

{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPersona==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}




