#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
int thr[11],					// 保存 3 的 n 次方
		num[60000][11],		// 预先计算 3^n 的二进制结果
		dp[60000][11],    // DP 数组
		maps[11][11];			// 领接矩阵

int n, m;
int ans;
int newState = 0;			// 储存新状态

bool flag;						// flag

int main()
{
	// 计算 3 的 n 次方
	thr[0] = 1;				// 3^0 = 1
	for (int i = 1; i < 11; i++)
	{
		thr[i] = thr[i-1] * 3;
	}

	// 建立十进制数对应的三进制表
	int tmp;
	for (int i = 0; i < thr[10]; i++)
	{
		tmp = i;
		for (int j = 0; j < 10; j++)
		{
			num[i][j] = tmp % 3;			// 从0到9是从低位到高位
			tmp /= 3;
		}
	}	

	// start solution
	while (scanf("%d%d", &n, &m) != EOF)
	{
		// 初始化邻接矩阵
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				maps[i][j] = inf;
			}
		}

		// 读入数据
		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);

			u--;
			v--;
			maps[u][v] = maps[v][u] = min(w, maps[u][v]);
		}

		// 初始化 DP 数组为 inf
		for (int i = 0; i < thr[n]; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				dp[i][j] = inf;
			}
		}

		// 对于每个初始状态，花费为 0
		for (int i = 0; i < n; i++)
		{
			dp[thr[i]][i] = 0;
		}

		// 初始化 ans
		ans = inf;

		// solution
		for (int i = 0; i < thr[n]; i++)
		{
			// 当 flag 为 false 的时候，说明还没找到覆盖所有点的最小花费
			flag = true;

			// 对于每一个状态，遍历到终点 j 的状态
			for (int j = 0; j < n; j++)
			{
				// 该点还没有访问过，还未找到最终答案，flag = false
				if (num[i][j] == 0) {
					flag = false;
				}

				// 这个状态还没有到达过
				if (dp[i][j] == inf) {
					continue;
				}

				for (int k = 0; k < n; k++)
				{
					// 没有路或者已经访问了两次
					if (maps[j][k] == inf || num[i][k] == 2) {
						continue;
					}
					// 计算新的状态
					newState = i + thr[k];
					dp[newState][k] = min(dp[newState][k], dp[i][j] + maps[j][k]);
				}
			}

			if (flag) {
				for (int j = 0; j < n; j++) {
					ans = min(ans, dp[i][j]);
				}
			}
		}
		if (ans == inf)
			ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}
