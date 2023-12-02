#include <deque>
#include <iostream>

using namespace std;
void findMin(int mass[], int n, int k)

{
    std::deque<int> gg(k);
    int i;
    for (i = 0; i < k; ++i)
    {
        while ((!gg.empty()) && mass[i] <= mass[gg.back()])
            gg.pop_back();
        gg.push_back(i);
    }
    for (; i < n; ++i)
    {
        cout << mass[gg.front()] << '\n';
        while ((!gg.empty()) && gg.front() <= i - k)
            gg.pop_front();
        while ((!gg.empty()) && mass[i] <= mass[gg.back()])
            gg.pop_back();
        gg.push_back(i);
    }
    cout << mass[gg.front()];
}

int main()

{
    int N, K;
    cin >> N >> K;
    int mass[150000];
    for (int i = 0; i < N; i++)
    {
        cin >> mass[i];
    }
    findMin(mass, N, K);
    return 0;
}
