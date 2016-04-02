#include <stdio.h>
#include <limits.h>

struct result
{
	int first;
	int second;
	int third;
};

typedef struct result result;

result find_max_crossing_subarray();

result find_maximum_subarray();

void main()
{
	int target[6] = { 12, -4, 5, -3, 4, 6 };
	result answer;
	answer = find_maximum_subarray(target, 0, 6);
	printf("%d\t%d\t%d\n", answer.first + 1, answer.second + 1, answer.third );
}

result find_maximum_subarray(int* target, int low, int high)
{
	if (low == high)
	{
		result Final;
		Final.first = low;
		Final.second = high;
		Final.third = target[low];
		return Final;
	}
	else
	{
		result left_final;
		result right_final;
		result cross_final;
		int mid = (low + high) / 2;
		left_final = find_maximum_subarray(target, low, mid);
		right_final = find_maximum_subarray(target, mid+1, high);
		cross_final = find_max_crossing_subarray(target, low, mid, high);
		if (left_final.third > right_final.third && left_final.third > cross_final.third)
		{
			return left_final;
		}
		else if (right_final.third > left_final.third && right_final.third > cross_final.third)
		{
			return right_final;
		}
		else
		{
			return cross_final;
		}
	}
}

result find_max_crossing_subarray(int* target, int low, int mid, int high)
{
	int left_sum = INT_MIN;
	int right_sum = INT_MIN;
	int sum = 0;
	int max_left = mid;
	int max_right = mid;
	result Final;
	for (int i = mid; i > low; i--)
	{
		sum += target[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}
	sum = 0;
	for (int i = mid + 1; i < high; i++)
	{
		sum += target[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = i;
		}
	}
	Final.first = max_left;
	Final.second = max_right;
	Final.third = left_sum + right_sum;
	return Final;
}
