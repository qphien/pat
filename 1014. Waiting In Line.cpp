#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

struct Window
{
	int PopTime;
	int EndTime;
	queue<int> que;
};
class WaitInLine
{
private:
	int start_time = 8 * 60;
	int end_time = 17 * 60;
	int N;
	int M;
	int K;
	int Q;
	//vector<int> windows;      //number of people in front of yellow line in windows[i]
	vector<Window> win;
	vector<int> DoneTime;
	vector<int> Transaction;
public:
	void get_data();
	void compute();
};
void WaitInLine::get_data()
{
	cin >> N >> M >> K >> Q;
	DoneTime.resize(K + 1);
	win.resize(N);
	Transaction.resize(K + 1);
	//DoneTime.resize(N + 1);
	for (int i = 1; i != K + 1; ++i)
		cin >> Transaction[i];
	for (int i = 0; i != N; ++i)
		win[i].EndTime = win[i].PopTime = start_time;
	int index = 1;
	for (; index != min(N*M, K) + 1; ++index)
	{
		win[(index - 1) % N].EndTime += Transaction[index];
		win[(index - 1) % N].que.push(index);
		if (index <= N) win[(index - 1) % N].PopTime += Transaction[index];
		DoneTime[index] = win[(index - 1) % N].EndTime;
	}
	for (; index != K + 1; ++index)
	{
		int t = 0;
		for (int i = 1; i != N; ++i)
		{
			if (win[i].PopTime < win[t].PopTime)
				t = i;
		}
		win[t].que.push(index);
		win[t].que.pop();
		win[t].PopTime += Transaction[win[t].que.front()];
		win[t].EndTime += Transaction[index];
		DoneTime[index] = win[t].EndTime;
	}
}
void WaitInLine::compute()
{
	for (int i = 0; i != Q; ++i)
	{
		int QueryID;
		cin >> QueryID;
		if (DoneTime[QueryID] - Transaction[QueryID] >= 17 * 60)
			cout << "Sorry" << endl;
		else
		{
			int hour = DoneTime[QueryID] / 60;
			int min = DoneTime[QueryID] % 60;
			cout << setw(2) << setfill('0') << hour << ':' << setw(2) << min << endl;
		}
	}
}
int main()
{
	WaitInLine wil;
	wil.get_data();
	wil.compute();
}

