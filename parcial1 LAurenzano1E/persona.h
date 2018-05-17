

#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
typedef struct
{
    char nombre[50];
    char apellido[50];
    char elCuit[50];
    float precio;
    int tipo;
    int idPersona;
    int isEmpty;
}Persona;
#endif


int persona_init(Persona* array,int limite);
int persona_mostrar(Persona* array,int limite);
int persona_mostrarDebug(Persona* array,int limite);
int persona_alta(Persona* array,int limite);
int persona_baja(Persona* array,int limite, int id);
int persona_modificacion(Persona* array,int limite, int id);
int persona_ordenar(Persona* array,int limite, int orden);
int persona_buscarPorId(Persona* array,int limite, int id);


