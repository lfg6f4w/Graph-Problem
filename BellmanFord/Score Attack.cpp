///   https://atcoder.jp/contests/abc061/tasks/abc061_d?lang=en

#include<iostream>    
#include<cstdio>  
#include<stdio.h>  
#include<cstring>    
#include<cstdio>    
#include<climits>    
#include<cmath>   
#include<vector>  
#include <bitset>  
#include<algorithm>    
#include <queue>  
#include<map>  
using namespace std; 
const long long int INF = 1LL << 50;
 
/*start:17/5/19 16:33*/
/*end:17/5/19   17:55  */
 
int w[2005],v[2005];
long long int lu[2005];
long long int l,dis[3005];
int n,m,x,y,i,k;
 
bool check;
 
int main()
{
	int j;
	memset(w,0,sizeof(w));
	memset(v,0,sizeof(v));
	memset(lu,0,sizeof(lu));
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y>>l;
		w[i]=x;
		v[i]=y;
		lu[i]=-l;
	}
	for(i=1;i<=n;i++)
		dis[i]=INF;
	dis[1]=0;
	//MAX=INF;
	for(i=1;i<=n-1;i++)
	{	
		check=false;
		for(j=1;j<=m;j++)
		{
			if(dis[v[j]]>dis[w[j]]+lu[j])
			{
				check=true;
				dis[v[j]]=dis[w[j]]+lu[j];
			}
		}
		if(!check)
			break;
	}
	l=dis[n];
	for(j=1;j<=m;j++)
	{
		if(dis[v[j]]>dis[w[j]]+lu[j])
		{
			dis[v[j]]=dis[w[j]]+lu[j];
		}
	}
 
	if(dis[n]==INF)
	{
		cout<<"inf"<<endl;
		return 0;
	}
	if(dis[n]!=l)
	{
		cout<<"inf"<<endl;
		return 0;
	}
	cout<<-dis[n]<<endl;
	return 0;
}
