// class Solution {
// public:
//     vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
//         vector<pair<int, pair<int, char>>> Robots;
//         unordered_map<int, int> indexMap;

//         // Populate Robots vector and map the positions to their original indices
//         for (int i = 0; i < healths.size(); i++) {
//             Robots.push_back({positions[i], {healths[i], directions[i]}});
//             indexMap[positions[i]] = i;
//         }

//         // Sort Robots by position
//         sort(Robots.begin(), Robots.end());

//         stack<pair<int, pair<int, char>>> details;

//         int n = healths.size();
//         for (int i = 0; i < n; i++) {
//             auto currRobot = Robots[i];
//             int currPos = currRobot.first;
//             int currHealth = currRobot.second.first;
//             char currDirection = currRobot.second.second;

//             while (!details.empty() && details.top().second.second == 'R' && currDirection == 'L') {
//                 auto prevRobot = details.top();
//                 int prevPos = prevRobot.first;
//                 int prevHealth = prevRobot.second.first;
//                 char prevDirection = prevRobot.second.second;

//                 if (prevHealth == currHealth) {
//                     details.pop();
//                     currHealth = 0;
//                 } else if (prevHealth < currHealth) {
//                     details.pop();
//                     currHealth--;
//                 } else {
//                     details.top().second.first--;
//                     currHealth = 0;
//                 }
//             }

//             if (currHealth > 0) {
//                 details.push({currPos, {currHealth, currDirection}});
//             }
//         }

//         vector<pair<int, int>> remainingRobots;
//         while (!details.empty()) {
//             remainingRobots.push_back({details.top().first, details.top().second.first});
//             details.pop();
//         }

//         // Sort remaining robots by their original indices using indexMap
//         sort(remainingRobots.begin(), remainingRobots.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
//             return indexMap[a.first] < indexMap[b.first];
//         });

//         vector<int> ans;
//         for (const auto& robot : remainingRobots) {
//             ans.push_back(robot.second);
//         }

//         return ans;
//     }
// };
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<vector<int>> robots;

        for (int i = 0; i < n; ++i) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(robots.begin(), robots.end());

        vector<vector<int>> stack;

        for (auto& robot : robots) {
            if (robot[2] == 'R' || stack.empty() || stack.back()[2] == 'L') {
                stack.push_back(robot);
                continue;
            }

            if (robot[2] == 'L') {
                bool add = true;
                while (!stack.empty() && stack.back()[2] == 'R' && add) {
                    int last_health = stack.back()[1];
                    if (robot[1] > last_health) {
                        stack.pop_back();
                        robot[1] -= 1;
                    } else if (robot[1] < last_health) {
                        stack.back()[1] -= 1;
                        add = false;
                    } else {
                        stack.pop_back();
                        add = false;
                    }
                }

                if (add) {
                    stack.push_back(robot);
                }
            }
        }

        vector<int> result;
        sort(stack.begin(), stack.end(), [](vector<int>& a, vector<int>& b) {
            return a[3] < b[3];
        });

        for (auto& robot : stack) {
            result.push_back(robot[1]);
        }

        return result;
    }
};