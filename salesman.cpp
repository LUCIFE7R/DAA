#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N = 0;
void tspBranchAndBound(int level, int cost, int path[], int bestPath[], int &minCost, std::vector<std::vector<int>> &distanceMatrix);
const int INF = 1e9;

int main()
{
    cout << "Enter Number of Nodes : ";
    cin >> N;

    std::vector<std::vector<int>> distanceMatrix(N, std::vector<int>(N));
    cout << "Enter Distance Matrix : " << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> distanceMatrix[i][j];
        }
    }

    int path[N];
    for (int i = 0; i < N; i++)
    {
        path[i] = i;
    }

    int bestPath[N];
    int minCost = INF;

    tspBranchAndBound(1, 0, path, bestPath, minCost, distanceMatrix);

    cout << "Optimal TSP tour: ";
    for (int i = 0; i < N; i++)
    {
        cout << bestPath[i] << " -> ";
    }
    cout << bestPath[0] << endl;

    cout << "Optimal TSP tour cost: " << minCost << endl;

    return 0;
}

void tspBranchAndBound(int level, int cost, int path[], int bestPath[], int &minCost, std::vector<std::vector<int>> &distanceMatrix)
{
    if (level == N)
    {
        cost += distanceMatrix[path[level - 1]][0];
        if (cost < minCost)
        {
            minCost = cost;
            for (int i = 0; i < N; i++)
            {
                bestPath[i] = path[i];
            }
        }
        return;
    }

    for (int i = level; i < N; i++)
    {
        swap(path[level], path[i]);
        int bound = cost + distanceMatrix[path[level - 1]][path[level]];
        if (bound < minCost)
        {
            tspBranchAndBound(level + 1, bound, path, bestPath, minCost, distanceMatrix);
        }
        swap(path[level], path[i]);
    }
}