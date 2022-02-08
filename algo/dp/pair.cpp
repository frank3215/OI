/*
    最优配对问题：
        在图中，对n个点两两配对，使距离之和尽量小。

    类型：
        状态压缩dp

    方程：
        d(S)=min{|PiPj|+d(S-{i}-{j})|j∈S,i=max{S}}
 */
void dp(){
    for(int S = 0; S < (1<<n); S++) {
        d[i][S] = INF;
        for(int j = 0; j < i; j++) if(S & (1<<j))
            d[i][S] = max(d[i][S], dist(i, j) + d[i-1][S^(1<<i)^(1<<j)]);
    }
}
