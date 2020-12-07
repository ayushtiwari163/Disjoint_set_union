#ifndef DSU
#define DSU
#include <vector>
using namespace std;

class DSU{
	int num;// number off nodes/elements.
	vector<int> par;
	vector<int> size;
public:
	// generally this is for intiallistion of dsu
	DSU(int num_val)// we pass the availabe number 
	{
		num = num_val;
		par.resize(num + 1);
		size.resize(num + 1);

		for (int i = 1; i <= n; ++i)
			par[i] = i, size[i] = 1;
	}

	//O(1) ammortized
    // return the root of node x
	int root(int x)
	{
		/*while(x!=par[x])
			x=par[x];
		return x;*/

		if (x == par[x])
			return x;

		return par[x] = root(par[x]);
	}

	//O(1) ammortized
	//this return two number is connected or not
	bool find(int a, int b)
	{
		return root(a) == root(b);
	}

	//O(1) ammortized
	//union two nodes/element
	void un(ll a, ll b)
	{
		int ra = root(a);
		int rb = root(b);

		if (ra == rb)
			return;

		if (sz[ra] > sz[rb])
			swap(ra, rb);

		par[ra] = rb;
		sz[rb] += sz[ra];
	
	}

};

//