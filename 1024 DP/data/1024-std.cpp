/*
״̬dp[i][j]��ǰj���������i��ĺ͵����ֵ�����ߣ� 
��j���������ڵڰ����ڵ�i�����棬�����Լ��������顣
���� dp[i][j]=Max(dp[i][j-1]+a[j] , max( dp[i-1][k] ) + a[j] ) 0<k<j
�ռ临�Ӷȣ�mδ֪��n<=1000000��  �����������顣 
ʱ�临�Ӷ� n^3. n<=1000000.  ��Ȼ�ᳬʱ�������Ż���
max( dp[i-1][k] ) ������һ�� 0....j-1 �����ֵ��
���ǿ�����ÿ�μ���dp[i][j]��ʱ���¼��ǰj�������ֵ 
�����鱣������  �´μ����ʱ������ã�����ʱ�临�Ӷ�Ϊ n^2.
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
