#ifndef BUCKET_H
#define BUCKET_H

#define B 7             // broj baketa
#define STEP 5          // fiksan korak
#define BUCKET_SIZE 3   // faktor baketiranja

#define WITH_HEADER 1
#define WITHOUT_HEADER 0

#define RECORD_FOUND 0

#define CODE_LEN 8
#define DATE_LEN 11

typedef enum { EMPTY = 0, ACTIVE, DELETED } RECORD_STATUS;

typedef struct DateTime {
    int dan;
    int mesec;
    int godina;
    int sati;
    int minuti;
} DATETIME;

typedef struct {
    long long key;
    char ID[12+1]; //Koristi se kao kljuc
    char name[40+1];
    DATETIME productionDT;
    int rok;
    int netWeight;
    RECORD_STATUS status; 
} Record;

typedef struct {
    Record records[BUCKET_SIZE];
} Bucket;

typedef struct {
    int ind1;           // indikator uspesnosti trazenja, 0 - uspesno, 1 - neuspesno
    int ind2;           // indikator postojanja slobodnih lokacija, 0 - nema, 1 - ima
    Bucket bucket;      
    Record record;
    int bucketIndex;    // indeks baketa sa nadjenim slogom
    int recordIndex;    // indeks sloga u baketu
} FindRecordResult;

int transformKey(long long key);
int nextBucketIndex(int currentIndex);
void printRecord(Record record, int header);
void printBucket(Bucket bucket);

#endif