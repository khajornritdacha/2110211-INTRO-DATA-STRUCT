// Task: [d64_q1b_moving_median] Moving Median
// Tag: Median, Observation
// Note: Simplify possible cases by making each element unique by add index to it
// There are 6 possible cases 2 for insertion(< or >) and 3 for erase(<, = or >)
// If insert and erase with (< and <) or (> and >), then median should not move
// If insert and erase with opposite sign (< and >=) or (> and <=), then median should move
// By just moving median before erasing element help prevent erasing invalid iterator.

#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, w; cin >> n >> w;
	vector<int> data(n);
	for (int &x : data) cin >> x;

	set<pair<int, int>> ss;
	for (int i = 0; i < w + 1; i++) ss.insert({data[i], i});
	auto med = next(ss.begin(), w / 2);
	vector<int> ans = {med->first};

	for (int i = w + 1; i < n; i++) {
		pair<int, int> to_insert = {data[i], i};
		pair<int, int> to_erase = {data[i - w - 1], i - w - 1};

		ss.insert(to_insert);
		if (to_insert < *med and to_erase >= *med) med--;
		else if (to_insert > *med and to_erase <= *med) med++;
		ss.erase(to_erase);

		ans.push_back(med->first);
	}

	for (int x : ans) cout << x << " ";
}
