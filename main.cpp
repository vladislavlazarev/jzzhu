
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

vector <int> v, f, rv;
int n;

 void rec() {
    	if( v.size() > rv.size()) rv = v;
    	for (int i = n; i>1; i--) {
    		if(!f[i]){
    			for(int j = i-1; j>1; --j) {
    				if(!f[j] && __gcd(i, j) > 1) {
    					v.push_back(i);
    					v.push_back(j);
    					f[i] = f[j] = 1;
    					rec();
    					f[i] = f[j] = 0;
    					v.pop_back();
    					v.pop_back();
    				}
    			}
    		}
    	}
    }


int main()
{
    cin >> n;
    f.assign(n+1, 0);
    rec();
    for (int i = 0; i< rv.size(); i++) {
    	cout << rv[i] << ' ';
    	if(i%2) cout << endl;
    }
    return 0;
}
