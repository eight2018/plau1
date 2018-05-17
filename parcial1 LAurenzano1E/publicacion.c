#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "utn.h"
#include "persona.h"



//Funciones privadas
static int proximoId(void);
static int buscarPorId(Publicacion* array,int limite, int id);
static int buscarLugarLibre(Publicacion* array,int limite);
//__________________



/** \brief inicializa un array
 * \param array Persona*
 * \param limite int
 * \return int
 *
 */
int cont_init(Publicacion* array,int limite)
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

/** \brief imprime por pantalla el array de publicaciones con debug
 * \param array Publicacion*
 * \param limite int
 * \return int
 *
 */
int cont_mostrarDebug(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            //printf("[DEBUG] - %d - %s - %s - %d - %d\n",array[i].id, array[i].cuit,array[i].archivo,array[i].dias, array[i].isEmpty);
        }
    }
    return retorno;
}
/** \brief imprime por pantalla el array de publicaciones
 * \param array Publicacion*
 * \param limite int
 * \return int
 *
 */
int cont_mostrar(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - ID de Publicacion: %d - Rubro: %s - Texto: %s - Estado:%d  (1:activo 2:inactivo):  - Is Empty: %d\n",array[i].id, array[i].cuit,array[i].archivo,array[i].dias, array[i].isEmpty);
        }
    }
    return retorno;
}
/** \brief da de alta a una publicacion
 * \param array Publicacion*
 * \param limite int
 * \param array Persona*
 * \param lenPersonas int

 * \return int
 *
 */
 int cont_alta(Publicacion* arrayC,int limite,
              Persona* personas, int lenPersonas)
{
    int retorno = -1;
    int i;
    int idPant;
    int posPant;
    int diaAux=1;
    char archivoAux[64];
    char cuitAux[64];
    if(limite > 0 && arrayC != NULL)
    {
        i = buscarLugarLibre(arrayC,limite);
        if(i >= 0)
        {

            getValidInt("ID?","\nNumero no valido\n",&idPant,0,999999,2);
            posPant = persona_buscarPorId(personas,lenPersonas,idPant);
            if(posPant>=0)
            {


                printf("\nPublicacion Activa: %d",diaAux);


                {
                  if (!getValidString("\nEscriba el texto: ","\nTexto no valido","Texto Demasiado Largo",archivoAux,64,2))
                 {
                    getString("\nIndique rubro(5=electro 6=bazar): ",cuitAux);
                   {

                    arrayC[i].dias = diaAux;
                    strcpy(arrayC[i].archivo,archivoAux);
                    strcpy(arrayC[i].cuit,cuitAux);
                    arrayC[i].idPersona = idPant; // relacion
                    arrayC[i].isEmpty=0;
                    arrayC[i].id = proximoId();
                    printf("\nID de publicacion: %d",arrayC[i].id);
                    }
                   }
                }
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}
/** \brief da de baja a una publicacion
 * \param array Publicacion*
 * \param limite int
 * \param int id
 * \return int
 *
 */

int cont_baja(Publicacion* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = buscarPorId(array,limite,id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}
/** \brief recibe un array y busca el primer lugar libre
 * \param array Publicacion*
 * \param limite int
 * \return int
 *
 */

static int buscarLugarLibre(Publicacion* array,int limite)
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
/** \brief recibe un id y encuentra a la publicacion
 * \param array Publi*
 * \param limite int
 * \param limite id
 * \return int
 *
 */
static int buscarPorId(Publicacion* array,int limite, int id)
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


int cont_ordenarCuit(Publicacion* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Publicacion auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].cuit,array[i+1].cuit) > 0 && orden) || (strcmp(array[i].cuit,array[i+1].cuit) < 0 && !orden)) //******
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
/** \brief modifica a una publicacion para pausarla
 * \param array Publicacion*
 * \param limite int
  * \param Id
 * \return int
 *
 */


int cont_modificacion(Publicacion* array,int limite, int id)
{
    int retorno=-1;
    int indiceAModificar;
    int diaAux;
   // char archivoAux[30];
    //char cuitAux[30];
    indiceAModificar=buscarPorId(array,limite,id);
    if (indiceAModificar>=0)
    {

        if(!getValidInt("Ingrese 2 nuevamente para confirmar la pausa de la publicacion","\nNumero no valido.Ingrese 2\n",&diaAux,2,2,2))
                {
                 // if (!getValidString("Escriba el texto: ","Archivo no valido\n","Nombre de Archivo Demasiado Largo",archivoAux,32,2))
                 {
                   // getString("Indique rubro(5=electro 6=bazar): ",cuitAux);
                    {

                            retorno = 0;
                           // strcpy(array[indiceAModificar].cuit,cuitAux);
                           // strcpy(array[indiceAModificar].archivo,archivoAux);
                            array[indiceAModificar].dias = diaAux;
                        }

                    }

                }
    }
    return retorno;
}
/** \brief modifica a una publicacion para activarla
 * \param array Publicacion*
 * \param limite int
  * \param Id
 * \return int
 *
 */
int cont_modificacionR(Publicacion* array,int limite, int id)
{
    int retorno=-1;
    int indiceAModificar;
    int diaAux;
     indiceAModificar=buscarPorId(array,limite,id);
    if (indiceAModificar>=0)
    {

        if(!getValidInt("Ingrese 1 nuevamente para confirmar la reactivacion de la publicacion","\nNumero no valido.Ingrese 1\n",&diaAux,1,1,2))

                    {
                            retorno = 0;

                            array[indiceAModificar].dias = diaAux;
                    }

    }
    return retorno;
}



int cont_mostrarContador(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    int cont=-1;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
            if((array[i].dias)==1)
        {


            {
            if(!array[i].isEmpty)

                printf("[RELEASE] - ID de Publicacion: %d - Rubro: %s - Texto: %s - Estado:%d  (1:activo 2:inactivo):  - Is Empty: %d\n",array[i].id, array[i].cuit,array[i].archivo,array[i].dias, array[i].isEmpty);

              cont=cont+1;

            }

        }
     printf("Cantidad de publicaciones activas %d ",cont);
    }

    return retorno;
}
