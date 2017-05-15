////////////////////////ERGASIA 2   12-2016/////////////////////////////////////
///////////////1. NEO SISTIMA KATAGRAFIS THESEWN LEOFOREIO//////////////////////
////////////////////////KOTINAS VASILEIOS///////////////////////////////////////


#include <stdio.h>              /*Aparaitites vivliothikes. Periexei diafores input/output entoles px scanf, printf*/
#include <string.h>             /* Periexei diafores entoles xeirismou string. Px strcat,strcpy,strcmp */
#include <stdlib.h>             /* Periexei diafores entoles metatropis arithmon,desmeysis apothikeytikou
                                   xorou klp. Edo sigkekrimena periexei exit*/

int i,j,numberofseats,temp;     /* Dilosi global parametron. Einai diathesima/mporoyn na xrisimopoiithoun pantou*/
char platenr[8],selection;      /* Metavlites me xaraktires-string. Epilogi menu-apothikeysi pinakidas 7 grammaton*/
char firstname[20],lastname[20]; /* Prosorini apothikeysi input gia metafora se fullname-structure*/
char phone[11];                  /*String gia prosorini apothikeysi phone number san string 10+1 thesewn opou zitite*/
char *p;                         /*Dilosi dikti *p pou deixnei metepeita se thesi mnimis*/

typedef struct                  /* Dilosi domis me 3 paidia kai onoma PASSENGERS*/
    {
    char fullname[40];
    unsigned short phonenr[10]; /*Apothikeysi phone nr se unsigned short array 10 psifion*/
    unsigned int seatnr;        /*Apothikeysi arithmou thesis se unsigned int-Unsigned->thetikes times*/
    }PASSENGERS;                /* Onoma structure. Tha mporouse na dilothi proairetika KAI meta to typedef*/

void readfile(PASSENGERS passenger[]) /*Sinartisi gia diavasma arxeiou. Eisagogi deikti
                                        se sinartisi(tha mporouse na einai kai *passenger*/
    {
    char buff[60];       /*Metavliti gia diavasma grammis megistou mikous 60 xaraktiron(tha mporousa na valw kai 41 onoma+10 phone+2 thesi+2kena)*/
    FILE *businfo;       /*Dilosi onomatos- businfo gia tin anagnosi kai xrisi arxeiou txt*/
    businfo = fopen ("bus.txt","r");  /* Anoigma arxeiou bus.txt pou brisketai ston idio fakelo kai periexei plirofories leoforeiou*/
    if (businfo == NULL)              /*Elegxos iparksis arxeiou*/
        {
        printf("Error Opening File, check if file bus.txt is present"); /*Minima sfalmatos an den iparxei arxeio bus.txt*/
        exit(1);
        }
    else                                                                /*Ean arxeio iparxi*/
        {
        fscanf(businfo,"%s %d",platenr, &numberofseats);      /*Diavasma protis grammis arxeiou me scanf kai sosimo 2 metavliton*/
        printf("Bus Licence plate Nr is: %s, and Number of Seats is: %d.", platenr, numberofseats); /*Ektiposi platenr kai number of seats
                                                                                                      pou diavase apo arxeio*/
        for (j=0;j<numberofseats;j++)   /*Simplirosi domis gia oses thesis exei to leoforeio gia ti metavliti seatnr tis domis*/
            {passenger[j].seatnr=j+1;   /*Se kathe thesi tis domis, ksekinontas apo tin 0,  stin metavliti seatnr vale arithmo thesis*/
            strcpy(passenger[j].fullname,"\0"); /*Arxikopoiisi onomaton epivaton se domi me \0, pou deixnei keni thesi*/
            for (i=0;i<10;i++)
                passenger[j].phonenr[i]=0; /*Arxikopoiisi phonenr me midenika*/
            }
        while (fgets(buff,sizeof(buff),businfo)!=0) /*Diavasma ipoloipon grammon bus.txt, kai perasma olokliriom grammon se buff.Diavamsa mexri EOF*/
            {sscanf(buff, "%s %s %d %s", lastname, firstname, &temp,phone); /*Meta to diavasma spasimo tou buff se 4 metavlites*/
            strcpy(passenger[temp-1].fullname,lastname); /*Grapse sti metavliti tis domis fullname to firstname apo to arxeio an iparxei*/
            strcat (passenger[temp-1].fullname, " ");    /*Kolla meta to fisrtname ena keno*/
            strcat(passenger[temp-1].fullname,firstname);  /*Kolla meta to keno to lastname*/
            i=0;                                  /*Gia to tilefono perasma enos enos psifiou apo string se thesis pinaka unsigned short*/
            for (p=phone;*p!='\0';p++)  /*Loop me ti xrisi deikti, opou o deiktis deixnei se thesi mnimis. Se kathe perasma o deiktis deixnei epomeni thesi mnimis*/
                {
                (passenger[temp-1].phonenr[i])=*p -'0'; /*Mesw tis afairesis me '0' i 48(apo ASCII code) metatropi string se int oste na mpei se unsigned short*/
                i++;        /*Loop gia deka psifia kai ayksisi kata ena kathe fora*/
                }
            }
           }
    }

void countfreeseats(PASSENGERS passenger[]) /*Sinartisi gia metrima kenon thesewn kai emfanisi tous.Eisagigi dikti passenger[].To idio me *passenger */
    {
    int freeseats = 0;    /*Metavliti gia metrima freeseats*/
    for (j=0; j<numberofseats; j++) /*Loop gia metrima freeseats. Prosthetei 1 kathe fora pou vriskei gemati thesi.*/
        strcmp(passenger[j].fullname,"\0")==0 ? freeseats = freeseats + 1 : freeseats ; /*Elegxos(Sigkrisi strings) an to fullname einai \0 kai ayksisi metavlitis freeseats ean den einai*/
    printf ("There are %d Free Seats in this Bus. \n", freeseats); /*Ektiposi arithmou eleftheron thesewn*/
    printf("Seats that are Available are:\n");

        for (j=0; j<numberofseats; j++)    /*Loop gia ektiposi olon ton arithmon ton kenon thesewn*/
            {if (strcmp(passenger[j].fullname,"\0")==0) /*Elegxos kenis thesis me sigkrisi 2 string.\0->keno*/
                printf ("%u\n", passenger[j].seatnr); /*Ektiposi arithmimenon eleftherwn thesewn*/
            }
    }

void bookSeat(PASSENGERS *target)   /*Sinartisi gia klisimo thesis k eisagogi stoixeiwn epivati.Eisago deikti.Call by reference*/
    {
    printf("Enter Passenger's First Name:");
    scanf("%s",firstname);          /*Eisagogi onomatos epivati */
    printf("Enter Passenger's Last Name:");
    scanf("%s",lastname);           /*Eisagogi epitheou epivati */
    strcpy(target->fullname,lastname); /*opos prin sinenosi se fullname me keno anamesa ton firstname,lastname*/
    strcat (target->fullname, " ");
    strcat(target->fullname,firstname);
    printf("Enter Passenger's Phone Nr(10digits):");
    scanf("%s",phone);      /*Eisagogi tilefonou se string*/
    i=0;                    /*Opos prin metatropi string se unsigned short 10 thesewn. De ginetai kanenas elegxos.Theoroume oti o xristis tha valei sosta 10 psifia*/
    for (p=phone;*p!='\0';p++)
        {
        (target->phonenr[i])=*p -'0'; /*Xrisi deikti gia na deiksoume se phonenr[i], kai perasma ekei arithmou int pou dimiourgeite meso afaireseis string -0*/
        i++;
        }
    printf("Seat was succesfully booked");
    }

void searchpassenger(PASSENGERS passenger[], char selection) /*Sinartisi gia anazitisi epivati.Sto input exei dikti opos prin,kai metavliti epilogis menu*/
    {
    char tempsel,tmpfirst[20],tmplast[20]; /*Topikes metavlites gia anazitisi*/
    unsigned short tempphone[10];          /*Topiki metavliti gia anazitisi me tilefono*/
    temp=0;    /*Arxikopoisi metavlitis gia elegxo se periptosi pou de vrethei epivatis*/
    if (selection == '1')                 /*Epilogi menu 1 apo xristi mesw selection*/
        {
        printf("Enter Passenger's First Name:");    /*Zitame apo xristi firstname,lastname*/
        scanf("%s",tmpfirst);
        printf("Enter Passenger's Last Name:");
        scanf("%s",tmplast);
        strcat (tmplast, " "); /*Sinenosi lastname me ena string-keno, sto telos. To tmplast xrisimopoiite kai san fullname*/
        strcat(tmplast,tmpfirst); /*sinenosi firstname  meta to keno*/
        for (j=0;j<numberofseats;j++) /*Gia oles tis theseis */
            {
            if (strcmp(passenger[j].fullname,tmplast)==0) /*Sigkrine to onoma sto structure me to onoma pou edose o xristis*/
                {printf ("Passenger %s has Seat Nr #: %u\n",tmpfirst,passenger[j].seatnr); /*Ean to vreis emfanise onoma kai thesi*/
                temp=1;     /*An vrethei epivatis kane metavliti temp->1.*/
                }
            }
        if (temp!=1) /*Elegxos. An i emp einai 0 epivatis de vrethike*/
            printf ("Passenger not found");

        }
    else if (selection == '2') /* An epilogi xristi to 2, anazitisi me tilefono*/
        {
        printf("Enter Passenger's Phone Nr(10 digits):");
        scanf("%s",phone);  /*Eisagogi tilefonou apo xristi*/
        i=0;
        for (p=phone;*p!='\0';p++) /*Opos proigoumenos perasma ena ena psifio apo string se prosorini unsigned short[10] */
            {
            (tempphone[i])=*p -'0'; /*Opos prin metatropi string se int meso afairesis me '0' kai eisagogi se thesi i unsigned short*/
            i++;    /*ayksise i kata 1 oste na deikseis epomeni thesi unsigned short*/
            }
        for (j=0;j<numberofseats;j++) /*Gia oles tis theseis leoforeiou(domis diladi)*/
            {if (memcmp(tempphone,passenger[j].phonenr,sizeof(tempphone))==0) /*Sigkrine mia mia tis dieythinsis mnimis tou tilefono se domi me to prosorino phone*/
                                                                                /*De xrisimopoiw strcmp giati evgaze warning.Meta apo psaksimo logo windows-Unicode sistimatos.Tha mporousa na xrisimopoiiso kai tcscmp logo UNICODE*/
                {
                printf("Passenger %s has Seat Nr %u  Booked",passenger[j].fullname,passenger[j].seatnr); /*Ektiposi onomatos ka thesis*/
                temp=1;
                }       /*An vrethei epivatis kane metavliti temp->1.*/
               }
            if (temp!=1) /*Elegxos. An i temp einai 0 epivatis de vrethike*/
            printf ("Passenger not found");
        }
    }



void cancelSeat(PASSENGERS *target){ /*Sinartisi gia akirosi thesis.Eisago deikti .Call by reference.*/
    strcpy(target->fullname,"\0");   /*Kano 0 ti thesi pou epelekse o xristis sto main body..*/
    for (i=0;i<10;i++)
    target->phonenr[i]=0; /*Kano miden ola ta psifia tilefonou*/
    printf("Seat Nr %d is now Free",target->seatnr); /*Ektiposi minimatos*/

    }

void showList(PASSENGERS passenger[])   /*Sinartisi gia emfanisi listas epivaton*/
    {
    printf("The following Seats are Booked: \n Name, PhoneNr, SeatNr\n\n");    /*Emfanisi epikefalidas*/
        for (i=0; i<numberofseats; i++) /*Loop gia na diatrekso domi*/
            if (strcmp(passenger[i].fullname,"\0")!=0) /*Opou de vriskei \0 sto onoma ektelei ta parakato*/
            {
                printf("%s, ",passenger[i].fullname); /*An alithes, Ektiposi onomatos*/
                for (j=0;j<10;j++) /*Loop gia ektiposi olon ton psifion tilefonou apo unsigned short*/
                {printf("%hu",passenger[i].phonenr[j]);}
                printf(", %u\n",passenger[i].seatnr); /*Ektiposi thesis*/
            }
    }


void writeFile(PASSENGERS passenger[]) /*Sinartisi gia apothikeysi arxeiou*/
   {
    FILE * output;                                      /* Dilosi onomatos arxeiou */
    output = fopen("output.txt","w");       /*Dimiourgia i eggrafi pano se iparxon arxeio me onoma output.txt,  Mesw tis parametrou w*/
    fprintf(output,"%s %d \n",platenr,numberofseats);    /* Mesw tis fprintf eksagogi pinakidas kai arithmou thesewn output.txt. Allagi grammis opou xreiazetai*/
    for (i=0; i<numberofseats; i++)     /*Loop gia na diatreksei domi gia olous tous epivates*/
        {if (strcmp(passenger[i].fullname,"\0")!=0) /*Ean sto onoma kapoiou epivati de vrei \0 i thesi einai katilimeni ara if alithes*/
            {
            fprintf(output,"%s ",passenger[i].fullname); /*Ean if alithes ektiposi onomatos*/
            fprintf(output,"%u ",passenger[i].seatnr);  /*Ektiposi thesis*/
            for (j=0;j<10;j++)      /*Loop gia ektiposi ena ena ta psifia*/
            fprintf(output,"%hu",passenger[i].phonenr[j]);
            fprintf(output,"%s","\n");  /*Allagi grammis*/
            }
        }
        fclose(output);                                     /* Kleisimo arxeiou*/
        printf("File Saved as Output.txt"); /*Emfanisi minimatos*/
   }

int main(void) /*Kirios soma sinartisis- Tha mporousa na dimiourgiso kai PROTOTYPE FUNCTIONS  kai na valw to soma parakato alla tis eftiaksa oles epano*/
{


PASSENGERS passenger[53];   /*Arxikopoisi metavlitis passenger sti domi PASSENGERS me megisto arithmo thesewn.
                            Arxikopoieitai giati xoris dinamiki paraxorisi mnimis exw themata me sinartisis*/
readfile(passenger);        /*Kalo sinartisi readfile me metavliti eisodou to passenger pou parapempei se lista.
                            Epeidi pinakas,passenger=&passenger[0].Deixeni diladi thesi mnimis*/

    do{                     /*Dimiourgia Menu Epilogon, kai epanalipsi emfanisis mexri o xristis na patisei 0*/
    printf("\n\nNeo Sistima Katagrafis Thesewn Leoforeiou\n");
    printf("Please make a selection:\n\n");
    printf("0. Exit and Save Txt File\n");
    printf("1. Empty Seats \n");
    printf("2. Book Specific Seat \n");
    printf("3. Advanced Search of Booked Seats\n");
    printf("4. Cancel Seat Booking\n");
    printf("5. Show List of Booked Seats\n");
    scanf(" %c",&selection);

    if (selection=='1')                  /*Menu 1-Arithmisi kai emfanisi kenon thesewn*/
        countfreeseats(passenger);        /*Kalese sinartisi countfreeseats. passenger deixnei se thesi mnimis passenger[0]*/

    else if (selection=='2')                                    /*Menu 2- Kratisi thesis*/
        {
        printf("Please give seat nr (between 1 and %d) that you want to book:\n", numberofseats);
        scanf("%d",&temp);                                      /*Eisagogi thesis apo xristi pou thelei na kleisei*/
        if (temp >numberofseats || temp <= 0)                   /*Elegxos orthotitas arithmou thesis*/
            printf("Error: Seat nr should be between 1 and %d", numberofseats); /*Emfanisi sfalmatos an ektos orion*/
         else if (strcmp(passenger[temp-1].fullname,"\0")!=0)  /*An arithmos entos orion, elegxos an i thesi einai keni*/
            printf("Error: Seat is already booked");           /*An den einai keni emfanisi sfalmatos*/

        else
        bookSeat(&passenger[temp-1]);   /*An ola ok, kalese sinartisi bookSeat gia na kleiseis ti thesi.
                                        Deixno kateytheian se thesi mnimis pou antistixi se thesi.Mporouse na ginei kai me dikti*/

        }

    else if (selection=='3')                                       /* Menu 3-Anazitisi*/
        {
        char tempsel;                                           /*Dimiourgia metavlitis gia epipleon epilogi xristi*/
        printf("Do you want to search with Name (1) or Phone Nr (2)?\n");   /*Menu epilogon anazitisis*/
        scanf(" %c",&tempsel);                                              /*Eisagogi xristi*/
        searchpassenger(passenger,tempsel);         /*Kalo sinartisi searchpassenger me 2 input variables. 1.Ithesi mnimis pou deixnei se passenger[]
                                                    2.Tin epilogi tou xristi*/
        }

    else if (selection=='4')    /* Menu 4- Akirosi kratisis*/
        {
        printf("Please give Seat Nr (between 1 and %d) that you want to Cancel Booking:\n", numberofseats);
        scanf("%d",&temp);      /*Epilogi apo xristi thesis gia akirosi*/
        if (temp >numberofseats || temp <= 0) /*Elegxos orthotitas thesis*/
            printf("Error: Seat nr should be between 1 and %d", numberofseats);
         else if (strcmp(passenger[temp-1].fullname,"\0")==0) /*Elegxos gia to an i thesi einai keni idi*/
            printf("Error: Seat is already free");

        else
        cancelSeat(&passenger[temp-1]); /*Ean i thesi den einai keni kalo sinartisi cancelSeat me metavliti pou deixnei se thesi mnimis opos prin*/
        }

    else if (selection=='5')                                                            /*Menu 5- Emfanisi listas epivaton*/
        {
            showList(passenger);        /*Kalei sinartisi showList, me input ti thesi mnimis tou passenger[0]*/

        }



    } while (selection!='0');   /*Epilogi Menu 0-Eksodos apo Loop*/
        writeFile(passenger);    /*Molis o xristis epileksi 0 kalei sinartisi writeFile gia eksagogi arxeiou epivaton*/



    }
