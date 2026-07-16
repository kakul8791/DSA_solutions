class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(0));

        ways.assign(n, vector<int>(n, 0));

        score[n-1][n-1] = 0;
        ways[n-1][n-1] = 1;

        for(int i=n-1;i>=0;i--){

            for(int j=n-1;j>=0;j--){

                if(board[i][j]=='X')
                    continue;

                if(i==n-1 && j==n-1)
                    continue;

                int best=-1;
                int cnt=0;

                vector<pair<int,int>> dir={{1,0},{0,1},{1,1}};

                for(auto [dx,dy]:dir){

                    int ni=i+dx;
                    int nj=j+dy;

                    if(ni>=n || nj>=n)
                        continue;

                    if(score[ni][nj]==-1)
                        continue;

                    if(score[ni][nj]>best){

                        best=score[ni][nj];
                        cnt=ways[ni][nj];

                    }
                    else if(score[ni][nj]==best){

                        cnt=(cnt+ways[ni][nj])%MOD;
                    }
                }

                if(best==-1)
                    continue;

                score[i][j]=best;

                if(board[i][j]!='E')
                    score[i][j]+=board[i][j]-'0';

                ways[i][j]=cnt;
            }
        }

        if(score[0][0]==-1)
            return {0,0};

        return {score[0][0],ways[0][0]};
    }
};