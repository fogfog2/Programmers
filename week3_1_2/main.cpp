//테스트 1 〉	통과(0.00ms, 3.77MB)
//테스트 2 〉	통과(0.00ms, 3.81MB)
//테스트 3 〉	통과(0.00ms, 3.76MB)
//테스트 4 〉	통과(0.00ms, 3.86MB)
//테스트 5 〉	통과(0.00ms, 3.88MB)
//테스트 6 〉	통과(0.08ms, 3.79MB)
//테스트 7 〉	통과(0.07ms, 3.8MB)
//테스트 8 〉	통과(0.01ms, 3.88MB)
//테스트 9 〉	통과(0.01ms, 3.91MB)
//테스트 10 〉	통과(0.06ms, 3.85MB)
//테스트 11 〉	통과(0.04ms, 3.9MB)
//테스트 12 〉	통과(0.13ms, 3.82MB)
//테스트 13 〉	통과(0.09ms, 3.85MB)
//테스트 14 〉	통과(0.01ms, 3.77MB)
//테스트 15 〉	통과(0.11ms, 3.86MB)
//테스트 16 〉	통과(0.00ms, 3.78MB)
//효율성  테스트
//테스트 1 〉	통과(46.16ms, 5.93MB)
//테스트 2 〉	통과(56.13ms, 8.63MB)
//테스트 3 〉	통과(281.50ms, 18.3MB)
//테스트 4 〉	통과(21.94ms, 5.21MB)
//테스트 5 〉	통과(389.21ms, 20.5MB)

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