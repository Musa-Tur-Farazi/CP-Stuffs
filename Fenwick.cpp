template <class T>
struct fenwick { //1-indexed
    int n; vector<T> t;
    fenwick() {}
    fenwick(int _n) {
        n = _n; t.assign(n + 1, 0);
    }
    T query(int i) {
        T ans = 0;
        for (; i >= 1; i -= (i & -i)) ans += t[i];
        return ans;
    }
    void upd(int i, T val) {
        if (i <= 0) return;
        for (; i <= n; i += (i & -i)) t[i] += val;
    }
    void upd(int l, int r, T val) {
        upd(l, val); upd(r + 1, -val);
    }
    inline T query(int l, int r) { return query(r) - query(l - 1); }
};
