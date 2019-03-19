#include <string>
#include <vector>
#include <queue>

using namespace std;

int searchHigh(queue<int> que)
{
	int first = que.front();
	int first_id = 0;
	que.pop();
	for (int i = 0; que.size()>0; i++)
	{
		int t = que.front();
		if (t> first)
		{
			first = t;
			first_id = i+1;
		}
		que.pop();
	}

	return first_id;
}

queue<int> rearange(queue<int> que, int idx)
{
	for (int i = 0; i < idx; i++)
	{
		int val = que.front();
		que.push(val);
		que.pop();
	}
	return que;
}

int solution(vector<int> priorities, int location) {
	int answer = 0;

	queue<int> que; 
	queue<int> order;
	
	for (int i = 0; i < priorities.size(); i++)
	{
		order.push(i);
	}

	for (auto elem : priorities)
	{
		que.push(elem);
	}

	int offset = 0;
	int order_num = 0;

	while (que.size() > 0)
	{
		answer++;
		int max_value = searchHigh(que);
		que = rearange(que, max_value);
		order = rearange(order, max_value);

		printf("%d, %d, %d \n", que.front(),max_value,order.front());

		if (order.front() == location)
		{
			return answer;
		}
		que.pop();
		order.pop();
	}	

	//return answer;
}

void main()
{
	vector <int> priorities;
	priorities.push_back(1);
	priorities.push_back(2);
	priorities.push_back(5);
	priorities.push_back(9);
	priorities.push_back(4);
	priorities.push_back(3);
	priorities.push_back(4);
	priorities.push_back(3);
	priorities.push_back(1);
	int location = 0;
	solution(priorities, location);
}


//��Ȯ��  �׽�Ʈ
//�׽�Ʈ 1 ��	���(0.08ms, 3.97MB)
//�׽�Ʈ 2 ��	���(0.12ms, 3.98MB)
//�׽�Ʈ 3 ��	���(0.02ms, 3.89MB)
//�׽�Ʈ 4 ��	���(0.03ms, 3.96MB)
//�׽�Ʈ 5 ��	���(0.02ms, 3.92MB)
//�׽�Ʈ 6 ��	���(0.03ms, 3.91MB)
//�׽�Ʈ 7 ��	���(0.03ms, 3.91MB)
//�׽�Ʈ 8 ��	���(0.09ms, 3.9MB)
//�׽�Ʈ 9 ��	���(0.02ms, 3.89MB)
//�׽�Ʈ 10 ��	���(0.04ms, 3.91MB)
//�׽�Ʈ 11 ��	���(0.08ms, 3.96MB)
//�׽�Ʈ 12 ��	���(0.02ms, 3.92MB)
//�׽�Ʈ 13 ��	���(0.06ms, 3.95MB)
//�׽�Ʈ 14 ��	���(0.02ms, 3.92MB)
//�׽�Ʈ 15 ��	���(0.02ms, 3.99MB)
//�׽�Ʈ 16 ��	���(0.03ms, 3.95MB)
//�׽�Ʈ 17 ��	���(0.07ms, 3.99MB)
//�׽�Ʈ 18 ��	���(0.02ms, 3.88MB)
//�׽�Ʈ 19 ��	���(0.08ms, 3.98MB)
//�׽�Ʈ 20 ��	���(0.03ms, 3.99MB)