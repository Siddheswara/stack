/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
struct stack{
    int size;
    int top;
    int *s;
};
void create(stack *st,int siz){
    st->size=siz;
    st->top=-1;
    st->s=new int[st->size];
    
    
}
void push(stack *st,int x){
    if(st->top==st->size-1){cout<<"stack overflow";}
    else{st->top++;
        st->s[st->top]=x;
    }
}
int pop(stack *st){
   int x=-1;
   if(st->top==-1)cout<<"stack underflow";
    else{
        x=st->s[st->top];
        st->top--;
    }
    return x;
}
void display(stack st){
    for(int i=st.top;i>=0;i--){
        cout<<st.s[i]<<" ";
    }
    cout<<"\n\n";
}
int peek(stack st,int idx){
    int x;
    if(st.top-idx+1<0)cout<<"stack underflow";
    else{
        x=st.s[st.top-idx+1];
    } return x;
}
int isempty(stack st){
    if(st.top==1)return 1;
    return 0;
}
int isfull(stack st){
    if(st.top==st.size-1)return 1;
    return 0;
}
int main()
{
    struct stack S;
    create(&S,5);
    push(&S,10);
    push(&S,20);
    push(&S,30);
    push(&S,40);
   push(&S,50);
   cout<<"The stack elements are: ";
   display(S);
   cout<<pop(&S);
   push(&S,69);
   
   cout<<endl;
   display(S);
   cout<<peek(S,2);
   

    return 0;
}

