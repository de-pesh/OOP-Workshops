#include<iostream>
using namespace std;
void Ap(int x) {
    for(int i = 1, n = 1; i<=x; i++, n++){
        int r = 3*n +2;
        if(r % 4== 0 )
            i--;
        else 
            cout<<r<<" ";
    }
}
int main() {
    int n;
    cin>>n;
    Ap(n);
    return 0;
}


// Terms of AP
// Send Feedback
// Write a program to print first x terms of the series 3N + 2 which are not multiples of 4.
// Input format :
// Integer x
// Output format :
// Terms of series (separated by space)
// Constraints :
// 1 <= x <= 1,000
// Sample Input 1 :
// 10
// Sample Output 1 :
// 5 11 14 17 23 26 29 35 38 41
// Sample Input 2 :
// 4
// Sample Output 2 :
// 5 11 14 17