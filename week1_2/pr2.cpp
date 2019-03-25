#include <string>
#include <vector>
#include <list>

using namespace std;


int getHashValue(string input, int size)
{
	int hash = 0;
	hash = input.at(0) - '0';//ascii code to int
	return hash;
}

bool checkOverlap(list<string> hashTable[], string newstring ,int size )
{

	list<string>::iterator iter;
	for (int i = 0; i < size; i++)
	{
		for (iter = hashTable[i].begin(); iter != hashTable[i].end(); ++iter)
		{
			int pos = -1;
			if ((*iter).length() == newstring.length() || (*iter).length() < newstring.length())
			{
				pos = newstring.find((*iter));
			}
			else if ((*iter).length() > newstring.length())
			{
				pos = (*iter).find(newstring);
			}

			if (pos == 0)
			{
				return false;
			}
		}
	}
	return true;

}

bool solution(vector<string> phone_book) {
	bool answer = true;
	int hash_size = 10;
	list<string> *hashTable = new list<string>[hash_size];

	for (int i = 0; i < phone_book.size(); i++) 
	{
		int hash = getHashValue(phone_book.at(i), hash_size);
		answer =  checkOverlap(hashTable, phone_book.at(i), hash_size);
		if (answer == false)
			return answer;
		hashTable[hash].push_back(phone_book.at(i));
	}
	

	return answer;
}

void main()
{
	vector<string> phone_book;
	bool answer;

	phone_book.push_back("12");
	phone_book.push_back("123");
	phone_book.push_back("1235");
	phone_book.push_back("567");
	phone_book.push_back("88");

	answer = solution(phone_book);
	printf("%d", answer);
}