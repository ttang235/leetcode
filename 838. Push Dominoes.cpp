// https://leetcode.com/contest/weekly-contest-85/problems/push-dominoes/
class Solution {
public:
    string pushDominoes(string dominoes) {
        if (dominoes.size() <= 1) {
            return dominoes;
        }
        int i = 0;
        char left = 'S', right = 'E'; //start, end
        while (i < dominoes.size()) {
            int j = i + 1;
            if (dominoes[i] == '.') {
                while (j < dominoes.size() && dominoes[j] == '.') j++;
                if (j == dominoes.size()) {
                    right = 'E';
                } else {
                    right = dominoes[j];
                }
                if (left == 'S' || left == 'L') {
                    if (right == 'L') {
                        for (int k = i; k < j; k++) dominoes[k] = 'L';
                    }
                } else { // left = 'R'
                    if (right == 'L') {
                        int cnt = (j - i) / 2;
                        for (int k = 0; k < cnt; k++) {
                            dominoes[i + k] = 'R';
                            dominoes[j - k - 1] = 'L';
                        }
                    } else { // right = 'R' or 'E'
                        for (int k = i; k < j; k++) dominoes[k] = 'R';
                    }
                }
                i = j;
                left = right;
            } else {
                left = dominoes[i];
                i++;
            }
        }
        return dominoes;
    }
};
