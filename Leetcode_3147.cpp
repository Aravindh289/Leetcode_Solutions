class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size(),maxx = INT_MIN;
        for(int i=k;i<n;i++)
        {
            energy[i] = max(energy[i],energy[i]+energy[i-k]);
        }
        for(int i=n-k;i<n;i++) maxx = max(maxx,energy[i]);
        return maxx;
    }
};