#include<iostream>
#include<vector>
using namespace std;
const int N=200010;
vector<int>father=vector<int>(N,0);	// 记录根节点 
vector<int>weight=vector<int>(N,0);	//记录到根节点的权重 
int ans;
 
void init()
{
	for(int i=0;i<N;i++){
		father[i]=i;
		weight[i]=0;
	}
 } 
 
 int find(int x)
 {
	if(x!=father[x])
	{
		int t=father[x];
		father[x]=find(father[x]);
		weight[x]+=weight[t];
	}
	return father[x]; 
 }
 
 void merge(int a, int b, int v)
 {
 	int roota=find(a);
	int rootb=find(b);
 	if(roota==rootb){
 		if(weight[b]-weight[a]!=v)	ans++;	
	}
	else{
		father[rootb]=roota;
		weight[rootb]=weight[a]+v-weight[b];
	}
 }
 
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		ans=0;
		for(int i=0;i<m;i++)
		{
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
            a--;
			merge(a,b,v);
		}
		printf("%d\n",ans);
	}
	return 0;
 } 