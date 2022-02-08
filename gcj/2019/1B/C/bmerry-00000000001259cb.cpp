//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

using namespace std;

/*** START OF TEMPLATE CODE ***/

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((ll) (x).size())

template<class T>
vector<T> splitstr(const string &s)
{
    istringstream in(s);
    vector<T> out;
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
    return out;
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

static void solve_case(int cas);

int main(int argc, char * const *argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    struct rlimit stack_limit;
    getrlimit(RLIMIT_STACK, &stack_limit);
    stack_limit.rlim_cur = 1024 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &stack_limit);

    if (argc >= 2)
    {
        int fd = open(argv[1], O_RDONLY);
        if (fd == -1) { perror(argv[1]); exit(1); }
        if (-1 == dup2(fd, 0)) { perror(argv[1]); exit(1); }
        if (-1 == close(fd)) { perror(argv[1]); exit(1); }
    }
    if (argc >= 3)
    {
        int fd = open(argv[2], O_WRONLY | O_CREAT, 0666);
        if (fd == -1) { perror(argv[2]); exit(1); }
        if (-1 == dup2(fd, 1)) { perror(argv[2]); exit(1); }
        if (-1 == close(fd)) { perror(argv[2]); exit(1); }
    }
    cin.exceptions(ios::failbit | ios::badbit);

    int cases;
    cin >> cases;
    for (int cas = 1; cas <= cases; cas++)
        solve_case(cas);
    return 0;
}

/*** END OF TEMPLATE CODE ***/

static void update(vi &u, const array<vi, 2> &s, int i0, int iN, int di, int K, int bias)
{
    vector<pii> hull[2];
    hull[0].emplace_back(i0 - di, INT_MAX / 2);
    hull[1].emplace_back(i0 - di, INT_MAX / 2);
    for (int i = i0; i != iN; i += di)
    {
        for (int j = 0; j < 2; j++)
        {
            while (s[j][i] >= hull[j].back().second + bias)
                hull[j].pop_back();
            hull[j].emplace_back(i, s[j][i]);
        }
        int L = 0;
        int R = hull[1].size();
        int lim = s[0][i] - K;
        while (R - L > 1)
        {
            int M = (L + R) / 2;
            if (hull[1][M].second >= lim)
                L = M;
            else
                R = M;
        }
        L = hull[1][L].first + di;
        int Q = hull[0][SZ(hull[0]) - 2].first + di;
        u[i] = di * max(di * L, di * Q);
    }
}

static void solve_case(int cas)
{
    int N, K;
    cin >> N >> K;
    array<vi, 2> s;
    s[0].resize(N);
    s[1].resize(N);
    for (int j = 0; j < 2; j++)
        for (int i = 0; i < N; i++)
            cin >> s[j][i];

    ll ans = ll(N) * ll(N + 1) / 2;
    for (int pass = 0; pass < 2; pass++)
    {
        vi uleft(N), uright(N);
        update(uleft, s, 0, N, 1, K, 1);
        update(uright, s, N - 1, -1, -1, K, 0);
        for (int i = 0; i < N; i++)
        {
            if (uleft[i] <= i && uright[i] >= i)
            {
                ll ul = i - uleft[i] + 1;
                ll ur = uright[i] - i + 1;
                ans -= ul * ur;
            }
        }

        swap(s[0], s[1]);
    }
    cout << "Case #" << cas << ": " << ans << "\n";
}
