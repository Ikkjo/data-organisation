#ifndef HASHFILE_H
#define HASHFILE_H

#define LOGICAL

#include <stdio.h>
#include "bucket.c"

FILE* openFile(char* file_name);
int createHashFile(FILE *pFile);
int initHashFile(FILE *pFile, FILE *pFilein);

FindRecordResult findRecord(FILE *pFile, long long key);
int insertRecord(FILE *pFile, Record record);
int modifyRecord(FILE *pFile, Record record);
int removeRecord(FILE *pFile, long long key);
void removeAllRecordsLogically(FILE* pFile);
void printContent(FILE *pFile, int valid_only);

#endif