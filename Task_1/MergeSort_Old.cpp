#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

void merge(vi &left, vi &right, vi &v);
void devide(vi &v);
void merge_sort(vi &v);

void merge_sort(vi &v)
{
    devide(v);
}

void devide(vi &v)
{
    int len = v.size();
    if (len <= 1)
        return;

    int mid = len / 2;
    vi left(mid), right(len - mid);

    copy(v.begin(), v.begin() + mid, left.begin());
    copy(v.begin() + mid, v.end(), right.begin());

    devide(left);
    devide(right);
    merge(left, right, v);
}

void merge(vi &left, vi &right, vi &v)
{
    int left_len = left.size(), right_len = right.size(), i = 0, l = 0, r = 0;
    while (l < left_len and r < right_len)
    {
        if (left[l] < right[r])
        {
            v[i] = left[l];
            l++;
        }
        else
        {
            v[i] = right[r];
            r++;
        }
        i++;
    }
    while (l < left_len)
    {
        v[i] = left[l];
        i++;
        l++;
    }
    while (r < right_len)
    {
        v[i] = right[r];
        i++;
        r++;
    }
}

int main()
{
    int n;
    cin >> n;
    vi v(n);
    for (auto &i : v)
        cin >> i;

    merge_sort(v);
    for (auto i : v)
        cout << i << " ";
}