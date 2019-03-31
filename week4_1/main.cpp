#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int mysort(vector<int> array, int start, int end, int pos)
{
	sort(array.begin() + start-1, array.begin() + end);


	return array.at(start-1+pos-1);
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for(auto elem : commands)
	{
		int start = elem.at(0);
		int end = elem.at(1);
		int pos = elem.at(2);

		answer.push_back(mysort(array, start, end, pos));

	}
	return answer;
}

void main()
{
	vector<int> array;
	vector<int> command;
	vector< vector<int> > commands;
	array.push_back(1);
	array.push_back(5);
	array.push_back(2);
	array.push_back(6);
	array.push_back(3);
	array.push_back(7);
	array.push_back(4);
	command.push_back(2);
	command.push_back(5);
	command.push_back(3);
	commands.push_back(command);
	command.clear();
	command.push_back(4);
	command.push_back(4);
	command.push_back(1);
	commands.push_back(command);
	command.clear();

	command.push_back(1);
	command.push_back(7);
	command.push_back(3);
	commands.push_back(command);
	command.clear();

	solution(array, commands);

}
