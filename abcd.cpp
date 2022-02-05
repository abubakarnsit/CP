int minSets(char*input1, int input2,int input3)
{
    int cnt = 0;
    int num = 0;
    int f = 0;
  
    // Iterate in the string
    for (int i = 0; i < input3; i++) {
        num = num * 10 + (input1[i] - '0');
        if (num <= input2)
            f = 1;
        else 
        {
            if (f)
                cnt += 1;
            num = input1[i] - '0';
            f = 0;
            if (num <= input2)
                f = 1;
            else
                num = 0;
        }
    }
    if (f)
        cnt += 1;
  
    return cnt;
}
  
// Driver Code
int main()
{
    char s[4] = "1234";
    int input2 = 30;
    cout << minimumSets(s, y,4);
  
 return 0;
}