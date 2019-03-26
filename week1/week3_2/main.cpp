//정확성  테스트
//테스트 1 〉	통과(0.00ms, 3.8MB)
//테스트 2 〉	통과(0.01ms, 3.85MB)
//테스트 3 〉	통과(0.01ms, 3.83MB)
//테스트 4 〉	통과(0.01ms, 3.87MB)
//테스트 5 〉	통과(0.01ms, 3.77MB)
//테스트 6 〉	통과(0.01ms, 3.87MB)
//테스트 7 〉	통과(0.01ms, 3.84MB)
//테스트 8 〉	통과(0.01ms, 3.85MB)
//테스트 9 〉	통과(0.01ms, 3.82MB)
//테스트 10 〉	통과(0.01ms, 3.93MB)
//테스트 11 〉	통과(0.00ms, 3.76MB)
//효율성  테스트
//테스트 1 〉	통과(0.25ms, 4.05MB)
//테스트 2 〉	통과(0.36ms, 4MB)
//테스트 3 〉	통과(0.19ms, 3.87MB)
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