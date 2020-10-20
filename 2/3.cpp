template <typename T>
T f(T x) {
    return x * 2;
}

char c = 5;
short s = 5;
long l = 5;
long long ll = 5;
long double ld = 5;

int main() {
    char yc = f(c);
    char ys = f(s);
    char yl = f(l);
    char yll = f(ll);
    char yld = f(ld);

    return 0;
}
