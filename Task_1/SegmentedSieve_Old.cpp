#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
bool seive[N + 1];

void create_seive()
{
    fill(seive, seive + N + 1, true);
    seive[0] = seive[1] = false;
    for (int i = 2; i * i <= N; i++)
        if (seive[i])
            for (int j = i * i; j <= N; j += i)
                seive[j] = false;
}

vector<int> getPrimes(int N)
{
    vector<int> v;
    for (int i = 2; i <= N; i++)
        if (seive[i])
            v.push_back(i);
    return v;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    create_seive();
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;

        vector<int> primes = getPrimes(sqrt(r) + 1);
        vector<bool> dummy(r - l + 1, true);

        for (int p : primes)
        {
            int firstMultiple = max(p * p, ((l + p - 1) / p) * p);
            for (int j = firstMultiple; j <= r; j += p)
            {
                dummy[j - l] = false;
            }
        }

        for (int i = l; i <= r; i++)
        {
            if (dummy[i - l] && i != 1)
                cout << i << '\n';
        }
        cout << '\n';
    }
}
