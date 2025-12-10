/**
 *   Advent of Code Template by DarkFalcon (Pratyay Roy)
 *   https://adventofcode.com
 *   Solved on: 2025-12-09
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

static auto __fast_io = []()
{ ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

int binToDec(string s) { return bitset<64>(s).to_ullong(); }
string decToBin(int a) { return bitset<64>(a).to_string(); }

class Solution
{
public:
    static bool cmp(const set<int> &a, const set<int> &b)
    {
        return a.size() > b.size();
    }

    // use `in >> x` for input
    void solve(istream &in = cin, ostream &out = cout)
    {
        string s;
        vvi arr;
        while (getline(in, s))
        {
            stringstream ss(s);
            vi temp(3);
            for (int i = 0; i < 3; i++)
            {
                string stemp;
                getline(ss, stemp, ',');
                temp[i] = stoll(stemp);
            }
            arr.pb(temp);
        }

        multiset<pair<int, pii>> mset;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                const auto temp = mp(sqrt(
                                         pow(arr[i][0] - arr[j][0], 2) +
                                         pow(arr[i][1] - arr[j][1], 2) +
                                         pow(arr[i][2] - arr[j][2], 2)),
                                     mp(i, j));
                mset.insert(temp);
            }
        }

        vector<set<int>> grps;

        int count = 1000;

        for (const auto &i : mset)
        {
            int f = i.second.first;
            int l = i.second.second;

            vector<set<int>>::iterator flag = grps.end(), j = grps.begin();
            while (j != grps.end())
            {
                if (j->find(f) != j->end() && j->find(l) != j->end())
                {
                    j = j + 1;
                    continue;
                }

                if (j->find(f) != j->end() || j->find(l) != j->end())
                {
                    j->insert(f);
                    j->insert(l);
                    if (flag != grps.end())
                    {
                        flag->insert(j->begin(), j->end());
                        j = grps.erase(j);
                    }
                    else
                    {
                        flag = j;
                        j = j + 1;
                    }
                }
                else
                {
                    j = j + 1;
                }
            }

            if (flag == grps.end())
            {
                set<int> temp;
                temp.insert(f);
                temp.insert(l);
                grps.pb(temp);
            }
            count--;
            if (count == 0)
                break;
        }

        sort(grps.begin(), grps.end(), cmp);

        int ans = 1;
        for (int i = 0; i < 3; i++)
        {
            if (i >= grps.size())
                continue;
            else
            {
                ans *= grps[i].size();
            }
        }
        cout << ans << endl;
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ifstream fin;
    istream *inPtr = &cin;
    vector<string> tries = {"./input.txt", "input.txt", "../input.txt"};

    for (string &p : tries)
    {
        fin.open(p);
        if (fin)
        {
            inPtr = &fin;
            break;
        }
    }

    if (inPtr == &cin)
    {
        cerr << "Failed to open input.txt\n";
        return 1;
    }

    Solution sol;
    sol.solve(*inPtr);

    return 0;
}