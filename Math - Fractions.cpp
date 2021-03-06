#include <bits/stdc++.h>
#include "Math - Signum.cpp"
using namespace std;
struct fraction {
    long long n, d;
    fraction(long long n=0, long long d=1) : n(n), d(d) { reduce(); }
    void reduce() {
        int s = sgn(n) / sgn(d);
        n = abs(n), d = abs(d);
        int g = gcd(n, d);
        n = s * n / g, d = d / g;
    }
    bool operator==(const fraction& f) const { return n == f.n and d == f.d; }
    bool operator!=(const fraction& f) const { return not (*this == f); }
    bool operator<(const fraction& f) const { return n * f.d < d * f.n; }
    bool operator<=(const fraction& f) const { return *this < f or *this == f; }
    bool operator>(const fraction& f) const { return n * f.d > d * f.n; }
    bool operator>=(const fraction& f) const { return *this > f or *this == f; }
    fraction operator-() const { return fraction(-n, d); }
    fraction operator~() const { return fraction(d, n); }
    fraction operator+(const fraction& f) const { return fraction(n * f.d + d * f.n, d * f.d); }
    fraction operator*(const fraction& f) const { return fraction(n * f.n, d * f.d); }
    fraction operator-(const fraction& f) const { return *this + -f; }
    fraction operator/(const fraction& f) const { return *this * ~f; }
    fraction& operator=(const fraction& f) { n = f.n, d = f.d; return *this; }
    fraction& operator+=(const fraction& f) { return *this = *this + f; }
    fraction& operator-=(const fraction& f) { return *this = *this - f; }
    fraction& operator*=(const fraction& f) { return *this = *this * f; }
    fraction& operator/=(const fraction& f) { return *this = *this / f; }
    friend ostream& operator<<(ostream& os, const fraction& f) { return os << f.n << "/" << f.d; }
    friend bool operator==(long long x, const fraction& y) { return fraction(x) == y; }
    friend bool operator!=(long long x, const fraction& y) { return fraction(x) != y; }
    friend bool operator< (long long x, const fraction& y) { return fraction(x) <  y; }
    friend bool operator<=(long long x, const fraction& y) { return fraction(x) <= y; }
    friend bool operator> (long long x, const fraction& y) { return fraction(x) >  y; }
    friend bool operator>=(long long x, const fraction& y) { return fraction(x) >= y; }
    friend fraction operator+(long long x, const fraction& y) { return fraction(x) + y; }
    friend fraction operator*(long long x, const fraction& y) { return fraction(x) * y; }
    friend fraction operator-(long long x, const fraction& y) { return fraction(x) - y; }
    friend fraction operator/(long long x, const fraction& y) { return fraction(x) / y; }
};
