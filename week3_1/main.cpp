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
	heaparray.erase(heaparray.begin()+ last_idx);

	int second_last_idx = find_min(heaparray);
	int second_last = heaparray.at(second_last_idx);
	heaparray.erase(heaparray.begin() + second_last_idx);


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
	scoville.push_back(1);         
	scoville.push_back(1);
	scoville.push_back(1);
	scoville.push_back(1);
	scoville.push_back(1);
	scoville.push_back(9);

	scoville.push_back(0);
	scoville.push_back(0);
	scoville.push_back(13);
	scoville.push_back(12);
	scoville.push_back(13);
	scoville.push_back(20);
	scoville.push_back(16);
	scoville.push_back(12);
	solution(scoville, 10);
}