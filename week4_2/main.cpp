#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool mycompare(int x, int y)
{
	string sx = std::to_string(x);
	string sy = std::to_string(y);
	string ab = sx + sy;
	string ba = sy + sx;	

	return atoi(ab.c_str()) < atoi(ba.c_str());
}
string solution(vector<int> numbers) {
	string answer = "";
	sort(numbers.begin(), numbers.end(), mycompare);
	
	while (!numbers.empty())
	{
		int num = numbers.back();
		string nums = std::to_string(num);
		answer += nums;
		numbers.pop_back();
	}

	while(answer.at(0)=='0' && answer.size()>1)
	{
		answer.erase(answer.begin());
	}

 	return answer;
}

void main()
{
	vector<int> numbers;
	numbers.push_back(0);
	numbers.push_back(0);
	solution(numbers);
}

