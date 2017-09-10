#include<bits/stdc++.h>
using namespace std;
const int inf=0x7fffffff;
int d[12],num[60000][12],dp[60000][12];

int main()
{
    int i,n,m,g[20][20],a,b,w,ans,flag,j,k,news;
    d[0]=1;
    for(i=1;i<=11;i++) d[i]=d[i-1]*3;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                g[i][j]=inf;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            a--;
            b--;
            g[a][b]=g[b][a]=min(w,g[a][b]);
        }
        for(i=0;i<d[10];i++)
        {
            a=i;
            for(j=0;j<10;j++)
            {
                num[i][j]=a%3;
                a/=3;
            }
        }
        for(i=0;i<d[n];i++)
        {
            for(j=0;j<10;j++)
            {
                dp[i][j]=inf;
            }
        }
        for(i=0;i<n;i++)
            dp[d[i]][i]=0;
        ans=inf;
        for(i=0;i<d[n];i++)
        {
            flag=1;
            for(j=0;j<n;j++)
            {
                if(num[i][j]==0) flag=0;
                if(dp[i][j]==inf) continue;
                for(k=0;k<n;k++)
                {
                    if(g[j][k]==inf||num[i][k]==2) continue;
                    news=i+d[k];
                    dp[news][k]=min(dp[news][k],dp[i][j]+g[j][k]);
                }
            }
            if(flag)
            {
                for(j=0;j<n;j++)
                    ans=min(ans,dp[i][j]);
            }
        }

        if(ans==inf) ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
