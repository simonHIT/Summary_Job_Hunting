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
        //������߶��ﵽĩβ��˵��ת����ϣ�����0����
        if(i >= word1.size() && j >= word2.size())
            return 0;
        //�������һ������ĩβ����ôֻ��ͨ��ɾ��/���뷽ʽʹ�������
        else if(i >= word1.size() && j < word2.size())
            return word2.size() - j;
        else if(i < word1.size() && j >= word2.size())
            return word1.size() - i;

        if(dp[i][j] != INT_MAX)
            return dp[i][j];

        if(word1[i] == word2[j])
            dp[i][j] = std::min(dp[i][j], minDistance(word1, word2, i + 1, j + 1, dp));

        // ��word1[i]�滻��word2[j]
        dp[i][j] = std::min(dp[i][j], 1 + minDistance(word1, word2, i + 1, j + 1, dp));
        // ��word1��ǰλ�ò���word2[j]
        dp[i][j] = std::min(dp[i][j], 1 + minDistance(word1, word2, i, j + 1, dp));
        // ɾ��word1[i]
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
