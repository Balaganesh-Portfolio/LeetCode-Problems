// LeetCode Problems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

int main()
{
	//MergeSort Problem
	vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
	vector<int> nums2 = { 2, 5, 6 };
	int m = 3;
	int n = 3;
	merge(nums1, m, nums2, n);

	for (size_t i = 0; i < nums1.size(); i++)
	{
		cout << nums1[i] << " ";
	}
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	int v1 = m - 1;      //pointer to end of vector 1
	int v2 = n - 1;      //pointer to end of vector 2
	int result = m + n - 1;  //pointer to end of result vector  

	while (v1 >= 0 && v2 >= 0)  //checking to see if theres value in either of the vectors
	{
		if (nums1[v1] > nums2[v2])
		{
			nums1[result] = nums1[v1];  //arranging the result vector backwards from descending
			v1--;
		}
		else
		{
			nums1[result] = nums2[v2];
			v2--;
		}
		result--;
	}

	while (v2 >= 0) //we are making sure there aren't any remaining values in the vector
	{
		nums1[result] = nums2[v2];  //adding the remaining element from second vector to the result
		v2--;
		result--;
	}
}
