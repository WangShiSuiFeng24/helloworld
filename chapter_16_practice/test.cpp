#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
int main(){
	struct node *head,*p,*q,*t;
	int i,n,a;
	printf("链表长度：");
	scanf("%d",&n);
	head=NULL;
	for(i=0;i<n;i++){
		printf("输入链表数据：");
		scanf("%d",&a);
		p=(struct node*)malloc (sizeof(struct node));
		p->data=a;
		p->next=NULL;
		if(head == NULL) 
            head=p;
		else 
            q->next=p;
		q=p;
	}
	printf("输出数据：");
	t=head;
	while(t!=NULL){
		printf("%d",t->data);
		t=t->next;
	}
   getchar();getchar();
	return 0;
}
