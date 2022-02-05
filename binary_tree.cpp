#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node*right;

    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

node*buildtree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node*root=new node(d);
    root->left=buildtree();
    root->right=buildtree();
    return root;

}

void print(node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

int height(node*root)
{
    if(root==NULL)
    return 0;
    return max(height(root->left),height(root->right))+1;
}

void printkthlevel(node*root,int k)
{
    if(root==NULL)
    return;
    if(k==1)
    {
        cout<<root->data<<" ";
        return ;
    }
    printkthlevel(root->left,k-1);
    printkthlevel(root->right,k-1);
    return;
}

void printleveloreder(node*root)
{
    int h=height(root);
    for(int i=1;i<=h;i++)
    {
    printkthlevel(root,i);
    cout<<endl;
    }
}

void BFS(node*root)
{
    if(root==NULL)
    return;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node*temp=q.front();
        if(temp==NULL)
        {
            q.pop();
            cout<<endl;
            if(!q.empty())
            q.push(NULL);
            
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
            q.push(temp->left);
            if(temp->right!=NULL)
            q.push(temp->right);
            q.pop();
        }        
    }
}




int count(node*root)
{
    if(root==NULL)
    return 0;
    return (1+count(root->left)+count(root->right));

}

int sum(node*root)
{
    if(root==NULL)
    return 0;
    return root->data+sum(root->left)+sum(root->right);
}

int diameter(node*root)
{
    if(root==NULL)
    return 0;
    int h1=height(root->left);
    int h2=height(root->right);
    int op1=h1+h2;
    int op2=diameter(root->left);
    int op3=diameter(root->right);
    return max(op1,max(op2,op3));
}

pair<int,int> fastdiameter(node*root)
{
    pair<int,int>p;
    if(root==NULL)
    {
        p.first=0;
        p.second=0;
        return p;
    }

    pair<int,int>left=fastdiameter(root->left);
    pair<int,int>right=fastdiameter(root->right);
    p.first=max(left.first,right.first)+1;
    p.second=max(left.first+right.first,max(left.second,right.second));
    return p;

}



int sumreplacement(node*root)
{
    if(root==NULL)
    return 0;
    int sum=0;
    if(root->left==NULL&&root->right==NULL)
       return root->data;
    int left=sumreplacement(root->left);
    int right=sumreplacement(root->right);
    int temp=root->data;
    root->data=left+right;
    return temp+root->data;

}

pair<int,bool>heightbalanced(node*root)
{
    pair<int,bool>p; 
    if(root==NULL)
    {
        p.first=0;
        p.second=true;
        return p;
    }
    pair<int,bool>left=heightbalanced(root->left);
    pair<int,bool>right=heightbalanced(root->right);
    p.first=max(left.first,right.first)+1;
    if(left.second==true&&right.second==true&&abs(left.first-left.second)<=1)
     p.second=true;
    else
     p.second=false;
    return p;
    
}

node* makebalancedfromarray(int *arr,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    int mid=(s+e)/2;
    node*root=new node(arr[mid]);
    root->left=makebalancedfromarray(arr,s,mid-1);
    root->right=makebalancedfromarray(arr,mid+1,e);  
    return root;
}


node*treefrompreandinorder(int *in,int*pre,int s,int e)
{
    static int i=0;
    if(s>e)
    return NULL;
    node*root=new node(pre[i]);
    int idx=-1;
    for(int j=s;j<=e;j++)
    {
        if(in[j]==pre[i])
        {
            idx=j;
            break;
        }
    }
    i++;
    root->left=treefrompreandinorder(in,pre,s,idx-1);
    root->right=treefrompreandinorder(in,pre,idx+1,e);
    return root;

}


void rightview(node*root,int level,int&maxlevel)
{
    if(root==NULL)
    return;
    if(maxlevel<level)
    {
    cout<<root->data<<" ";
    maxlevel=level;
    }
    rightview(root->right,level+1,maxlevel);
    rightview(root->left,level+1,maxlevel);
}


node*lowestcommonancestor(node*root,int a,int b)
{
    if(root==NULL)
    return NULL;
    if(root->data==a or root->data==b)
    return root;
    node*le=lowestcommonancestor(root->left,a,b);
    node*ri=lowestcommonancestor(root->right,a,b);
    if(le!=NULL and ri!=NULL)
    {
    return root;
    }
    if(le!=NULL)
    {
    return le;
    }
    return ri;

}


//finding distance from the common ancestor 
int search(node*root,int key,int level)
{
    if(root==NULL)
    return -1;
    if(root->data==key)
    {
        return level;
    }
    int left=search(root->left,key,level+1);
    if(left!=-1)
    return left;
    return search(root->right,key,level+1);

}


bool checkbst(node*root,int min,int max)
{
    if(root==NULL)
    return true;
    bool left=checkbst(root->left,min,root->data);
    bool right=checkbst(root->right,root->data,max);
    if(root->data<=max and root->data>=min and left and right )
    return true;
    return false;

}


int finddistance(node*root,int a,int b)
{
    if(root==NULL)
    return 0;
    node*ab=lowestcommonancestor(root,a,b);
    int left=search(ab,a,0);
    int right=search(ab,b,0);
    return left+right;
}


int main()
{
   node*root=buildtree();
   print(root);
   cout<<endl;
   cout<<endl;
   

   cout<<height(root)<<endl;
   printkthlevel(root,3);
   cout<<endl;
   cout<<endl;


   if(checkbst(root,INT_MIN,INT_MAX))
       cout<<"yes it is bst"<<endl;
    else
       cout<<"no it is not bst"<<endl;

   printleveloreder(root);
   cout<<endl;
   cout<<endl;


   BFS(root);
   cout<<endl;
   cout<<endl;
   

   
   node*a=lowestcommonancestor(root,8,10);
   cout<<"lca of 8 and 10 is "<<a->data<<endl<<endl;
   node*b=lowestcommonancestor(root,1,6);
   cout<<"lca of 1 and 6 is "<<b->data<<endl<<endl;

   cout<<"total nodes in the tree is "<<count(root)<<endl<<endl;


   cout<<"total sum of nodes is "<<sum(root)<<endl;


   cout<<"diameter of the tree is "<<diameter(root)<<endl<<endl;


   cout<<"min distance between 8 and 10 is "<<finddistance(root,8,10)<<endl;
   cout<<"min distance between 9 and 13 is "<<finddistance(root,9,13)<<endl;



   pair<int,int>dia=fastdiameter(root);
   cout<<"fast diameter is "<<dia.second<<endl<<endl;


   sumreplacement(root);
   printleveloreder(root);
   cout<<endl<<endl;
   cout<<endl<<endl;


    pair<int,bool>p=heightbalanced(root);
    if(p.second==true)
    {
        cout<<"tree is balanced "<<endl<<endl;
    }
    else
    {
        cout<<"tree is not balanced "<<endl<<endl;
    }

   int arr[]={1,2,3,4,5,6,7};
   int n=sizeof(arr)/sizeof(int);
   root=makebalancedfromarray(arr,0,n-1);


    p=heightbalanced(root);
    if(p.second==true)
    {
        cout<<"tree is balanced "<<endl<<endl;
    }
    else
    {
        cout<<"tree is not balanced "<<endl<<endl;
    }

   BFS(root);
   cout<<endl<<endl;
   printleveloreder(root);
   cout<<endl<<endl;

   int in[]={3,2,8,4,1,6,7,5};
   int pre[]={1,2,3,4,8,5,6,7};
   n=sizeof(in)/sizeof(int);
   root=treefrompreandinorder(in,pre,0,n-1);
   BFS(root);
   cout<<endl<<endl;

   int maxlevel=-1;
   rightview(root,0,maxlevel);
   cout<<endl;

   BFS(root);
   cout<<endl<<endl;
}
