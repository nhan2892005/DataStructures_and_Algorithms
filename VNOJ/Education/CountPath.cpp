#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

class Matrix {
private:
    vector<vector<long long>> data;
    int n;

public:
    Matrix(int size) : n(size) {
        data.resize(n, vector<long long>(n, 0));
    }

    void set(int i, int j, long long val) {
        data[i][j] = val;
    }

    Matrix multiply(const Matrix& other) const {
        Matrix result(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    result.data[i][j] = (result.data[i][j] + data[i][k] * other.data[k][j]) % MOD;
                }
            }
        }
        return result;
    }

    Matrix power(long long k) {
        Matrix result(n);
        Matrix base = *this;
        for (int i = 0; i < n; i++) result.data[i][i] = 1;
        while (k > 0) {
            if (k & 1) result = result.multiply(base);
            base = base.multiply(base);
            k >>= 1;
        }
        return result;
    }

    long long sum() const {
        long long total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                total = (total + data[i][j]) % MOD;
            }
        }
        return total;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    Matrix graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph.set(u-1, v-1, 1);  // Chú ý: đỉnh được đánh số từ 1, nhưng ma trận từ 0
    }

    Matrix result = graph.power(k);
    cout << result.sum() << endl;

    return 0;
}
