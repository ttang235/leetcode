// https://leetcode.com/problems/largest-triangle-area/description/
class Solution {
public:
    double area(const vector<int>& A, const vector<int>& B, const vector<int>& C) {
        return abs(A[0] * (B[1] - C[1]) + B[0] * (C[1] - A[1]) + C[0] * (A[1] - B[1]))/2.0;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxi = -1;
        for(int i = 0; i < points.size(); i++) {
            for(int j = i + 1; j < points.size(); j++) {
                for(int k = j + 1; k < points.size(); k++) {
                    double a = area(points[i], points[j], points[k]);
                    if(a > maxi){
                        maxi = a;
                    }
                }
            }
        }
        return maxi;
    }
};
