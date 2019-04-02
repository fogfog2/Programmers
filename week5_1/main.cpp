#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int myscore(string student, vector<int> answers)
{
	int _score = 0;
	int idx = 0;
	for (auto ans : answers)
	{
		int  a =  (int)(student.at(idx%student.size()) - '0');
		_score = (a ==ans) ? _score+1 : _score ;
		idx++;
	}

	return _score;
}

vector<int> solution(vector<int> answers) {
	vector<int> answer;	
	vector<int> score;
	string student1, student2, student3;
	student1 = "12345";
	student2 = "21232425";
	student3 = "3311224455";

	score.push_back(myscore(student1, answers));
	score.push_back(myscore(student2, answers));
	score.push_back(myscore(student3, answers));
	int maxvalue = *std::max_element(score.begin(), score.end());
	
	for (int i = 0; i < 3; i++)
	{
		if (maxvalue == score.at(i))
		{
			answer.push_back(i+1);
		}
	}

	return answer;
}

void main()
{
	vector <int> answers;
	answers.push_back(1);
	answers.push_back(2);
	answers.push_back(3);
	answers.push_back(4);
	answers.push_back(5);

	solution(answers);

}