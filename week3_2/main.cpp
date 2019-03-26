//��Ȯ��  �׽�Ʈ
//�׽�Ʈ 1 ��	���(0.00ms, 3.8MB)
//�׽�Ʈ 2 ��	���(0.01ms, 3.85MB)
//�׽�Ʈ 3 ��	���(0.01ms, 3.83MB)
//�׽�Ʈ 4 ��	���(0.01ms, 3.87MB)
//�׽�Ʈ 5 ��	���(0.01ms, 3.77MB)
//�׽�Ʈ 6 ��	���(0.01ms, 3.87MB)
//�׽�Ʈ 7 ��	���(0.01ms, 3.84MB)
//�׽�Ʈ 8 ��	���(0.01ms, 3.85MB)
//�׽�Ʈ 9 ��	���(0.01ms, 3.82MB)
//�׽�Ʈ 10 ��	���(0.01ms, 3.93MB)
//�׽�Ʈ 11 ��	���(0.00ms, 3.76MB)
//ȿ����  �׽�Ʈ
//�׽�Ʈ 1 ��	���(0.25ms, 4.05MB)
//�׽�Ʈ 2 ��	���(0.36ms, 4MB)
//�׽�Ʈ 3 ��	���(0.19ms, 3.87MB)
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int> stq;
	
	int idx =0; 
	for (int i = 0; i < k; i++)
	{
		if (idx < dates.size())
		{
			if (i == dates[idx])
			{
				stq.push(supplies[idx]);
				idx++;
			}
		}
		stock--;
		if (stock < 0)
		{
			stock += stq.top();
			stq.pop();
			answer++;
		}
	}

	return answer;
}

void main()
{
	vector<int> dates, supplies;
	dates.push_back(4);
	dates.push_back(10);
	dates.push_back(15);
	supplies.push_back(20);
	supplies.push_back(5);
	supplies.push_back(10);
	solution(4, dates, supplies, 30);

}