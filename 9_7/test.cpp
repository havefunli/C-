#include<iostream>
#include<vector>


using namespace std;


class shuzu {
public:
	int Person(vector <int>& aa, int target)
	{
		int lift = 0;
		int right = aa.size();

		while (lift < right)
		{
			int middle = lift + (right - lift) / 2;
			if (aa[middle] < target)
			{
				lift = middle + 1;
			}
			else if (aa[middle] > target)
			{
				right = middle;
			}
			else
				return  middle;
		}
		return  -1;

	}
};




int main()
{
	vector <int> arr;
	vector <int> ::iterator it;
	arr.push_back(2);
	arr.push_back(4);
	arr.push_back(6);
	arr.push_back(7);
	arr.push_back(11);
	arr.push_back(23);
	//arr.push_back(34);
	int taraget1 = 11;
	shuzu a;
	cout << a.Person(arr, taraget1);
	return 0;
}