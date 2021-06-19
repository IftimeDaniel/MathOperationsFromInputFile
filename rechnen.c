/************************
 * Lesen von            *
 * Rechenoperationen    *
 *                      *
 * Autor: Daniel Iftime *
 ************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int isdigit(int arg);

int main(int argc, char **argv)
{
  if (argc != 2)
  {
      printf("Ungültige Parameterzahl: ./rechnen exampleFile \n");
      exit(EXIT_FAILURE);
  } // Parameteranzahl stimmt nicht.


FILE *filePointer;
char operation[10 + 1] = "";
double wert = 0;
int i=0;

filePointer = fopen(argv[1], "r");  //Öffnet Datei die in Kommandozeile übergeben wurde
  if(filePointer == NULL)
  {
    printf("Datei wurde nicht gefunden = %s\n", argv[1]);
    exit(EXIT_FAILURE);
  } //Datei nicht gefunden


while(fgets(operation, sizeof(operation), filePointer) != NULL) //Schleife läuft so lange bis alle Zeilen eingelesen wurden
{
  //Falls Subtraktion gefunden wurde lies alle Zeichen in dieser Zeile
  if(strncmp(operation, "SUB", strlen("SUB")) == 0)
  {
  char *str = operation, *b = str;
  // Läuft solange Zeichen verarbeitet werden müssen
  while (*b)
  {
   // Falls eine Nummer gefunden wurde
   if ( isdigit(*b) || ( (*b=='-'||*b=='+') && isdigit(*(b+1)) ))
   {
    // Lese die Nummer
    long nummer = strtol(b, &b, 10);
    //Führe Subtraktion aus
    wert -=nummer;
    // Ansonsten gehe zum nächsten Zeichen
    } else {b++;}
 }
}
  //Addition
  else if(strncmp(operation, "ADD", strlen("ADD")) == 0)
  {
  char *str = operation, *b = str;
  while (*b)
  {
   if ( isdigit(*b) || ( (*b=='-'||*b=='+') && isdigit(*(b+1)) ))
   {
    long nummer = strtol(b, &b, 10);
    wert +=nummer;
    } else {b++;}
 }
}
  //Multiplikation
  else if(strncmp(operation, "MUL", strlen("MUL")) == 0)
  {
  char *str = operation, *b = str;
    while (*b)
    {
     if ( isdigit(*b) || ( (*b=='-'||*b=='+') && isdigit(*(b+1)) ))
     {
      long nummer = strtol(b, &b, 10);
      wert *=nummer;
      } else {b++;}
   }
  }
  //Division
  else if(strncmp(operation, "DIV", strlen("DIV")) == 0)
  {
  char *str = operation, *b = str;
    while (*b)
    {
     if ( isdigit(*b) || ( (*b=='-'||*b=='+') && isdigit(*(b+1)) ))
     {
      long nummer = strtol(b, &b, 10);
      wert /=nummer;
      } else {b++;}
   }
  }
  //zum Quadrat (Hoch 2)
  else if(strncmp(operation, "SQR", strlen("SRQ")) == 0)
  {
  wert = pow(wert,2);
  }

//Es können maximal 10 Zeilen gelesen werden
 if(i>=10){
  printf("Eine Datei darf Maximal 10 Zeilen enhalten \n");
  exit(EXIT_FAILURE);
          }
 i++;
 }

printf("%g \n",wert);
return (EXIT_SUCCESS);
}
