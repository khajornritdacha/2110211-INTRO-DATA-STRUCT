// Task: Time After
// Algo: Modulo
// Date: 9/8/2023
// Author: Jo

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int hr, mm;
    cin >> hr >> mm;
    int shift_mm;
    cin >> shift_mm;
    int minPerDay = 24 * 60;
    int totalMin = (hr * 60 + mm + shift_mm) % minPerDay;
    cout.fill('0');
    cout
        << setw(2) << totalMin / 60 << " " << setw(2) << totalMin % 60 << "\n";
}
