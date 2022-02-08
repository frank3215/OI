#include <cstdio>
#include <cstdlib>
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
int ans, a[25];
char s[100];
int t = 100;
int a[24];
int RAND() {
    return rand()*32768+rand();
}
int RAND(int N) {
    return RAND()%N;
}
void change(char i) {
    int t = a[act[i-'A'][0]];
    for (int j = 0; j < 6; ++j) {
        a[act[i-'A'][j]] = a[act[i-'A'][j+1]];
    }
    a[act[i-'A'][6]] = t;
}
int main() {
    int seed;
    FILE *fin = fopen("seed", "r");
    fscanf(fin, "%d", &seed);
    srand(seed);
    seed = RAND();
    FILE *fout = fopen("seed", "w");
    fprintf(fout, "%d", seed);
//  puts("1");
    while (t--) {
        for (int i = 0; i < 24; ++i) a[i] = i/8+1;
        std::random_shuffle(a, a+24);
        for (int i = 0; i < 24; ++i) printf("%d ", a[i]);
        puts("");
    }
    puts("0");
}


