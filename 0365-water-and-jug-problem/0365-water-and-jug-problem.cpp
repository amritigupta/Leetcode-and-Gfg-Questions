class Solution {
public:
// Input: x = 3, y = 5, target = 4

// Output: true

// Explanation:

// Follow these steps to reach a total of 4 liters:

// Fill the 5-liter jug (0, 5).
// Pour from the 5-liter jug into the 3-liter jug, leaving 2 liters (3, 2).
// Empty the 3-liter jug (0, 2).
// Transfer the 2 liters from the 5-liter jug to the 3-liter jug (2, 0).
// Fill the 5-liter jug again (2, 5).
// Pour from the 5-liter jug into the 3-liter jug until the 3-liter jug is full. This leaves 4 liters in the 5-liter jug (3, 4).
// Empty the 3-liter jug. Now, you have exactly 4 liters in the 5-liter jug (0, 4).
class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        
        int x=jug1Capacity,y=jug2Capacity,z=x+y;
        int steps[]={x,-x,-y,y}; //STEPS THAT CAN BE PERFORMED
        
        queue<int> q;
        vector<int> vis(z+1,0); // VISITED ARRAY TO KEEP NOT ITERATING THE SAME VALUES OVER AND OVER AGAIN
        q.push(0);
        vis[0]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            if(node==targetCapacity)
            {
                return true; // WHEN WE FIND THE TARGET CAPACITY ACHIEVED
            }
            for(int i=0;i<4;i++)
            {
                int newNode=node+steps[i];
                if(newNode>=0 && newNode<=z && vis[newNode]==0) //BOUNDARY CHECKS 
                {
                    q.push(newNode);
                    vis[newNode]=1;
                }
            }
        }
        return false; // IF TARGET CAPACITY CAN NEVER BE ACHIVED
    }

};