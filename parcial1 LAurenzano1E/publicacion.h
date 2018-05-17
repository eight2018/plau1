
#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
typedef struct
{
    char cuit[50];
    int idPersona;
    int dias;//estado
    char archivo[64];//texto
    //------------
    int id;
    int isEmpty;
}Publicacion;

#include "persona.h"


int cont_init(Publicacion* array,int limite);
int cont_mostrar(Publicacion* array,int limite);
int cont_mostrarDebug(Publicacion* array,int limite);

int cont_alta(Publicacion* arrayC,int limite,
              Persona* personas, int lenPantallas);

int cont_baja(Publicacion* array,int limite, int id);
int cont_modificacion(Publicacion* array,int limite, int id);
int cont_modificacionR(Publicacion* array,int limite, int id);
int cont_ordenar(Publicacion* array,int limite, int orden);
int cont_ordenarCuit(Publicacion* array,int limite, int orden);
int cont_mostrarContador(Publicacion* array,int limite);



#endif



