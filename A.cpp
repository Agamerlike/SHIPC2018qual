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
	int a,b;
	int ans=0;
	
	cin>>a>>b;
	if(a*b==15)
		cout<<"*"<<endl;
	else if(a+b==15)
		cout<<"+"<<endl;
	else
		cout<<"x"<<endl;
	
	return 0;
}