#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	// Считываем данные в массив строк
	vector<string> A(n);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	cout << "Initial array:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << A[i];
		if (i + 1 != n)
			cout << ", ";
	}
	// Вычисляем количество раундо (равно длине элемента)
	int m = A[0].size();
	cout << endl;
	for (int i = m - 1; i >= 0; i--)
	{
		cout << "**********" << endl
			 << "Phase " << m - i << endl;
		// Заводим 26 корзин (26 букв в английском алфавите)
		vector<vector<string>> bucket(10);
		// Применяем сортировку подсчётом
		for (int j = 0; j < n; j++)
		{
			// A[j][i] - это символ от 'a' до 'z'
			// Чтобы номер буквы достаточно вычесть код символа 'a'
			bucket[A[j][i] - '0'].push_back(A[j]);
		}
		int p = 0;
		for (int j = 0; j < 10; j++)
		{
			cout << "Bucket " << j << ": ";
			if (bucket[j].size() == 0)
				cout << "empty";
			for (int k = 0; k < bucket[j].size(); k++)
			{
				A[p] = bucket[j][k];
				cout << bucket[j][k];
				if (k + 1 != bucket[j].size())
					cout << ", ";
				p++;
			}
			cout << endl;
		}
	}
	// Выводим отсортированный
	cout << "**********" << endl
		 << "Sorted array:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << A[i];
		if (i + 1 != n)
			cout << ", ";
	}
	return 0;
}