#include <iostream>
using namespace std;

//---------------------------------------------------------
// Function to generate all subsets of a string
//
// str    -> Original input string
// output -> Current subset being formed
// index  -> Current character being processed
//---------------------------------------------------------
void solve(string str, string output, int index)
{
    //-----------------------------------------------------
    // Base Case
    // If all characters have been processed,
    // the current subset is complete.
    //-----------------------------------------------------
    if(index >= str.length())
    {
        cout << "\"" << output << "\"" << endl;// to print " we use \"
        return;
    }

    //-----------------------------------------------------
    // Choice 1:
    // Exclude the current character and move
    // to the next character.
    //-----------------------------------------------------
    solve(str, output, index + 1);

    //-----------------------------------------------------
    // Choice 2:
    // Include the current character in the subset.
    //-----------------------------------------------------
    output.push_back(str[index]);

    //-----------------------------------------------------
    // Continue forming subsets with the
    // updated output string.
    //-----------------------------------------------------
    solve(str, output, index + 1);
}

int main()
{
    // Input string
    string str = "abc";

    // Initially, subset is empty
    string output = "";

    // Start recursion from the first character
    solve(str, output, 0);

    return 0;
}
//call stack

solve("",0)

↓

solve("",1)

↓

solve("",2)

↓

solve("",3)

↓

Print ""

↓

solve("c",3)

↓

Print "c"

↓

solve("b",2)

↓

Print "b"

↓

Print "bc"

↓

solve("a",1)

↓

Print "a"

↓

Print "ac"

↓

Print "ab"

↓

Print "abc"
