#include <bits/stdc++.h>
using namespace std;

class Matrix {
private:
    vector<vector<double>> data;

public:
    Matrix(int size = 2) : data(size, vector<double>(size, 0.0)) {}

    void InitMood(double p) {
        data = {{1-p, p}, {p, 1-p}};
    }

    Matrix multiply(const Matrix& other) const {
        Matrix result(2);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix power(long long n) const {
        if (n == 0) {
            Matrix identity(2);
            identity.data[0][0] = identity.data[1][1] = 1;
            return identity;
        }
        if (n == 1) return *this;
        Matrix half = power(n / 2);
        Matrix result = half.multiply(half);
        if (n % 2 == 1) result = result.multiply(*this);
        return result;
    }

    double getHappyProbability() const {
        return data[0][0];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    double p;
    cin >> n >> p;

    Matrix mood;
    mood.InitMood(p);
    Matrix result = mood.power(n);

    cout.precision(10);
    cout << fixed << result.getHappyProbability() << endl;

    return 0;
}