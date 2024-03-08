#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freqMap;
        for(auto i: nums){
            freqMap[i]++;
        }
        int maxFreq = 0;
        int k = 0;
        for(auto i : freqMap){
            if(i.second > maxFreq){
                maxFreq = i.second;
                k = 1;
            }
            else if(i.second == maxFreq){
                k++;
            }
        }
        return maxFreq*k; 
    }
};

int main()
{
    vector<int> nums = {1,2,3,4,5};
    Solution s;
    cout << s.maxFrequencyElements(nums);
    return 0;
}