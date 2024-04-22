class Solution {
public:
    int openLock(vector<string>& arr, string target) {
        
        unordered_map<string, bool> deadend;
        
        for(auto x: arr)
        {
            if(x=="0000" or x == target)
            {
                return -1;
            }
            deadend[x]=true;
        }
        
        if(target=="0000")
        {
            return 0;
        }
        
        unordered_map<string,bool> codeProcessBefore;
        
         unordered_map<char, char> prevSlot = {
            {'0', '9'}, 
            {'1', '0'}, 
            {'2', '1'}, 
            {'3', '2'}, 
            {'4', '3'},
            {'5', '4'}, 
            {'6', '5'}, 
            {'7', '6'}, 
            {'8', '7'}, 
            {'9', '8'}
        };
        
         unordered_map<char, char> nextSlot = {
            {'0', '1'}, 
            {'1', '2'}, 
            {'2', '3'}, 
            {'3', '4'}, 
            {'4', '5'},
            {'5', '6'}, 
            {'6', '7'}, 
            {'7', '8'}, 
            {'8', '9'}, 
            {'9', '0'}
        };
        
        
        queue<string> bfs;
        
        bfs.push("0000");
        
        int min_turns=0;
        
        
        while(!bfs.empty()){
            
            int n= bfs.size();
            ++min_turns;
            
            for(int sz=0;sz<n;sz++)
            {
                string code = bfs.front();
                
                bfs.pop();
                
                for(int i=0;i<4;i++)
                {
                    string newCode= code;
                    
                    int value = newCode[i]-'0';
                    
                    newCode[i]=nextSlot[newCode[i]];
                    
                     if(newCode == target)
                    {
                        return min_turns;
                    }
                    if(!deadend[newCode] and !codeProcessBefore[newCode])
                    {
                        codeProcessBefore[newCode]=true;
                        bfs.push(newCode);
                    }
                    
                    newCode=code;
                    newCode[i]=prevSlot[newCode[i]];
                    
                     if(newCode == target)
                    {
                        return min_turns;
                    }
                    
                    if(!deadend[newCode] and !codeProcessBefore[newCode])
                    {
                        codeProcessBefore[newCode]=true;
                        bfs.push(newCode);
                    }
                }
                    
              
                }
            }
        
        return -1;
    }
};