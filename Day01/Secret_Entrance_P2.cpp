/**
*   Advent of Code Template by DarkFalcon (Pratyay Roy)
*   https://adventofcode.com
*   Solved on: 2025-12-01
*/



#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>


#define endl '\n'
#define _ << ' ' <<
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define int long long
#define nl cout << endl;
#define SZ(A) (int)(A.size())
#define SUM(A) accumulate(all(A), 0LL)
#define print(...) cout << __VA_ARGS__ << endl
#define YN(f) cout << (f ? "YES" : "NO") << endl
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define LB(A, x) distance((A).begin(), lower_bound(all(A), (x)))
#define UB(A, x) distance((A).begin(), upper_bound(all(A), (x)))
#define UNQ(A) sort(all(A)), A.erase(unique(all(A)), A.end()), A.shrink_to_fit()
#define all(A) A.begin(), A.end()
#define rall(A) A.rbegin(), A.rend()
#define SOR(A) sort(all(A))
#define RSOR(A) sort(rall(A))
#define REV(A) reverse(all(A))
#define MAX(A) *max_element(all(A))
#define MIN(A) *min_element(all(A))



using namespace std;
using namespace __gnu_pbds;



using i128 = __int128;
using f128 = __float128;
using ld = long double;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using pii = pair<int, int>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using vvc = vector<vc>;
using vvs = vector<vs>;
using vpii = vector<pii>;

const int mod = 1000000007;
const int mod2 = 998244353;
const int INF32 = 1'010'000'000;
const ld PI = 3.1415926535897932384626;
const int INF64 = 2'020'000'000'000'000'000;


static auto __fast_io = [](){ ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();


int binToDec(string s) { return bitset<64>(s).to_ullong(); }
string decToBin(int a) { return bitset<64>(a).to_string(); }

class Solution {
public:
    // use `in >> x` for input
    void solve(istream &in = cin, ostream &out = cout) {
        string s;
        int res = 0, currPos = 50;
        while(in >> s) {
            int dir = (s[0] == 'L') ? -1 : 1;
            int count = stoi(s.substr(1));

            // number of whole rotations
            res += (count / 100);

            // if a partial rotation causes a zero CLICK
            if (currPos !=0) {
                if (dir < 0 && count % 100 >= currPos) res++;
                else if (dir > 0 && count % 100 >= abs(100 - currPos)) res++;
            }

            currPos += count * dir;
            currPos = currPos % 100;
            if (currPos < 0) currPos = 100 + currPos;
            cout << ". New position is" << currPos << endl;       
        }
        
        cout << res << endl;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ifstream fin;
    istream* inPtr = &cin;
    vector<string> tries = {"./input.txt", "input.txt", "../input.txt"};

    for (string &p : tries) {
        fin.open(p);
        if (fin) { inPtr = &fin; break; }
    }

    if (inPtr == &cin) {
        cerr << "Failed to open input.txt\n";
        return 1;
    }

    Solution sol;
    sol.solve(*inPtr);

    return 0;
}