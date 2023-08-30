// Task: Food Delivery
// Tag: Queue, Offline query
// Date: 30/08/2023

#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

void clear_query(priority_queue<pi, vector<pi>, greater<pi>> &query, int &profit, vector<int> &ans, const int &idx) {
    while (!query.empty() and query.top().first <= profit) {
        ans[query.top().second] = idx;
        query.pop();
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    priority_queue<pi, vector<pi>, greater<pi>> query;
    queue<int> shop[3];

    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        query.push({x, i});
    }

    int profit = 0;
    int sold_cnt = 0;
    vector<int> ans(m + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int shop_id, price;
            cin >> shop_id >> price;
            shop[shop_id].push(price);
        }
        else
        {
            if ((!shop[1].empty() and !shop[2].empty() and shop[1].front() <= shop[2].front()) 
                || (!shop[1].empty() and shop[2].empty()))
            {
                profit += shop[1].front();
                shop[1].pop();
            } else {
                profit += shop[2].front();
                shop[2].pop();
            }
            sold_cnt++;
        }
        clear_query(query, profit, ans, sold_cnt);
    }

    for (int i = 1; i < ans.size(); i++) cout << ans[i] << " ";
}