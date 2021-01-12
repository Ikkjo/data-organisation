#include <stdio.h>
#include <stddef.h>
#include <string.h>

#define OK       0
#define NO_INPUT 1
#define TOO_LONG 2



void print_menu();
void get_option_from_user(int*);
void chose_file(char*);
void display_chosen_file(char*);
static int getLine(char*, char*, size_t);

int main() {
    int user_choice = -1;
    size_t fn_buffer = 101
    char file_name[fn_buffer];

    while (1){
        print_menu();
        getOptionFromUser(&user_choice);

        if (user_choice == 0) {
            break;
        }

        switch (user_choice) {
            case 1:
                chose_file(file_name);
                break;

            case 2:

                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
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
    printf("7 - Izbor aktivne datoteke\n");
    printf("0 - Izlaz iz programa\n");
    printf("\n");
}

void get_option_from_user(int* userChoice){
    printf(">>");
    scanf("%d", userChoice);
}

void chose_file(char* file_name) {
    getf("%s", file_name);
}

void display_chosen_file(char* file_name, len) {

}


static int getLine (char *prmpt, char *buff, size_t sz) {
    int ch, extra;

    // Get line with buffer overrun protection.
    if (prmpt != NULL) {
        printf ("%s", prmpt);
        fflush (stdout);
    }
    if (fgets (buff, sz, stdin) == NULL)
        return NO_INPUT;

    // If it was too long, there'll be no newline. In that case, we flush
    // to end of line so that excess doesn't affect the next call.
    if (buff[strlen(buff)-1] != '\n') {
        extra = 0;
        while (((ch = getchar()) != '\n') && (ch != EOF))
            extra = 1;
        return (extra == 1) ? TOO_LONG : OK;
    }

    // Otherwise remove newline and give string back to caller.
    buff[strlen(buff)-1] = '\0';
    return OK;

