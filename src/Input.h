#include <stdlib.h>
#include <string.h>



#ifndef INPUT_H_
#define INPUT_H_

int GetInt(char *);
void GetString(char *, char *);
float GetFloat(char *);
int ValidateRange(char *, int, int, int);

int getStringLetras(char cadena[]);
int getStringNumeros(char cadena[]);

void GetStringSoloNumeros (char mensaje[], char cadena[]);
void GetStringSoloLetras (char mensaje[], char cadena[]);


#endif /* FUNCIONES_H_ */
