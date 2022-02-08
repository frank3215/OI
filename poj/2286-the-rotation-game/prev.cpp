#include <cstdio>
#include <algorithm>
const int act[8][7]={
    {1, 3, 7, 12, 16, 21, 23},
    {2, 4, 9, 13, 18, 22, 24},
    {11, 10, 9, 8, 7, 6, 5},
    {20, 19, 18, 17, 16, 15, 14},
    {24, 22, 18, 13, 9, 4, 2},
    {23, 21, 16, 12, 7, 3, 1},
    {14, 15, 16, 17, 18, 19, 20},
    {5, 6, 7, 8, 9, 10, 11},
}, center[8] = {7, 8, 9, 12, 13, 16, 17, 18};
const char corr[] = "FEHGBADC";
int ans, a[25];
char s[100];
void p1(int x) {
    printf("  %d %d\n", a[x], a[x+1]);
}
void p2(int x) {
    for (int i = x; i < x+7; ++i)
        printf("%d", a[i]);
    puts("");
}
void print() {
    p1(1), p1(3), p2(5), p1(12), p2(14), p1(21), p1(23);
}
void change(char i) {
    int t = a[act[i-'A'][0]];
    for (int j = 0; j < 6; ++j) {
        a[act[i-'A'][j]] = a[act[i-'A'][j+1]];
    }
    a[act[i-'A'][6]] = t;
}
int dfs(int lev, char last) {
//  printf("%d/%d %c\n", lev, ans, last);
//  print();
    int c[4]={0, 0, 0, 0};
    for (int i = 0; i < 8; ++i) c[a[center[i]]]++;
    c[0] = std::max(c[1], std::max(c[2], c[3]));
//  printf("%d %d %d %d\n\n", c[0], c[1], c[2], c[3]);
    if (c[0] == 8) return 1;
    if (lev + (8-c[0]) > ans) return 0;
    for (int i = 'A'; i <= 'H'; ++i) {
        if (corr[i-'A'] == last) continue;
        change(i);
        s[lev] = i;
        if (dfs(lev+1, i)) return 1;
        change(corr[i-'A']);
    }
    return 0;
}

int main() {
    while (scanf("%d", a+1) && a[1]) {
        for (int i = 2; i <= 24; ++i) scanf("%d", a+i);
        for (ans = 0; !dfs(0, 0); ans++);
//      printf(" %d", ans);
        if (ans == 0) puts("No moves needed");
        else {
            s[ans] = '\0';
            printf("%s\n", s);
            printf("%d\n", a[center[0]]);
        }
    }
}
        
