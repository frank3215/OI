/* Before this, A lemma shoud be proved.
   let r[i] be the inverse of i modulo m.
   we know that 
        m % i = m -( m / i ) * i
   mod m on both sides and we get
        m % i = -( m / i ) * i [mod m]
   time r[m%i] and r[i] and we're done.
        r[i] = -(m/i) * r[m%i] % m [mod m]
   This gives us the algorithm:*/
r[1] = 1;
for (int i=2; i<m; ++i)
    r[i] = (m - (m/i) * r[m%i] % m) % m;
/* And to calculate the inverse of factorials:
   rfac[x] = rfac[x-1] * r[x]*/


/*
Firstly, we denote the multiplicative inverse of x mod p as inv(x,p).
1. use dp method to calculation x! mod p for x=1 ~ n (1<=n<p, p is some prime)
2. calculate inv(n!,p) utilize Extended Euclidean algorithm.
3. use dp again to calculate inv(x!,p) for x=n-1 ~ 1 with the fact inv(x!,p) * x = inv((x-1)!, p)
4. now, if we want to now inv(x,p) for some x in [1,n], we only need to calculate (x-1)! * inv(x!,p)*/
