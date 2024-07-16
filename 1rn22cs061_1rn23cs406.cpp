#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 10; 
const int INF = 500;

int calculatePathDistance(int graph[MAX_N][MAX_N], int path[MAX_N], int n) 
{
    int distance = 0;
    for (int i = 0; i < n; ++i)
    {
        distance += graph[path[i]][path[(i + 1) % n]];
    }
    return distance;
}
int tsp(int graph[MAX_N][MAX_N], int n) 
{
    int path[MAX_N];
    for (int i = 0; i < n; ++i)
    {
        path[i] = i;
    }

    int min_distance = INF;
    do
    {
        int current_distance = calculatePathDistance(graph, path, n);
        min_distance = min(min_distance, current_distance);
    } while (next_permutation(path + 1, path + n));

    return min_distance;
}

int main()
{
    int n;
    cin >> n;

    int graph[MAX_N][MAX_N];
    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> graph[i][j];
        }
    }

    int min_path = tsp(graph, n);
    cout  << min_path << endl;

    return 0;
}
