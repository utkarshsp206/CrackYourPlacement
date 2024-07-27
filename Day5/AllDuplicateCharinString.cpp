// C++ code to implement the above approach
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
void printDuplicates(string str)
{
    int len = str.length();

    // Sorting the string
    sort(str.begin(), str.end());

    // Loop through the sorted string to find duplicates
    for (int i = 0; i < len; i++) {
        int count = 1;

        // Counting the occurrences of each character
        while (i < len - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }

        // Printing the duplicate character and its count
        if (count > 1) {
            cout << str[i] << ", count = " << count << endl;
        }
    }
}
int main()
{
    string str = "test string";
    printDuplicates(str);
    return 0;
}
// This code is contributed by Veerendra_Singh_Rajpoot
