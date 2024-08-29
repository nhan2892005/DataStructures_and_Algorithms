#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const int MOD = 1e9 + 7;

class Matrix {
private:
    vector<vector<long long>> data;
    size_t rows, cols;

public:
    Matrix(size_t r, size_t c) : rows(r), cols(c) {
        data = vector<vector<long long>>(r, vector<long long>(c, 0));
    }

    void set(size_t i, size_t j, long long val) {
        data[i][j] = val % MOD;
    }

    long long get(size_t i, size_t j) const {
        return data[i][j] % MOD;
    }

    long long mulMod(long long a, long long b) const {
        long long res = 0;
        a %= MOD;
        while (b) {
            if (b & 1) res = (res + a) % MOD;
            a = (a * 2) % MOD;
            b >>= 1;
        }
        return res;
    }

    // Nhân ma trận
    Matrix operator * (const Matrix &b) {
        Matrix a = *this;

        // Kiểm tra điều kiện nhân ma trận
        if (a.cols != b.rows) {
            cout << "Error: Matrix size mismatch" << endl;
            exit(1);
        }

        Matrix c(a.rows, b.cols);
        for (int i = 0; i < a.rows; ++i)
            for (int j = 0; j < b.cols; ++j)
                for (int k = 0; k < a.cols; ++k)
                    c.set(i, j, a.get(i, k) * b.get(k, j));
        return c;
    }
    static Matrix identity(long long n) {
        Matrix a = Matrix(n, n);
        while (n--) a.set(n, n, 1);
        return a;
    }

    // Lũy thừa ma trận
    Matrix pow(long long exp) {

        // Kiểm tra điều kiện lũy thừa ma trận (là ma trận vuông)
        if (rows != cols) {
            cout << "Error: Matrix is not square" << endl;
            exit(1);
        }

        Matrix base = *this, ans = identity(rows);
        for (; exp > 0; exp >>= 1, base = base * base)
            if (exp & 1) ans = ans * base;
        return ans;
    }
};

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    long long p, q, r;
    cin >> p >> q >> r;

    if (k < n) {
        cout << a[k] << endl;
        return 0;
    }

    Matrix base(n+3, 1);
    for (int i = 0; i < n + 3; ++i) {
        base.set(i, 0, a[i]);
    }
    base.set(n, 0, 1);
    base.set(n + 1, 0, n);
    base.set(n + 2, 0, n * n);

    Matrix Transform(n + 3, n + 3);
    for (int i = 1; i <= n; ++i) {
        Transform.set(0, i - 1, c[n - i]);
    }
    Transform.set(0, n, p);
    Transform.set(0, n + 1, q);
    Transform.set(0, n + 2, r);

    // Xây dựng ma trận chuyển đổi
    // Hàng đầu tiên: các hệ số c và các hệ số cho p, q*i, r*i^2
    for (size_t i = 1; i < n; i++) {
        Transform.set(i, i + 1, 1);
    }
    base.set(n, n, 1);     
    base.set(n + 1, n, 1);   
    base.set(n + 1, n + 1, 1);
    base.set(n + 2, n, 1); 
    base.set(n + 2, n + 1, 2);
    base.set(n + 2, n + 2, 1);

    // Tính lũy thừa ma trận
    Matrix result = Transform.pow(k - n + 1);

    // Tính kết quả cuối cùng
    result = result * base;

    cout << result.get(0, 0) << endl;

    return 0;
}
