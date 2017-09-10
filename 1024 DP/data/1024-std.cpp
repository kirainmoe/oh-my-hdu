/*
状态dp[i][j]有前j个数，组成i组的和的最大值。决策： 
第j个数，是在第包含在第i组里面，还是自己独立成组。
方程 dp[i][j]=Max(dp[i][j-1]+a[j] , max( dp[i-1][k] ) + a[j] ) 0<k<j
空间复杂度，m未知，n<=1000000，  继续滚动数组。 
时间复杂度 n^3. n<=1000000.  显然会超时，继续优化。
max( dp[i-1][k] ) 就是上一组 0....j-1 的最大值。
我们可以在每次计算dp[i][j]的时候记录下前j个的最大值 
用数组保存下来  下次计算的时候可以用，这样时间复杂度为 n^2.
*/

#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define MAXN 1000000
#define INF 0x7fffffff
int dp[MAXN+10];
int mmax[MAXN+10];
int a[MAXN+10];
int main()
{
    freopen("1024.in", "r", stdin);
    freopen("1024.std.out", "w", stdout);
    int n,m;
    int i,j,mmmax;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            mmax[i]=0;
            dp[i]=0;
        }
        dp[0]=0;
        mmax[0]=0;    
        for(i=1;i<=m;i++)
        {
                mmmax=-INF;
                for(j=i;j<=n;j++)
                {
                    dp[j]=max(dp[j-1]+a[j],mmax[j-1]+a[j]);
                    mmax[j-1]=mmmax;
                    mmmax=max(mmmax,dp[j]);
                }    
        }  
        printf("%d\n",mmmax);  
          
    } 
    fclose(stdin);
    fclose(stdout);
    return 0;   
}    
