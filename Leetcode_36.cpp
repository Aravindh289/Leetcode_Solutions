class Solution {
public:
    bool gridcheck(vector<vector<char>>& board,int row,int col)
    {
        unordered_map<int,int> m = {};
        for(int i=row;i<row+3;i++)
        {
            for(int j=col;j<col+3;j++)
            {
                if(board[i][j] != '.')
                   m[board[i][j]]++;
            }
        }
        for(auto a:m)
        {
            if(a.second > 1) return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int r = 9,c = 9;

        for(int i=0;i<r;i++)
        {
            unordered_map<int,int> m = {};
            for(int j=0;j<c;j++)
            {
                if(board[i][j] != '.')
                   m[board[i][j]]++;
            }
            for(auto a:m)
            {
                if(a.second > 1) return false;
            }
        }

        for(int j=0;j<c;j++)
        {
            unordered_map<int,int> m = {};
            for(int i=0;i<r;i++)
            {
                if(board[i][j] != '.')
                    m[board[i][j]]++;
            }
            for(auto a:m)
            {
                if(a.second > 1) return false;
            }
        }

        for(int i=0;i<r;i+=3)
        {
            for(int j=0;j<c;j+=3)
            {
                if(!gridcheck(board,i,j)) return false;
            }
        }

        return true;
    }
};
