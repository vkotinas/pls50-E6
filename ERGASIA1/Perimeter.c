#include <stdio.h>                                                      /* I stdio.h periexei printf,scanf klp, enw i math.h tin sqrt kai alles mathimatikes sinartiseis*/
#include <math.h>
float perim_tet (float a){                                              /* Dimiourgia Sinartiseon ipologismou perimetroy gia tetragono,orth.parallilogramo,orth.trigono,kiklo*/
float temp;
temp= 4 * a;
return temp;
}
float perim_orth (float a,float b){
float temp;
temp= (2*a)+(2*b);
return temp;
}
float perim_triangl (float a,float b){
float temp;
float tempc;
tempc= sqrt ((a*a)+(b*b));
temp = a+b+tempc;
return temp;
}
float perim_circle (float r){
float temp;
temp= 2*3.14*r;
return temp;
}

int main (void)                                                         /*Enarksi mesw tis sinartisis main*/
{
char selection; float pleyra1; float pleyra2; float aktina;             /*Dilosi metavliton prin i meta tin int main. Xrisimopoio pleyra1,pleyra 2 gia ta tria prota sximata (analoga me to poio xreiazetai ti), kai tin aktina gia to tetarto sxima*/
do{                                                                     /*Epanalipsi emfanisis menu mesw do...while*/
    printf("Perimeter Calculator\n");                                   /*Dimiourgia Arxikou menu Menu epilogon*/
    printf("Please make a selection:\n\n");
    printf("0.Exit\n");
    printf("1.Tetragono\n");
    printf("2.Orthogonio Parallilogrammo\n");
    printf("3.Orthogonio_Trigono\n");
    printf("4.Kiklos\n");
    scanf(" %c",&selection);                                                                                    /*Epilogi menu apo xristi*/
    if (selection=='1')
    {   printf("Parakalo doste tin pleyra tou tetragonou:");                                                    /*Elegxos epologis menu meso pollaplon if kai emfanisi katallilon minimaton stin othoni gia kathe sxima */
        scanf(" %f",&pleyra1);                                                                                  /* Ean o xristis epelekse 1. Eisagogi pleyras tetragonou-pleyra1*/
        printf("I perimetros tou tetragonou einai: %f \n\n",perim_tet(pleyra1));                                /*Ektiposi minimatos kai epeita kaloume sinartisi perim_tet me a = pleyra1 gia ipologismo perimetroy*/
    }
    else if (selection=='2')
    {   printf("Parakalo doste to mikos kai to platos tou parallilogramou (me keno):");
        scanf(" %f %f",&pleyra1, &pleyra2);
        printf("I perimetros tou orth.parallilogramou einai: %f \n\n",perim_orth(pleyra1,pleyra2));             /* An o xristis epileksi to Menu 2 ..zitame na eisagei tis 2 pleyres kai Kaloume sinartisi perim_orth me a = pleyra1 kai b = playra2*/
    }
    else if (selection=='3')
    {   printf("Parakalo doste to mikos ton kathetwn pleyrwn tou trigonou (me keno):");
        scanf(" %f %f",&pleyra1, &pleyra2);
        printf("I perimetros tou orthogoniou trigonou einai: %f \n\n",perim_triangl(pleyra1,pleyra2));          /*Antistoixa gia to Menu 3 eisagei tis 2 pleyres tou trigonou o xristis kai Kaloume sinartisi perim_triangl me a=pleyra1 b=pleyra2*/
    }
    else if (selection=='4')
    {   printf("Parakalo doste tin aktina tou kiklou:\n");
        scanf(" %f",&aktina);
        printf("I perimetros tou kiklou: %f \n\n",perim_circle(aktina));                                        /* Antistoixa kai gia ton kiklo zitame tin aktina kai kaloume ti sinartisi perim_circle*/
    }
    else if(selection!='0') printf("Wrong selection\n\n");                                                      /* Elegxos Epilogis orthou menu*/
}
while (selection!='0');                                                                                         /* Kleisimo epanalipsis do..while me to pou o xristis epileksi exit*/
}
