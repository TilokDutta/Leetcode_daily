class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                // Check if the point (i, j) is within or on the circle
                if ((i - xCenter) * (i - xCenter) + (j - yCenter) * (j - yCenter) <= radius * radius) {
                    return true; // Overlap detected
                }
            }
        }
        return false; // No overlap
    }
};
