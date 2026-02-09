#include <stdio.h>
#include <string.h>

int main() {
    char s[1000], t;
    int i, n;

    scanf("%s", s);
    n = strlen(s);

    for (i = 0; i < n / 2; i++) {
        t = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = t;
    }

    printf("%s", s);
    return 0;
}
