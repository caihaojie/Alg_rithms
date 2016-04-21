#include <stdio.h>
#include <limits.h>

//定义结构体，first代表子数组的左边界，second代表子数组的右边界，third代表该子数组元素和
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

/*************************************************
Function: find_maximum_subarray(int* target, int low, int high)
Description: 得到跨越mid的最大子数组的边界
Calls: find_max_crossing_subarray()
Called By: main()
Input:  int* target->数组首地址
		int low->左边界的最小值
		int high->右边界的最大值
Output: NULL
Return: 包含最大子数组边界的结构体
Others: 使用了递归
*************************************************/
result find_maximum_subarray(int* target, int low, int high)
{
	//是否进入递归的判断条件
	if (low ！= high)
	{
		//子数组均在中点左边
		result left_final;

		//子数组均在中点右边
		result right_final;

		//子数组过中点
		result cross_final;

		int mid = (low + high) / 2;

		//子数组均在中点左边求解
		left_final = find_maximum_subarray(target, low, mid);

		//子数组均在中点右边求解
		right_final = find_maximum_subarray(target, mid+1, high);

		//子数组过中点情况求解
		cross_final = find_max_crossing_subarray(target, low, mid, high);

		//取三种情况中和最大情况
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
	else
	{
		result Final;
		Final.first = low;
		Final.second = high;
		Final.third = target[low];
		return Final;
	}
}

/*************************************************
Function: find_max_crossing_subarray(int* target, int low, int mid, int high)
Description: 得到跨越mid的最大子数组的边界
Calls: NULL
Called By: find_maximum_subarray()
Input:  int* target->数组首地址
		int low->左边界最小值
		int mid->要跨越的中点
		int high->右边界最大值
Output: NULL
Return: 包含跨越mid的最大子数组的边界的结构体
Others: NULL
*************************************************/
result find_max_crossing_subarray(int* target, int low, int mid, int high)
{
	int left_sum = INT_MIN;
	int right_sum = INT_MIN;
	int sum = 0;
	int max_left = mid;
	int max_right = mid;
	result Final;

	//得到以mid为右边界的最大合法子数组,以max_left记录左边界
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

	//得到以mid为左边界的最大合法子数组,以max_right记录右边界
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
