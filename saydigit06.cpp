#include<iostream> 
using namespace std;

void sayDigit(int n, string arr[]) {

    //base case
    if(n == 0)
        return ;

    //processing 
    int digit = n % 10;
    n = n / 10;
    

    //recursive call
    sayDigit(n, arr);

    cout << arr[digit] << " ";

}

int main() {

    string arr[10] = {"zero", "one", "two", "three",
                         "four", "five", "six"
                        , "seven", "eight", "nine"};
    int n;
    cin >> n;

    cout << endl << endl << endl ;
    sayDigit(n, arr);
    cout << endl << endl << endl ;


    return 0;
}
// output
// 412
// four one two


sayDigit(413)

digit = 3
n = 41
        ↓
sayDigit(41)

digit = 1
n = 4
        ↓
sayDigit(4)

digit = 4
n = 0
  
    //stack unwinding↓
sayDigit(0)   // Base case
return

sayDigit(4)
prints Four

↓

sayDigit(41)
prints One

↓

sayDigit(413)
prints Three
