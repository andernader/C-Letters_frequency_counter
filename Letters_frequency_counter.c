#include <stdio.h>
#include <string.h>
#define PADDING 10
#define PRINTABLE_LETTER_START 32
#define ASCII_SIZE 128
#define LAST_LETTER_ASCII 127

int main(){
    int ascii_letters[ASCII_SIZE] = {0};
    int temp[ASCII_SIZE] = {0};
    int c;

    char filename[100];

    FILE *fptr;

    int width = 0, length = 0;

    printf("Enter the file name with the extension : ");
    scanf("%99s", filename);

    fptr = fopen(filename, "r");

    while((c = fgetc(fptr)) != EOF){
        ascii_letters[c]++;
    }

    fclose(fptr);

    memcpy(temp, ascii_letters, sizeof(ascii_letters));

    printf("\n\n");
    for(int i = PRINTABLE_LETTER_START; i <= LAST_LETTER_ASCII; i++){
        if(ascii_letters[i] != 0)
            width++;
        if(length < ascii_letters[i])
            length = ascii_letters[i];
    }

    for(int i = length; i >= 0; i--){
        for(int s = 0; s <= PADDING; s++)
            printf(" ");
        for(int j = PRINTABLE_LETTER_START; j <= LAST_LETTER_ASCII; j++){
            if(i == temp[j] && temp[j] != 0){
                printf("# ");
                temp[j]--;
            }else if(temp[j] != 0)
                printf("  ");
        }
        printf("\n");
    }


    for(int s = 0; s <= PADDING; s++)
        printf(" ");
    for(int i = PRINTABLE_LETTER_START; i <= LAST_LETTER_ASCII; i++){
        if(ascii_letters[i] != 0)
            printf("%c ", i);
    }

    printf("\n\n\n");

    for(int i = PRINTABLE_LETTER_START; i <= LAST_LETTER_ASCII; i++){
        if(ascii_letters[i] != 0){
            for(int s = 0; s <= PADDING; s++)
                printf(" ");
            printf("%c = %3d\n", i, ascii_letters[i]);
        }
    }
    printf("\n");

    return 0;
}
