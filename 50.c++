
class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;

        // Handle negative powers
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }

        double result = 1.0;

        while (power > 0) {
            // If power is odd, multiply result by x
            if (power % 2 == 1) {
                result *= x;
            }

            // Square x and divide power by 2
            x *= x;
            power /= 2;
        }

        return result;
    }
};
