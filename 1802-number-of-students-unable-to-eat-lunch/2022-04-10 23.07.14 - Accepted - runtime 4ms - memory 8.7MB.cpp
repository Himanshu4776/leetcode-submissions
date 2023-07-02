class Solution {
public:
    int countStudents(vector<int>& stud, vector<int>& sand) {
        // Brute force:
//         if(accumulate(stud.begin(),stud.end(),0)==accumulate(sand.begin(),sand.end(),0))
//             return 0;
        
//         int n = stud.size(),newsize = 0;
//         queue<bool>q;
//         for(int i=0;i<n;i++) q.push(stud[i]);
//         for(int i=0;i<n;i++)
//         {
//             if(sand[i] == q.front()) q.pop();
//             else 
//             {
//                 newsize = q.size();
//                 int j=0; bool broke = false;
//                 while(j<newsize)
//                 {
//                     if(sand[i] == q.front()) {
//                         broke = true;
//                         q.pop();
//                         break;
//                     }
//                     else {
//                         int val = q.front();
//                         q.pop();
//                         q.push(val);
//                     }
//                     j++;
//                 }
//                 if(broke == false) return newsize;
//             }
//         }
//         return newsize;
        
        // Optimised:
        int s = stud.size();
        int m =0,n = 0, i;
        for(i=0;i<s;i++) {
            if(stud[i] == 0) m++;
            else n++;
        }
        for(i=0;i<s;i++)
        {
            if(sand[i] == 0){
                if(m>0) m--;
                else break;
            }
            if(sand[i] == 1){
                if(n>0) n--;
                else break;
            }
        }
        return sand.size() - i;
    }
};