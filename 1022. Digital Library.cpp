#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct BookInfo
{
	int ID;
	string title;
	string author;
	string key_words;
	string publisher;
	string published_year;
};
class DigitalLibrary
{
private:
	int N;
	int M;
	vector<BookInfo> vecBookInfo;
	//vector<string> map = {0, "title", "author", "key_words", "publisher", "published_year"};
public:
	void get_data();
	void compute();
};
void DigitalLibrary::get_data()
{
	cin >> N;
	vecBookInfo.resize(N);
	for (int i = 0; i != N; ++i)
	{
		cin >> vecBookInfo[i].ID;
		cin.ignore(1);
		getline(cin, vecBookInfo[i].title);
		getline(cin, vecBookInfo[i].author);
		getline(cin, vecBookInfo[i].key_words);
		getline(cin, vecBookInfo[i].publisher);
		getline(cin, vecBookInfo[i].published_year);
	}
}
void DigitalLibrary::compute()
{
	cin >> M;
	cin.ignore();
	string temp;
	for (int i = 0; i != M; ++i)
	{
		vector<int> result;
		getline(cin, temp);
		int index = temp[0] - '0';
		string query = temp.substr(3);
		for (int j = 0; j != N; ++j)
		{
			switch (index)
			{
			case 1:
				if (vecBookInfo[j].title == query)
					result.push_back(vecBookInfo[j].ID);
				break;
			case 2:
				if (vecBookInfo[j].author == query)
					result.push_back(vecBookInfo[j].ID);
				break;
			case 3:
				if (vecBookInfo[j].key_words.find(query) != string::npos)
					result.push_back(vecBookInfo[j].ID);
				break;
			case 4:
				if (vecBookInfo[j].publisher == query)
					result.push_back(vecBookInfo[j].ID);
				break;
			case 5:
				if (vecBookInfo[j].published_year == query)
					result.push_back(vecBookInfo[j].ID);
			}
		}
		cout << temp << endl;
		if (result.empty())
			cout << "Not Found" << endl;
		else
		{
			sort(result.begin(), result.end());
			for (int t = 0; t != result.size(); ++t)
				cout << setw(7) << setfill('0') << result[t] << endl;       //输出一定是7位
		}
	}
}
int main()
{
	DigitalLibrary dl;
	dl.get_data();
	dl.compute();
}
