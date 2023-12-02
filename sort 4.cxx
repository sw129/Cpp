#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n;
	vector<int> S(n);
	for (int i = 0; i < n; i++)
	{
		cin >> S[i];
	}
	cin >> k;
	vector<int> A(k);
	int Amin = 1e9;
	int Amax = -1e9;
	for (int i = 0; i < k; i++)
	{
		cin >> A[i];
		Amin = min(Amin, A[i]);
		Amax = max(Amax, A[i]);
	}
	vector<int> C(Amax - Amin + 1);
	for (int i = 0; i < k; i++)
	{
		C[A[i] - Amin]++;
	}
	for (int i = 0; i < C.size(); i++)
	{
		S[i] -= C[j];
	}
	for (int i = 0; i < n; i++)
	{
		if (S[i] < 0)
			cout << "yes";
		else
			cout << "no";
		cout << endl;
	}
	return 0;
}