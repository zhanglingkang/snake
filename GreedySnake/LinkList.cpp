#include"LinkList.h"
#include<iostream>
template <class T>
LinkList<T>:: LinkList( )
{
 first=new Node<T>; first->next=NULL;
}

template <class T>  
LinkList<T>:: LinkList(T a[ ], int n)
 {
    first=new Node<T>;   //生成头结点
	Node<T> *r,*s;
     r=first;          //尾指针初始化
    for (int i=0; i<n; i++)
	{ 
      s=new Node<T>; s->data=a[i];  //为每个数组元素建立一个结点
      r->next=s; r=s;      //插入到终端结点之后
	}
    r->next=NULL;    //单链表建立完毕，将终端结点的指针域置空
 }
template <class T>
LinkList<T>:: ~LinkList()
{
}
template <class T>
T LinkList<T>::Get(int i) 
{   
  Node<T> *p; 
  int j;
  p=first->next; 
  j=1;  //或p=first;  j=0;
  while (p && j<i)    
  {
    p=p->next;       //工作指针p后移
    j++;
  }
  if (!p) throw "位置";
  else return p->data;
}
template <class T> 
int LinkList<T>::Locate(T x)
{
	Node<T> *p; int j;
	p=first->next; j=1;
	if(p&&p->next){
	  while(p->data!=x)
	  {
		 p=p->next;
	     j++;
	  }
	return j;
	}
	else throw "位置";
	
}
template <class T>  
void LinkList<T>::Insert(int i, T x)
{  
   Node<T> *p; int j;
   p=first ; j=0;    //工作指针p初始化
   while (p && j<i-1)
   {
     p=p->next;   //工作指针p后移
     j++;
   }
   if (!p) throw "位置";
    else { 
	  Node<T> *s;
      s=new Node<T>; 
	  s->data=x;  //向内存申请一个结点s，其数据域为x
      s->next=p->next;       //将结点s插入到结点p之后
      p->next=s;
	}
}
template <class T> 
int LinkList<T>::Length( )
{
  Node <T> *p = first->next;
  int i = 0;
  while(p)
  {
    p = p->next;
    i++;
  }
  return i;
}

template <class T>  
T LinkList<T>::Delete(int i)
{ 
  Node<T> *p; int j;
  p=first ; j=0;  //工作指针p初始化
  while (p && j<i-1)  //查找第i-1个结点
  {
    p=p->next;
    j++;
  }
  if (!p || !p->next) throw "位置";  //结点p不存在或结点p的后继结点不存在
    else {
		  Node<T> *q; 
		  T x;
          q=p->next;
		  x=q->data;  //暂存被删结点
          p->next=q->next;  //摘链
          delete q; 
          return x;
	}
}
template <class T> 
void LinkList<T>::PrintList( )
{
	Node<T> *p;
	p=first->next;
	while (p)
	{
	  cout<<p->data<<endl;
	  p=p->next;
	}
	
}
template <class T> 
void LinkList<T>::Reverse()
{
  Node <int> *p,*u;
  p=first->next;
  first->next=NULL;
  while(p)
  {
     u=p->next;
     p->next=first->next;
     first->next=p;
     p=u;
  }
}
