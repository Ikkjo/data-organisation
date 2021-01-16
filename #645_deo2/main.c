#include <stdio.h>
#include <stddef.h>

#include "file_handling.c"

void print_menu();
void get_option_from_user(int*);
void chose_file(char*);
void display_chosen_file(char*);
void new_file();
void find_syllable(FILE*);
void new_syllable(FILE*);

int main() {
    int user_choice = -1;
    size_t fn_buffer = 101;
    char file_name[fn_buffer];
    int opened = 0;
    FILE* p_file;

    while (1){
        print_menu();
        get_option_from_user(&user_choice);

        if (user_choice == 0) {
            break;
        }

        switch (user_choice) {
            case 1:
                chose_file(file_name);
                p_file = otvoriDatoteku(file_name);
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
                    find_syllable(p_file);
                }
                break;

            case 5:
                if (!opened) {
                    printf("Niste izabrali aktivnu datoteku!");
                } else {
                    new_syllable(p_file);
                }

                break;

            case 6:
                if (!opened) {
                    printf("Niste izabrali aktivnu datoteku!");
                } else {
                    ispisiSveSlogove(p_file);
                }
                break;

            case 7:
                if (!opened) {
                    printf("Niste izabrali aktivnu datoteku!");
                } else {
                    ispisiSveAktuelne(p_file);
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
    printf("4 - Pretraga sloga u aktivnoj datoteci\n");
    printf("5 - Upis novog sloga u aktivnu datoteku\n");
    printf("6 - Prikaz svih slogova\n");
    printf("7 - Prikaz svih aktuelnih slogova\n");
    printf("0 - Izlaz iz programa\n");
    printf("\n");
}

void get_option_from_user(int* userChoice){
    printf(">>");
    scanf("%d", userChoice);

    return;
}

void chose_file(char* file_name) {
    printf("Unesi ime zeljene datoteke: \n>>");

    scanf("%s", file_name);

    return;
}

void display_chosen_file(char* file_name) {
    printf(file_name);

    return;
}

void new_file() {
    char new_file[101];

    printf("Unesi ime za novu datoteku (bez razmaka): \n>>");

    scanf("%s", new_file);

    kreirajDatoteku(new_file);
    printf("\nNova datoteka je uspesno kreirana!\n");

}

void find_syllable(FILE* file){
    CookiePackage* p_cookie = malloc(sizeof(CookiePackage));
    char ID[13];

    printf("Unesi ID sloga:\n>>");
    scanf("%s", ID);

    p_cookie = pronadjiSlog(file, ID);

    if (p_cookie != NULL) {
        ispisiSlog(p_cookie);
    } else {
        printf("Slog sa identifikacionim brojem %12s nije pronadjen", ID);
    }

}

void new_syllable(FILE* file) {
    CookiePackage new_cp;

    printf("Unesi ID sloga:\n>>");
    scanf("%s", new_cp.ID);

    printf("Unesi ime sloga:\n>>");
    scanf("%s", new_cp.name);

    printf("Rok trajanja (format: dd-mm-YYYY HH:mm)\n>>");
    scanf("%d-%d-%d %d:%d",
          &new_cp.useByDT.dan,
          &new_cp.useByDT.mesec,
          &new_cp.useByDT.godina,
          &new_cp.useByDT.sati,
          &new_cp.useByDT.minuti);

    printf("Unesi neto kolicinu:\n>>");
    scanf("%d", &new_cp.netWeight);

    new_cp.deleted = 0;

    dodajSlog(file, &new_cp);

}

