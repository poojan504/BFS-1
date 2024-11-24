// we are given the total number of courses
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //firstly create an indegrees array
        vector<int>indegrees(numCourses,0);

        for(auto &pr : prerequisites)
        {
            indegrees[pr[0]]++;
        }

        //now in out case [dep, ind]

        // Now to keep track of the dependecies we need to create a map as we are 
        // going to update the indegrees array based on the courses we have taken
        // and will reduce there dependecies

        unordered_map<int,vector<int>>Tracker;
        for(auto &pr : prerequisites)
        {
            Tracker[pr[1]].push_back(pr[0]);
        }
        //once we have the graph and idegrees array we can apply the BFS starting from each childern

        queue<int>currCourse;
        int count = 0;


        for(int i = 0; i < indegrees.size(); i++)
        {
            if(indegrees[i]==0)
            {
                currCourse.push(i);
                count++;
            }

        }
        // we need to check
        
        while(!currCourse.empty())
        {
            
            int course = currCourse.front();
            currCourse.pop();

            for(int nextCourse : Tracker[course])
            {
                indegrees[nextCourse]--;
                if(indegrees[nextCourse] == 0)
                {
                    currCourse.push(nextCourse);
                    count++;
                }
            }

        }
        return (count == numCourses);

    }
};

//Time complexity O(m+n)
//space complexity O(m+n)