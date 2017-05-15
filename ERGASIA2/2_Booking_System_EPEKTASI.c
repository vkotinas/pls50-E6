////////////////////////ERGASIA 2   12-2016/////////////////////////////////////
///////////////2.EPEKTASI SISTIMATOS KATAGRAFIS THESEWN/////////////////////////
////////////////////////KOTINAS VASILEIOS///////////////////////////////////////


#include <stdio.h>              /*Aparaitites vivliothikes. Periexei diafores input/output entoles px scanf, printf*/
#include <string.h>             /* Periexei diafores entoles xeirismou string. Px strcat,strcpy,strcmp */
#include <stdlib.h>             /* Periexei diafores entoles metatropis arithmon,desmeysis apothikeytikou
                                   xorou klp. Edo sigkekrimena periexei malloc*/
//GLOBAL VARIABLES
int i,j,numberofseats,temp;     /* Dilosi global parametron. Einai diathesima/mporoyn na xrisimopoiithoun pantou*/
char platenr[8],selection;      /* Metavlites me xaraktires-string. Epilogi menu-apothikeysi pinakidas 7 grammaton*/
char firstname[20],lastname[20]; /* Prosorini apothikeysi input gia metafora se fullname-structure*/
char phone[11];                  /*String gia prosorini apothikeysi phone number san string 10+1 thesewn opou zitite*/

//DOMI
typedef struct               /* Dilosi domis me 3 paidia kai onoma PASSENGERS*/
    {
    char fullname[40];          /*Metavliti  onomatos*/
    unsigned short phonenr[10]; /*Apothikeysi phone nr se unsigned short array 10 psifion*/
    unsigned int seatnr;        /*Apothikeysi arithmou thesis se unsigned int-Unsigned->thetikes times*/
    }PASSENGERS;                /* Onoma structure. Tha mporouse na dilothi proairetika KAI meta to typedef*/

//SINDEDEMENI LISTA GIA TO TELOS
typedef struct list1
    {
    char fullname[40];
    unsigned short phonenr[10]; /*Apothikeysi phone nr se unsigned short array 10 psifion*/
    unsigned int seatnr;        /*Apothikeysi arithmou thesis se unsigned int-Unsigned->thetikes times*/
    struct list1 *next;
    }LIST1;

//SINARTISI readfile gia diavasma arxeiou kai arxikopoiisi structure (eisagogi kai timon apo arxeio)
PASSENGERS * readfile(char *platenr, int *seatnr)  /*Sinartisi dexetai 2 input(theseis mnimis) kai paragei output sto structure*/
    {
    unsigned int seat;          /*Topiki metavliti gia prosorini apothikeysi arithmou thesis*/
    char name[40],tmp[20];      /*Topikes metavlites gia prosorini apothikeysi  FULLNAME, tmp gia prosorini apothikeysi first/last name */
    FILE *businfo;              /*Dilosi onomatos- businfo gia tin anagnosi kai xrisi arxeiou txt*/
    PASSENGERS *passenger;      /*Dilosi metavlitis passenger structure PASSENGERS. Diktis deixni se mnimi*/

    businfo = fopen ("bus.txt","r"); /*Anoigma arxeiou gia anagnosi*/
    if (businfo == NULL)            /*Elegxos iparksis arxeiou*/
        {
        printf("Error Opening File, check if file bus.txt is present"); /*Minima sfalmatos an den iparxei arxeio bus.txt*/
        exit(1);
        }
    else {                          /*Ean arxeio iparxi*/
      fscanf(businfo,"%s %d",platenr, seatnr);      /*Eisodos apo xristi global metavliton platenr kai numberofseats-diladi seatnr. Den evala &seatnr giati idi dixni mnimi*/
      fscanf(businfo,"\n");                         /*Allagi grammis sto arxeio txt*/
      printf("Bus Licence plate Nr is: %s, and Number of Seats is: %d", platenr, *seatnr);  /*Ektiposi pinakidas kai arithmou thesewn leoforeiou*/
      passenger  = (PASSENGERS *) malloc ((*seatnr)*sizeof(PASSENGERS));        /*Dinamiki desmeysi mnimis gia oli ti lista PASSENGERS. To*seatnr deixnei periexomeno thesis mnimis
                                                                                Epistrofi thesis mnimis arxis tis listas sto passenger*/
      if (passenger==NULL) {            /*Elegxos orthis desmeysis mnimis*/
         puts("Unable to Allocate Memory"); /*Minima sfalmatos me entoli puts se periptosi provlimatos desmeysis mnimis*/
         exit(1);
         }
      for (i=0;i<*seatnr;i++) {             /*Arxikopoiisi Olon ton Theseon. To *seatnr deixnei periexomeno deikti*/
         passenger[i].fullname[0] = '\0';   /* Opou onoma vazei \0 gia oles tis theseis leoforeiou*/
         passenger[i].seatnr = i+1;         /*Arxikopoiei arithmo thesewn gia kathe thesi*/
      }
      while (!feof(businfo))            /*Loop-Mexri to telos arxeiou txt*/
        {
           fscanf(businfo,"%s",tmp);     /*Diavasma eponimou apo txt kai apothikeysi se tmp*/
           strcpy(name,tmp);            /*Antigrafi metaksi 2 string. To tmp antigrafetai sto name*/
           strcat(name," ");            /*Vazei ena keno meta to eponimo*/
           fscanf(businfo,"%s",tmp);    /*Diavasma onomatos epivati kai apothikeysi se tmp*/
           strcat(name,tmp);              /*Antigrafi tou tmp meta to keno pou eixe eisagei prin*/
           fscanf(businfo,"%d",&seat);      /* Diabasma arithmou piasmenis thesis*/
           //pernao onomateponymo,thesi sto struct
           passenger[seat-1].seatnr=seat; /*Arxika pernaw tis piasmenes theseis sto structure*/
           strcpy(passenger[seat-1].fullname,name);     /*Antigrafo to onoma tis topikis metavlitis sto fullname tou structure*/
           for (i=0;i<10;i++)                       /*Loop gia diavasma 10 psifiwn unsigned short tou tilefonou*/
               fscanf(businfo,"%1hu",&passenger[seat-1].phonenr[i]); /*Diavasma apo arxeio kai kateytheian apothikeysi sto structure*/
           fscanf(businfo,"\n");                    /*Allagi grammis sto telos*/
         }
    }
    fclose(businfo);                /*Kleisimo arxeiou*/
    return passenger;               /*Epistrofi apo sinartisi timis sti metavliti passenger. Etsi ginetai i sindesi me lista Mazi me to passenger = readfile...*/
}
//SINARTISI countfreeseats
void countfreeseats(PASSENGERS *passenger) /*Sinartisi gia metrima kenon thesewn kai emfanisi tous.Eisagigi dikti  *passenger */
    {
    int freeseats = 0;                      /*Metavliti gia metrima freeseats*/
    for (j=0; j<numberofseats; j++)         /*Loop gia metrima freeseats. Prosthetei 1 kathe fora pou vriskei gemati thesi.*/
        strcmp(passenger[j].fullname,"\0")==0 ? freeseats = freeseats + 1 : freeseats ; /*Triadikos Telestis.Elegxos(Sigkrisi strings) an to fullname
                                                                                            einai \0 kai ayksisi metavlitis freeseats ean den einai*/
    printf ("There are %d Free Seats in this Bus. \n", freeseats);               /*Ektiposi arithmou eleftheron thesewn*/
    printf("Seats that are Available are:\n");

        for (j=0; j<numberofseats; j++)                 /*Loop gia ektiposi olon ton arithmon ton kenon thesewn*/
            if (strcmp(passenger[j].fullname,"\0")==0)  /*Elegxos kenis thesis me sigkrisi 2 string.\0->keno*/
                printf ("%u\n", passenger[j].seatnr);   /*Ektiposi arithmimenon eleftherwn thesewn*/

    }
//SINARTISI bookSeat
void bookSeat(PASSENGERS *target)   /*Sinartisi gia klisimo thesis k eisagogi stoixeiwn epivati.Eisago deikti target o opoios antistoixei me passenger[temp-1].Call by reference*/
    {
    char *p; /*Topikos voithitikos diktis gia metatropi string se unsigned short sto phone*/
    printf("Enter Passenger's First Name:");
    scanf("%s",firstname);          /*Eisagogi onomatos epivati */
    printf("Enter Passenger's Last Name:");
    scanf("%s",lastname);           /*Eisagogi epitheou epivati */
    strcpy(target->fullname,lastname); /*Opos prin sinenosi se fullname me keno anamesa ton firstname,lastname.*/
    strcat (target->fullname, " ");     /*Opos prin gia thesi pou epelekse o xristis gia (temp-1) thesi*/
    strcat(target->fullname,firstname);
    printf("Enter Passenger's Phone Nr(10digits):");
    scanf("%s",phone);      /*Eisagogi tilefonou se string*/
    i=0;                    /*Gia eisagogi phone. Metatropi string se unsigned short 10 thesewn. De ginetai kanenas elegxos.Theoroume oti o xristis tha valei sosta 10 psifia*/
    for (p=phone;*p!='\0';p++)
        {
        (target->phonenr[i])=*p -'0'; /*Xrisi deikti gia na deiksoume se phonenr[i], kai perasma ekei arithmou int pou dimiourgeite meso afaireseis string -0*/
        i++;
        }
    printf("Seat was succesfully booked");
    }
//SINARTISI searchpassenger
void searchpassenger(PASSENGERS *passenger, char selection) /*Sinartisi gia anazitisi epivati.Sto input exei dikti pou dexetai thesi mnimis, metavliti epilogis menu
                                                                kai voithithitikos deiktis p gia metatropi phone apo string se unsigned short*/
    {
    char tempsel,name[20],tmp[20],*p;     /*Topikes metavlites gia anazitisi.Eisagogi xristi gia tropos anazitisis, kai 2 voithitikes gia onoma*/
    unsigned short tempphone[10];          /*Topiki metavliti gia anazitisi me tilefono*/
    temp=0;                                 /*Arxikopoisi metavlitis gia elegxo se periptosi pou de vrethei epivatis*/
    if (selection == '1')                 /*Epilogi menu 1 apo xristi mesw selection*/
        {
        printf("Enter Passenger's First Name:");    /*Zitame apo xristi firstname,lastname*/
        scanf("%s",tmp);
        printf("Enter Passenger's Last Name:");
        scanf("%s",name);                          /* Kateytheian eggrafi eponimou sti metavliti name*/
        strcat (name, " ");             /*Sinenosi eponimou me ena string-keno, sto telos. */
        strcat(name,tmp);               /*Sinenosi firstname  meta to keno*/
        for (j=0;j<numberofseats;j++)   /*Loop - Gia oles tis theseis */
            {
            if (strcmp(passenger[j].fullname,name)==0) /*Sigkrine to onoma sto structure me to onoma pou edose o xristis*/
                {printf ("Passenger %s has Seat Nr #: %u\n",passenger[j].fullname,passenger[j].seatnr); /*Ean to vreis emfanise onoma kai thesi*/
                temp=1;     /*An vrethei epivatis kane metavliti temp->1.*/
                }
            }
        if (temp!=1) /*Elegxos. An i temp einai 0 epivatis de vrethike*/
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
//SINARTISI cancelseat
void cancelSeat(PASSENGERS *target){        /*Sinartisi xoris eksodo (void) gia akirosi thesis.Eisago deikti se thesi mnimis, opou eisago ti thesi tou antistoixou
                                            passenger.Call by reference.*/
    strcpy(target->fullname,"\0");          /*Kano \0 ti thesi pou epelekse o xristis sto main body..*/
    for (i=0;i<10;i++)
    target->phonenr[i]=0; /*Kano miden ola ta psifia tilefonou.Den vrika kapoio allo tropo na ta adeiazw..*/
    printf("Seat Nr %d is now Free",target->seatnr); /*Ektiposi minimatos*/

    }
//SINARTISI selectsortnm        /*Sinartisi xoris eksodo kai mia eisodo gia taksinomisi me vasi to onoma kai selection sorting algorithm*/
void selectsortnm(PASSENGERS passenger[])
    {
    char tempname[40];          /*Topiki voithitiki metavliti pou tha periexei onoma gia antallagi thesewn*/
    int h,pos,tempseat;         /*Topikes metavlites gia loop, kai antallagi thesewn kata tin taksinomisi*/
    unsigned short tempnr;      /*Topiki metavliti gia antallagi timon kata tin taksinomisi*/
    for (i=0;i<numberofseats-1;i++) /*Loop gia na diatreksw domi se oles tis theseis */
        {
        pos = i;        /*Thesi epomenis antallagis selection sorting algorithm. Mikrotero apo j kai apo pos*/
        for (j=i+1;j<numberofseats;j++)
            {
            if ((strcasecmp(passenger[j].fullname,passenger[pos].fullname))<0) /*Ean to j pou einai to epomeno tou pos einai mikrotero.
                                                                                Xrisimopoiw strcasecmp gia taksinomisi aneksartita apo MIKRA-KEFALAIA*/
                pos=j;                      /*Simiose ti thesi tou mikroterou */
            }
            if (pos!=i)
                {                       /* Ean to pos den einai iso me i*/
                strcpy(tempname,passenger[i].fullname);   /*Kane antallagi pliroforias anamesa se pos  kai tou i, dimiourgontas voithitiki metavliti tempname.
                                                            Arxika grapse sto tempname to fullname tou passenger i, to opoio prepei na metaferthei sti thesi i+1=pos. */
                strcpy(passenger[i].fullname,passenger[pos].fullname); /*Epeita metefere to passenger[pos] to opoio alfavitika einai se proigoumeni thesi sto passenger[i]*/
                strcpy(passenger[pos].fullname,tempname);  /* Metefere to palio passenger[i]=tempname, sti thesi epomenou passenger*/
                tempseat=passenger[i].seatnr;              /*Opos prin me xrisi tempseat enallagi kai ton thesewn*/
                passenger[i].seatnr=passenger[pos].seatnr;
                passenger[pos].seatnr=tempseat;

                for (h=0;h<10;h++)   /*Me for loop,opos prin allagi theseis kai tilefonon, kai me voithia prosorinis metavlitis tempnr*/
                    {tempnr=passenger[i].phonenr[h];
                    passenger[i].phonenr[h]=passenger[pos].phonenr[h];
                    passenger[pos].phonenr[h]=tempnr;
                    }

                }
        }
    }
//SINARTISI selectsortnr
void selectsortnr(PASSENGERS passenger[])   /*Sinartisi gia sortarisma me seatnr. Akolouthei tin sinartisi me sorting me onoma gia epanafora structure se arxiki morfi*/
    {
    char tempname[40];   /*Opos prin topikes metavlites*/
    int h,pos,tempseat;
    unsigned short tempnr;
    for (i=0;i<numberofseats-1;i++) /*For loop gia na diatrekso domi*/
        {
        pos = i;        /*Thesi epomenis antallagis selection sorting algorithm. Mikrotero apo j kai apo pos*/
        for (j=i+1;j<numberofseats;j++)
            {
            if (passenger[j].seatnr<passenger[pos].seatnr) /*Ean to seatnr tou j mikrotero tou seatnr tou pos (diladi tou epomenou)*/
                pos=j;                      /*Simiose ti thesi tou mikroterou */
            }
            if (pos!=i)
                {                       /* Ean to pos den einai iso me i*/
                strcpy(tempname,passenger[i].fullname);   /*Kane antallagi pliroforias anamesa se pos  kai tou i, dimiourgontas voithitiki metavliti tempname.
                                                            Arxika grapse sto tempname to fullname tou passenger i, to opoio prepei na metaferthei sti thesi i+1=pos. */
                strcpy(passenger[i].fullname,passenger[pos].fullname); /*Epeita metefere to passenger[pos] to opoio alfavitika einai se proigoumeni thesi sto passenger[i]*/
                strcpy(passenger[pos].fullname,tempname);  /* Metefere to palio passenger[i]=tempname, sti thesi epomenou passenger*/
                tempseat=passenger[i].seatnr;              /*Opos prin me xrisi tempseat enallagi kai ton thesewn*/
                passenger[i].seatnr=passenger[pos].seatnr;
                passenger[pos].seatnr=tempseat;

                for (h=0;h<10;h++)   /*Me for loop,opos prin allagi theseis kai tilefonon, kai me voithia prosorinis metavlitis tempnr*/
                    {tempnr=passenger[i].phonenr[h];
                    passenger[i].phonenr[h]=passenger[pos].phonenr[h];
                    passenger[pos].phonenr[h]=tempnr;
                    }

                }
        }

    }

//SINARTISI showList
void showList(PASSENGERS passenger[], char selection)   /*Sinartisi gia emfanisi listas epivaton analoga me epilogi xristi*/
    {
    if (selection == '1')                 /*Epilogi menu 1 apo xristi mesw selection*/
    {printf("The following Seats are Booked: \n SeatNr / Name\n\n");    /*Emfanisi epikefalidas*/
        for (i=0; i<numberofseats; i++) /*Loop gia na diatrekso domi apo 0 ews numberofseats*/
            if (strcmp(passenger[i].fullname,"\0")!=0) /*Opou de vriskei \0 sto onoma ektelei ta parakato*/
            {
                printf("\n%-8u/ ",passenger[i].seatnr); /*Ektiposi thesis,kai orizo oti tha katalamvanei 8 xaraktires othonis, gia na exw alignment me epikefalida*/
                printf("%s \n ",passenger[i].fullname); /*An alithes, Ektiposi onomatos*/
            }
    }
    if (selection == '2')                 /*Epilogi menu 2 apo xristi mesw selection*/
        {selectsortnm(passenger);   /*Klisi sinartisis selectsort gia sortarisma me onoma*/
         //EKTIPOSI  apotelesmatos. TILEFONO DEN EKTIPONO
        for (i=0; i<numberofseats; i++) /*Loop gia na diatrekso domi apo 0 ews numberofseats*/
            if (strcmp(passenger[i].fullname,"\0")!=0) /*Opou de vriskei \0 sto onoma ektelei ta parakato*/
            {
                printf("\n%-8u/ ",passenger[i].seatnr); /*Ektiposi thesis,kai orizo oti tha katalamvanei 8 xaraktires othonis, gia na exw alignment me epikefalida*/
                printf("%-40s ",passenger[i].fullname); /*An alithes, Ektiposi onomatos*/


            }
            //EPANAFORA PINAKA SE AARXIKI MORFI*/
        selectsortnr(passenger); /*Meta tin emfanisi tis taksinomimenis listas kata onoma epanafora tou structure stin arxiki morfi mesw sorting me seatnr*/
        }

    }

    //SINARTISI COPYLIST

 LIST1* copylist(LIST1 *list1, PASSENGERS *passenger)  /*Sinartisi gia antigrafi domis se sindedemeni lista*/
    {
    int h;
    LIST1 *start=NULL;      /*Diktis arxis listas*/
    for (i=0;i<numberofseats;i++)   /*loop gia na diatrekso domi*/
        {if (strcmp((passenger[i].fullname),"\0")!=0)   /*Elegxos gia to an to onoma epivati einai \0, diladi keno*/
        {list1 = (LIST1 *) malloc (sizeof(LIST1));  /*Ean epivatis iparxei, desmeyse mnimi gia lista oso kai xreiazetai gia to mikos tis listas ayti ti stigmi*/
        list1->next = NULL; /*To next tou stoixeiou tis listas ginetai null*/
        strcpy(list1->fullname,passenger[i].fullname); /*Antigrafi tou epivati sto antistoixo pedio tis listas*/
        list1->seatnr=passenger[i].seatnr;  /*Antigrafi kai tou seatnr gia ton idio epivati*/
        for (h=0;h<10;h++)   /*Me for loop,opos prin allagi theseis kai tilefonon, kai me voithia prosorinis metavlitis tempnr*/
            list1->phonenr[h]=passenger[i].phonenr[h];
        if (start ==NULL)       /*Ean to start einai Null kane to start na diksi stin arxi tis listas. Mono stin proti diatreksi efarmozetai*/
            start = list1;
        else                    /*Apo ti deyteri diatreksi kai meta efarmozetai to else*/
            {
            list1->next = start;    /*kane to next tis energis metavlitis tou list na deixnei tin proigoumeni metavliti tis listas*/
            start = list1;      /*To start isoute me tin nea metavliti */
            }
        }
        }
        return start;       /*Sinartisi epistrefi to start, diladi tin metavliti pou allazoume tora px list1[1]*/
    }
//SINARTISI writeFIle
void writeFile(LIST1 *current) /*Sinartisi gia apothikeysi arxeiou opou eisago dikti current pou deixen ise thesi tis listas*/
   {int h;
    FILE * output;                                      /* Dilosi onomatos arxeiou */
    output = fopen("output.txt","w");       /*Dimiourgia i eggrafi pano se iparxon arxeio me onoma output.txt,  Mesw tis parametrou w*/
    fprintf(output,"%s %d \n",platenr,numberofseats);    /* Mesw tis fprintf eksagogi pinakidas kai arithmou thesewn output.txt. Allagi grammis opou xreiazetai*/
    while (current !=NULL)          /* gia oso to current den einai NULL*/
        {
        fprintf(output,"%s %d ",current->fullname, current->seatnr);    /*Ektipose sto arxeio to onoma tou current*/
        for (h=0;h<10;h++)              /*Omoiws to tilefono tou current, me for loop logo unsigned integer 10 psifion*/
            fprintf(output,"%1hu",current->phonenr[h]);
        fprintf(output,"\n");
        current = current->next;        /*TO current isoute me to next tou current*/
        }

        fclose(output);                                     /* Kleisimo arxeiou*/
        printf("File Saved as Output.txt"); /*Emfanisi minimatos*/
   }
//Sinartisi reverselist
LIST1* reverselist (LIST1 *head)        /*Antistrofi ton nodes tis listas xrisimopoiwntas 1 dikti pou deixnei stin kefali tis listas */
{
    LIST1 *cursor=NULL;             /*Deiktis cursor gia na diatrekso lista kai na epistrefw thesi mnimis stoixeiou pou allazei thesi*/
    LIST1 *next;
    while(head)     /*Gia oso to head den einai NULL. Opos kseroume i ixnilatisi tis stoivas ginetai apo panw pros to head*/
    {
        next=head->next;    /*To next deixnei sto next tou head*/
        head->next=cursor;  /*To next tou head sto cursor */
        cursor=head;        /*to cursor isoute me head*/
        head=next;          /*to head isoute me next*/
    }
    return cursor;  /*Epistrefw cursor*/
}
//Sinartisi printList
void printList(LIST1 *list1)        /*Sinartisi gia ektiposi listas se arxeio meta to reverse tis*/
{
    while (list1)       /*Oso i lista den einai NULL*/
    {
        printf("%d\n", list1->fullname);    /*Ektiposi tou fullname tou steixeiou list1. */
        list1 = list1->next;                /*Pigaine sto epomeno stoixeio*/
    }
    printf("\n");
}

int main()      /*Kirios soma sinartisis- Tha mporousa na dimiourgiso kai PROTOTYPE FUNCTIONS  kai na valw to soma parakato alla tis eftiaksa oles epano*/
{
PASSENGERS *passenger, *start=NULL, *tmp;              /* Deiktis se domi*/
passenger= readfile(platenr,&numberofseats); /*Kalesma sinartisis readfile, me 2 parametrous-theseis mnimis. To platenr deixnei idi thesi
                                                mnimis epeidi einai string. Sindesi sinartisis me structure mesw tou dikti passenger*/

do{                     /*Dimiourgia Menu Epilogon, kai epanalipsi emfanisis mexri o xristis na patisei 0*/
    printf("\n\nNeo Sistima Katagrafis Thesewn Leoforeiou\n");
    printf("Please make a selection:\n\n");
    printf("0. Exit and Save Txt File\n");
    printf("1. Empty Seats \n");
    printf("2. Book Specific Seat \n");
    printf("3. Advanced Search of Booked Seats\n");
    printf("4. Cancel Seat Booking\n");
    printf("5. Show List of Booked Seats\n");
    scanf(" %c",&selection);           /*Epilogi menu apo xristi*/

    if (selection=='1')                  /*Menu 1-Arithmisi kai emfanisi kenon thesewn*/
        countfreeseats(passenger);            /*Kalese sinartisi countfreeseats. passenger deixnei se thesi mnimis passenger[0]*/

    else if (selection=='2')                                    /*Menu 2- Kratisi thesis*/
        {
        printf("Please give seat nr (between 1 and %d) that you want to book:\n", numberofseats); /*Minima pros xristi*/
        scanf("%d",&temp);                                      /*Eisagogi thesis gia kleisimo apo xristi*/
        if (temp > numberofseats || temp <= 0)                   /*Elegxos orthotitas arithmou thesis*/
            printf("Error: Seat nr should be between 1 and %d", numberofseats); /*Emfanisi sfalmatos an ektos orion*/
         else if (strcmp(passenger[temp-1].fullname,"\0")!=0)  /*An arithmos entos orion, elegxos an i thesi einai keni*/
            printf("Error: Seat is already booked");           /*An den einai keni emfanisi sfalmatos*/

        else
        bookSeat(&passenger[temp-1]);   /*An ola ok, kalese sinartisi bookSeat gia na kleiseis ti thesi.
                                        Eisago se sinartisi thesi mnimis pou antistixi se thesi, oste na mporo na kano allages-Call by reference.*/

        }

    else if (selection=='3')                                       /* Menu 3-Advanced Anazitisi*/
        {
        char tempsel;                                           /*Dimiourgia topikis metavlitis gia epipleon epilogi xristi*/
        printf("Do you want to search with Name (1) or Phone Nr (2)?\n");   /*Menu epilogon anazitisis*/
        scanf(" %c",&tempsel);                                              /*Eisagogi xristi epilogis tropou anazitisis*/
        searchpassenger(passenger,tempsel);         /*Kalw sinartisi searchpassenger me 2 input variables. 1.Diktis gia thesi mnimis passenger
                                                    2.Epilogi tou xristi*/
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
        cancelSeat(&passenger[temp-1]); /*Ean i thesi den einai keni kalw sinartisi cancelSeat me metavliti pou deixnei se thesi mnimis opos prin sto bookSeat*/
        }

    else if (selection=='5')                                                            /*Menu 5- Emfanisi listas epivaton*/
        {
        char tempsel;                                           /*Dimiourgia metavlitis gia epipleon epilogi xristi*/
        printf("Do you want to Show List of Passengers, sorted by Seat Number (1) or Name (2)?\n");   /*Menu epilogon anazitisis.De mou itan ksekathato apo ekfonisi an thelei kai triti epilogi
                                                                                                    diladi seatnr-surname-firstname, alla theoro oti einai pleonasmos*/
        scanf(" %c",&tempsel);                                              /*Eisagogi xristi*/

        showList(passenger,tempsel);                /*Kalei sinartisi showList, me input ti thesi mnimis tou passenger[0], alla kai tin epilogi tou xristi*/

        }
} while (selection!='0');   /*Epilogi Menu 0-Eksodos apo Loop*/
    {
    int h;
    selectsortnm(passenger);   /*Taksinomisi kata onoma tis domis mesw tis antistoixis sinartisis*/
    LIST1 *list1;
    list1=copylist(list1,passenger);    /*Antigrafi tis domis se lista*/

    LIST1 *current = list1;     /*Thetw to current na deixnei to prwto stoixeio tis listas*/

    current=reverselist(list1);   /*Kalo sinartisi reverselist gia na allakso seira nodes, gia na exw sosti ixnilatisi kata to grapsimo tou arxeiou*/

    writeFile(current);         /*Apothikeysi se arxeio olon ton aparaititon pliroforion*/
    }

}




