// class Solution {
// public:
//     int bsearch(vector<int>& arr, int t){
//         int beg=0;
//         int end=arr.size();
//         if(arr.size()==1) return 0;
        

//         while(beg<=end){
//             int mid=beg+(end-beg)/2;

//             if(arr[mid]==t) return mid;
//             else if(arr[mid]<t) beg=mid+1;
//             else end=mid-1;
//         }
//         return beg;
//     }
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {

//         int n=matrix.size();
//         if(matrix.size()==1){
//             for(int i=0;i<matrix[0].size();i++){
//                 if(target==matrix[0][i]) return true;
//             }
//             return false;
//         }
//         vector<int> col(matrix.size());
//         for(int i=0;i<matrix.size();i++){
//             col[i]=matrix[i][0];
//         }
//         //left Col me bsearch
//         int idx=bsearch(col, target);
//         cout<<idx<<" "<<endl;
        
//         //desired row me search
//         int final_idx=bsearch(matrix[idx-1], target);

//         cout<<idx<<" "<<final_idx<<endl;
//         if(final_idx<matrix[idx-1].size()){
//             return matrix[idx-1][final_idx]==target;
//         }
//         else return false;
//      }
// };
class Solution {
public:

    bool rowsearch(vector<int> row, int target)
    {
        int li = 0;
        int hi = row.size()-1;
        while(li<hi)
        {
            int mid = (li+hi)/2;
            if(target==row[mid])
            {
                return true;
            }
            if(target>row[mid])
            {
                li=mid+1;
            }
            else
            {
                hi = mid-1;
            }
        }
        if(target==row[li])
        {
            return true;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if(target<matrix[0][0])
        {return false;}
        int x = matrix.size()-1;
        int y = matrix[x].size()-1;
        if(target>matrix[x][y])
        {
            return false;
        }
        int l = 0,h=x;
        if(target==matrix[l][0] || target==matrix[h][0])
        {
            return true;
        }
        if(target>matrix[h][0])
        {
            return rowsearch(matrix[h],target);
        }
        int ctr=0;
        for(int i=0;i<matrix.size();i++)
        {
            if(matrix[i][0]>target)
            {
                ctr = i-1;
                break;
            }
        }
        return rowsearch(matrix[ctr], target);
    }
};