// C++ program to find celebrity
#include <bits/stdc++.h>
using namespace std;

bool knows(int a, int b, vector<vector<int> >& matrix)
{
    return matrix[a][b];
}

// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
int findCelebrity(int n, vector<vector<int> >& matrix)
{
    // the graph needs not be constructed
    // as the edges can be found by
    // using knows function

    // degree array;
    int indegree[n] = { 0 }, outdegree[n] = { 0 };

    // query for all edges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = knows(i, j, matrix);

            // set the degrees
            outdegree[i] += x;
            indegree[j] += x;
        }
    }

    // find a person with indegree n-1
    // and out degree 0
    for (int i = 0; i < n; i++)
        if (indegree[i] == n - 1 && outdegree[i] == 0)
            return i;

    return -1;
}

// Driver code
int main()
{
    int n = 4;
    vector<vector<int> > matrix = { { 0, 0, 1, 0 },
                                    { 0, 0, 1, 0 },
                                    { 0, 0, 0, 0 },
                                    { 0, 0, 1, 0 } };
    int id = findCelebrity(n, matrix);
    if (id == -1)
        cout << "No celebrity";
    else
        cout << "Celebrity ID " << id;
    return 0;
}
