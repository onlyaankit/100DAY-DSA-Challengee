#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int> >& matrix, int n)
{
    int i = 0, j = n - 1;
    while (i < j) {
        if (matrix[j][i] == 1) {
            j--;
        } else {
            i++;
        }
    } // Close the while loop here

    int candidate = i;

    for (i = 0; i < n; i++) {
        if (i != candidate) {
            if (matrix[i][candidate] == 0 || matrix[candidate][i] == 1)
                return -1;
        }
    }

    return candidate;
}

int main()
{
    int n = 4;
    vector<vector<int> > matrix = { { 0, 0, 1, 0 },
                                    { 0, 0, 1, 0 },
                                    { 0, 0, 0, 0 },
                                    { 0, 0, 1, 0 } };

    int celebIdx = celebrity(matrix, n);

    if (celebIdx == -1)
        cout << "No Celebrity";
    else {
        cout << "Celebrity ID " << celebIdx;
    }
    return 0;
}
