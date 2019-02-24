#include <iostream>
#include <map>
#include <string>

using namespace std;


int main()
{
	string str;
	map<string, int> mp;
	getline(cin, str, '\n');
	int count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		// 大写变成小写
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] -= 'A' - 'a';
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9'))
		{
			count++;
		}
		else
		{
			if (count == 0)
				continue;
			string temp = str.substr(i - count, count);
			count = 0;
			mp[temp]++;
			continue;
		}
		if (i == str.length() - 1)
		{
			mp[str.substr(i - count + 1, count)]++;
		}
	}
	string maxk;
	int maxc = 0;
	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		// map 会自动排序
		if (it->second > maxc)
		{
			maxc = it->second;
			maxk = it->first;
		}
	}
	cout << maxk << ' ' << maxc << endl;
	return 0;
}