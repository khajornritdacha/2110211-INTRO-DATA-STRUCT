// Task: Moving Median
// Tag: Fenwick Tree, Binary search, Index compression
// Date: 26/08/2023
// Note: This solution is not full solution as it gets TLE(Time Limit Exceed)
// as its time complexity is n*(logn)^2

#include <bits/stdc++.h>
using namespace std;

class FenwickTree
{
private:
    int n;
    vector<int> fen;

public:
    FenwickTree(int n)
    {
        fen.assign(n + 10, 0);
        this->n = n;
    }

    void up(int idx, int val)
    {
        for (; idx <= n; idx += idx & -idx)
        {
            fen[idx] += val;
        }
    }

    int sum(int idx)
    {
        if (idx <= 0)
            return 0;
        int res = 0;
        for (; idx; idx -= idx & -idx)
        {
            res += fen[idx];
        }
        return res;
    }
};

pair<unordered_map<int, int>, vector<int>> compress_index(const vector<int> &vec, const int n)
{
    vector<int> tmp;
    for (int i = 1; i <= n; i++)
        tmp.push_back(vec[i]);
    sort(tmp.begin(), tmp.end());
    tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
    unordered_map<int, int> res;
    for (size_t i = 0; i < tmp.size(); i++)
    {
        res[tmp[i]] = i + 1;
    }
    return {res, tmp};
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, W;
    cin >> n >> W;
    W++;
    vector<int> arr(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    auto [comp_idx, sorted_elements] = compress_index(arr, n);

    int distinct_count = comp_idx.size();
    FenwickTree fwt(distinct_count);

    for (int i = 1; i <= n; i++)
    {
        fwt.up(comp_idx[arr[i]], 1);
        if (i < W)
        {
            continue;
        }

        int l = 1, r = distinct_count, ans = -1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (fwt.sum(mid) >= (W + 1) / 2)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        cout << sorted_elements[ans - 1] << " ";

        if (i >= W)
        {
            fwt.up(comp_idx[arr[i - W + 1]], -1);
        }
    }
}