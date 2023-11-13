void get_max(std::pair<KeyT, int> &cur, const std::pair<KeyT, int> other) {
    if (other.second > cur.second or (other.second == cur.second and mLess(other.first, cur.first))) {
        cur = other;
    }
}

std::pair<std::pair<KeyT, int>, int> dfs(node* n) {
    if (!n) return {{KeyT(), -1}, 0};
    auto [L, dep_l] = dfs(n->left);
    auto [R, dep_r] = dfs(n->right);
    auto [key_l, mx_l] = L;
    auto [key_r, mx_r] = R;
    std::pair<std::pair<KeyT, int>, int> res = {{n->data.first, abs(dep_l - dep_r)}, std::max(dep_l, dep_r) + 1};
    get_max(res.first, {key_l, mx_l});
    get_max(res.first, {key_r, mx_r});
    return res;
}

KeyT getValueOfMostImbalanceNode() {
    return dfs(mRoot).first.first;
}
