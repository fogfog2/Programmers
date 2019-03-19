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


//정확성  테스트
//테스트 1 〉	통과(0.08ms, 3.97MB)
//테스트 2 〉	통과(0.12ms, 3.98MB)
//테스트 3 〉	통과(0.02ms, 3.89MB)
//테스트 4 〉	통과(0.03ms, 3.96MB)
//테스트 5 〉	통과(0.02ms, 3.92MB)
//테스트 6 〉	통과(0.03ms, 3.91MB)
//테스트 7 〉	통과(0.03ms, 3.91MB)
//테스트 8 〉	통과(0.09ms, 3.9MB)
//테스트 9 〉	통과(0.02ms, 3.89MB)
//테스트 10 〉	통과(0.04ms, 3.91MB)
//테스트 11 〉	통과(0.08ms, 3.96MB)
//테스트 12 〉	통과(0.02ms, 3.92MB)
//테스트 13 〉	통과(0.06ms, 3.95MB)
//테스트 14 〉	통과(0.02ms, 3.92MB)
//테스트 15 〉	통과(0.02ms, 3.99MB)
//테스트 16 〉	통과(0.03ms, 3.95MB)
//테스트 17 〉	통과(0.07ms, 3.99MB)
//테스트 18 〉	통과(0.02ms, 3.88MB)
//테스트 19 〉	통과(0.08ms, 3.98MB)
//테스트 20 〉	통과(0.03ms, 3.99MB)