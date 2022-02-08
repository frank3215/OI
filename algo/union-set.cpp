//Disjoint-set(Data structure) A.K.A. 并查集
//set[node] means node's parent
//find
int find(int d){
    if(set[d]!=d) d=find(set[d])
    return d
}
//union
void Union(int a,int b){
    int A=find(a),B=find(b);
    if(A==B) return;
/* one can modify the following line to attach the shorter tree to the root of the taller tree
 * like if(rank[A]<rank[B]) swap(A,B); //so rank[A]>rank[B]
 * or attach the tree with fewer elements to the root of the tree having more elements
 */
    set[B]=A;
/* rank[A]=rank[A]+rank[A]==rank[B]*/
    find(a);
}
//combined
int mod(int d,int v=-1){
    int &res=set[d],root;
    if(res!=d) res=g[p[d]]=mod(set[d],v);
    else if(v>0){
        root=mod(v);
        if(root>d) res=root;
        else set[root]=d,mod(v);
    }
    return res;
}
