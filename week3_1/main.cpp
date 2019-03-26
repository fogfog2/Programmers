#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> heap_insert(vector<int> heaparray, int pos, int child_value)
{
	int parent = (pos-1) / 2 ;
	int parent_value = heaparray.at(parent);
	if (parent_value >= child_value || (pos ==0 && parent ==0))
	{
		return heaparray;
	}
	else 
	{
		heaparray.at(parent) = child_value;
		heaparray.at(pos) = parent_value; 
		return heap_insert(heaparray, parent, child_value); 
	}
}
vector<int> heap_delete(vector<int> heaparray, int pos, int parent_value)
{
	int child1, child2;
	child1 = (pos + 1) * 2 - 1;
	child2 = (pos + 1) * 2;

	if (child1 < heaparray.size() && child2 < heaparray.size())
	{

		int child_value1 = heaparray.at(child1);
		int child_value2 = heaparray.at(child2);
		int max_value = max(child_value1, child_value2);

		if (max_value > parent_value)//바꿔야한다면
		{
			if (max_value == child_value1)
			{
				heaparray.at(pos) = child_value1;
				heaparray.at(child1) = parent_value;
				return heap_delete(heaparray, child1, parent_value);
			}
			else
			{
				heaparray.at(pos) = child_value2;
				heaparray.at(child2) = parent_value;
				return heap_delete(heaparray, child2, parent_value);
			}
		}
		else
		{
			return heaparray;
		}
	}
	else if (child1 == heaparray.size() - 1) //노드가 하나인게 마지막 노드인경우
	{
		int child_value1 = heaparray.at(child1);

		if (child_value1 > parent_value)
		{
			heaparray.at(pos) = child_value1;
			heaparray.at(child1) = parent_value;
			return heaparray;
		}
		else
		{
			return heaparray;
		}
	}
	else //노드가 없는경우
	{
		return heaparray;
	}
	


}

int find_min(vector<int> heaparray)
{
	int min = 1000001;
	int minidx = -1;
	for (int i = 0; i < heaparray.size(); i++)
	{
		minidx = heaparray.at(i) < min ? i: minidx;
		min = heaparray.at(i) < min ? heaparray.at(i) : min;

	}
	return minidx;
}
bool isend(vector<int> heaparray, int k)
{
	int last_idx = find_min(heaparray);	
	int last = heaparray.at(last_idx); 
	heaparray= heap_delete(heaparray, last_idx, last);
	//heaparray.erase(heaparray.begin()+ last_idx);

	int second_last_idx = find_min(heaparray);
	int second_last = heaparray.at(second_last_idx);
	heaparray = heap_delete(heaparray, second_last_idx, second_last);
	//heaparray.erase(heaparray.begin() + second_last_idx);


	if (min(last, second_last) >= k)
	{
		return true;
	}
	else
		return false;
}

vector<int> scovile_sort(vector<int> heaparray, int k )
{
	int last_idx = find_min(heaparray);
	int last = heaparray.at(last_idx);
	heaparray.erase(heaparray.begin() + last_idx);

	int second_last_idx = find_min(heaparray);
	int second_last = heaparray.at(second_last_idx);
	heaparray.erase(heaparray.begin() + second_last_idx);

	int new_value = min(last, second_last) + 2* max(last, second_last);
	heaparray.push_back(new_value);

	heaparray = heap_insert(heaparray, heaparray.size() - 1, new_value);

	return heaparray;
}
bool compare(int a, int b)
{
	return a > b;
}

void printscoville(vector<int> heaparray)
{
	for (int i = 0; i < heaparray.size(); i++)
	{
		printf("%d ", heaparray.at(i));
	}
	printf("\n");
}
int solution(vector<int> scoville, int K) {
	int answer = 0;
	int counter = 0;
	sort(scoville.begin(), scoville.end(),compare); //max heap;

	while (true)
	{
		printf("%2d] ", counter);
		printscoville(scoville);
		if (scoville.size() == 1)
		{
			if (scoville.back() < K)
			{
				counter = -1;
				break;
			}
			else
			{
				break;
			}
		}
		if (isend(scoville, K))
		{
			break;
		}

		scoville = scovile_sort(scoville, K);
		counter++;
	}
	answer = counter;                       
	return answer;
} 

void main()
{
	vector<int> scoville;

	scoville.push_back(11);
	scoville.push_back(15);
	scoville.push_back(13);
	scoville.push_back(12);
	scoville.push_back(25);         
	scoville.push_back(15);
	scoville.push_back(100);
	scoville.push_back(6);
	scoville.push_back(7);
	scoville.push_back(91);
	scoville.push_back(1);
	scoville.push_back(9);
	scoville.push_back(8);
	scoville.push_back(9);
	scoville.push_back(1);
	scoville.push_back(71);
	scoville.push_back(1);
	scoville.push_back(2);
	scoville.push_back(5);
	scoville.push_back(6);
	scoville.push_back(9);
	scoville.push_back(1);
	solution(scoville, 50);
}