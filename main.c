#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int menu1Select, sayac;
int select2 = 0;
void menu1();
void login();
int totalmoney;
int *greentheaters;
int *redtheaters;
int *bluetheaters;
int totalMoneyfunc(int a);
int price();
int ticketsale();
char ID[50];
char PW[50];
char fileID[50];
char filePW[50];
int matineselect;
int theaterNumber;
void encrypt(char *);
void hasilatgoster();
void decoding(char *);

enum secim
{
    ticket = 1,
};

enum theaters
{
    red = 1,
    blue,
    yes
};

typedef struct
{
    int matine[5][50];

} Blue;

typedef struct
{
    int matine[5][50];
} Green;

typedef struct
{
    int matine[5][50];
} Red;

typedef struct
{
    Blue b;
    Green g;
    Red r;
} theater;

enum money
{
    normalTicket = 30,
    studentTicket = 20
};

void login()
{
    printf("\t\t\t\tPROGRAMA HOSGELDINIZ\n\t\t--------------------------------------------------\n\n");
    printf("Kullanici Adi : ");
    scanf("%s", ID);
    printf("\n");
    printf("Sifre : ");
    scanf("%s", PW);
    FILE *dosya;
    dosya = fopen("sifre.txt", "r");
    if (dosya == NULL)
    {
        dosya = fopen("sifre.txt", "w+");
        encrypt(ID);
        encrypt(PW);
        fprintf(dosya, "%s\n%s", ID, PW);
    }
    else
    {

        fscanf(dosya, "%s\n%s", fileID, filePW);
        decoding(fileID);
        decoding(filePW);
        if (strcmp(ID, fileID) == 0 && strcmp(PW, filePW) == 0)
        {
            printf("\t\t\t\tGIRIS BASARILI\n\n");
        }
        else
        {
            printf("\t\t\t   KULLANICI ADI VEYA SIFRE YANLIS\n\n\n\n\n\n");
            exit(1);
        }
    }
    fclose(dosya);
}
void encrypt(char *metin)
{
    int length = strlen(metin);
    for (int i = 0; i < length; i++)
    {
        metin[i] = metin[i] + 10;
    }
}
void decoding(char *metin)
{
    int length = strlen(metin);
    for (int i = 0; i < length; i++)
    {
        metin[i] = metin[i] - 10;
    }
}

int main()
{
    login();

    theater movieTheater;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            movieTheater.r.matine[i][j] == 0;
            movieTheater.b.matine[i][j] == 0;
            movieTheater.g.matine[i][j] == 0;
        }
    }

    menu1();
    return 0;
}

void menu1()
{

    printf("\n\nBilet Satin Al : 1 \n\nSalon Doluluk bilgileri : 2\n\nHasilat Bilgileri : 3\n\n");
    scanf("%d", &menu1Select);

    switch (menu1Select)
    {
    case 1:
        select2 = ticketsale(ticket, select2);
        break;
    case 2:
        ticketsale();
        break;
    case 3:
        hasilatgoster();
        break;
    default:
        printf("\n\nHATALI SECIM YAPTINIZ LUTFEN TEKRAR DENEYINIZ");
        break;
    }
}
void hasilatgoster(){
printf("TOPLAM HASÝLAT : %d",totalmoney);
}
int ticketsale(int yonlendirme, int returned)
{
    int priceselect, totalmoney = returned;

    FILE *logtxt;

    theater movieTheater;

    switch (yonlendirme)
    {
    case ticket:

        printf("Salon Seciniz:\nRed salonu icin : 1 \nBlue salonu icin : 2 \nGreen salonu icin : 3\n");
        scanf("%d", &theaterNumber);
        printf("Matine seciniz [1-5]:  ");
        scanf("%d", &matineselect);

        switch (theaterNumber)
        {
        case red:
            srand(time(NULL));
            int redrandom = rand() % 50;
            redtheaters = movieTheater.r.matine;
            int i = ((matineselect - 10) * 50) + redrandom;
            if (*(redtheaters + i) != 1)
            {
                *(redtheaters + i) == 1;
                if (logtxt == NULL)
                {
                    printf("\n log.txt Dosyasi açilamadi.");
                }
                printf("Red salonu %d. matine %d. koltuk satin alinmistir\n", matineselect, redrandom);
                logtxt = fopen("log.txt", "a");
                fprintf(logtxt, "\t\t\t\t\t\tSALON BILGILERI", matineselect, redrandom);
                fprintf(logtxt, "\nSALON : Red\nMATINE : %d\nKOLTUK : %d \n\n", matineselect, redrandom);
                fclose(logtxt);
            }
            break;

        case blue:
            srand(time(NULL));
            int bluerandom = rand() % 50;

            bluetheaters = movieTheater.b.matine;
            int f = ((matineselect - 10) * 50) + bluerandom;
            if (*(bluetheaters + f) != 1)
            {
                *(bluetheaters + f) == 1;
                if (logtxt == NULL)
                {
                    printf("\n log.txt Dosyasi açilamadi.");
                }
                printf("Blue salonu %d. matine %d. koltuk satin alinmistir\n", matineselect, bluerandom);
                logtxt = fopen("log.txt", "a");
                fprintf(logtxt, "SALON : BLUE\nMATINE : %d\nKOLTUK : %d \n\n", matineselect, bluerandom);
                fclose(logtxt);
            }
            break;

        case yes:
            srand(time(NULL));
            int greenrandom = rand() % 50;
            greentheaters = movieTheater.g.matine;
            int h = ((matineselect - 10) * 50) + greenrandom;
            if (*(greentheaters + h) != 1)
            {
                *(greentheaters + h) == 1;
                if (logtxt == NULL)
                {
                    printf("\n log.txt Dosyasi açilamadi.");
                }
                printf("Yesil salonu %d. matine %d. koltuk satin alinmistir\n", matineselect, greenrandom);
                logtxt = fopen("log.txt", "a");
                fprintf(logtxt, "SALON : GREEN\nMATINE : %d\nKOLTUK : %d \n\n", matineselect, greenrandom);
                fclose(logtxt);
            }
            break;
        }

        price(returned);
        fclose(logtxt);
    }
}

int price(int returned)
{

    int priceselect;
    printf("Ogrenci bileti icin : 1\nTam Bilet icin : 2\n");
    scanf("%d", &priceselect);

    switch (priceselect)
    {
    case 1:

        printf("Ogrenci Ucreti : 20 TL\n");
        totalmoney += studentTicket;
        totalMoneyfunc(totalmoney);
        return totalmoney;
        menu1();
        break;
    case 2:
        printf("Tam Ucret : 30 TL\n");
        totalmoney += normalTicket;
        totalMoneyfunc(totalmoney);
        return totalmoney;
        menu1();
        break;
    default:
        printf("\nLutfen gecerli bir sayi giriniz");
        price(returned);
        break;

    }
}

int totalMoneyfunc(int a)
{

    FILE *hasilat, *programhasilat;
    hasilat = fopen("hasilat.txt", "w");
    fprintf(hasilat, "Hasilat: %d \n", a);
    fclose(hasilat);
    hasilat = fopen("hasilat.txt", "r");
}
