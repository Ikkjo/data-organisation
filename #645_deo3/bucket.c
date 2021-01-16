#include "bucket.h"

#include <stdio.h>

int transformKey(long long id) {
    return id % B;
}

int nextBucketIndex(int currentIndex) {
    return (currentIndex + STEP) % B;
}

void printHeader() {
    printf("ID            Name                                      Datum proiz.      Rok   Net Weight\n");
}

void printRecord(Record record, int header) {
    if (header) {
        printHeader();
    }
    printf("%12s  %-40s  %02d-%02d-%4d %02d:%02d  %-5d %-5d \n",
           record.ID,
           record.name,
           record.productionDT.dan,
           record.productionDT.mesec,
           record.productionDT.godina,
           record.productionDT.sati,
           record.productionDT.minuti,
           record.rok,
           record.netWeight);
}

void printBucket(Bucket bucket) {
    int i;
    printHeader();
    for (i = 0; i < BUCKET_SIZE; i++) {
        printRecord(bucket.records[i], WITHOUT_HEADER);
    }
}

void printValidFromBucket(Bucket bucket) {
    int i;
    Record current_record;
    printHeader();
    for (i = 0; i < BUCKET_SIZE; i++) {
        current_record = bucket.records[i];
        if (current_record.status == ACTIVE) {
            if (current_record.netWeight < 10000 && current_record.netWeight > 0) {
                printRecord(bucket.records[i], WITHOUT_HEADER);
            }
        }


    }
}
