#include <iostream>
#include <fstream>

#define MOD 1000000007
#define MAX_SIZE 200001

std::ifstream f("transport.in");
std::ofstream g("transport.out");

int n, c;
int x[MAX_SIZE];
int d[MAX_SIZE];

int pow(int a, int b) {
    int r = 1;
    while (b != 0) {
        while (b%2 == 0) {
            a = 1ll*a*a % MOD;
            b /= 2;
        }
        r = 1ll*r*a % MOD;
        b--;
    }
    return r;
}

void regio()
{
    int k = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (c * (x[j] - x[i]) == d[i] + d[j]) {
                k++;
                k %= MOD;
            }
        }
    }
    g << k << std::endl;
}

void express()
{
    int k = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (c * (x[j] - x[i]) == d[i] + d[j]) {
                k += pow(2, (j-i-1));
                k %= MOD;
            }
        }
    }
    g << k << std::endl;
}

int main()
{
    int t;
    f >> t;

    f >> n >> c;
    for (int i = 0; i < n; ++i) {
        f >> x[i] >> d[i];
    }

    switch (t) {
        case 1: {
            regio();
        } break;

        case 2: {
            express();
        } break;
    }

    return 0;
}