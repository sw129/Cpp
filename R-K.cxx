#include <iostream>
#include <string>
using namespace std;

int get_hash(string &s, int n, int p, int x)
{
	int res = 0;
	for (int i = 0; i < n; i++)
		res = (1ll * res * x + s[i]) % p;
	return res;
}

int rabin_karp(string &t, string &s, int p, int x)
{
	int ht = get_hash(t, t.size(), p, x);
	int hs = get_hash(s, t.size(), p, x);
	int xt = 1;
	for (int i = 0; i < t.size(); i++)
		xt = (1ll * xt * x) % p;
	for (int i = 0; i <= s.size(); i++)
	{
		if (ht == hs)
			return i;
		hs = (1ll * hs * x - 1ll * s[i] * xt + s[i]) % p;
		hs = (hs + p) % p;
	}
	return -1;
}

int main()
{
	string s, t;
	cin >> s >> t;
	int p = 1e9 + 7;
	int x = 26;
	cout << rabin_karp(s, t, p, x);
	return 0;
}
