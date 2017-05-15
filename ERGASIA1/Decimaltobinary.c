#include <stdio.h>                                                          /*periexei printf,scanf ka functions*/
int main(void)
{
int number;                                                                 /*Orizo metavliti number os akeraio arithmo*/
const y=2;                                                                  /* Orizo statheri metavliti y kai tis dino timi 2.*/
    do                                                                      /* do..while loop gia elegxo eisagogis thetikou akeraiou kai ksanaemfanisi minimatos mexri na eisaxthei thetikos arithmos*/
    {
        printf("Eisagetai akeraio thetiko arithmo:\n");                                           /*Emfanisi minimatos-Eisagetai thetiko akeraio arithmo*/
        scanf("%d",&number);                                                                      /*Eisodos apo pliktrologio arithmou kai apothikeysi se thesi mnimis number(&)*/
        (number<=0)? printf("Wrong Number\n"):printf("The number %d in binary form is:\n",number);/*Triadikos Telestis gia elegxo rois (Sinthiki/Energeia an einai true/energeia an einai false)*/
    }
    while (number<=0);                                                                            /*Elegxos eisagogis thetikou akeraiou kai emfanisi ton proigoumenwn mexri na valei o xristis kapoio thetiko akeraio*/
    do                                                                                            /*Loop gia ipologismo binary number mesw diadoxikon diairesewn me 2*/
    {
        (number%y)?putchar('1'):putchar('0');                               /*Triadikos Telestis opou ipologizei to ipoloipo. An einai true meso tis entolis putchar emfanizei stin othoni 1 an einai false 0*/
        number = number/y;                                                  /*Ipologismos Pilikou diairesis(Quotient) kai antikatastasi sto number me to neo piliko*/
    }
    while (number!=0);                                                      /*Loop sinexizete gia oso to piliko diairesis einai >0*/
}
