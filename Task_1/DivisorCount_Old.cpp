#include <bits/stdc++.h>
using namespace std;
#define M 1e7 + 6
bool marked[(long)M];
vector<int> primes;
void seive()
{
    int n = M;
    marked[0] = marked[1] = true;
    for (int i = 2; i * i <= n; i++)
        if (marked[i] == false)
            for (int j = i * i; j <= n; j += i)
                marked[j] = true;

    for (int i = 0; i < n; i++)
        if (marked[i] == false)
            primes.push_back(i);
}

int divisor_count(int n)
{
    set<int> st;
    int cnt = 1, size = primes.size();
// st.insert(n)
    for (int i = 0; i < size; i++)
    {
        while (n % primes[i] == 0)
        {
            // cout << primes[i] << " " << n / primes[i] << endl;
            st.insert(primes[i]);
            st.insert(n / primes[i]);
            cnt++;
            n /= primes[i];
            // cout<<"\t"<<n<<"\n";
        }
    }
    for (auto i : st)
        cout << i << " ";
    cout << endl;
    return cnt * 2;
}

int main()
{
    seive();
    int a;
    cin >> a;
    cout << endl;

    cout << divisor_count(a) << endl;
    cout << endl;
}