#include <stdio.h>

int main() {
////////////////////////////////
int n;
scanf("%d",&n);
int count = 9;
while (n > 0) {
    n = n/2;
    count++;
}
printf("%d",count);
////////////////////////////////
return 0;}