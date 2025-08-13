#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
struct Node{
	int x;
	Node* next;
};
typedef Node* node;

struct List{
	node pHead;
};
void init(List &L){
	L.pHead=NULL;
}

node getnode(int x){
	node moi=(node)malloc(sizeof(Node));
	if(moi==NULL){
		printf("Khong du bo nho!\n");
		return NULL;
	}
	else{
		moi->x=x;
		moi->next=NULL;
		return moi;
	}
}

node searchX(List L, int x){
	if(L.pHead==NULL){
		return NULL;
	}
	for(node i=L.pHead; i!=NULL; i=i->next){
		if(i->x==x){
			return i;
		}
	}
	return NULL;
}

void display(List L){
	for(node i=L.pHead; i!=NULL; i=i->next){
		printf("%d ", i->x);
	}
	printf("\n");
}

void addlast(List &L, int x){
	node moi=getnode(x);
	if(L.pHead==NULL){
		L.pHead=moi;
	}
	else{
		node tmp=L.pHead;
		while(tmp->next!=NULL){
			tmp=tmp->next;
		}
		tmp->next=moi;
	}
}

void create_list(List &L){
	init(L);
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int x;
		scanf("%d", &x);
		addlast(L,x);
	}
}

int main(){
	List L;
	create_list(L);
	display(L);
}
