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