#include<stdio.h>
#include <stdlib.h>//for the malloc function

int main()
{
    int num;//user input of number of students
    printf("enter the number of students ");
    scanf("%d",&num);

    //usr input of number of subjects
    int subjects;
    printf("enter the number of subjects ");
    scanf("%d",&subjects);

    int *ptr, **arr;

    //making 2d dynamic array of size nXsubjects with the help of malloc
    int len = sizeof(int *) * num + sizeof(int) * subjects * num;
    arr = (int **)malloc(len);//will allocate the memory of size len dynamically
    ptr = (int *)(arr + num);

    //for loop to point rows pointer to appropiate location in 2D array
    for(int i=0;i<num;i++)
    arr[i]=(ptr+subjects*i);

    int sum=0;//total sum of marks of a student
    float average;//average of marks

    //iterating for each student
    for(int i=0;i<num;i++)
    {
        //user input the marks of each subject from a user
        printf("enter the marks of student %d: ",i+1);
        for(int j=0;j<subjects;j++)
        scanf("%d",&arr[i][j]);

        //summing up the total marks of the student
        for(int j=0;j<subjects;j++)//iterating for each subject
        sum+=arr[i][j];
        printf("the total marks of stduent %d is %d \n",i+1,sum);//printing the total marks

        //average of the marks of the student
        average=(float)sum/(float)subjects;//average is equal to total sum divided by the total subjects
        printf("and the average is %0.2f \n",average);

        //making sum and average again 0 for the next student
        sum=0;
        average=0;
    }
  
 return 0;
}