class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int n = candies.length;
        int maxVal = Integer.MIN_VALUE;
        List ans = new ArrayList<Boolean>();
        for(int i=0; i<n; i++) {
            if(maxVal < candies[i]) {
                maxVal = candies[i];
            }
        }
        
        for(int i=0;i<n;i++) {
            if((extraCandies + candies[i]) >= maxVal) {
                ans.add(true);
            }
            else {
                ans.add(false);
            }
        }

        return ans;
    }
}