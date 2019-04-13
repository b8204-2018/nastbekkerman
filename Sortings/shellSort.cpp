#include "pch.h"
#include <iostream>
#include <stack> 

using namespace std;

class Sort {
private:
public:
	virtual void sortName() = 0;
	virtual void sort(int* mass, int n) = 0;
};


class Shell : public Sort {
public:

	void sortName() override {
		cout << "Shell Sort : " << endl;
	}
	void sort(int* mass , int n) override
	{
		int i, j, step;
		int tmp;
		for (step = n / 2; step > 0; step /= 2)
			for (i = step; i < n; i++)
			{
				tmp = mass[i];
				for (j = i; j >= step; j -= step)
				{
					if (tmp < mass[j - step])
						mass[j] = mass[j - step];
					else
						break;
				}
				mass[j] = tmp;
			}
	}
};



void printSortedArray(Sort &sortC, int *arr, int n) {
	int *res = new int[n];
	memcpy(res, arr, n * sizeof(int));
	sortC.sortName();
	sortC.sort(arr, n);
	for (int i = 0; i < n; i++)
		cout << " " << res[i];
	cout << endl;
}
int main()
{
	Shell shellSort;

	int n;
	cout << "Enter array values : " << endl;
	cin >> n;
	cout << " Array values: " << endl;
	int *arrUser = new int[n];
	for (size_t i = 0; i < n; i++) {
		arrUser[i] = rand() % 100;
		cout << arrUser[i] << " ";
	}

	cout << endl;
	shellSort.sort(arrUser, n);

	printSortedArray(shellSort, arrUser, n);
	return 0;
}


