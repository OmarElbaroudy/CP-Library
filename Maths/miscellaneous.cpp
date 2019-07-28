//performing fast b^p
int fastpow(int b, int p) {
    if (p == 0) return 1;
    int sq = fastpow(b, p / 2);
    sq = sq * sq;

    if (p % 2 == 1) sq = sq * b;
    return sq;
}

// find the greatest common divisor of a and b
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);

}

// find the least common multiple of a and b
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// for solving ax+by=gcd(a,b) given a & b
ll extendedeuclid(ll a, ll b, ll &x, ll &y) {
    if (a < 0) {
        ll r = extendedeuclid(-a, b, x, y);
        x *= -1;
        return r;
    }
    if (b < 0) {
        ll r = extendedeuclid(a, -b, x, y);
        y *= -1;
        return r;
    }

    if (b == 0) {
        x = 1, y = 0;
        return a;
    }

    ll g = extendedeuclid(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
}

// for solving ax+by=c given a,b & c
ll diophantine(ll a, ll b, ll c, ll &x, ll &y, bool &found) {
    ll g = extendedeuclid(a, b, x, y);
    if ((found = (c % g == 0))) x *= c / g, y *= c / g;
    return g;
}

