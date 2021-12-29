#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define MOD 1000000007
#define INF 1e18
#define endl "\n"
#define pb push_back
#define vl vector<ll>
#define vs vector<string>
#define pll pair<ll, ll>
#define ump unordered_map
#define mp make_pair
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll, vi, greater<ll>>
#define all(n) n.begin(), n.end()
#define ff first
#define ss second
#define mid(l, r) (l + (r - l) / 2)
#define bitc(n) __builtin_popcount(n)
#define forc(i, a, b) for (ll i = (a); i <= (b); i++)
#define rforc(i, a, b) for (ll i = (a); i >= (b); i--)
#define forcn(i, a, b, n) for (ll i = (a); i <= (b); i += n)
#define rforcn(i, a, b, n) for (ll i = (a); i >= (b); i -= n)
#define max(a, b) (a > b) ? a : b
#define iter(container, it) for (__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define logarr(arr, a, b)            \
    for (int z = (a); z <= (b); z++) \
        cout << (arr[z]) << " ";     \
    cout << endl;
template <typename T>
T gcd(T a, T b)
{
    if (a % b)
        return gcd(b, a % b);
    return b;
}
template <typename T>
T lcm(T a, T b) { return (a * (b / gcd(a, b))); }
template <typename T>
T iss(T a) { return ceil(sqrt(a)) == floor(sqrt(a)); }
vs tokenizer(string str, char ch)
{
    std::istringstream var((str));
    vs v;
    string t;
    while (getline((var), t, (ch)))
    {
        v.pb(t);
    }
    return v;
}

void fastcin()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll knapSack(vector<pll> pairs, ll W, ll n)
{
    ll dp[W + 1];
    memset(dp, 0, sizeof(dp));

    forc(i, 1, n)
    {
        rforc(w, W, 0)
        {
            if (pairs[i - 1].ff <= w)
                dp[w] = max(dp[w], dp[w - pairs[i - 1].ff] + pairs[i - 1].ss);
        }
    }

    return dp[W];
}

void solve()
{
    vector<pll> pairs;
    ll weight, value;
    ll n, w;
    cout << "ENTER NUMBER OF ELEMENTS : ";
    cin >> n;
    cout << "ENTER MAXIMUM CAPACITY OF KNAPSACK : ";
    cin >> w;
    cout << endl;
    forc(i, 1, n)
    {
        cout << "ENTER FOR " << i << " ELEMENT IN ORDER <WEIGHT, VALUE> : ";
        cin >> weight >> value;
        pairs.pb(mp(weight, value));
    }

    time_t start, end;

    time(&start);
    cout << "MAXIMUM VALUE OBTAINED : " << knapSack(pairs, w, n);
    time(&end);

    double time_taken = double(end - start);

    cout << "\n\nTIME TAKEN BY PROGRAM : " << fixed
         << time_taken << setprecision(5);
    cout << " SEC " << endl;
}

int main()
{
    //fastcin();

    solve();

    return 0;
}