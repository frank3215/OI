#include<bits/stdc++.h>
using namespace std;

const int M = 300000;

struct Node{
    Node *lc, *rc;
    int l, r, val;
    Node(int l = 1, int r = M << 1) {
        this->lc = this->rc = NULL;
        this->l = l;
        this->r = r;
        this->val = r - l + 1;
    }
};

struct SegTree{
    Node *rt;
    vector<long long> add;
    SegTree(void) {
        rt = new Node();
        add.clear();
    }
    int Del(Node *p, int x) {
        p->val--;
        if(p->l == p->r) return p->l;
        int mid = (p->l + p->r) >> 1;
        int lcv = p->lc ? p->lc->val : mid - p->l + 1;
        if(lcv >= x) {
            if(!p->lc) p->lc = new Node(p->l, mid);
            return Del(p->lc, x);
        } else {
            if(!p->rc) p->rc = new Node(mid + 1, p->r);
            return Del(p->rc, x - lcv);
        }
    }
}line[M + 10], row;

int n, m, q, x, y;
long long now;

int main(void) {
    scanf("%d%d%d", &n, &m, &q);
    while(q--) {
        scanf("%d%d", &x, &y);
        int id = row.Del(row.rt, x);
        if(id <= n) now = 1LL * id * m;
        else now = row.add[id - n - 1];
        if(y != m) {
            line[x].add.push_back(now);
            int id = line[x].Del(line[x].rt, y);
            if(id < m) now = 1LL * (x - 1) * m + id;
            else now = line[x].add[id - m];
        }
        row.add.push_back(now);
        printf("%lld\n", now);
    }
    return 0;
}