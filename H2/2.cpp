#include<iostream>
#include<cstdio>
#include<cstdlib>//用free（）要用这个库
using namespace std;
int m, n;
struct Node{
	int data;
	Node *next;
} *head, *p, *tail, *temp;
int main(){
	scanf("%d%d",&m,&n);
	head = new Node;
	head -> next = NULL;
	tail = head;
	for(int i = 1; i <= m; i++){
		p = new Node;
		p -> data = i;
		p -> next = NULL;
		tail -> next = p;
		tail = p;
	}
	p = head -> next;
	tail -> next = head -> next;// 链接尾和头 
	for(int i = 1; i <= m; i++){
		for(int j = 1; j < n - 1; j++){
			p = p -> next;
		}
		printf("%d ",p -> next -> data);
		temp = p -> next;
		p -> next = temp -> next;//连接要删除那个结点上下结点
		p = p -> next;//更新
		free(temp);//释放空间 
	}
	return 0;
}