#include<stdlib.h>                                      /* gia xrisi exit, xwris na emfanizei sfalma o debugger*/
#include <stdio.h>                                      /*Periexei printf,scanf ka functions*/
int main(void)
{
int seatnr[53];                                         /*Dimioyrgia pinaka akeraiwn timon me 53 theseis, 0 ews 52*/
int i,j,temp,numberofseats;                             /* Orismos metavliton akeraion pou tha xrisimopoiiso sti sinexeia */
char platenr[8];                                        /* Orismos pinaka string pou tha periexei pinakida leoforeiou meta tin anagnosi tou txt file. vazoume n+1 apo ta stoixeia pou xreiazomaste*/
int freeseats = 0;                                      /*Orismos kai arxikopoisi metavlitis pou periexei tis eleytheres theseis*/
int item_changed = 0;                                   /*orismos kai arxikopoiisi metavlitis pou tha xrisimopoiithi gia elegxo allagon se for loop*/
char selection;                                         /*orismos metavlitis selection - character gia dimiourgia menu*/

for (i=0; i<53; i++)                                    /*Arxikopoiisi pinaka gia tis 53 theseis me midenika gia kathe thesi*/
    seatnr[i] = 0;

FILE *businfo;                                          /*Dilosi onomatos- businfo gia tin anagnosi kai xrisi arxeiou txt*/
businfo = fopen ("bus.txt","r");                        /* Anoigma arxeiou bus.txt pou brisketai ston idio fakelo kai periexei plirofories leoforeiou*/
if (businfo == NULL)                                                                        /*Elegxos iparksis arxeiou bus.txt. An den iparxei error kai eksodos*/
{
    printf("Error Opening File, check if file bus.txt is present");
    exit(1);
}
fscanf(businfo,"%s %d",platenr, &numberofseats);                                                  /*Anagnosi string kai integer (platenr kai number of seats) apo arxeio. Sta string de xreiazetai dilosi thesis mnimis*/
    if (numberofseats > 53)                                                                       /*Elegxos ipervasis theseon leoforeiou kai eksodos*/
        {printf("Error: Seats are over 53, which is the maximum. Please check txt file") ;
        exit(1);}
    else if ((numberofseats-5)%4)                                                                 /*Elegxos oti oi theseis akolouthoun to format 4n+5*/
    {   printf("Error: Please check seat Number in txt file");
        exit(1); }
    else                                                                                          /*Ean den iparxei provlima ektiposi pinakidas+ arithmou theseon*/
        printf("Bus Licence plate Nr is: %s and number of seats is: %d", platenr, numberofseats);

do{                                                                                               /*Epanalipsi mesw do...while gia epanalipsi dimiourgias menu*/
    printf("\n\nSistima katagrafis thesewn leoforeiou\n");                                        /*Dimiourgia Arxikou  Menu epilogon*/
    printf("Please make a selection:\n\n");
    printf("0. Exit\n");
    printf("1. Empty Seats \n");
    printf("2. Book Specific Seat \n");
    printf("3. Book first available Seat near Window\n");
    printf("4. Cancel Seat Booking\n");
    printf("5. Search for specific seat availability\n");
    printf("6. Show List of booked Seats\n");
    printf("7. Show Seat Diagram of Bus\n");
    printf("8. Save Seat Diagram of Bus in txt file\n");
    scanf(" %c",&selection);                                                                      /*Eisodos xristi arithmou menu*/

    if (selection=='1')                                                                           /*Menu1 emfanisi plithous kenon thesewn kai arithmou tous*/
        {
        for (i=0; i<numberofseats; i++)                                                           /*for loop apo 0 ews numberofseats-1 (logo tou 0) me vima 1*/
            {seatnr[i] == 0 ? freeseats = freeseats + 1 : freeseats ;}                            /*triadikos telestis gia metrima eleyhtherwn thesewn se metavliti freeseats*/
            printf ("There are %d free seats in bus %s\n", freeseats, platenr);                   /*emfanisi sinolou eleytherwn thesewn*/
            printf("Seats that are available are:\n");                                            /* emfanisi arithmon thesewn kai me ti voithia for loop kai if statement*/

        for (i=0; i<numberofseats; i++)                                                 /*for loop apo 0 ews numberofseats-1 (logo 0) me vima 1*/
            {if (seatnr[i]==0)                                                          /*elegxos se kathe mia apo tis theseis tou pinaka pou periexei tin pliroforia 0(eleytheri) i 1(kateilimeni) thesi gia eleytheres theseis*/
                printf ("%d\n", i+1);                                                   /*Ektiposi arithmou eleytherwn thesewn. Ektiponi i+1 giati o pinakas ksekinaei apo 0 enw oi theseis ksekinan apo 1*/
            }
        freeseats = 0;                                                                  /* Midenisma freeseats gia na einai etoimos na ksanatreksei apo tin arxi to metrima ton eleytherwn theseon an zitithei*/
        }

    else if (selection=='2')                                                                       /* Menu2 Book sigkekrimenis thesis*/
        {
        printf("Please give seat nr (between 1 and %d) that you want to book:\n", numberofseats);  /*Ektiposi minimatos*/
        scanf("%d",&temp);                                                                         /* Eisagogi apo xeiristi thesis pou thelei na kleisei*/
        if (temp >numberofseats || temp <= 0)                                                      /*Elegxos oti den exei eisaxthei arnitikos arithmos i megaliteros apo to plithos ton thesewn*/
            printf("Error: Seat nr should be between 1 and %d", numberofseats);
        else if (seatnr[temp-1]==1)                                                     /*Anazitisi ston pinaka sti thesi temp-1 (temp->ayti pou eisigage o xristis) kai elegxos an einai kateilimeni*/
            printf("Error: Seat is already booked");                                    /*Minima lathous se periptosi pou i thesi einai katilimeni*/
        else if (temp <= numberofseats && temp > 0)                                     /*Ean den einai kateilimeni grafei 1 (kateilimeni ston pinaka sti thesi temp-1(kathos o pinakas arxizei apo 0, enw o xristis vazei theseis 1-...*/
            {seatnr[temp-1] = 1;
            printf("You booked seat nr: %d", temp);                                     /*Emfanisi minimatos kai arithmou thesis*/
            }
        }
     else if (selection=='3')                                                           /*Menu 3 Aytomati anazitisi eleytheris thesis se parathiro*/
        {
        for (i=0; i<(numberofseats); i++)                                               /* For loop opou diatrexei olo ton pinaka gia evresi thesewn me parathiro*/
        { item_changed=0;

            {   if ((i%4==0) && i<(numberofseats-5)&&(seatnr[i]==0))                    /*Elegxos gia to an einai se parathiro (aristero) kai oxi stin galaria(5 theseis)& an einai eleytheri*/
                {
                    seatnr[i]=1;                                                        /*Kratisi thesis*/
                    printf("You booked seat nr %d, which is near a window",i+1);        /*Ektiposi minimatos kai arithmou thesis pou klistike*/
                    item_changed = 1;                                                   /*Allazei ti metavliti item_changed se 1. Xrisimopoiithei sto telos gia na elegxo mi iparksis thesewn se parathiro*/
                    break;                                                              /*Eksodos apo loop*/
                }


                else if ((i%4==3)&&i<(numberofseats-5)&&(seatnr[i]==0))                 /*Elegxos gia to an einai se parathiro (deksi) kai oxi stin galaria(5 theseis)& an einai eleytheri*/
                {
                    seatnr[i]=1;                                                        /*Kratisi thesis*/
                    printf("You booked seat nr %d, which is near a window",i+1);        /*Ektiposi minimatos kai arithmou thesis pou klistike*/
                    item_changed = 1;                                                   /*Allazei ti metavliti item_changed se 1. Xrisimopoiithei sto telos gia na elegxo mi iparksis thesewn se parathiro*/
                    break;                                                              /*Eksodos apo loop*/
                }
                else if (i==(numberofseats-5)&&(seatnr[i]==0))                          /*Elegxos gia thesi sto aristero parathiro tis galarias(5 theseis)& an einai eleytheri*/
                {
                    seatnr[i]=1;                                                        /*Kratisi thesis*/
                    printf("You booked seat nr %d, which is near a window",i+1);        /*Ektiposi minimatos kai arithmou thesis pou klistike*/
                    item_changed = 1;                                                   /*Allazei ti metavliti item_changed se 1. Xrisimopoiithei sto telos gia na elegxo mi iparksis thesewn se parathiro*/
                    break;                                                              /*Eksodos apo loop*/
                }
                else if (i==(numberofseats-1)&&(seatnr[i]==0))                          /*Elegxos gia thesi sto deksio parathiro tis galarias(5 theseis)& an einai eleytheri*/
                {
                    seatnr[i]=1;                                                        /*Kratisi thesis*/
                    printf("You booked seat nr %d, which is near a window",i+1);        /*Ektiposi minimatos kai arithmou thesis pou klistike*/
                    item_changed = 1;                                                   /*Allazei ti metavliti item_changed se 1. Xrisimopoiithei sto telos gia na elegxo mi iparksis thesewn se parathiro*/
                    break;                                                              /*Eksodos apo loops*/
                }

            }

        }
                       if (item_changed == 0)                                           /*Elegxos gia to an to for loop allakse kati.An oxi tote ektiposi minimatos*/
                            printf("No seat near window is available");
        }


    else if (selection=='4')                                                                        /*Menu 4 akirosi kratisis*/
        {
        printf("Please give seat nr (between 1 and %d) that you want to cancel:\n", numberofseats); /* Minima gia Eisagogi thesis apo xristi*/
        scanf("%d",&temp);                                                                          /*Eisagogi arithmou thesis apo xristi*/
        if (temp >numberofseats || temp <= 0)                                                       /*Elegxos oti o arithmos thesis iparxei*/
            printf("Error: Seat nr should be between 1 and %d", numberofseats);
        else if (seatnr[temp-1]==0)                                                                 /*Elegxos gia to an i thesi einai katilimeni. panta ston pinaka psaxnoume gia temp-1 epeidi arxizei apo 0*/
            printf("Seat if already free");
        else                                                                                        /*Akirosi kratisis*/
            {seatnr[temp-1] = 0;
            printf("You cancelled booking for seat nr: %d", temp);
            }
        }
    else if (selection=='5')                                                                                    /*Menu 5 - anazitisi gia to an sigkekrimeni thesi einai kratimeni*/
        {
        printf("Please give seat nr (between 1 and %d) that you want to check availability:\n", numberofseats); /* Minima gia Eisagogi thesis apo xristi gia elegxo diathesimotitas*/
        scanf("%d",&temp);                                                                                      /*Eisagogi arithmou thesis apo xristi*/
        if (temp >numberofseats || temp <= 0)                                                                   /*Elegxos oti o arithmos thesis iparxei*/
            printf("Error: Seat nr should be between 1 and %d", numberofseats);
        else if (seatnr[temp-1]==0)                                                                 /*Elegxos kai minima gia mi kateilimeni thesi - panta ston pinaka psaxnoume gia temp-1 epeidi arxizei apo 0*/
            printf("Seat nr %d is not booked", temp);
        else
            {seatnr[temp-1] = 1;                                                        /*Elegxos kai minima gia kateilimeni thesi-panta ston pinaka psaxnoume gia temp-1 epeidi arxizei apo 0*/
            printf ("Seat nr %d is booked", temp);
            }
        }

    else if (selection=='6')                                                            /*Menu 6 - Emfanisi listas kratimenon thesewn taksinomimenon kata ayksonta arithmo*/
        {
        printf("The following seats are booked:\n");                                    /*Emfanisi minimatos*/
        do                                                                              /* Do..while loop gia anazitisi theseon pou den exoun timi 0 ston pinaka..kai emfanisi tou arithmou tous(i+1 kathos o pinakas arxizei apo 0 enw emeis exoyme theseis apo 1*/
        {   for (i=0; i<numberofseats; i++)
                if(seatnr[i]!=0) printf("%d\n",i+1);

        }
        while (i<numberofseats);                                                        /*Kleisimo do while loop molis ftasoume ton arithmo ton thesewn tou leoforeiou*/
        }

    else if (selection=='7')                                                            /*Menu 7 - Emfanisi arithmou kikloforias kai sxediagrammatos leoforeiou*/
        {
        printf("Licence Number: %s \n",platenr);                                                        /*Emfanisei arithmou kikloforias kai allagi grammis*/
        {
            for (j = 0; j < numberofseats-5; j+=4)                                      /* Pollaplo for loop opou j antiprosopeyei seira leoforeiou.. pairnei times 0,4,8,12.... xoris tin galaria (n-5)*/
            {
            for (i=j; i < j+4; i++)                                                     /* gia kathe grammi pou ksekinaei apo 0,4,8... allo loop me vima 1 (den periexetai i galaria)*/
            {
                if (seatnr[i]==1) printf("*");                                          /*gia kathe grammi se kathe stoixeio tis vazei * se kateilimeni thesi (stoixio pinaka=1)*/
                else printf("-");                                                       /*gia kathe grammi eisagogi - stis kenes theseis -*/
                if (i==j+1) printf(" ");                                                /* eisagogi kenou sti mesi ton seiron*/
            }
        printf("\n");                                                                   /* allagi grammis prin sinexisei to loop stin epomeni grammi kai mexri ti galaria*/
            }
        for (i=numberofseats-5;i< numberofseats; i++)                                   /* gia tin galaria diatrexei tis pente times me vima 1*/
            {
            if (seatnr[i]==1) printf("*");                                          /*gia galaria  kai kathe stoixeio tis vazei * se kateilimeni thesi (stoixio pinaka=1)*/
            else printf("-");                                                       /* gia ti galaria vazei - stis kenes theseis*/
            }
        }
        }

    else if (selection=='8')                                                        /* Menu 8 - APothikeysi pinakidas kai sxediagrammatos*/
        {
        FILE * output;                                                              /* Dilosi onomatos arxeiou */
        output = fopen("output.txt","w");                                           /*dimiourgia i eggrafi pano se iparxon arxeio me onoma output.txt,  mesw tis parametrou w*/
        fprintf(output,"%s \n%s\n",platenr, "Bus Diagram:");                        /* mesw tis fprintf eksagogi pinakidas kai epikefalidas "Diagramma leoforeiou" sto arxeio output.txt. Allagi grammis opou xreiazetai*/
        for (j = 0; j < numberofseats-5; j+=4)                                      /* opos proigoumenos me pollaplo for loop, dimiourgia diagrammatos leoforeiou alla ayti ti fora me printf eggrafi sto arxeio kateytheian*/
        {
        for (i=j; i < j+4; i++)                                                     /* Opos proigoumenos gia kathe seira (orizetai me j), vlepw kathe thesi mesw tou i kai pollaplwn loop. Apothikeysi se arxeio mesw fprintf*/
            {
            if (seatnr[i]==1) fprintf(output,"%s","*");
            else fprintf(output,"%s","-");
            if (i==j+1) fprintf(output,"%s", " " );                                 /* Eisagogi kenou opos kai prin sti mesi ton seirwn*/
            }
        fprintf(output,"%s","\n");
        }
        for (i=numberofseats-5;i< numberofseats; i++)                               /* Opos proigoumenos dimiourgia diagrammatos gia galaria, alla me fprintf apothikeysei se arxeio output.txt*/
            {
                if (seatnr[i]==1) fprintf(output,"%s","*");
                else fprintf(output,"%s", "-");
            }
        fclose(output);                                                             /* Kleisimo arxeiou*/
        printf("File saved as Output.txt");

        }
    else if(selection!='0') printf("Wrong selection\n\n");                          /* Elegxos Epilogis orthou menu*/
}
while (selection!='0');                                                             /* Kleisimo epanalipsis do..while me to pou o xristis epileksi exit*/

}
