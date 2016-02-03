#include <stdio.h>
#include <string.h>

int main() {
char str[7];
int i;
int flag = 1;

puts( "Enter six digits without any spaces..." ) ;

gets(str);

for(i = 0; i < 6; i++) {
    if(!isdigit(str[i])) {
        flag = 0;
    }
    if(isalpha(str[i])) {
            printf( "Letter %c Found\n" , toupper(str[i]) ) ;
        } else if(ispunct(str[i])) {
            printf( "Punctuation Found\n" ) ;
        } else if(isspace(str[i])) {
            printf( "Space Found\n" ) ;
        }
}
( flag ) ? puts("Entry Valid") : puts("Entry Invalid") ;
return 0;
}