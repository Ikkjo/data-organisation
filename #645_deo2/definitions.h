//
// Created by Ilija on 1/12/2021.
//

#ifndef _645_DEO2_DEFINITIONS_H
#define _645_DEO2_DEFINITIONS_H

#define FBLOKIRANJA 3
#define OZNAKA_KRAJA_DATOTEKE "********"

typedef struct DateTime {
    int dan;
    int mesec;
    int godina;
    int sati;
    int minuti;
} DATETIME;

//Svaki slog predstavlja jedno pakovanje keksa.

typedef struct cp{
    char ID[12+1]; //Koristi se kao kljuc
    char name[40+1];
    DATETIME productionDT;
    int rok;
    int netWeight;
    int deleted;

}CookiePackage;

typedef struct Blok {
    CookiePackage slogovi[FBLOKIRANJA];
} BLOK;


#endif //_645_DEO2_DEFINITIONS_H
