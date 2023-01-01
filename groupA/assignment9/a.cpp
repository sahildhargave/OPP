/*

Title  :-  a) Write C++ program using STL to add binary numbers (assume one bit as one number); use STL stack.

Author :-  Sahil Dhargave.

*/

#include<iostream>
#include<stack>
using namespace std;
 
stack<int> read()
  {
    stack<int> s;
    int x,n,i;
 
    cout<<"\nEnter the no. of bits in the Number. :";
    cin>>n;
    cout<<"\nEnter the binary number : ";
 
    for(i=0;i<n;i++)
    {
	    cin>>x;
	    s.push(x);
    }
    return s;
  }
        
 
void display(stack<int> &s)
{
    cout<<"  ";
    while(!s.empty())
    {
	    cout<<s.top()<<" ";
	    s.pop();
    }
}
    
stack<int> add(stack<int> &s1,stack<int> &s2)
  {
    stack<int> s;
    int sum,carry=0,b1,b2;
 
    while(!s1.empty()||!s2.empty())
    {
	    b1=b2=0;
	    if(!s1.empty())
	    {
	        b1=s1.top();
	        s1.pop();
	    }
	    if(!s2.empty())
	    {
	        b2=s2.top();
	        s2.pop();     
	    }
	    sum=(b1+b2+carry)%2;
	    carry=(b1+b2+carry)/2;
	    s.push(sum);
    }
    if(carry==1){
    	s.push(1);
	}
      
    return s;
}
 

int main()
  {
    stack<int> s1,s2,s3;
    int ch;
    do{
      	cout<<"\n  | MAIN MENU |   \n";
	    cout<<"\n1.Read First Binary Number"
	    <<"\n2.Read Second Binary Number"
	    <<"\n3.Addtion of Binary Numbers"
	    <<"\n4.Exit";
	    cout<<"\n--------------------------------";
	    cout<<"\nEnter your choice..: ";
	    cin>>ch;
 
	    switch(ch){
	        case 1:
	           s1=read();
	           break;
	 
	        case 2:
	           s2=read();
	           break;
	 
	        case 3:
	           cout<<"\nThe Addtion of Two Binary Number is :";
	           s3=add(s1,s2);
	           display(s3);
	           break;
	      }
      }while(ch!=4);
    return 0;
  }
