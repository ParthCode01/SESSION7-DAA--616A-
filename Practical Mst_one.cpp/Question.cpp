class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {

        priority_queue<pair<int,int>> pq;
        vector<int> output;

        for(int i = 0; i < arr.size(); i++)
        {
            pq.push({arr[i], i});
            
            int x = i -k;

            while(pq.top().second <= x)
                pq.pop();

            if(i>=k - 1)
                output.push_back(pq.top().first);
        }

        return output;
    }
};