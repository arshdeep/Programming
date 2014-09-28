#include <climits>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define V 4
#define INF INT_MAX

int countwalksRec(int g[][V], int u, int v, int k)
{
	if (k == 0 && u == v) return 0;
	if (k == 1 && g[u][v]) return g[u][v];
	if (k <= 0) return INF;
	int count = INF;
	for (int i = 0; i < V; ++i)
	{
		int t = g[u][i];
		if (t != INF && i != u && i != v)
		{
			count = std::min(count, t + countwalksRec(g, i, v, k - 1));
		}
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
				dp[i][j][edges] = INF;
				if (edges == 0 && i == j)
					dp[i][j][edges] = g[i][j];
				else if (edges == 1 && g[i][j])
					dp[i][j][edges] = g[i][j];
				else if (edges > 1) {
					for (int t = 0; t < V; ++t)
					{
						if (g[i][t] != INF && t != i && t!= j)
							dp[i][j][edges] = std::min(dp[i][j][edges], g[i][t] + dp[t][j][edges-1]);
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
     int graph[V][V] = { {0, 10, 3, 2},
                        {INF, 0, INF, 7},
                        {INF, INF, 0, 16},
                        {INF, INF, INF, 0}
                      };
    int u = 0, v = 3, k = 2;
    cout << countwalks(graph, u, v, k);
	getchar();
    return 0;
}