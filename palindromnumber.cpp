

bool isPalindrome(long long x) {
    if (x>=0) {
        long long temp = x;
        long long d = 0;
        while (temp!=0) {
            d = d*10 + temp%10;
            temp=temp/10;
        }
        // printf("%d",d);
        if (x == d) {
            return true;
        }
    }
    return false;
}
