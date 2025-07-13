class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int ps = players.size();
        int ts = trainers.size();
        int c=0;
        int pi=0,ti=0;
        while(pi < ps && ti <ts)
        {
            if(trainers[ti] >= players[pi])
            {
                c++;
                ti++;
                pi++;
            }
            else if (trainers[ti] < players[pi])
            {
                ti++;
            }
        }
        return c;
    }
};
