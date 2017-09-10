#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
int thr[11],					// ���� 3 �� n �η�
		num[60000][11],		// Ԥ�ȼ��� 3^n �Ķ����ƽ��
		dp[60000][11],    // DP ����
		maps[11][11];			// ��Ӿ���

int n, m;
int ans;
int newState = 0;			// ������״̬

bool flag;						// flag

int main()
{
	// ���� 3 �� n �η�
	thr[0] = 1;				// 3^0 = 1
	for (int i = 1; i < 11; i++)
	{
		thr[i] = thr[i-1] * 3;
	}

	// ����ʮ��������Ӧ�������Ʊ�
	int tmp;
	for (int i = 0; i < thr[10]; i++)
	{
		tmp = i;
		for (int j = 0; j < 10; j++)
		{
			num[i][j] = tmp % 3;			// ��0��9�Ǵӵ�λ����λ
			tmp /= 3;
		}
	}	

	// start solution
	while (scanf("%d%d", &n, &m) != EOF)
	{
		// ��ʼ���ڽӾ���
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				maps[i][j] = inf;
			}
		}

		// ��������
		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);

			u--;
			v--;
			maps[u][v] = maps[v][u] = min(w, maps[u][v]);
		}

		// ��ʼ�� DP ����Ϊ inf
		for (int i = 0; i < thr[n]; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				dp[i][j] = inf;
			}
		}

		// ����ÿ����ʼ״̬������Ϊ 0
		for (int i = 0; i < n; i++)
		{
			dp[thr[i]][i] = 0;
		}

		// ��ʼ�� ans
		ans = inf;

		// solution
		for (int i = 0; i < thr[n]; i++)
		{
			// �� flag Ϊ false ��ʱ��˵����û�ҵ��������е����С����
			flag = true;

			// ����ÿһ��״̬���������յ� j ��״̬
			for (int j = 0; j < n; j++)
			{
				// �õ㻹û�з��ʹ�����δ�ҵ����մ𰸣�flag = false
				if (num[i][j] == 0) {
					flag = false;
				}

				// ���״̬��û�е����
				if (dp[i][j] == inf) {
					continue;
				}

				for (int k = 0; k < n; k++)
				{
					// û��·�����Ѿ�����������
					if (maps[j][k] == inf || num[i][k] == 2) {
						continue;
					}
					// �����µ�״̬
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
