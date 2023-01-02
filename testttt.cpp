#include<queue>
#include<iostream>
#include<algorithm>
#include<string>
#include<array>
#include<vector>
using namespace std;
vector<int> olasieve_variation(int n) {
	vector<int> prime;
	bool IsPrime[5001];
	int cnt = 0;

	memset(IsPrime, true, sizeof(IsPrime));

	for (int i = 2; i <= n; i++) {
		if (IsPrime[i]) {
			prime.push_back(i); cnt++; // 2, 3, 5

			for (int j = 0; j < cnt; j++) {      //遍历质数表
				if (i * prime[j] > n) break;      //如果超过最大范围，跳出
				IsPrime[i * prime[j]] = false;    //将以prime[j]]为最小质因数的合数筛掉
				if (i % prime[j] == 0) break; //保证只筛到以prime[j]为最小质因数的数
			}
		}
		return prime;
	}
}
int mp(int sn)
{
	auto jg = vector<int>(olasieve_variation(sn));
	int * temp = new int;
	*temp = jg.size();
	auto ans = 1;
	auto t = (sn / jg.back());
	for (int i = 0; i < *temp; i++)
	{
		if (!(1.0 * static_cast<double>(sn) / jg.back()) - t)
		{
			ans = max(ans, jg.front());
			break;
		}
		jg.pop_back();
	}
	return ans;
}
int main()
{
	int n; cin >> n; auto ans = 0;
	int old_data = 0, new_data;
	for (int i = 0; i < n; i++)
	{
		cin >> new_data;
		old_data = max(old_data, mp(new_data));
	}
	cout << old_data;
	return 0;
}