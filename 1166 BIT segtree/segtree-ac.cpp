#include<stdio.h>
#include<string.h>
#define maxn 50000
int ans;
struct node 
{
    int left,right,sum;
    int mid()
    {
        return (left+right)>>1;
    }
}tree[maxn*4];
void btree(int left,int right,int rt)
{
    tree[rt].left=left;
    tree[rt].right=right;
    if(left==right)
    {
        scanf("%d",&tree[rt].sum);
        return ;
    }
    int mid=tree[rt].mid();
    btree(left,mid,rt<<1);
    btree(mid+1,right,rt<<1|1);
    tree[rt].sum=tree[rt<<1].sum+tree[rt<<1|1].sum;
}
void query(int left,int right,int rt,int L,int R)
{
    if(L<=left&&right<=R)
    {
        ans+=tree[rt].sum;
        return;
    }
    int mid=tree[rt].mid();
    if(R<=mid)
        query(left,mid,rt<<1,L,R);
    else if(L>mid)
        query(mid+1,right,rt<<1|1,L,R);
    else
    {
        query(left,mid,rt<<1,L,R);
        query(mid+1,right,rt<<1|1,L,R);
    }
}
void update(int left,int right,int rt,int pos,int add)
{
    if(left==right)
    {
        tree[rt].sum+=add;
        return;
    }
    int mid=tree[rt].mid();
    if(pos<=mid)
        update(left,mid,rt<<1,pos,add);
    else
        update(mid+1,right,rt<<1|1,pos,add);
    tree[rt].sum=tree[rt<<1].sum+tree[rt<<1|1].sum;
}
int main()
{
    int t,n,cnt;
    int a,b;
    char str[10];
    cnt=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        btree(1,n,1);
        printf("Case %d:\n",cnt++);
        while(scanf("%s",str))
        {
            if(str[0]=='E')
                break;
            scanf("%d%d",&a,&b);
            if(str[0]=='Q')
            {
                ans=0;
                query(1,n,1,a,b);
                printf("%d\n",ans);
            }
            else if(str[0]=='A')
                update(1,n,1,a,b);
            else 
                update(1,n,1,a,-b);
        }
    }
    return 0;
}
