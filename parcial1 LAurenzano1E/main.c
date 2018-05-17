
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "persona.h"
#include "utn.h"
#include "publicacion.h"
#include "informes.h"

#define QTY 10
#define LEN_CONT    1000

int main()
{
    Persona array[QTY];
    Publicacion publicaciones[LEN_CONT];
    int menu;
    int auxiliarId;
    int auxiliarIdV;
    int auxiliarIdVv;
    int auxiliarIdPubAmod;
    persona_init(array,QTY);
    cont_init(publicaciones,LEN_CONT);

      do
    {
        getValidInt("\n\nPARCIAL 1 LAURENZANO 1 E\n \n1.ALTA CLIENTE\n2.MODIFICAR DATOS DEL CLIENTES\n3.BAJA DEL CLIENTE\n4.PUBLICAR\n5.PAUSAR PUBLICACION\n6.REANUDAR PUBLICACION\n7.IMPRIMIR CLIENTES\n8.IMPRIMIR PUBLICACIONES\n9.SALIR\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                persona_alta(array,QTY);
                break;
              case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                persona_modificacion(array,QTY,auxiliarId);
                                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarIdV,0,200,2);
                cont_mostrar(publicaciones,LEN_CONT);
                printf("quiere dar de baja el Id numero: %d ?Si la respuesta es si , ingrese 1",auxiliarIdV );

                getValidInt(" ","\nNumero valida\n",&auxiliarIdVv,1,100,1);
                if((auxiliarIdVv)==1);
                {auxiliarId=auxiliarIdV;
                persona_baja(array,QTY,auxiliarId);
                printf("El Id fue dado de baja" );
                }

                break;

            case 4:
                cont_alta(publicaciones,LEN_CONT,array,QTY);
                break;
            case 5:
                getValidInt("ID de publicacion a pausar?","\nNumero no valido.\n",&auxiliarIdPubAmod,0,200,2);
                persona_mostrar(array,QTY);
                getValidInt("\nQuiere pausar la publicacion?.Ingrese 2 para pausar?","\nNumero valida\n",&auxiliarIdVv,2,2,1);
                if((auxiliarIdVv)==2);
                {
                cont_modificacion(publicaciones,LEN_CONT, auxiliarIdPubAmod);
                printf("La publicacion fue pausada");
                }
                break;
            case 6:
                cont_mostrar(publicaciones,LEN_CONT);
                getValidInt("\nID de publicacion a reanudar?","\nNumero no valida.\n",&auxiliarIdPubAmod,0,200,2);
                persona_mostrar(array,QTY);
                getValidInt("\nQuiere reaunudar la publicacion?Ingrese 1 para reanudar","\nNumero valida\n",&auxiliarIdVv,1,100,1);
                if((auxiliarIdV)==1);
                {
                cont_modificacionR(publicaciones,LEN_CONT, auxiliarIdPubAmod);
                printf("La publicacion fue reanudada" );
                }
                break;
            case 7:
                persona_mostrar(array,QTY);
                //cont_mostrar(publicaciones,LEN_CONT);
                cont_mostrarContador(publicaciones,LEN_CONT);
                break;
            case 8:
                //cont_mostrar(publicaciones,LEN_CONT);
                informar_ListarContrataciones(publicaciones,LEN_CONT,
              array, QTY);
              break;
        }

    }while(menu != 9);

    return 0;
}
