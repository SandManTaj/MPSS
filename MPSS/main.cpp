#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

void quick_sort(vector<int> &arr, int l, int r)
{
	int left = l;
	int right = r;
	int mid = ceil((double(l + r)) / 2);

	int pivot = 0;
	if (arr[mid] < arr[left] && arr[left] < arr[right] || arr[mid] > arr[left] && arr[left] > arr[right])
		pivot = left;
	else if (arr[mid] < arr[right] && arr[right] < arr[left] || arr[mid] > arr[right] && arr[right] > arr[left])
		pivot = right;
	else
		pivot = mid;


	while (left < pivot || pivot < right)
	{
		if (left < pivot)
		{
			while (arr[left] < arr[pivot])
			{
				left++;
			}
		}
		if (right > pivot)
		{
			while (arr[right] > arr[pivot])
			{
				right--;
			}
		}

		if (left < pivot && right > pivot)
		{
			swap(arr[left], arr[right]);
			right--;
			left++;
		}

		else if (left < pivot && pivot >= right)
		{
			for (int i = left; i < pivot; i++)
			{
				swap(arr[i], arr[i + 1]);
			}
			pivot--;
			left++;
		}
		else if (left >= pivot && pivot < right)
		{
			for (int i = right; i > pivot; i--)
			{
				swap(arr[i], arr[i - 1]);
			}
			pivot++;
		}


	}


	if (l < pivot)
	{
		quick_sort(arr, l, pivot - 1);
	}
	if (pivot < r)
	{
		quick_sort(arr, pivot + 1, r);
	}
}

int mcm(vector<int> arr, int left, int mid, int right)
{
	int cSum = INT_MAX;
	int sum = INT_MAX;
	vector<int> arr1 = arr;

	sort(arr1.begin(), arr1.begin() + mid);
	sort(arr1.begin() + mid, arr1.end(), std::greater<int>());

	int i = left;
	int j = mid;
	while (i < mid && j < right && i < j)
	{
		cSum = arr[i] + arr[j];
		if (cSum <= 0)
		{
			if(i < mid)
				i++;
		}
		else if (cSum < sum)
		{
			sum = cSum;
			if(j <= right)
				j++;
		}
		else
		{
			if(j <= right)
				j++;
		}
	}

	return sum;
}

int mms(vector<int> arr, int left, int right)
{
	if (left == right)
		return arr[left];
	else
	{
		int mid = (left + right) / 2;
		int midSum = mcm(arr, left, mid, right);
		int leftSum = mms(arr, left, mid);
		int rightSum = mms(arr, mid + 1, right);
		if (leftSum < midSum && rightSum < midSum && leftSum)
		{
			return midSum;
		}
		else if (midSum < leftSum && rightSum < leftSum && leftSum)
		{
			return leftSum;
		}
		else
		{
			return rightSum;
		}
	}
	return 0;
}

int main()
{
	int n = 0;
	vector<int> vec;
	srand(time(NULL));
	cout << "Please enter an array size: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vec.push_back(rand() % 201 - 100);
	}
	n = vec.size() - 1;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;

	cout << "nlogn time: " << mms(vec, 0, n) << endl;

}
