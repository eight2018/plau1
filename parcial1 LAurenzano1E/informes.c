#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "utn.h"
#include "persona.h"


int informar_ConsultaFacturacion(Publicacion* arrayC,int limite,
              Persona* personas, int lenPersonas, char* cuit)
{
    int retorno = -1;
    int i;
    int indexPersona;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
            if(!arrayC[i].isEmpty && !strcmp(arrayC[i].cuit,cuit))
            {
                indexPersona = persona_buscarPorId(personas,lenPersonas,arrayC[i].idPersona);
                printf("\n\nCuit: %s - Unitario: %.2f - Total: %.2f - Dias: %d\n",
                                    arrayC[i].cuit,
                                    personas[indexPersona].precio,
                                    (arrayC[i].dias * personas[indexPersona].precio),
                                    arrayC[i].dias );
            }
        }

        retorno = 0;
    }
    return retorno;
}



int informar_ListarContrataciones(Publicacion* arrayC,int limite,
              Persona* personas, int lenPersonas)
{
    int retorno = -1;
    int i;
    int indexPersona;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
                if(!arrayC[i].isEmpty)
                {
                    indexPersona = persona_buscarPorId(personas,lenPersonas,arrayC[i].idPersona);
                    if((arrayC[i].dias)==1)
                    {


                    printf("\n Id de cliente:%d - Cuit: %s - Nombre: %s -Apellido: %s - Rubro: %s - Texto: %s - Estado: %d\n",personas[indexPersona].idPersona,personas[indexPersona].elCuit,personas[indexPersona].nombre,personas[indexPersona].apellido,arrayC[i].cuit,
                                        arrayC[i].archivo,  arrayC[i].dias );
                     }
                }


        }

        retorno = 0;
    }
    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Publicacion* arrayC,int limite,
              Persona* personas, int lenPersonas)
{
    int retorno = -1;
    int i;
    //int indexPersona;
    char ultimoCuit[50];

    cont_ordenarCuit(arrayC,limite,0);
    strcpy(ultimoCuit,"");
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
                if(!arrayC[i].isEmpty)
                {
                    if(strcmp(ultimoCuit,arrayC[i].cuit) != 0)
                    {
                        printf("\nCuit: %s", arrayC[i].cuit);
                        strcpy(ultimoCuit,arrayC[i].cuit);
                    }



                }


        }

        retorno = 0;
    }
    return retorno;
}

