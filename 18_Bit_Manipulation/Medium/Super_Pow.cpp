class Solution {
public:
    int modularPow(int a, int b) {
        int mod = 1337;
        int result = 1;
        a %= mod;
        while (b > 0) {
            if (b % 2 == 1) {
                result = (result * a) % mod;
            }
            a = (a * a) % mod;
            b /= 2;
        }
        return result;
}
    int superPow(int a, vector<int>& b) {
        int n=b.size();
        int res=1;
        for(int i=0;i<n;i++){
            int d=b[i];
            res=modularPow(res,10);
            int apow=modularPow(a,d);
            res=(res*apow)%1337;
        }
        return (int)res;
    }
};