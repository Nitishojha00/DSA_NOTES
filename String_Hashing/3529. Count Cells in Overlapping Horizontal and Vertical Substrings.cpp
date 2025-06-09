// ek code kam tamam kaisa lps nikalta sara ekhi me khatam
// step 1 -> Finding lps of pattern string
// step 2 -> making the horizontal and vertical string as question said
// step 3-> start traversion first horizontally whenever i find a complete find of pattern then i have a integer 
//           that indicate that till that index we already visited its all dont by kmp algorithm

// step 4 -> now started traversing on vertical string whenever i find the match  i take that string start index or 
//           pinned index+1 whatever maximum we will take and traverse till last of string index if in real grid there marked 1 
//            that we done when we traversiong horizontally in increase ans++
// step 5->  return ans

class Solution {
public:
    int countCells(vector<vector<char>>& grid, string pattern) {
        
        int n = pattern.size();
        vector<int>lps(n,0);

        // making lps of pattern
        int pref = 0 , suff = 1;
        while(suff<n)
        {
            if(pattern[pref]==pattern[suff])
            {
                lps[suff] = pref+1;
                pref++ , suff++ ;
            }
            else
            {
                if(!pref)
                {
                    lps[suff] = 0;
                    suff++;
                }
                else
                {
                    pref = lps[pref-1];
                }
            }
        }

        string hor,ver;
        for(int i=0;i<grid.size();i++) // making hirzontal string
        {
            for(int j=0;j<grid[i].size();j++)
            {
                hor+=grid[i][j];
            }
        }
        for(int i=0;i<grid[0].size();i++)  // making vertical string
        {
            for(int j=0;j<grid.size();j++)
            {
                ver+=grid[j][i];
            }
        }

         // start traversing row wise taking horizontal string
         pref = 0 , suff = 0 ;
         int lastpinned = -1 , c = grid[0].size() , r = grid.size();
         while(suff<hor.size())
         {
            if(hor[suff]==pattern[pref])
            {
                suff++,pref++;
                if(pref==n)
                {
                    for(int i=max(suff-n,lastpinned+1);i<suff;i++)
                    {
                            grid[i/c][i%c] = 1;
                            cout<<i/c<<" "<<i%c<<endl;
                    }
                    lastpinned = suff-1;
                    pref = lps[pref-1];
                }
            }
            else
            {
                    if(pref==0)
                    suff++;
                    else
                    pref = lps[pref-1];
            }
         }

          pref = 0 , suff = 0 ;
         lastpinned = -1 ;
         int ans = 0;
         while(suff<ver.size())
         {
            if(ver[suff]==pattern[pref])
            {
                suff++,pref++;
                if(pref==n)
                {
                    for(int i=max(suff-n,lastpinned+1);i<suff;i++)
                    {
                            if(grid[i%r][i/r] == 1)
                            ans++;
                            cout<<i%r<<" "<<i/c<<endl;
                    }
                    lastpinned = suff-1;
                    pref = lps[pref-1];
                }
            }
            else
            {
                if(pref==0)
                    suff++;
                    else
                    pref = lps[pref-1];
            }
         }

         return ans;
    }
};