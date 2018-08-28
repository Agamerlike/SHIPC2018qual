#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

ll aa[100];

int main()
{
	ll d,n,m;
	ll cnt=0;
	double ans=0;
	
	cin>>n>>m>>d;
	n=101;
	m=3;
	//d=50;
	fill(aa,aa+100,1);
	for(int i=1;i<102;i++)
	{
		for(int j=1;j<102;j++)
		{
			for(int k=1;k<102;k++)
			{
				if(abs(i-j)==d)
				{
					cnt++;
				}
				if(abs(k-j)==d)
					cnt++;
			}
		}
	}
	ans=(double)cnt/pow(n,m);
	cout<<ans<<endl;
	return 0;
}