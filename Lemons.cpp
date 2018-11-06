#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, M, S;
    cin >> N >> M >> S;
    
    cout << ceil(log2(N)*S)+ (N-1)*M;
}