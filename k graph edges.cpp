#include <limits.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define V 4

int countwalksRec(int g[][V], int u, int v, int k)
{
	if (k == 0 && u == v) return 1;
	if (k == 1 && g[u][v]) return 1;
	if (k <= 0) return 0;
	int count = 0;
	for (int i = 0; i < V; ++i)
	{
		if (g[u][i])
			count += countwalksRec(g, i, v, k - 1);
	}
	return count;
}

int countwalks(int g[][V], int u, int v, int k)
{
	vector<vector<vector<int>>> dp(V, vector<vector<int>>(V, vector<int>(k+1)));

	for (int edges = 0; edges <= k; ++edges)
	{
		for (int i = 0; i < V; ++i)
		{
			for (int j = 0; j < V; ++j)
			{
				if (edges == 0 && i == j)
					dp[i][j][edges] = 1;
				else if (edges == 1 && g[i][j])
					dp[i][j][edges] = 1;
				else if (edges > 1) {
					for (int t = 0; t < V; ++t)
					{
						if (g[i][t])
							dp[i][j][edges] += dp[t][j][edges-1];
					}
				}
			}
		}
	}
	return dp[u][v][k];
}

int main()
{
    /* Let us create the graph shown in above diagram*/
     int graph[V][V] = { {0, 1, 1, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 0}
                      };
    int u = 0, v = 3, k = 2;
    cout << countwalks(graph, u, v, k);
	getchar();
    return 0;
}