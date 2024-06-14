#include <stdio.h>
int main() {
    int a;
    scanf("%d", &a);
    char b[a];
    scanf("%s", b);
    int ans = 0;
    for (int i = 0; i < a; i++) {
        ans += (b[i] - 48);
    }
    printf("%d",ans);
return 0;}