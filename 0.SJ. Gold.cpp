#include<bits/stdc++.h>
using namespace std;          
char str[1010];        
int sa[1010],Rank[1010],rank2[1010],height[1010],c[1010],*x,*y,s[1010],k; 
void cmp(int n,int sz)      
{      
    int i;      
    memset(c,0,sizeof(c));      
    for(i=0;i<n;i++)      
        c[x[y[i]]]++;      
    for(i=1;i<sz;i++)      
        c[i]+=c[i-1];      
    for(i=n-1;i>=0;i--)      
        sa[--c[x[y[i]]]]=y[i];      
}      
void build_sa(int *s,int n,int sz)      
{      
    x=Rank,y=rank2;      
    int i,j;      
    for(i=0;i<n;i++)      
        x[i]=s[i],y[i]=i;      
    cmp(n,sz);      
    int len;      
    for(len=1;len<n;len<<=1)      
    {      
        int yid=0;      
        for(i=n-len;i<n;i++)      
        {      
            y[yid++]=i;      
        }      
        for(i=0;i<n;i++)      
            if(sa[i]>=len)      
                y[yid++]=sa[i]-len;      
            cmp(n,sz);      
        swap(x,y);      
        x[sa[0]]=yid=0;      
        for(i=1;i<n;i++)      
        {      
            if(y[sa[i-1]]==y[sa[i]]&&sa[i-1]+len<n&&sa[i]+len<n&&y[sa[i-1]+len]==y[sa[i]+len])      
                x[sa[i]]=yid;      
            else      
                x[sa[i]]=++yid;      
        }      
        sz=yid+1;      
        if(sz>=n)      
            break;      
    }      
    for(i=0;i<n;i++)      
        Rank[i]=x[i];      
}      
void getHeight(int *s,int n)      
{      
    int k=0;      
    for(int i=0;i<n;i++)      
    {      
        if(Rank[i]==0)      
            continue;      
        k=max(0,k-1);      
        int j=sa[Rank[i]-1];      
        while(s[i+k]==s[j+k])      
            k++;      
        height[Rank[i]]=k;      
    }      
} 
signed main(){
	int t;
	cin >> t;
	while(t--){
		int i,j;
		cin >> str;
		int n=strlen(str);
		for(i=0;i<n;i++) s[i]=str[i]-'A'+1;
		s[n]=0;
		build_sa(s,n+1,26);
		getHeight(s,n);
		int ans=0;
		for(i=1;i<=n;i++)
			if(height[i]>ans)	ans=height[i];
		if(ans==0){
			printf("No repetitions found!\n");
			continue;
		}
		for(i=1;i<=n;i++){
			if(height[i]>=ans)	break;
		}
		int k=1;
		for(j=i;j<=n&&height[j]>=ans;j++)	k++;
		for(j=0;j<ans;j++)	printf("%c",str[sa[i]+j]);
		printf(" %d\n",k);
	}
}

