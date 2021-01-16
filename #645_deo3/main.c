#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "bucket.h"
#include "hash_file.c"

void print_menu();
void get_option_from_user(int*);

void chose_file(char*);
void display_chosen_file(char*);
void new_file();
void find_item(FILE*);
void new_item(FILE*);

int main() {
    int user_choice = -1;
    size_t fn_buffer = 101;
    char file_name[fn_buffer];
    int opened = 0;
    FILE* p_file = NULL;

    while (1){
        print_menu();
        get_option_from_user(&user_choice);

        if (user_choice == 0) {
            break;
        }

        switch (user_choice) {
            case 1:
                chose_file(file_name);
                p_file = openFile(file_name);
                if (p_file != NULL) {
                    opened = 1;
                }

                break;

            case 2:
                if (opened){
                    display_chosen_file(file_name);
                } else {
                    printf("Ne postoji aktivna datoteka!");
                }

                break;

            case 3:
                new_file();
                break;

            case 4:
                if (!opened) {
                    printf("Niste izabrali aktivnu datoteku!");
                } else {
                    find_item(p_file);
                }
                break;

            case 5:
                if (!opened) {
                    printf("Niste izabrali aktivnu datoteku!");
                } else {
                    new_item(p_file);
                }

                break;

            case 6:
                if (!opened) {
                    printf("Niste izabrali aktivnu datoteku!");
                } else {
                    printContent(p_file, 1);
                }
                break;

            case 7:
                if (!opened) {
                    printf("Niste izabrali aktivnu datoteku!");
                } else {
                    removeAllRecordsLogically(p_file);
                }
                break;

            default:
                printf("\nTa opcija nije ponudjena, pokusaj ponovo...\n\n");
                break;
        }

    }

    return 0;

}

void print_menu(){
    printf("\n");
    printf("1 - Izbor aktivne datoteke\n");
    printf("2 - Prikaz naziva aktivne datoteke\n");
    printf("3 - Nova datoteka\n");
    printf("4 - Pretraga keksa u aktivnoj datoteci\n");
    printf("5 - Upis novog keksa u aktivnu datoteku\n");
    printf("6 - Prikaz svih aktuelnih slogova\n");
    printf("7 - Logicko brisanje svih aktuelnih slogova\n");
    printf("0 - Izlaz iz programa\n");
    printf("\n");
}

void get_option_from_user(int* userChoice){
    printf(">>");
    scanf("%d", userChoice);
}

void chose_file(char* file_name) {
    printf("Unesi ime zeljene datoteke: \n>>");

    scanf("%s", file_name);
}

void display_chosen_file(char* file_name) {
    printf(file_name);
}

void new_file() {
    char new_file[101];
    FILE *file;

    printf("Unesi ime za novu datoteku (bez razmaka): \n>>");

    scanf("%s", new_file);
    file = fopen(new_file, "wb+");
    createHashFile(file);
    fclose(file);

}

void find_item(FILE* file){
    FindRecordResult fcpr;
    char ID[13];
    long long key = 0;

    printf("Unesi ID sloga:\n>>");
    scanf("%s", ID);

    key = strtoll(ID, NULL, 0);

    fcpr = findRecord(file, key);
    FindRecordResult *p_fcpr = &fcpr;

    if (p_fcpr != NULL) {
        printRecord(fcpr.record, 1);
    } else {
        printf("Slog sa identifikacionim brojem %12s nije pronadjen", ID);
    }

}

void new_item(FILE* file) {
    Record new_cp;
    int retVal;

    printf("Unesi ID sloga:\n>>");
    scanf("%s", new_cp.ID);

    printf("Unesi ime sloga:\n>>");
    scanf("%s", new_cp.name);

    printf("Datum proizvodnje (format: dd-mm-YYYY HH:mm)\n>>");
    scanf("%d-%d-%d %d:%d",
          &new_cp.productionDT.dan,
          &new_cp.productionDT.mesec,
          &new_cp.productionDT.godina,
          &new_cp.productionDT.sati,
          &new_cp.productionDT.minuti);

    printf("Unesi rok trajanja:\n>>");
    scanf("%d", &new_cp.rok);

    printf("Unesi neto kolicinu:\n>>");
    scanf("%d", &new_cp.netWeight);

    new_cp.status = ACTIVE;

    new_cp.key = strtoll(new_cp.ID, NULL, 0);

    retVal = insertRecord(file, new_cp);

    if(retVal == -1) {
        printf("Podatak vec postoji, ili je datoteka popunjena!\n");
    } else if (retVal == -2) {
        printf("Unos je neuspesan...\n");
    } else {
        printf("Podatak je uspesno unet!");
        fseek(file, 0, SEEK_SET);
    }

}


