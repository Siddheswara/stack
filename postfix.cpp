
#include <iostream>
#include<string.h>

using namespace std;
struct node{
    char data;
    node *next;
}*top;
void push(char x){
    node *t=new node;
    if(t==NULL)cout<<"stack overflow";
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
char pop(){
 char x='0';
    if(top==NULL){cout<<"stack underflow";return x;}
    else{
        node *p=top;
        top=top->next;
        x=p->data;
        delete p;
        
    }
    return x;
}
/*int peek(int pos){node *p=top;
    for(int i=0;p!=NULL&&i<pos-1;i++){
        p=p->next;
    }
    if(p)return p->data;
    return -1;
}
void display(){
    node *p=top;
    while(p){cout<<p->data<<" ";
    p=p->next;}cout<<endl;
}*/
/*int isbal(char *ex){
    for(int i=0;ex[i]!='\0';i++){
        if(ex[i]=='(')push(ex[i]);
        else if(ex[i]==')'){
            if(top==NULL)return 0;
            else {
                pop();
            }
        }
        
    }
    if(top==NULL)return 1;
    else return 0;
}*/
int isempty(){
    if(top==NULL)return 1;
    return 0;
}
char stacktop(){
    if(top)return top->data;
    return '0';
}
int isoperand(char e){if(e=='+'||e=='-'||e=='*'||e=='/')return 0;
    return 1;
}
int pre(char e){
    if(e=='+'||e=='-')return 1;
    else if(e=='*'||e=='/')return 2;
    return 0;
}
char * infix_to_postfix(char *infix){
    char *post=new char[strlen(infix)+1];
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(isoperand(infix[i])){
            post[j++]=infix[i++];
        }
        else{
            if(pre(infix[i])>pre(stacktop()))push(infix[i++]);
            else
            {
                post[j++]=pop();
            }
        }  
        
    }
    while(!isempty()){post[j++]=pop();}
    post[j]='\0';
    return post;
}
int main()
{ char *ex="a+b*c-d/e";
push('.');
 char *postfix=infix_to_postfix(ex);
 cout<<postfix;


    return 0;
}

