#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int num_tests;
int n, gap;
int sa[100005], sb[100005];

long long ans;

int stka[100005], pa;
int stkb[100005], pb;

int good_count;

int count_close_values(int s[100005], int stk[100005], int p, int v, int pol, int por){
	// find smallest index <= v + gap
	int bl, br;
	bl = 0, br = p + 1;
	while(br - bl > 1){
		int bm = (bl + br) / 2;
		if(s[stk[bm]] <= v + gap){
			br = bm;
		}
		else{
			bl = bm;
		}
	}
	pol = max(pol, stk[br - 1] + 1);
	
	// find largest index >= v - gap
	bl = 0, br = p + 1;
	while(br - bl > 1){
		int bm = (bl + br) / 2;
		if(s[stk[bm]] >= v - gap){
			bl = bm;
		}
		else{
			br = bm;
		}
	}
	por = min(por, stk[bl]);
	return max(0, por - pol + 1);
}

void solve(){
	ans = 0;
	scanf("%d %d", &n, &gap);
	for(int i = 1; i <= n; i++){
		scanf("%d", &sa[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &sb[i]);
	}
	
	ans = 0;
	good_count = 0;
	pa = pb = 0;
	
	for(int i = 1; i <= n; i++){
		// update stka
		while(pa > 0 && sa[stka[pa]] <= sa[i]){
			good_count -= count_close_values(sb, stkb, pb, sa[stka[pa]], stka[pa - 1] + 1, stka[pa]);
			pa--;
		}
		good_count += count_close_values(sb, stkb, pb, sa[i], stka[pa] + 1, i - 1); // i - 1 is important
		stka[++pa] = i;
		
		// update stkb
		while(pb > 0 && sb[stkb[pb]] <= sb[i]){
			good_count -= count_close_values(sa, stka, pa, sb[stkb[pb]], stkb[pb - 1] + 1, stkb[pb]);
			pb--;
		}
		good_count += count_close_values(sa, stka, pa, sb[i], stkb[pb] + 1, i);
		stkb[++pb] = i;
		
		ans += good_count;
	}
	printf("%lld\n", ans);
	return;
}

int main(){
	scanf("%d", &num_tests);
	for(int t = 1; t <= num_tests; t++){
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}
