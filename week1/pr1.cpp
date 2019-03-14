#include <string>
#include <vector>
#include <list>

using namespace std;


int getHashValue(string input, int size)
{
	int hash = 0;
	for (int i = 0; i < input.size(); i++)
	{
		hash += input.at(i);
	}
	hash %= size;
	return hash;
}

string getRemainValue(list<string> table[], int size)
{
	list<string>::iterator iter;
	for (int i = 0; i < size; i++)
	{
		for (iter = table[i].begin(); iter != table[i].end(); ++iter)
		{
			return *iter;
		}
	}
}

bool eraseValue(list<string> table[], string value, int hash_size)
{
	int hash = getHashValue(value, hash_size);

	list<string>::iterator iter;
	for (iter = table[hash].begin(); iter != table[hash].end(); ++iter)
	{
		if ((*iter).compare(value) == 0)
		{
			table[hash].erase(iter);
			return true;
		}			
	}
	return false;
}

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	int hash_size = participant.size();
	list<string> *hashTable = new list<string>[hash_size];

	for (int i = 0; i < participant.size(); i++)
	{
		int hash = getHashValue(participant.at(i), hash_size);
		hashTable[hash].push_back(participant.at(i));
	}
	
	for (int i = 0; i < completion.size(); i++)
	{
		eraseValue(hashTable, completion.at(i), hash_size);
	}

	answer = getRemainValue(hashTable, hash_size);

	return answer;
}


void main()
{
	vector<string> participant, completion;
	string answer;

	participant.push_back("leo");
	participant.push_back("kiki");
	participant.push_back("eden");
	participant.push_back("eden");

	completion.push_back("eden");
	completion.push_back("kiki");
	completion.push_back("leo");

	answer = solution(participant, completion);
}