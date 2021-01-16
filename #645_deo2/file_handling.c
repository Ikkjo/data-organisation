#include "file_handling.h"

FILE* otvoriDatoteku(char *filename) {
	FILE *fajl = fopen(filename, "rb+");
	if (fajl == NULL) {
		printf("Doslo je do greske! Moguce da datoteka \"%s\" ne postoji.\n", filename);
	} else {
		printf("Datoteka \"%s\" otvorena.\n", filename);
	}
	return fajl;
}

void kreirajDatoteku(char *filename) {
	FILE *fajl = fopen(filename, "wb");
	if (fajl == NULL) {
		printf("Doslo je do greske prilikom kreiranja datoteke \"%s\"!\n", filename);
	} else {
		//upisi pocetni blok
		BLOK blok;
		strcpy(blok.slogovi[0].ID, OZNAKA_KRAJA_DATOTEKE);
		fwrite(&blok, sizeof(BLOK), 1, fajl);
		printf("Datoteka \"%s\" uspesno kreirana.\n", filename);
		fclose(fajl);
	}
}

CookiePackage *pronadjiSlog(FILE *fajl, char *ID) {
	if (fajl == NULL) {
		return NULL;
	}

	fseek(fajl, 0, SEEK_SET);
	BLOK blok;

	while (fread(&blok, sizeof(BLOK), 1, fajl)) {

		for (int i = 0; i < FBLOKIRANJA; i++) {
			if (strcmp(blok.slogovi[i].ID, OZNAKA_KRAJA_DATOTEKE) == 0) {
				//nema vise slogova
				return NULL;
			}

			if (strcmp(blok.slogovi[i].ID, ID) == 0 && !blok.slogovi[i].deleted) {
                //Ako se ID poklapa i slog NIJE logicki obrisan
                //(logicki obrisane slogove tretiramo kao da i ne
                //postoje u datoteci).

				CookiePackage *slog = (CookiePackage *)malloc(sizeof(CookiePackage));
				memcpy(slog, &blok.slogovi[i], sizeof(CookiePackage));
				return slog;
			}
		}
	}

	return NULL;
}

void dodajSlog(FILE *fajl, CookiePackage *slog) {
	if (fajl == NULL) {
		printf("Datoteka nije otvorena!\n");
		return;
	}

	CookiePackage *slogStari = pronadjiSlog(fajl, slog->ID);
	if (slogStari != NULL) {
        //U datoteci vec postoji slog sa tim evid. brojem,
        //pa ne mozemo upisati novi slog.
        printf("Vec postoji slog sa tim ID!\n");
        return;
    }

	BLOK blok;
	fseek(fajl, -sizeof(BLOK), SEEK_END); //u poslednji blok upisujemo novi slog
	fread(&blok, sizeof(BLOK), 1, fajl);

	int i;
	for (i = 0; i < FBLOKIRANJA; i++) {
		if (strcmp(blok.slogovi[i].ID, OZNAKA_KRAJA_DATOTEKE) == 0) {
            //Ovo je mesto gde se nalazi slog sa oznakom
            //kraja datoteke; tu treba upisati novi slog.
			memcpy(&blok.slogovi[i], slog, sizeof(CookiePackage));
			break;
		}
	}

	i++; //(na to mesto u bloku cemo upisati krajDatoteke)

	if (i < FBLOKIRANJA) {
        //Jos uvek ima mesta u ovom bloku, mozemo tu smestiti slog
        //sa oznakom kraja datoteke.
		strcpy(blok.slogovi[i].ID, OZNAKA_KRAJA_DATOTEKE);

		//Sada blok mozemo vratiti u datoteku.
		fseek(fajl, -sizeof(BLOK), SEEK_CUR);
		fwrite(&blok, sizeof(BLOK), 1, fajl);
	} else {
		//Nema vise mesta u tom bloku, tako da moramo
        //praviti novi blok u koji cemo upisati slog
        //sa oznakom kraja datoteke.

		//Prvo ipak moramo vratiti u datoteku blok
        //koji smo upravo popunili:
		fseek(fajl, -sizeof(BLOK), SEEK_CUR);
		fwrite(&blok, sizeof(BLOK), 1, fajl);

		//Okej, sad pravimo novi blok:
		BLOK noviBlok;
		strcpy(noviBlok.slogovi[0].ID, OZNAKA_KRAJA_DATOTEKE);
		//(vec smo na kraju datoteke, nema potrebe za fseekom)
		fwrite(&noviBlok, sizeof(BLOK), 1, fajl);
	}

	if (ferror(fajl)) {
		printf("Greska pri upisu u fajl!\n");
	} else {
		printf("Upis novog sloga zavrsen.\n");
	}
}

void ispisiSveSlogove(FILE *fajl) {
	if (fajl == NULL) {
		printf("Datoteka nije otvorena!\n");
		return;
	}

	fseek(fajl, 0, SEEK_SET);
	BLOK blok;
	int rbBloka = 0;
	printf("BL SL ID           Name                                       Rok trajanja     Net Weight\n");
	while (fread(&blok, sizeof(BLOK), 1, fajl)) {

		for (int i = 0; i < FBLOKIRANJA; i++) {
			if (strcmp(blok.slogovi[i].ID, OZNAKA_KRAJA_DATOTEKE) == 0) {
				printf("B%d S%d *\n", rbBloka, i);
                break; //citaj sledeci blok
			}


			if (!blok.slogovi[i].deleted) {
                printf("B%d S%d ", rbBloka, i);
                ispisiSlog(&blok.slogovi[i]);
                printf("\n");
            }
		}

		rbBloka++;
	}
}

void ispisiSlog(CookiePackage *slog) {
	printf("%12s  %40s  %02d-%02d-%4d %02d:%02d %5d ",
        slog->ID,
		slog->name,
		slog->useByDT.dan,
		slog->useByDT.mesec,
		slog->useByDT.godina,
		slog->useByDT.sati,
		slog->useByDT.minuti,
		slog->netWeight);
}

void ispisiSveAktuelne(FILE* fajl) {
    if (fajl == NULL) {
        printf("Datoteka nije otvorena!\n");
        return;
    }

    fseek(fajl, 0, SEEK_SET);
    BLOK blok;
    int rbBloka = 0;
    printf("BL SL ID           Name                                       Datum proiz.     Rok Net Weight\n");
    while (fread(&blok, sizeof(BLOK), 1, fajl)) {

        for (int i = 0; i < FBLOKIRANJA; i++) {
            if (strcmp(blok.slogovi[i].ID, OZNAKA_KRAJA_DATOTEKE) == 0) {
                printf("B%d S%d *\n", rbBloka, i);
                break; //citaj sledeci blok
            }


            if (!blok.slogovi[i].deleted) {
                if(blok.slogovi[i].netWeight <= 10000 && blok.slogovi[i].useByDT.godina == 2021){

                    printf("B%d S%d ", rbBloka, i);
                    ispisiSlog(&blok.slogovi[i]);
                    printf("\n");
                }

            }
        }

        rbBloka++;
    }

}

