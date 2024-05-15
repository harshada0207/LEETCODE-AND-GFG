class Solution {
public:
    bool solve(int ind ,int n,int m,vector<vector<char>>& board, string word,int row ,int col)
    {
        if(ind==word.size())
        {
            return true;
        }
        if(row<n-1)
        {
            if(board[row+1][col]==word[ind])
            {
                char c=board[row][col];
                board[row][col]='.';
                bool ans =solve(ind+1,n,m,board,word,row+1,col);
                if(ans)
                {
                    return true;
                }
                board[row][col]=c;
             }
        }
        if(col<m-1)
        {
            if(board[row][col+1]==word[ind])
            {
                char c=board[row][col];
                board[row][col]='.';
                bool ans =solve(ind+1,n,m,board,word,row,col+1);
                if(ans)
                {
                    return true;
                }
                board[row][col]=c;
             }
        }
        if(row>0)
        {
             if(board[row-1][col]==word[ind])
            {
                char c=board[row][col];
                board[row][col]='.';
                bool ans =solve(ind+1,n,m,board,word,row-1,col);
                if(ans)
                {
                    return true;
                }
                board[row][col]=c;
             }
        }
        if(col>0)
        {
            
             if(board[row][col-1]==word[ind])
            {
                char c=board[row][col];
                board[row][col]='.';
                bool ans =solve(ind+1,n,m,board,word,row,col-1);
                if(ans)
                {
                    return true;
                }
                board[row][col]=c;
             }

        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        int ind=0;
         for(int row=0;row<n;row++)
        {
            for (int col=0;col<m;col++)
            {
                     if(board[row][col]==word[0])
                     {
                        if(solve(ind+1,n,m,board,word,row,col))
                        {
                               return true;
                        }
                     }
            }
        }

        return false;
        
    }
};