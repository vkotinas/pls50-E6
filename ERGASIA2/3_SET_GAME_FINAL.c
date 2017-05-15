////////////////////////ERGASIA 2   12-2016/////////////////////////////////////
//////////////////3. PARALLAGI PAIXNIDIOU KARTWN - SET//////////////////////////
////////////////////////KOTINAS VASILEIOS///////////////////////////////////////



#include <stdio.h>      /*Eisagogi aparaititon vivliothikon.Periexei input/output entoles*/
#include <stdlib.h>     /* Periexei diafores entoles metatropis arithmon,desmeysis apothikeytikou
                            xorou klp. Edo sigkekrimena periexei rand ka*/
#include <strings.h>    /*Periexei diafores entoles xeirismou string. Px strcat,strcpy,strcmp*/
#include <time.h>       /*Gia random number -srand*/

//DOMI PLAYERS
typedef struct          /*Dimiourgia domis gia tous paiktes tou paixnidiou*/
    {
    char name[17];      /*String pou perilamvanei to onoma tou paikti*/
    char id;            /* To id tou paikti-1 xaraktiras*/
    unsigned int score;  /*To score tou paikti*/
    }PLAYERS;           /*Onoma domis*/

//DOMI CARDS
typedef struct      /*Dimiourgia domis pou tha perilamvanei ta xaraktiristika ton karton*/
    {
    char colour;        /*Metavliti pou periexei to xroma(r,g,b)*/
    char shape;         /*Metavliti pou periexei to sxima(c-t-r)*/
    char nr;            /*Metavliti pou periexei ton arithmo sximaton tis kartas(1-2-3*/
    char texture;       /*Metavliti pou periexei tin yfh(b,h,e)*/
    int selected;       /*Metavliti pou tha ginetai 1 otan einai epilegmeni karta kai vrisketai sto deck*/

    }CARDS;                     /*Onoma domis*/

//DILOSI 2D PINAKA
int MDarray[3][4];              /* Dilosi 2d array me 3 grammes kai 4 stiles*/

//Sinartisi initiatepl
void initiatepl(PLAYERS *player)  /*Sinartisi arxikopoiisis domis PLAYERS*/
    {
    int i;                      /*Topiki metavliti gia loop*/
    strcpy(player[0].name,"Marina Andreou");   /*Eggrafi onomatos paiktwn sto antistoixo pedio tis domis*/
    strcpy(player[1].name,"Kostas Grammenos");
    strcpy(player[2].name,"Maria Perdika");
    player[0].id='a';    /*Eggrafi ton id ton paiktwn sto katallilo pedio tis domis PLAYERS,pou tha xrisimopoioyntai mesa sto paixnidi gia dilosi energou paikti*/
    player[1].id='g';
    player[2].id='p';
    for(i=0;i<3;i++)      /*Arxikopoiisi tou score se 0 gia olous tous paiktes mesw loop*/
        player[i].score=0;
    }
//Sinartisi initialize
void initialize(CARDS *card)    /*Sinartisi gia arxikopoisi karton me MONADIKOUS sindiasmous! */
    {
    int i,j,k,l;                /*Topikes metavlites gia 4plo loop*/
    int current = 0;            /*Voithitikos deiktis gia prosdiorismo tis thesis -cards[current]- tis domis pou epeksergazomaste sto 4plo loop*/
    for (i=0;i<81;i++)          /*Arxikopoiisi tou pediou selected tis domis CARDS se 0. Diladi kamia karta den einai epilegmeni gia to deck*/
        card[i].selected=0;
    char color_list[] = {'r','g','b'};  /*Dilosi pithanon timon gia kathe mia apo tis parametrous tou CARDS. Edo gia to xroma*/
    char shape_list[] = {'d','e','f'};  /*Dilosi pithanon timon gia to sxima*/
    char nr_list[] = {'1','2','3'};     /*Dilosi pithanon timon gia to nr*/
    char t_list[] = {'j','k','l'};      /*Dilosi pithanon timon gia tin ifi*/
    for (i=0; i<3; i++)                 /*Dimiourgia 4plou Loop gia apodosi MONADIKON sindiasmon se kathe thesi tis domis, gia 81 monadikous sindiasmous*/
    {for (j=0; j<3; j++)
    {for (k=0; k<3; k++)
    {for (l=0; l<3; l++)
        {
        card[current].colour = color_list[i];   /*Apodosi monadikon sindiasmwn, xrisimopoiwntas to 4plo loop, xrisimopoiwntas voithitiko dikti current*/
        card[current].shape = shape_list[j];
        card[current].nr = nr_list[k];
        card[current].texture = t_list[l];
        current++;
        }}}}
    }
//Sinartisi getRandomNumber
int getRandomNumber(int Min, int Max)               /*Sinartisi gia paragogi tixaion timon me 1 eksodo,2 eisodous*/
    {
    double rnd= (double)rand()/((double)RAND_MAX+1); /*Dimiourgia random number me ti voithia sinartisis rand(prosoxi xreiazetai to srand-einai stin getNextCard*/
    return   (int)(rnd*(Max-Min+1))+Min;            /*Epistrofi tixaias timis */
    }
//Sinartisi getNextCard
void getNextCard (CARDS *card)      /*Sinartisi gia paragogi 12 tyxaiwn arithmwn kai xrisi aytwn gia epilogi 12 tixaion karton(apo tis 81*/
    {
    int i,temp,counter;         /*Topikes metavlites*/
    for(i=0;i<81;i++)           /*Loop gia midenismo ton epilegmenwn karton (xreiazetai otan theloume nea random 12ada*/
    {card[i].selected =0;}
    srand(time(NULL));          /*Xrisi srand pou iparxi sti vivliothiki time, gia tin paragogi orthon random arithmon*/
    counter=0;                  /*Metritis gia apofigi diplon karton*/
    while (counter<12)          /*Gia oso den exw 12 monadikous arithmous karton*/
        {
        temp = getRandomNumber(0,80);   /*Mesw tis sinartisis getRandomNumber, ftiakse tixaio arithmo kai valton sto temp*/
        if (card[temp].selected==0)     /*Elegxos sto selected, gia to an i karta einai idi epilegmeni. Ginetai gia apofigi diplis kartas*/
            {card[temp].selected=1;     /*Ean i karta den einai idi epilegmeni, epelekse tin (kane to selected 1)*/
            counter=counter+1;          /*Ean epelekses kapoia karta allakse to counter se 1*/
            }
        }
    }
//Sinartisi printselected
void printselected (CARDS *card)   /*Ektiposi energwn random karton+eisagogi thesis tous (se domi) ston 2D pinaka.Den exei kamia eksodo kai eisodo mia-dikti*/
    {
    int i,line=0;int col=0;     /*Topikes metavlites gia loop, kai prosdiorismo line,column 2d pinaka*/
    for (i=0;i<81;i++)          /*Loop gia oles tis metavlites cards tis domis*/
        {
        if (card[i].selected==1)    /*Ean i karta einai energi-diladi emfanizetai ston paikti*/
            {
            MDarray[line][col]=i;   /*Stin thesi 0,0 tou pinaka grapse tin thesi tis kartas sti domi*/
            printf ("\t[%c,%c,%c,%c]",card[i].colour,card[i].shape,card[i].nr,card[i].texture); /*Ektipose tis plirofories tis energis kartas*/
            col=col+1;              /*Prosthese ena ston arithmo stilis tou 2d array,wste na eisai etoimos gia epomeno perasma tou loop*/
            if (col==4)             /*Elegxos ean eftasa stin tetarti stili*/
                {
                puts("\n \n");      /*Ean exw ftasei sto telos grammis-4 stili diladi- allakse grammi*/
                line=line+1;        /*An allakseis grammi,prosthese 1 ston arithmo grammis*/
                col=0;              /*Midenise stili molis allakseis grammi wste na exeis steiles 0 ews 3 gia ti nea grammi*/
                }
            }
        }
    }
//Sinartisi gia elegxo apantisis xristis
checkAnswer(CARDS *card, int xgrid1, int ygrid1, int xgrid2, int ygrid2,int xgrid3,int ygrid3) /*Sinartisi me polles eisodous + 1 eksodo. X,y gia kathe mia epilogi tou xristi*/
    {
    int tempc1,tempc2,tempc3;        /*Topikes metavlites gia apothikeysi tou arithmou pou iparxei ston 2d pinaka kai deixnei thesi domis CARDS*/
    tempc1=MDarray[xgrid1][ygrid1]; /*Vazo x,y se 2d array kai travaw timi pou antistoixei se thesi structure gia tin proti karta pou epilextike*/
    tempc2=MDarray[xgrid2][ygrid2]; /*Omoios gia tin deyteri karta*/
    tempc3=MDarray[xgrid3][ygrid3]; /*Omoios gia tin triti*/

    int  count=(card[tempc1].colour==card[tempc2].colour && card[tempc1].colour==card[tempc3].colour)+(card[tempc1].shape==card[tempc2].shape && card[tempc1].shape==card[tempc3].shape)+
    (card[tempc1].nr==card[tempc2].nr && card[tempc1].nr==card[tempc3].nr)+(card[tempc1].texture==card[tempc2].texture && card[tempc1].texture==card[tempc3].texture);
                                            /*Elegxos gia to possa stoixeia apo tis 3 kartes einai koina kai stis 3*/
    if (count==3||count==0)   /*Ean oi kartes 3 koina stoixeia i kanena koino stoixeio*/
        {printf("\n\nCongratulations!!!\nYou have found a set.\n + 2 Points \n(Winner is the first that gets 10 points)\n\n");  /*Xristis kerdizei*/
        getNextCard(card);      /*Paragogi epomenou tixaiou deck opos proigoumenos, molis xristis vrei triada pou kerdizei*/
        return 2;               /*Epistrofi 2 apo sinartisi gia prosthesi se score antistoixou paikti*/
        }
    else        /*Se oles tis alles periptoseis(1,2 koino stoixeio*/
        {
        printf("\n\nIt's a pity.. \nYou lose 1 point (Minimum score is 0)\n\n");
        return -1; /*Epistrofi arnitikis timis apo sinartisi gia score paikti*/
        }
    }

int main(void)   /* Kirios soma programmatos*/
    {int i;
    char selection;   /*Metavliti gia dimiourgia kai epilogi menu*/
    PLAYERS player[3];  /*Dilosi arithmou metavliton tis domis PLAYERS*/
    CARDS card[81];     /*Omoiws gia CARDS*/
    initiatepl(player); /*Arxikopoisi PLAYERS mesw sinartisis initiatepl opou dexete thesi mnimis player diladi &player[0]*/
    initialize(card); /*Kalo sinartisi initialize gia na arxikopoiiso structure  CARDS me monadikous sindiasmous*/
    getNextCard(card);  /* Mesw tis sinartisi getNextCard, pairnw 12 tixaies kartes kai tis emfanizo*/
    printf("\t\t\t\t    *** Set Game***\n\t\t\t\t**Developed by vkotinas** \n\t\t\t\t* * *Christmas 2016* * *\n\n"); /*Ektiposi titlou*/
    printf("Available Players: \n\n%17s\tId\n","Player Name");      /*Ektiposi paiktwn*/
    for (i=0;i<3;i++)
        printf("%17s\t%c\n\n\n", player[i].name,player[i].id);      /*Ektiposi id paikton, ta opoia epilegei o xristis gia na ginei energos*/
    do{                                                                 /*do while loop gia kirios energeies paixnidiou*/
        printf("Current score is a: %d points, g: %d points, p:%d points\n",player[0].score,player[1].score,player[2].score); /*Ektiposi score paiktwn mexri tora*/
        printf("\nCurrent Deck oF Random Cards is: \n\n");              /*Ektiposi epikefalidas*/
        printselected(card);                                  /*Ektiponi kartes + topotheti theseis karton ston 2d pinaka stis antistoixes theseis,mesw tis sinartisis printselected*/
        printf("\n\nEnter player Id to Play or 0 to terminate. \nIf you want to shuffle cards enter something else.\n");  /*Ektiposi minimatos*/
        scanf(" %c",&selection);                    /*Eisodos xristi. Id gia na thesi energo xristi.0 Gia eksodo.Otidipote allo gia neo Deck karton*/


        if (selection=='a')         /*Ean o xristis epileksei a ginetai energos o protos paiktis*/
            {
            int tempscore,xgrid1,ygrid1,xgrid2,ygrid2,xgrid3,ygrid3;    /*topikes metavlites*/
            do     /*Do while gia elegxo orthis epilogi kartwn apo xristi kai epanemfanisi epilogon ean ginei lathos*/
                {
                printf("\n\n");         /*Ektimosi minimatos*/
                printf("Please select three cards that you consider set\n");
                printf("Select first card. Enter x(0-3),y(0-2) separated with space:");   /*Minima gia eisagogi x,y protis kartas*/
                scanf(" %d %d",&xgrid1,&ygrid1);                /*Diavase 2 noumera kai apothikeyse ta stis antistoixes metavlites*/
                printf("Select second card. Enter x(0-3),y(0-2) separated with space:");   /*Omoiws minima gia deyteri karta*/
                scanf(" %d %d",&xgrid2,&ygrid2);                                 /*Eisagogi xristi gia deyteri karta*/
                printf("Select third card. Enter x(0-3),y(0-2) separated with space:");     /*Omoiws gia triti karta*/
                scanf(" %d %d",&xgrid3,&ygrid3);
                }while ((xgrid1<0||xgrid1>3||ygrid1<0||ygrid1>2||xgrid2<0||xgrid2>3||ygrid2<0||ygrid2>2||
                    xgrid3<0||xgrid3>3||ygrid3<0||ygrid3>2)&&printf("\nPlease check your input\n"));    /*Elegxos orthis eisagogis apo xristi +
                                                                                                    error message an oxi orthi.Kleisimo topikou loop*/
            tempscore=checkAnswer(card,xgrid1,ygrid1,xgrid2,ygrid2,xgrid3,ygrid3);  /*Kalo sinartisi pou elegxi an oi kartes einai sostes stelnontas sti sinartisi x,y 3 karton
                                                                            Sinartisi epistrefei -1 an lathos epilogi i +2 an sosti, pou antistoixei sto score tou paikti*/
            if (tempscore==-1)                          /*Ean i sinartisi epestrepse -1, diladi o xristis epelekse lathos*/
                {if (player[0].score!=0)                /*Elegxos wste na min pesoume kato apo miden me tin afairesi tou -1*/
                    player[0].score=player[0].score + tempscore;    /*Allagi score -1*/
                }
            else                            /*Ean i sinartisi epestrepse +2*/
                {player[0].score=player[0].score + tempscore;   /*Prosthesi sto score tou paikti*/
                if (player[0].score>=10)        /*Elegxos oste vathmologia na min kseperasei to 10*/
                    {player[0].score=10;
                    printf("\n\n\n\nYou are the Winner, Matina Andreou!!"); /*Extra:Emfanisi minimatos gia nikiti an exei score =10*/
                    }                                                   /*Tha mporousa na kanw kai exit alla i askisi thelei na vgainoume me 0*/
                }
            }

        else if (selection=='g')     /*Akrivos idio menou kai epiloges gia deytero paikti. Des parapanw gia comment seira-seira.*/
            {
            int tempscore,xgrid1,ygrid1,xgrid2,ygrid2,xgrid3,ygrid3;
            do
                {
                printf("\n\n");
                printf("Please select three cards that you consider set\n");
                printf("Select first card. Enter x(0-3),y(0-2) separated with space:");
                scanf(" %d %d",&xgrid1,&ygrid1);
                printf("Select second card. Enter x(0-3),y(0-2) separated with space:");
                scanf(" %d %d",&xgrid2,&ygrid2);
                printf("Select third card. Enter x(0-3),y(0-2) separated with space:");
                scanf(" %d %d",&xgrid3,&ygrid3);
                }while ((xgrid1<0||xgrid1>3||ygrid1<0||ygrid1>2||xgrid2<0||xgrid2>3||ygrid2<0||ygrid2>2||
                xgrid3<0||xgrid3>3||ygrid3<0||ygrid3>2)&&printf("\nPlease check your input\n"));
                tempscore=checkAnswer(card,xgrid1,ygrid1,xgrid2,ygrid2,xgrid3,ygrid3);
                if (tempscore==-1)
                {if (player[1].score!=0)
                player[1].score=player[1].score + tempscore;
                }
                else
                {player[1].score=player[1].score + tempscore;
                if (player[1].score>=10)
                    {player[1].score=10;
                    printf("\n\n\n\nYou are the Winner,Kostas Grammenos!!");
                    }
                }
            }

        else if (selection=='p')    /*Akrivos ta idia gia trito paikti. Idia gia allon paikti omos */
            {
            int tempscore,xgrid1,ygrid1,xgrid2,ygrid2,xgrid3,ygrid3;
            do
                {
                printf("Please select three cards that you consider set\n");
                printf("Select first card. Enter x(0-3),y(0-2) separated with space:");
                scanf(" %d %d",&xgrid1,&ygrid1);
                printf("Select second card. Enter x(0-3),y(0-2) separated with space:");
                scanf(" %d %d",&xgrid2,&ygrid2);
                printf("Select third card. Enter x(0-3),y(0-2) separated with space:");
                scanf(" %d %d",&xgrid3,&ygrid3);
                }while ((xgrid1<0||xgrid1>3||ygrid1<0||ygrid1>2||xgrid2<0||xgrid2>3||ygrid2<0||ygrid2>2||
                xgrid3<0||xgrid3>3||ygrid3<0||ygrid3>2)&&printf("\nPlease check your input\n"));    /*Elegxos orthis eisagogis apo xristi + error message*/
            tempscore=checkAnswer(card,xgrid1,ygrid1,xgrid2,ygrid2,xgrid3,ygrid3);
            if (tempscore==-1)
                {if (player[2].score!=0)
                    player[2].score=player[2].score + tempscore;
                }
            else
                {player[2].score=player[2].score + tempscore;
                if (player[2].score>=10)
                   {player[2].score=10;
                    printf("\n\n\n\nYou are the Winner, Maria Perdika!!");
                   }
                }
            }

        else if (selection!='0')   /*Ean xristis pliktrologisi otidipote allo ektos apo 0, neo dect random karton*/
            {printf("\n\nGenerating New Random Deck\n\n"); /*Ektiposi minimatos.Tha mporousa na valw kai delay*/
            getNextCard(card);          /*Dimiourgia neou deck meso sinartisi*/
            }

        }while (selection!='0');                            /*Otan o xristis epileksi 0*/
            {printf ("%17s\t%2s\t%s\n","Name","Id","Score"); /*Ektiposi titlou(Name,Id,Score */
            for (i=0;i<3;i++)                               /*Loop gia ektiposi Name,Id,Score*/
                {printf("%17s\t %c \t%1hu\n",player[i].name,player[i].id,player[i].score);
            if (player[i].score>=10)        /*Ean kapoios paiktis exei 10 einai o nikitis*/
                printf("The winner is [%s]",player[i].name);
                }
            }
    }

