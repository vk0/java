// 1 Alter the program above that prints out the provinces, so that it prints out each province using all upper case letters. Hint: Ascii Table. Another hint:
// #include <stdio.h>

// int main(int argc, char *argv[])
// {
//   char c = 'a';
//   printf("%c - 32 = %c\n", c, c-32);
//   return 0;
// }
// a - 32 = A

// gcc -Wall -o go 9_1.c

#include <stdio.h>

int main(int argc, char *argv[])
{
    char *provinces[] = { "British Columbia", "Alberta", "Saskatchewan",
                          "Manitoba", "Ontario", "Quebec", "New Brunswick",
                          "Nova Scotia", "Prince Edward Island", "Newfoundland",
                          "Yukon", "Northwest Territories", "Nunavut"
                        };
    int i, j;
    char tmpchar;
    for (i = 0; i < 13; i++) {
        printf("provinces[%d] = %c", i, provinces[i][0]);
        j = 1;
        while (provinces[i][j] != 0) {
            tmpchar = provinces[i][j];
            if ((provinces[i][j] >= 'a') && (provinces[i][j] <= 'z')) {
                tmpchar = provinces[i][j] - 32;
            }
            printf("%c", tmpchar);
            j++;
        }
        printf("\n");
    }
    return 0;
}

// provinces[0] = BRITISH COLUMBIA
// provinces[1] = ALBERTA
// provinces[2] = SASKATCHEWAN
// provinces[3] = MANITOBA
// provinces[4] = ONTARIO
// provinces[5] = QUEBEC
// provinces[6] = NEW BRUNSWICK
// provinces[7] = NOVA SCOTIA
// provinces[8] = PRINCE EDWARD ISLAND
// provinces[9] = NEWFOUNDLAND
// provinces[10] = YUKON
// provinces[11] = NORTHWEST TERRITORIES
// provinces[12] = NUNAVUT
