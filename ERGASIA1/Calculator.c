//*************************************************************
//*** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ***
//***                   Εργασία Ε01 - Θέμα 1                ***
//***                   Κοτίνας Βασίλειος                   ***
//***                   Ακ.έτος 2016-17                     ***
//***                                                       ***
//*************************************************************

#include <stdio.h>;                                                                        /*Periexei printf,scanf ka functions*/
float number1; char praksi; float number2;                                                 /* Orismos metavliton. Float gia na exw kai dekadika psifia stous arithmous. Character gia tin praksi */
int main(void)                                                                             /* Enarksi ektelesimou kodika me ti xrisi PANTA tis sinartisis main. DOULEYEI KAI XORIS VOID*/
{
    printf("Parakalo doste arithmo praksi arithmo(xrisimopoiontas keno anamesa tous):\n"); /*Emfanizei stin othoni to minima gia eisagogi arithmon k praksis mesa se '..' */
    scanf("%f %c %f",&number1,&praksi,&number2);                                           /*Eisagogi timon apo ton xristi vazontas keno anamesa sta dedomena(float-character-float) To & antiprosopeyei thesi mnimis*/
    if (praksi=='+')
        printf("To apotelesma einai: %f",number1+number2);                                 /* Elegxos Rois meso tis entolis If. Ean o xristis exei eisagi + sthn praksi tote emfanizei to athroisma ton number1+number2 */
    else if (praksi =='-')
        printf ("To apotelesma einai: %f",number1-number2);                                /* Elegxos Rois meso tis entolis If. Ean o xristis exei eisagi - sthn praksi tote emfanizei to apotelesma number1-number2 */
    else if (praksi=='*')
        printf ("To apotelesma einai: %f",number1*number2);                                /* Elegxos Rois meso tis entolis If. Ean o xristis exei eisagi * sthn praksi tote emfanizei to apotelesma number1*number2*/
    else if (praksi=='/')
    {                                                                                      /* Elegxos Rois meso tis entolis If. Ean o xristis exei eisagi / sthn praksi tote emfanizei to apotelesma number1/number2*/
        if (number2==0) printf ("Prosoxi: De mporei na ginei diairesi me to 0");           /* Nested If statement gia elegxo diairesis me 0 kai emfanisis katalilou sfalmatos*/
        else printf ("To apotelesma einai: %f",number1/number2);
    }
    else printf("I praksi pou eisagate den einai sosti");                                  /* Mynhma se periptosi pou kapoios den epileksi praksi +,-,*,/ */

}
