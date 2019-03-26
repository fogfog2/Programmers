//�׽�Ʈ 1 ��	���(0.00ms, 3.77MB)
//�׽�Ʈ 2 ��	���(0.00ms, 3.81MB)
//�׽�Ʈ 3 ��	���(0.00ms, 3.76MB)
//�׽�Ʈ 4 ��	���(0.00ms, 3.86MB)
//�׽�Ʈ 5 ��	���(0.00ms, 3.88MB)
//�׽�Ʈ 6 ��	���(0.08ms, 3.79MB)
//�׽�Ʈ 7 ��	���(0.07ms, 3.8MB)
//�׽�Ʈ 8 ��	���(0.01ms, 3.88MB)
//�׽�Ʈ 9 ��	���(0.01ms, 3.91MB)
//�׽�Ʈ 10 ��	���(0.06ms, 3.85MB)
//�׽�Ʈ 11 ��	���(0.04ms, 3.9MB)
//�׽�Ʈ 12 ��	���(0.13ms, 3.82MB)
//�׽�Ʈ 13 ��	���(0.09ms, 3.85MB)
//�׽�Ʈ 14 ��	���(0.01ms, 3.77MB)
//�׽�Ʈ 15 ��	���(0.11ms, 3.86MB)
//�׽�Ʈ 16 ��	���(0.00ms, 3.78MB)
//ȿ����  �׽�Ʈ
//�׽�Ʈ 1 ��	���(46.16ms, 5.93MB)
//�׽�Ʈ 2 ��	���(56.13ms, 8.63MB)
//�׽�Ʈ 3 ��	���(281.50ms, 18.3MB)
//�׽�Ʈ 4 ��	���(21.94ms, 5.21MB)
//�׽�Ʈ 5 ��	���(389.21ms, 20.5MB)

#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int> > scoq;

	while (scoville.size() > 0)
	{
		scoq.push(scoville.back());
		scoville.pop_back();
	}

	while (true)
	{
		int min = scoq.top();
		scoq.pop();

		int min2 = scoq.top();
		scoq.pop();

		int new_value = min + 2 * min2;
		scoq.push(new_value);

		answer++;

		if (scoq.top() >= K)
			break;
		if (scoq.size() == 1)
		{
			return -1;
		}
			
	}

	return answer;
}
void main()
{
	vector<int> scoville;

	scoville.push_back(1);
	scoville.push_back(2);
	scoville.push_back(3);
	scoville.push_back(9);
	scoville.push_back(10);
	scoville.push_back(12);
	solution(scoville, 7);
}