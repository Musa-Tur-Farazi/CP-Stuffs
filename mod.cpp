template<int modulo>
struct TurInt {
    unsigned x;
    TurInt() : x() { }
    TurInt(signed sig) : x(sig) {  }
    TurInt(signed long long sig) : x(sig%modulo) { }
    TurInt pow(long long p) { TurInt res = 1, a = *this; while (p) { if (p & 1) res *= a; a *= a; p >>= 1; } return res; }
    int norm(unsigned k) { if (!(-modulo <= k && k < modulo)) k %= modulo; if (k < 0) k += modulo; return k; }
    TurInt &operator+=(TurInt that) { if ((x += that.x) >= modulo) x -= modulo; return *this; }
    TurInt &operator-=(TurInt that) { if ((x += modulo - that.x) >= modulo) x -= modulo; return *this; }
    TurInt &operator*=(TurInt that) { x = (unsigned long long)x * that.x % modulo; return *this; }
    TurInt &operator/=(TurInt that) { return (*this) *= that.pow(modulo - 2); }
    TurInt operator+(TurInt that) const { return TurInt(*this) += that; }
    TurInt operator-(TurInt that) const { return TurInt(*this) -= that; }
    TurInt operator*(TurInt that) const { return TurInt(*this) *= that; }
    TurInt operator/(TurInt that) const { return TurInt(*this) /= that; }
    friend istream& operator>>(istream &is, TurInt& a) { long long k; is >> k; a.x = a.norm(k); return is; }
    friend ostream& operator<<(ostream &os, TurInt a) { os << a.x; return os; }
    TurInt inv(){ assert(x != 0); return pow(mod - 2); }
};
typedef TurInt<mod> lint;
inline lint pw(int a,int b){
    lint res = 1;
    while (b) { if (b & 1) (res *= a); (a *= a)%=mod; b >>= 1; }
    return res;
}

