class Solution {
public:
    // m[i][j] =
    // if j < i, m[i][j] = m[j][i] --- keep row <= col
    // assume i <= j
    // if j - i >= 2, m[i][j] = m[i][j-2]
    // if j - i == 1, m[i][j] = m[i-1][j-2] + m[i][j-2] 
    // if j - i == 0, m[i][j] = m[i-1][j-1] + m[i-1][j-2] + m[i-2][j-1] + m[i-2][j-2]
    int numTilings(int N) {
        if (N == 1) {
            return 1;
        }
        int mod = 1000000007;
        vector<vector<int>> m(N+1, vector<int>(N+1, -1));
        m[0][0] = 1;
        for(int i = 1; i <= N; i++) {
            m[0][i] = i % 2 == 1 ? 0 : 1;
            m[i][0] = m[0][i];
            m[1][i] = 1;
            m[i][1] = 1;
        }
        for(int i = 2; i <= N; i++) {
            for(int j = 2; j <= N; j++) {
                if(i > j) {
                    m[i][j] = m[j][i];
                } else if(j - i == 0) {
                    m[i][i] = ((m[i-1][i-1] + m[i-2][i-2]) % mod + (m[i-2][i-1] * 2) % mod) % mod;
                } else if(j - i == 1) {
                    m[i][j] = (m[i-1][j-2] + m[i][j-2]) % mod;
                } else {
                    m[i][j] = m[i][j-2];
                }
            }
        }
        return m[N][N];
    }
};
