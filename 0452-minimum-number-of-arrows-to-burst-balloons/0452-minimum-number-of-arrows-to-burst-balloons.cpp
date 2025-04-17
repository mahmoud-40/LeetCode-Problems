class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(), points.end());
        int farthest = points[0][1];
        int arrows = 1;

        for (int i = 0; i < points.size(); i++) {
            if (farthest >= points[i][0]) {
                farthest = min(farthest, points[i][1]);
                continue;
            } else {
                farthest = points[i][1];
                arrows++;
            }
        }

        return arrows;
    }
};