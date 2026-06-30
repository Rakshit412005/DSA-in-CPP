#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

void sortWrtFrequencies(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;
    unordered_map<int, int> freq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (auto i : freq)
    {
        pq.push({i.second, i.first});
    }

    while(!pq.empty())
    {
        pair<int, int> topEle = pq.top();
        pq.pop();
        int freq = topEle.first;
        int ele = topEle.second;
        for (int i = 0; i < freq; i++)
        {
            ans.push_back(ele);
        }
    }
    arr = ans;
}

int main(){
    vector<int> arr = {40,20,40,30,10,40,20,20,30,40};

    sortWrtFrequencies(arr);

    for(int i =0; i< arr.size(); i++){
        cout<<arr[i]<<'\t';
    }
    
    return 0;
}