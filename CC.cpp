#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

double cc[3];
int main()
{
	double d,n,m;
	double ans=0;
	
	cin>>n>>m>>d;
	fill(cc,cc+3,0);
	if(d==0)
	{
		ans=(double)(m-1)/(double)n;
	}else{
		if(2*d<n)
		{
			cc[0]=0;
			cc[1]=2*d;
			cc[2]=n-2*d;
		}else if(2*d==n){
			cc[0]=0;
			cc[1]=n;
			cc[2]=0;
		}else{
			cc[0]=2*d-n;
			cc[2]=0;
			cc[1]=n-cc[0];
		}
		double pp=(cc[1]+cc[2]*2)/n/n;
		ans=pp*(m-1);
	}
	cout<<ans<<endl;
	return 0;
}