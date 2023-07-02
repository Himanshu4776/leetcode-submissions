/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(long long int n) {
        long long int start = 1;
        long long int end = n;
        long long int mid;
        while(start <= end)
        {
            mid = (start+end)/2;
            if(guess(mid) == 0)
                break;
            else if(guess(mid) == 1)
            {
                start = mid +1;
            }
            else
            {
                end = mid -1;
            }
        }
        return mid;
    }
};