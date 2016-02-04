#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {

int i, r, temp, nums[50];

char buf[4], str[50]= { "Your Six Lucky Numbers Are: " } ;

srand(time(NULL));

for(i = 0; i < 50; i++) { nums[i] = i; }

for(i = 1; i < 50; i++) {
    r = (rand() % 49) + 1;
    temp = nums[i]; nums[i] = nums[r]; nums[r] = temp;
}

for(i = 1; i < 7; i++) {
    sprintf(buf, "%d", nums[i]);
    strcat(buf, " "); strcat(str, buf);
}

printf("\n%s\n\n", str);
return 0;
}