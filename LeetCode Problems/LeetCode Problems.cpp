// LeetCode Problems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <stack>
#include <unordered_map>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
bool isPalindrome(string s);
bool canConstruct(string ransomNote, string magazine);
vector<string> summaryRanges(vector<int>& nums);
bool isValid(string s);
bool hasCycle(ListNode* head);	
int maxDepth(TreeNode* root);

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};

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

	//Summary Ranges
	//vector<int> nums = { 0, 1, 2, 4, 5, 7 };

	//// Save the result
	//vector<string> ranges = summaryRanges(nums);

	//// Print the result
	//cout << "Ranges: ";
	//for (size_t i = 0; i < ranges.size(); i++)
	//{
	//	cout << ranges[i];
	//	if (i < ranges.size() - 1) // Add space between ranges
	//		cout << " ";
	//}
	//cout << endl;

	//return 0;

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

		if (found == false)
		{
			return false;
		}
	}
	return true;
}

vector<string> summaryRanges(vector<int>& nums)
{
	vector<string> result; // To store the ranges

	//handle empty case
	if (nums.empty())
	{
		return result;
	}

	int start = nums[0];  // Start value of the current range

	for (size_t i = 0; i < nums.size(); i++)
	{
		if (i == nums.size() - 1 || nums[i] + 1 != nums[i + 1])	
		{
			if (start == nums[i])
			{
				result.push_back(to_string(start)); //if single number range we add it to vector
			}
			else //if multiple number range
			{
				result.push_back(to_string(start) + "->" + to_string(nums[i]));
			}

			// Update start to the next number (if there is one)
			if (i < nums.size() - 1)
			{
				start = nums[i + 1];
			}

		}
	}
	return result;
}

bool isValid(string s) 
{
	stack<char> bracketStack;
	unordered_map<char, char> matchingBrackets = { {')', '('}, {'}', '{'}, {']', '['} };  //push all values in

	for (char c : s) {
		if (matchingBrackets.count(c)) {  //if theres a closing bracket
			if (!bracketStack.empty() && bracketStack.top() == matchingBrackets[c]) {	//if it matches, remove them
				bracketStack.pop();	
			}
			else {
				return false;
			}
		}
		else {
			bracketStack.push(c);	//If the character is an opening bracket, push it onto the stack.
		}
	}
	return bracketStack.empty();		
}

bool hasCycle(ListNode* head) 
{
	if (head == nullptr || head->next == nullptr)	// Empty list or single node
	{
		return false;
	}

	ListNode* slow = head; // Slow pointer
	ListNode* fast = head->next; // Fast pointer

	while (fast != nullptr && fast->next != nullptr)
	{
		if (slow == fast)	
		{
			return true; // Cycle detected
		}
		slow = slow->next;  // Move slow pointer one step
		fast = (fast->next)->next;   // Move fast pointer two steps
	}
	return false;  //no cycle
}

int maxDepth(TreeNode* root)
{
	if (root == nullptr)	
	{
		return 0;
	}

	int leftNode = maxDepth(root->left);
	int rightNode = maxDepth(root->right);

	/*if (leftNode > rightNode)
	{
		leftNode += 1;
		return leftNode;	
	}
	else
	{
		rightNode += 1;
		return rightNode;
	}*/

	return 1 + std::max(leftNode, rightNode);	
}