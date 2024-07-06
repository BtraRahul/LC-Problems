class Solution {
public:
    int passThePillow(int n, int time) {
        int direction = 1; // initially direction is fwd

        int curr = 1, next_person = 0;
        for (int t = 1; t <= time; t++) {
            int next_person = curr + direction;
            if (next_person == n || next_person == 1)
                direction *= -1;
            curr = next_person;
        }
        return curr;
    }
};