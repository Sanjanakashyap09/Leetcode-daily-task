class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n= points.size();     // number of balloons (intervals)

        sort(points.begin(), points.end());     //sort the coordinates

        vector<int>prev=points[0];     // track the current overlapping interval (start, end)
        int count=1;                  // at least one arrow is needed initially

        for(int i=1; i<n; i++){      //start traversing 

            int currStartPoint= points[i][0];    //start point of cuurent ballon
            int currEndPoint= points[i][1];      //ending point

            int prevStartPoint= prev[0];        //starting point of prev.ballon
            int prevEndPoint= prev[1];         //ending point 

            if(currStartPoint>prevEndPoint){       
                count++;                       //then move to next one
                prev=points[i];           //curr become prev for next one
            }
            else{
                prev[0] = max(prevStartPoint,currStartPoint);   // overlap exists     
                prev[1]= min(prevEndPoint,currEndPoint);       
            }

        }
        return count;        // finally return the total number of arrows needed
        
    }
};