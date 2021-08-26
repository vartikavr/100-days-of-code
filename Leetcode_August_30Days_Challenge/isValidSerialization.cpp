//O(n) time, O(1) space
// reference video => https://www.youtube.com/watch?v=_mbnPPHJmTQ

class Solution {
public:
    bool isValidSerialization(const string& preorder) {
        int nodeArrows = 1;
        istringstream in(preorder);
        string nodeVal;
        while(getline(in, nodeVal, ',')) 
        /*',' => delimitation character which tells the function to stop reading further input after reaching this character.
        */
        {
            nodeArrows--;
            if(nodeArrows<0)
                return false;
            if(nodeVal!="#")
                nodeArrows+=2;
        }
        if(nodeArrows==0)
            return true;
        return false;
    }
};