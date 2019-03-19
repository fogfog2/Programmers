#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(string arrangement) {
	int answer = 0;
	queue<char> queue;

	int stick = 0;
	for (auto elem : arrangement)
	{
		if (queue.size() > 0)
		{
			if (queue.back() == '(' && elem == '(')
			{
				stick += 1;
				queue.pop();
				queue.push(elem);
			}
			else if (queue.back() == '(' && elem == ')')
			{
				answer += stick;
				queue.pop();
			}
		}
		else
		{
			if (elem == ')')
			{
				stick -= 1;
				answer += 1;
			}
			else
			{
				queue.push(elem);
			}
		}
	}

	return answer;
}

void main()
{
	string ans = "()(((()())(())()))(())";

	
	solution(ans);
}
//
//��Ȯ��  �׽�Ʈ
//�׽�Ʈ 1 ��	���(0.32ms, 4.02MB)
//�׽�Ʈ 2 ��	���(0.01ms, 3.81MB)
//�׽�Ʈ 3 ��	���(0.30ms, 3.95MB)
//�׽�Ʈ 4 ��	���(0.03ms, 3.79MB)
//�׽�Ʈ 5 ��	���(0.04ms, 3.8MB)
//�׽�Ʈ 6 ��	���(0.04ms, 3.83MB)
//�׽�Ʈ 7 ��	���(0.34ms, 3.95MB)
//�׽�Ʈ 8 ��	���(0.34ms, 4.01MB)
//�׽�Ʈ 9 ��	���(0.42ms, 4.04MB)
//�׽�Ʈ 10 ��	���(0.36ms, 3.95MB)
//�׽�Ʈ 11 ��	���(0.29ms, 3.82MB)
//�׽�Ʈ 12 ��	���(0.29ms, 3.88MB)
//�׽�Ʈ 13 ��	���(0.30ms, 3.99MB)
//�׽�Ʈ 14 ��	���(0.43ms, 3.91MB)
//�׽�Ʈ 15 ��	���(0.50ms, 3.99MB)
//�׽�Ʈ 16 ��	���(0.45ms, 4.08MB)
//�׽�Ʈ 17 ��	���(0.52ms, 4.04MB)
//�׽�Ʈ 18 ��	���(0.58ms, 3.95MB)
//�׽�Ʈ 19 ��	���(0.55ms, 4.05MB)
//�׽�Ʈ 20 ��	���(0.55ms, 3.96MB)