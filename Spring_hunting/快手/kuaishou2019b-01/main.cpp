#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define INT_MAX 2147483647
class Solution {
public:
    int minNum(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int> > dp(n1, vector<int>(n2, INT_MAX));
        return minDistance(word1, word2, 0, 0, dp);
    }

private:
    int minDistance(string& word1, string& word2, int i, int j, vector<vector<int> >& dp)
    {
        //如果二者都达到末尾，说明转换完毕，返回0即可
        if(i >= word1.size() && j >= word2.size())
            return 0;
        //如果其中一个到达末尾，那么只能通过删除/插入方式使二者相等
        else if(i >= word1.size() && j < word2.size())
            return word2.size() - j;
        else if(i < word1.size() && j >= word2.size())
            return word1.size() - i;

        if(dp[i][j] != INT_MAX)
            return dp[i][j];

        if(word1[i] == word2[j])
            dp[i][j] = std::min(dp[i][j], minDistance(word1, word2, i + 1, j + 1, dp));

        // 将word1[i]替换成word2[j]
        dp[i][j] = std::min(dp[i][j], 1 + minDistance(word1, word2, i + 1, j + 1, dp));
        // 在word1当前位置插入word2[j]
        dp[i][j] = std::min(dp[i][j], 1 + minDistance(word1, word2, i, j + 1, dp));
        // 删除word1[i]
        dp[i][j] = std::min(dp[i][j], 1 + minDistance(word1, word2, i + 1, j, dp));
        return dp[i][j];
        }
};

int main()
{
    string word1,word2;
    cin>>word1>>word2;
    Solution solution;
    int result=solution.minNum(word1,word2);
    cout<<result;
    return 0;
}
