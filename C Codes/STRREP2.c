#include <stdlib.h>
#include <stdio.h>

int my_strlen(char s[]) {
    int i;
    i = 0;
    while (s[i] != '\0') i++;
    return i;
}

int search(char p[], char t[]) {
    int n, m, i, j;
    n = my_strlen(t);
    m = my_strlen(p);
    for (i = 0; i <= n - m; i++) {
        j = 0;
        while (j < m && p[j] == t[i + j])
            j++;
        if (j == m) return i;
    }
    return -1;
}

void replace(char p[], char t[], char r[], int pos) {
    int i, k; 
    char d[100]; // Increase the size of d to avoid overflow
    for (k = 0; k < pos; k++) d[k] = t[k];
    for (i = 0; i < my_strlen(r); i++) {
        d[k] = r[i];
        k++;
    }
    pos += my_strlen(p);
    for (i = pos; i <= my_strlen(t); i++) {
        d[k] = t[i];
        k++;
    }
    for (i = 0; i <= my_strlen(d); i++)
        t[i] = d[i];
}

int main() {
    char t[100], p[30], r[30]; // Increase the size of t to avoid overflow
    int pos;
    printf("STR : "); scanf("%[^\n]", t);
    printf("PTR : "); scanf("%s", p);
    printf("REP : "); scanf("%s", r);
    pos = search(p, t);
    if (pos == -1) {
        printf("Pattern not found\n");
        exit(0);
    }
    for (;;) {
        replace(p, t, r, pos);
        pos = search(p, t);
        if (pos == -1) break;
    }
    printf("FINAL : %s\n", t);
    return 0;
}
