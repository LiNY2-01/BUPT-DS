#include<bits/stdc++.h>
using namespace std;

template<class T>
struct Node
{
    T data;
    struct Node<T>* next;
};

template <class T>
class LinkList
{
public:
    LinkList(){front = new Node<T>; front->next = NULL;}
    LinkList(T a[], int n); 
    ~LinkList();

    void PrintList();    

    int GetLength();     

    Node<T>* Get(int i);    

    int Locate(T x);    

    void Insert(int i, T x);

    Node<T>* Delete(Node< T > *p);

    void deleteDuplicates();

private:
    Node<T> *front;  

};

const int Maxn=1e6+50;
int a[Maxn];
int n;

template <class T>
LinkList<T>::LinkList(T a[],int n)
{
    front=new Node<T>;
    front->next= NULL;
    front->data=-1;
    Node<T> *p=front,*x;
    for(int i=1;i<=n;i++)
    {
        x=new Node<T>;
        x->data=a[i];
        x->next=NULL;
        p->next=x;
        p=x;
    }
}
template <class T>
int LinkList<T>::GetLength()
{
    Node<T> *p=front->next;
    int cnt=0;
    while(p!=NULL){p=p->next;++cnt;}
    return cnt;
}
template <class T>
void LinkList<T>::PrintList()
{
    int len=GetLength();
    if(!len){cout<<"empty";return;}
    Node<T> *p=front->next;
    while(p!=NULL){cout<<p->data<<" ";p=p->next;}
}
template <class T>
LinkList<T>::~LinkList()
{
    while(front!=NULL)
    {
        Node<T>*p=front;
        front=front->next;
        delete p;
    }
}

template <class T>
void LinkList<T>::deleteDuplicates( )
{
    Node<T>*p=front->next;
    while(p!=NULL)
    {
        if(p->next!=NULL)
        {
            if(p->data!=p->next->data)p=p->next;
            else
            {
                int num=p->data;
                while(p->data==num&&p!=front)
                p=Delete(p);

            }   
        
        }
        else {break;}
        
    }
}
template <class T>
Node<T>*  LinkList<T>::Delete(Node<T> *p)
{
    //if(p==NULL)return ;
    if(p->next==NULL)
    {
        Node<T> *temp=front;
        //cout<<temp->data<<endl;
        while(temp->next!=p)
        temp=temp->next;
        delete p;
        temp->next=NULL;
        return temp;

    }
    else
    {
        p->data=p->next->data;
        Node<T> *temp=p->next;
        p->next=p->next->next;
        delete temp;
        return p;
    }
    
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];

    LinkList <int>L(a,n);
    //cout<<L.GetLength();
    L.deleteDuplicates();
    L.PrintList();

    return 0;
}