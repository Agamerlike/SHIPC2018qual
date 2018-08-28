#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	string s;
	int w;
	string ans;
	
	cin>>s;
	cin>>w;
	for(int i=0;i<s.length();i+=w)
	{
		ans+=s[i];
	}
	cout<<ans<<endl;
	return 0;
}