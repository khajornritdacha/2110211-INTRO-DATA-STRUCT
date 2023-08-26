// Task: Moving Median
// Tag: Multi set, median of subarray
// Date: 26/08/2023

#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e6 + 10;

int arr[MXN], n, W;
set<array<int, 2>> bot, top;
array<int, 2> med = {-1};

void fix()
{
    int sz = bot.size() + top.size() + 1;
    if (sz == 1)
        return;
    while (bot.size() < sz / 2)
    {
        bot.insert(med);
        med = *top.begin();
        top.erase(med);
    }
    while (bot.size() > sz / 2)
    {
        top.insert(med);
        med = *bot.rbegin();
        bot.erase(med);
    }
}

void add(array<int, 2> x)
{
    if (med[0] == -1)
        med = x;
    else if (x[0] < med[0])
        bot.insert(x);
    else
        top.insert(x);
    fix();
}

void remove(array<int, 2> x)
{
    if (x == med)
    {
        med = *bot.rbegin();
        bot.erase(med);
    }
    else if (x < med)
        bot.erase(x);
    else
        top.erase(x);
    fix();
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> W;
    W++;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= W - 1; i++)
    {
        add({arr[i], i});
    }
    for (int i = W; i <= n; i++)
    {
        add({arr[i], i});
        cout << med[0] << " ";
        remove({arr[i - W + 1], i - W + 1});
    }
}