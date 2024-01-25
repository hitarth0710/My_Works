#include <iostream>
#include <cstdlib>
#include <ctime>
#include<iomanip>
using namespace std;
typedef long long hit;
#define size 100

void prime_factors(hit n) 
{
    for (hit i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cout << i << " ";
            n = n / i;
        }
    }
    if (n > 1) {
        cout << n;
    }
}

int main() 
{
    srand(time(0)); // seed for random number generator
    clock_t start = clock();
    for(int i = 0; i < size; i++) {
        hit num = rand() % size + 1; // generate a random number between 1 and 10000
        cout << "Number: " << num << "\nPrime factors: ";
        prime_factors(num);
        cout << "\n";
    }
    clock_t end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}