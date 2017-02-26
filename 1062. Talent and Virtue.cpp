#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Info
{
	int ID;
	int virtue;
	int talent;
};
bool cmp(const Info &a, const Info &b)
{
	if (a.virtue + a.talent != b.virtue + b.talent) return a.virtue + a.talent >= b.virtue + b.talent;
	if (a.virtue != b.virtue) return a.virtue >= b.virtue;
	return a.ID < b.ID;
}
int main()
{
	int N, L, H;
	int M = 0;
	cin >> N >> L >> H;
	vector<Info> sage, noble, fool, small;
	int temp_id, temp_virtue, temp_talent;
	for (int i = 0; i != N; ++i)
	{
		scanf("%d%d%d", &temp_id, &temp_virtue, &temp_talent);
		if (!(temp_virtue >= L && temp_talent >= L))
			continue;
		if (temp_virtue >= H && temp_talent >= H)
			sage.push_back({ temp_id, temp_virtue, temp_talent });
		else if (temp_virtue >= H && temp_talent < H)
			noble.push_back({ temp_id, temp_virtue, temp_talent });
		else if (temp_virtue >= temp_talent)
			fool.push_back({ temp_id, temp_virtue, temp_talent });
		else
			small.push_back({ temp_id, temp_virtue, temp_talent });
		++M;
	}
	sort(sage.begin(), sage.end(), cmp);
	sort(noble.begin(), noble.end(), cmp);
	sort(fool.begin(), fool.end(), cmp);
	sort(small.begin(), small.end(), cmp);
	cout << M << endl;
	for (auto val : sage)
		printf("%d %d %d\n", val.ID, val.virtue, val.talent);
	for (auto val : noble)
		printf("%d %d %d\n", val.ID, val.virtue, val.talent);
	for (auto val : fool)
		printf("%d %d %d\n", val.ID, val.virtue, val.talent);
	for (auto val : small)
		printf("%d %d %d\n", val.ID, val.virtue, val.talent);
}