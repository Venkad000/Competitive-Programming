#include <bits/stdc++.h>

using namespace std;

int main() {
    long long m, n, a ;
    cin >> m >> n >> a;
    long long result = 0;
    if (m%a != 0 && n %a != 0) 
        result = (m / a + 1) * (n / a + 1);
    else if (m % a !=0 && n % a == 0) 
        result = (m / a + 1) * (n /a );
    else if (m % a == 0 && n % a != 0)
        result = (m / a ) * (n / a + 1);
    else
        result = (m/a) * (n/a);
    cout << result << endl;
    return 0;
}