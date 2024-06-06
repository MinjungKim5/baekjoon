#include <stdio.h>
int count[2] = {0,0};

void countones(int remainder, int pow, int idx) {

    int mox, rem;
    mox = remainder/(1<<pow);
    rem = remainder%(1<<pow);
    if(pow == 0) {
        count[idx] += mox;
        return;
    }
    if (((1<<pow) - rem) < (rem % (1<<pow-1))) {
        rem = (1<<pow) - rem;
        mox += 1;
    }
    count[idx] += mox;
    pow -= 1;
    countones(rem, pow, idx);
}


int main() {
/////////////////////////////////
int n, m;
scanf("%d %d", &n, &m);
if (m < n) {
    printf("%d",n-m);
    return 0;
}

if (n == m) {
    printf("0");
    return 0;
}
int n_was_zero = 0;
if (n == 0) {
    n = 1;
    n_was_zero = 1;
}

int small, large;
for (int i = 0; i < 1000; i++) {
    int bipow = 1 << i;
    if(n*bipow == m) {
        printf("%d", n_was_zero);
        return 0;
    }
    if(n * bipow > m) {
        large = i;
        break;
    }
}
small = large-1;
int remainder;
countones(m-n*(1<<small), small, 0);
countones(n*(1<<large)-m, large, 1);

if (count[0] > count[1]) printf("%d",count[1] + n_was_zero);
else printf("%d",count[0] + n_was_zero);

/////////////////////////////////
return 0;}