#include<bits/stdc++.h>
using namespace std;
int main()
{
    //taking the ldimnesions of 2D char array
    int n,m;
    cout<<"enter the number of rows and columns in 2D char array: "<<endl;
    cin>>n>>m;

    //initialising the 2D char array
    char arr[n][m];

    //initialising an array to take inpput as string
    string str;

    cout<<"enter the names: "<<endl;
    //taking string inputs from user
    for(int i=0;i<n;i++)
    {
        cin>>str;

        //if string length is greater than the maximum length
        //then generate an error and re-enter the string
        if(str.length()>m)
        {
            cout<<"maximum length exceed, re-enter the name "<<endl;
            i--;
        }

        //else copy the string into the char array
        else
        {
            strcpy(arr[i],str.c_str());
        }
        
    }

    cout<<endl<<endl;
    //printing the all the names in the 2D char array
   for (int i=0; i<n; ++i) {
       for(int j=0;arr[i][j]!='\0';j++)//char array terminates with '\0'
        cout<<arr[i][j];
      cout<<endl;
   }

   //taking index at which we have to reverse the string
   int index;
   cout<<endl<<"enter the index: ";
   cin>>index;

   //if index is out of limit generate an error and re-enter the index
   if(index>n)
   {
   cout<<"index is out of limit, please re-enter index"<<endl;
   cin>>index;
   }

   //getting the length of string at index entered
   int len;
   for(len=0;arr[index][len]!='\0';)
   len++;

   //reversing the string present at the index entered 
   int start=0;
   len--;
   while(start<len)
   {
       //reversing by string by swapping the character from end with from beginning
       //anf the decrease the end and increasing the start index
        char temp = arr[index][start];
        arr[index][start] = arr[index][len];
        arr[index][len] = temp;
        start++;
        len--;
   }

    cout<<endl<<endl;
  //printing the string from the 2D char array
   for (int i=0; i<n; ++i) {
       for(int j=0;arr[i][j]!='\0';j++)//char array terminates with '\0'
      cout<<arr[i][j];
      cout<<endl;
   }

}