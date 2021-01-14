#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>

#include "definitions.h"

FILE* otvoriDatoteku(char* filename);
void kreirajDatoteku(char* filename);
CookiePackage* pronadjiSlog(FILE* fajl, char* ID);
void dodajSlog(FILE* fajl, CookiePackage* slog);
void ispisiSveSlogove(FILE* fajl);
void ispisiSlog(CookiePackage* slog);
void ispisiSveAktuelne(FILE* fajl);

#endif
