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
//정확성  테스트
//테스트 1 〉	통과(0.32ms, 4.02MB)
//테스트 2 〉	통과(0.01ms, 3.81MB)
//테스트 3 〉	통과(0.30ms, 3.95MB)
//테스트 4 〉	통과(0.03ms, 3.79MB)
//테스트 5 〉	통과(0.04ms, 3.8MB)
//테스트 6 〉	통과(0.04ms, 3.83MB)
//테스트 7 〉	통과(0.34ms, 3.95MB)
//테스트 8 〉	통과(0.34ms, 4.01MB)
//테스트 9 〉	통과(0.42ms, 4.04MB)
//테스트 10 〉	통과(0.36ms, 3.95MB)
//테스트 11 〉	통과(0.29ms, 3.82MB)
//테스트 12 〉	통과(0.29ms, 3.88MB)
//테스트 13 〉	통과(0.30ms, 3.99MB)
//테스트 14 〉	통과(0.43ms, 3.91MB)
//테스트 15 〉	통과(0.50ms, 3.99MB)
//테스트 16 〉	통과(0.45ms, 4.08MB)
//테스트 17 〉	통과(0.52ms, 4.04MB)
//테스트 18 〉	통과(0.58ms, 3.95MB)
//테스트 19 〉	통과(0.55ms, 4.05MB)
//테스트 20 〉	통과(0.55ms, 3.96MB)