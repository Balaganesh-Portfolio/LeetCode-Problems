// LeetCode Problems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
bool isPalindrome(string s);
bool canConstruct(string ransomNote, string magazine);
vector<string> summaryRanges(vector<int>& nums);

int main()
{
	//MergeSort Problem
	/*vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
	vector<int> nums2 = { 2, 5, 6 };
	int m = 3;
	int n = 3;
	merge(nums1, m, nums2, n);

	for (size_t i = 0; i < nums1.size(); i++)
	{
		cout << nums1[i] << " ";
	}*/

	//Palindrome Problem
	//string s = "race a car";

	//if (isPalindrome(s))  //if true
	//{
	//	cout << "Is a Palindrome" << endl;
	//}
	//else
	//{
	//	cout << "Is not a Palindrome" << endl;
	//}


	//Ransom Note
	/*string ransomNote = "aa";
	string magazine = "aab";

	if (canConstruct(ransomNote, magazine))	
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}*/
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

bool isPalindrome(string s)
{
	string result;
	for (char c : s)
	{
		if (isalnum(c))                    // Keep only alphanumeric characters
		{
			result += tolower(c);		   // Convert to lowercase
		}
	}

	if (result.empty())	//if string is empty return true	
	{
		return true;
	}

	int len = result.size();

	int splitIndex = len / 2;

	// Compare characters from the start and end
	for (int i = 0; i < splitIndex; i++) 
	{
		if (result[i] != result[len - i - 1]) 
		{
			return false;  // Return false if characters don't match
		}
	}
	return true;
}

bool canConstruct(string ransomNote, string magazine) 
{
	for (size_t i = 0; i < ransomNote.size(); i++)	
	{
		bool found = false;

		for (size_t j = 0; j < magazine.size(); j++)	
		{
			if (ransomNote[i] == magazine[j])	
			{
				magazine[j] = ' '; // Mark the character as used
				found = true;
				break;
			}
		}

		if (found ==  false)	
		{
			return false;
		}
	}
	return true;
}

//vector<string> summaryRanges(vector<int>& nums) 
//{
//	for (size_t i = 0; i < nums.size(); i++)	
//	{
//
//	}
//}