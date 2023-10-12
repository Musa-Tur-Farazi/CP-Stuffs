template<class T>
struct fenwick { //1-based
    vector<T> M, A;
    fenwick() {
        M.resize(N); A.resize(N);
    }
    void update(int i, T mul, T add) {
        while (i < N) {
            M[i] += mul;
            A[i] += add;
            i |= (i + 1);
        }
    }
    void upd(int l, int r, T x) {
        update(l, x, -x * (l - 1));
        update(r, -x, x * r);
    }
    int qry(int i) {
        int mul = 0, add = 0;
        int st = i;
        while (i >= 0) {
            mul += M[i];
            add += A[i];
            i = (i & (i + 1)) - 1;
        }
        return (mul * st + add);
    }
    int qry(int l, int r) { return qry(r) - qry(l - 1); }
};
