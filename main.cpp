#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
char* Decimal_a_Binario (int *decimal)
{
 int i=0 ,*paso,*dec_aux;
 char *bin,*aux;
 paso = (int *) malloc (sizeof(int));
 dec_aux = (int *) malloc (sizeof(int));
 bin = (char *) malloc (sizeof(char)*32);
 aux = (char *) malloc (sizeof(char)*3);
 *paso = 0;
 *dec_aux = *decimal;
 strcpy (aux,"\0");
 strcpy (bin,"\0");
 while (true)
 {
  *paso=*decimal/2;
  itoa (*decimal%2,aux,10);
  *(aux+1) = '\0';
  *decimal=*paso;
  *(bin+i) = *(aux+0);
      *(aux+0) = '\0';
  i++;
   if (*paso == 0)
    break;
 }
 *decimal = *dec_aux;
 *(bin+i)='\0';
 strrev (bin);
 return bin;
 free (paso);
 free (dec_aux);
 free (bin);
 free (aux);
}
char* Decimal_a_Octal (int *decimal)
{
 int i=0 ,*paso,*dec_aux;
 char *oct,*aux;
 paso = (int *) malloc (sizeof(int));
 dec_aux = (int *) malloc (sizeof(int));
 oct = (char *) malloc (sizeof(char)*12);
 aux = (char *) malloc (sizeof(char)*3);
 *paso = 0;
 *dec_aux = *decimal;
 strcpy (aux,"\0");
 strcpy (oct,"\0");
 while (true)
 {
  *paso=*decimal/8;
  itoa (*decimal%8,aux,10);
  *(aux+1) = '\0';
  *decimal=*paso;
  *(oct+i) = *(aux+0);
      *(aux+0) = '\0';
  i++;
  if (*paso == 0)
   break;
 }
 *decimal = *dec_aux;
 *(oct+i)='\0';
 strrev (oct);
 return oct;
 free (paso);
 free (dec_aux);
 free (oct);
 free (aux);
}
char* Decimal_a_Hexadecimal (int *decimal)
{
 int i=0 ,*paso,*dec_aux;
 char *hex,*aux;
 paso = (int *) malloc (sizeof(int));
 dec_aux = (int *) malloc (sizeof(int));
 hex = (char *) malloc (sizeof(char)*12);
 aux = (char *) malloc (sizeof(char)*3);
 *paso = 0;
 *dec_aux = *decimal;
 strcpy (aux,"\0");
 strcpy (hex,"\0");
 while (true)
 {
  *paso=*decimal/16;
  if (*decimal%16 < 10)
   itoa (*decimal%16,aux,10);
  else
  {
   switch (*decimal%16)
   {
    case 10:
     *(aux+0) = 'A';
     break;
    case 11:
     *(aux+0) = 'B';
     break;
    case 12:
     *(aux+0) = 'C';
     break;
    case 13:
     *(aux+0) = 'D';
     break;
    case 14:
     *(aux+0) = 'E';
     break;
    case 15:
     *(aux+0) = 'F';
     break;
   }
  }
  *(aux+1) = '\0';
  *decimal=*paso;
  *(hex+i) = *(aux+0);
  *(aux+0) = '\0';
  i++;
  if (*paso == 0)
   break;
 }
 *decimal = *dec_aux;
 *(hex+i)='\0';
 strrev (hex);
 return hex;
 free (paso);
 free (dec_aux);
 free (hex);
 free (aux);
}
char* Binario_a_Hexadecimal (char *bin)
{
 int i=0;
 char *hex,*aux;
 hex = (char *) malloc (sizeof(char)*12);
 aux = (char *) malloc (sizeof(char)*5);
 strcpy (hex, "\0");
 strcpy (aux, "\0");
 i = strlen (bin) - 1;
 while (i >= 0)
 {
  *(aux+0) = *(bin+(i-3));
  *(aux+1) = *(bin+(i-2));
  *(aux+2) = *(bin+(i-1));
  *(aux+3) = *(bin+i);
  *(aux+4) = '\0';
  for (int j = 0 ; j < 4 ; j++)
   if (*(aux+j) != '0' && *(aux+j) != '1')
    *(aux+j) = '0';
  if (strcmp (aux,"0000") == 0)
   strcat (hex ,"0");
  else if (strcmp (aux,"0001") == 0)
   strcat (hex ,"1");
  else if (strcmp (aux,"0010") == 0)
   strcat (hex ,"2");
  else if (strcmp (aux,"0011") == 0)
   strcat (hex ,"3");
  else if (strcmp (aux,"0100") == 0)
   strcat (hex ,"4");
  else if (strcmp (aux,"0101") == 0)
   strcat (hex ,"5");
  else if (strcmp (aux,"0110") == 0)
   strcat (hex ,"6");
  else if (strcmp (aux,"0111") == 0)
   strcat (hex ,"7");
  else if (strcmp (aux,"1000") == 0)
   strcat (hex ,"8");
  else if (strcmp (aux,"1001") == 0)
   strcat (hex ,"9");
  else if (strcmp (aux,"1010") == 0)
   strcat (hex ,"A");
  else if (strcmp (aux,"1011") == 0)
   strcat (hex ,"B");
  else if (strcmp (aux,"1100") == 0)
   strcat (hex ,"C");
  else if (strcmp (aux,"1101") == 0)
   strcat (hex ,"D");
  else if (strcmp (aux,"1110") == 0)
   strcat (hex ,"E");
  else if (strcmp (aux,"1111") == 0)
   strcat (hex ,"F");
  i -= 4;
  *(aux+0) = '\0';
 }
 strrev (hex);
 return hex;
 free (hex);
 free (aux);
}
char* Binario_a_Octal (char *bin)
{
 int i=0;
 char *oct,*aux;
 oct = (char *) malloc (sizeof(char)*12);
 aux = (char *) malloc (sizeof(char)*4);
 strcpy (oct, "\0");
 strcpy (aux, "\0");
 i = strlen (bin) - 1;
 while (i >= 0)
 {
  *(aux+0) = *(bin+(i-2));
  *(aux+1) = *(bin+(i-1));
  *(aux+2) = *(bin+i);
  *(aux+3) = '\0';
  for (int j = 0 ; j < 3 ; j++)
   if (*(aux+j) != '0' && *(aux+j) != '1')
    *(aux+j) = '0';
  if (strcmp (aux,"000") == 0)
   strcat (oct ,"0");
  else if (strcmp (aux,"001") == 0)
   strcat (oct ,"1");
  else if (strcmp (aux,"010") == 0)
   strcat (oct ,"2");
  else if (strcmp (aux,"011") == 0)
   strcat (oct ,"3");
  else if (strcmp (aux,"100") == 0)
   strcat (oct ,"4");
  else if (strcmp (aux,"101") == 0)
   strcat (oct ,"5");
  else if (strcmp (aux,"110") == 0)
   strcat (oct ,"6");
  else if (strcmp (aux,"111") == 0)
   strcat (oct ,"7");
  i -= 3;
  *(aux+0) = '\0';
 }
 strrev (oct);
 return oct;
 free (oct);
 free (aux);
}
int Binario_a_Decimal (char *bin)
{
 int *decimal;
 char *bin_aux,*aux;
 decimal = (int *) malloc (sizeof(int));
 bin_aux = (char *) malloc (sizeof(char)*32);
 aux = (char *) malloc (sizeof(char)*2);
 *decimal = 0;
 strcpy (bin_aux,"\0");
 strcpy (aux,"\0");
 strcpy (bin_aux,bin);
 strrev (bin_aux);
 for (int i = 0 ; i < strlen (bin_aux) ; i++)
 {
  *(aux+0) = *(bin_aux+i);
  *(aux+1) = '\0';
  *decimal += (pow (2.0,i) * atoi(aux));
 }
 return *decimal;
 free (decimal);
 free (bin_aux);
 free (aux);
}
int Hexadecimal_a_Decimal (char *hex)
{
 int *decimal;
 char *hex_aux,*aux;
 decimal = (int *) malloc (sizeof(int));
 hex_aux = (char *) malloc (sizeof(char)*12);
 aux = (char *) malloc (sizeof(char)*2);
 *decimal = 0;
 strcpy (hex_aux,"\0");
 strcpy (aux,"\0");
 strupr (hex);
 strcpy (hex_aux,hex);
 strrev (hex_aux);
 for (int i = 0 ; i < strlen (hex_aux) ; i++)
 {
  if (*(hex_aux+i) >= '0' && *(hex_aux+i) <= '9')
  {
   *(aux+0) = *(hex_aux+i);
   *(aux+1) = '\0';
   *decimal += (pow (16.0,i) * atoi(aux));
  }
  else
  {
   switch (*(hex_aux+i))
   {
    case 'A':
     *decimal += (pow (16.0,i) * 10);
     break;
    case 'B':
     *decimal += (pow (16.0,i) * 11);
     break;
    case 'C':
     *decimal += (pow (16.0,i) * 12);
     break;
    case 'D':
     *decimal += (pow (16.0,i) * 13);
     break;
    case 'E':
     *decimal += (pow (16.0,i) * 14);
     break;
    case 'F':
     *decimal += (pow (16.0,i) * 15);
     break;
   }
  }
 }
 return *decimal;
 free (decimal);
 free (hex_aux);
 free (aux);
}
char* Hexadecimal_a_Binario (char *hex)
{
 char *bin;
 bin = (char *) malloc (sizeof(char)*32);
 strcpy (bin, "\0");
 strupr (hex);
 for (int i = 0 ; i < strlen (hex) ; i++)
 {
  switch (*(hex+i))
  {
   case '0':
    strcat (bin ,"0000");
    break;
   case '1':
    strcat (bin ,"0001");
    break;
   case '2':
    strcat (bin ,"0010");
    break;
   case '3':
    strcat (bin ,"0011");
    break;
   case '4':
    strcat (bin ,"0100");
    break;
   case '5':
    strcat (bin ,"0101");
    break;
   case '6':
    strcat (bin ,"0110");
    break;
   case '7':
    strcat (bin ,"0111");
    break;
   case '8':
    strcat (bin ,"1000");
    break;
   case '9':
    strcat (bin ,"1001");
    break;
   case 'A':
    strcat (bin ,"1010");
    break;
   case 'B':
    strcat (bin ,"1011");
    break;
   case 'C':
    strcat (bin ,"1100");
    break;
   case 'D':
    strcat (bin ,"1101");
    break;
   case 'E':
    strcat (bin ,"1110");
    break;
   case 'F':
    strcat (bin ,"1111");
    break;
  }
 }
 return bin;
 free (bin);
}
char* Hexadecimal_a_Octal (char *hex)
{
 char *oct ,*bin;
 oct = (char *) malloc (sizeof(char)*12);
 bin = (char *) malloc (sizeof(char)*32);
 strcpy (oct, "\0");
 strcpy (bin, "\0");
 strupr (hex);
 bin = Hexadecimal_a_Binario (hex);
 oct = Binario_a_Octal (bin);
 return oct;
 free (oct);
 free (bin);
}
int Octal_a_Decimal (char *oct)
{
 int *decimal;
 char *oct_aux,*aux;
 decimal = (int *) malloc (sizeof(int));
 oct_aux = (char *) malloc (sizeof(char)*12);
 aux = (char *) malloc (sizeof(char)*2);
 *decimal = 0;
 strcpy (oct_aux,"\0");
 strcpy (aux,"\0");
 strcpy (oct_aux,oct);
 strrev (oct_aux);
 for (int i = 0 ; i < strlen (oct_aux) ; i++)
 {
  *(aux+0) = *(oct_aux+i);
  *(aux+1) = '\0';
  *decimal += (pow (8.0,i) * atoi(aux));
 }
 return *decimal;
 free (decimal);
 free (oct_aux);
 free (aux);
}
char* Octal_a_Binario (char *oct)
{
 char *bin;
 bin = (char *) malloc (sizeof(char)*32);
 strcpy (bin, "\0");
 for (int i = 0 ; i < strlen (oct) ; i++)
 {
  switch (*(oct+i))
  {
   case '0':
    strcat (bin ,"000");
    break;
   case '1':
    strcat (bin ,"001");
    break;
   case '2':
    strcat (bin ,"010");
    break;
   case '3':
    strcat (bin ,"011");
    break;
   case '4':
    strcat (bin ,"100");
    break;
   case '5':
    strcat (bin ,"101");
    break;
   case '6':
    strcat (bin ,"110");
    break;
   case '7':
    strcat (bin ,"111");
    break;
  }
 }
 return bin;
 free (bin);
}
char* Octal_a_Hexadecimal (char *oct)
{
 char *hex ,*bin;
 hex = (char *) malloc (sizeof(char)*12);
 bin = (char *) malloc (sizeof(char)*32);
 strcpy (hex, "\0");
 strcpy (bin, "\0");
 strupr (hex);
 bin = Octal_a_Binario (oct);
 hex = Binario_a_Hexadecimal (bin);
 return hex;
 free (hex);
 free (bin);
}
int main ()
{
 int *decimal,*opc;
 char *bin,*oct,*hex;
 decimal = (int *) malloc (sizeof(int));
 opc = (int *) malloc (sizeof(int));
 bin = (char *) malloc (sizeof(char)*32);
 oct = (char *) malloc (sizeof(char)*12);
 hex = (char *) malloc (sizeof(char)*12);
 *decimal = 0;
 *opc = 0;
 strcpy (bin, "\0");
 strcpy (oct,"\0");
 strcpy (hex,"\0");
 printf("Convertir de decimal a otros sistemas press 1\n");
 printf("Convertir de hexadecimal a otros sistemas press 2\n");
 printf("Convertir de binario a otros sistemas press 3\n");
 printf("Convertir de octal a otros sistemas press 4\n");
 printf("opcion: ");
 scanf ("%d", &*opc);
 system("cls");
 switch (*opc)
 {
  case 1:
   printf ("Ingresa un numero decimal: ");
   scanf ("%d" ,&*decimal);
   printf ("Decimal: %d \nBinario: %s \nOctal: %s \nHexadecimal: %s\n",*decimal,Decimal_a_Binario(decimal),Decimal_a_Octal(decimal),Decimal_a_Hexadecimal(decimal));
   break;
  case 2:
   printf ("Ingresa un numero hexadecimal: ");
   fflush (stdin);
   gets (hex);
   printf ("Hexadecimal: %s \nDecimal: %d \nBinario: %s \nOctal: %s\n",hex,Hexadecimal_a_Decimal(hex),Hexadecimal_a_Binario(hex),Hexadecimal_a_Octal(hex));
   break;
  case 3:
   printf ("Ingresa un numero binario: ");
   fflush (stdin);
   gets (bin);
   printf ("Binario: %s \nDecimal: %d \nHexadecimal: %s \nOctal: %s\n",bin,Binario_a_Decimal(bin),Binario_a_Hexadecimal(bin),Binario_a_Octal(bin));
   break;
  case 4:
   printf ("Ingresa un numero octal: ");
   fflush (stdin);
   gets (oct);
   printf ("Octal: %s \nDecimal: %d \nHexadecimal: %s \nBinario: %s\n",oct,Octal_a_Decimal(oct),Octal_a_Hexadecimal(oct),Octal_a_Binario(oct));
   break;
 }
 system("pause");
 free (opc);
 free (decimal);
 free (hex);
 free (oct);
 free (bin);
 return 0;
}
