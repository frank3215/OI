#include <cstdio>
#include <cstdlib>
#include <algorithm>
int RAND() {
    return rand()*32768+rand();
}
int RAND(int N) {
    return RAND()%N;
}
int t = 100;
int a[24];
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
