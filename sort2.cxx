#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> &A, vector<int> &B, int &s)
{
	int i = 0;
	int j = 0;
	int k = 0;
	vector<int> C(A.size() + B.size());
	for (k = 0; k < C.size(); k++)
	{
		if (i == A.size())
		{
			C[k] = B[j];
			j++;
		}
		else if (j == B.size())
		{
			C[k] = A[i];
			i++;
		}
		else if (A[i] <= B[j])
		{
			C[k] = A[i];
			i++;
		}
		else
		{
			C[k] = B[j];
			j++;
			s += A.size() - i;
		}
	}
	return C;
}

vector<int> merge_sort(vector<int> &V, int l, int r, int &s)
{
	if (r - l == 1)
	{
		vector<int> res(1);
		res[0] = V[l];
		return res;
	}
	int m = (l + r) / 2;
	vector<int> left = merge_sort(V, l, m, s);
	vector<int> right = merge_sort(V, m, r, s);
	return merge(left, right, s);
}

int main()
{
	int n, s = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	merge_sort(v, 0, n, s);
	cout << s;
	return 0;
}