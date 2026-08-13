class Solution {
public:
    int sumofsqaureofdigits(int n) {
        int sum = 0;
        while (n != 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        while (fast != 1) {
            slow = sumofsqaureofdigits(slow);
            fast = sumofsqaureofdigits(fast);
            fast = sumofsqaureofdigits(fast);
            if (slow == fast && slow != 1) {
                return false;
            }
        }
        return true;
    }
};