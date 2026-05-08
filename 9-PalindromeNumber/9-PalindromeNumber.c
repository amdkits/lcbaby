// Last updated: 5/8/2026, 6:38:45 PM
bool isPalindrome(int x) {
    int num = 0;
    if (x<0 || x!=0 && x%10==0) return false;
    while (x>num){
        num = num*10 + x%10;
        x/=10;
    }
    return (x == num || x==num/10);
}