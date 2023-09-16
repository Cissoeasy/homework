#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ShoppingItem {
 char name[50]; // 商品名称
 int quantity; // 商品数量
 struct ShoppingItem* next; // 指向下一个节点的指针
};

struct ShoppingItem* shoppingList = NULL; // 初始化购物清单为空
struct ShoppingItem* z=NULL;
struct ShoppingItem* creatList();
void addItem(char itemName[], int itemQuantity);
void removeItem(char itemName[]);
void displayList();
void updateQuantity(char itemName[], int newItemQuantity);
void clearList();
int totalQuantity();
void findItem(char itemName[]);
void sortList();
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2);
void deleteItem(char itemName[], int deleteAll);
int main(){
	int x,i=0;
	
	while(1){
	//shoppingList=NULL;
	printf("请输入数字1到10\n输入其他数将会退出程序\n");
	printf("输入1添加商品到购物清单\n输入2从购物清单中移除商品\n输入3查看购物清单\n输入4修改购物清单中商品的数量\n输入5清空购物清单\n输入6计算购物清单中商品的总数量\n输入7查找购物清单中的商品\n输入8排序购物清单\n输入9合并购物清单\n输入10删除购物清单中的商品\n");
	//printf("请先创建一个（即输入一个0）再输入其他数字\n");
	scanf("%d",&x);
	if(x<1||x>10) break;
	switch(x){
		case 1:
			{
			char n[50];
			int q;
			scanf("%s %d",n,&q);
			addItem(n,q);
			break;}
		case 2:{
			char n[50];
			scanf("%s",n);
			removeItem(n);
			break;}
		case 3:{
			displayList();
			break;}
		case 4:
			{
			
			char n[50];
			int q;
			scanf("%s %d",n,&q);
			updateQuantity(n,q);
			break;}
		case 5:{
			clearList();
			break;}
		case 6:{
			
			printf("%d\n",totalQuantity());
			break;}
		case 7:
			{
			char n[50];
			scanf("%s",n);
			findItem(n);
			break;}
		case 8:
			{
			sortList();
			break;}
		case 9:
			{
			printf("请输入第一个购物清单，按0退出\n");
			struct ShoppingItem*list1;
			list1=creatList();
		//	printf("%s\n",list1->name);
			printf("请输入第二个购物清单，按0退出\n");
			struct ShoppingItem*list2;
			list2=creatList();
			//printf("%s\n",list2->name);
			//printf("54\n");//找出错误地方 
			if(list1!=NULL) mergeLists(&list1,&list2);
			
			//printf("5\n");
			shoppingList=list1;
			
			break;}
		case 10:
			{
			printf("如果不要删除全部请输入在输入商品名称之后输入0\n");
			char n[50];
			int d;
			scanf("%s %d",n,&d);
			deleteItem(n,d);
			break;}
		default:break;
					
	}printf("程序已执行!\n");}
return 0;}
struct ShoppingItem* creatList(){
	struct ShoppingItem *s,*q,*h;
	
	q=(struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	h=(struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	h=NULL;
	do{
	s=(struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	scanf("%s %d",s->name,&s->quantity);
	s->next=NULL;
	if(h==NULL&&s->quantity!=0){
		//printf("1\n");
	h=s;}
	else{
		//printf("2\n");
	q->next=s;}
	q=s;
	//printf("54\n");
	//printf("%s\n",h->name);
	}while(s->quantity!=0);
	
return h;}

void addItem(char itemName[], int itemQuantity) {
 struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
 strcpy(newItem->name,itemName);
 newItem->quantity=itemQuantity;
 newItem->next=NULL;
 if(shoppingList==NULL) shoppingList=newItem;
 else z->next=newItem;
 z=newItem;

}

void removeItem(char itemName[]) {
 struct ShoppingItem* current = shoppingList;
 struct ShoppingItem* previous = NULL;
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 if (previous != NULL) {
 previous->next = current->next;
 } else {
 shoppingList = current->next;
 }
 free(current);
 break;
 }
previous=current;
current=current->next;
 }
}
void displayList() {
 struct ShoppingItem* current = shoppingList;
 printf("购物清单:\n");
 while (current != NULL) {
 printf("%s - 数量：%d\n", current->name, current->quantity);
 current=current->next;
 }
}

void updateQuantity(char itemName[], int newItemQuantity) {
 struct ShoppingItem* current = shoppingList;
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 current->quantity=newItemQuantity;
 break;
 }
 current = current->next;
 }
}

void clearList() {
	struct ShoppingItem *temp;
	temp= (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
 while (shoppingList != NULL) {
 temp=shoppingList;
 shoppingList=shoppingList->next;
 free(temp);
 }
}

int totalQuantity() {
 struct ShoppingItem* current = shoppingList;
 int total = 0;
 while (current != NULL) {
 total+=current->quantity;
 current=current->next;
 }
 return total;
}

void findItem(char itemName[]) {
 struct ShoppingItem* current = shoppingList;
 printf("查找商品 \"%s\" ：\n", itemName);
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 printf("%s - 数量：%d\n", current->name, current->quantity);
 return;
 }
 current=current->next;
 }
 printf("未找到商品 \"%s\"。\n", itemName);
}

void sortList() {
 struct ShoppingItem* current = shoppingList;
 struct ShoppingItem* nextItem = NULL;
 char tempName[50];
 int tempQuantity;
 while (current != NULL) {
 nextItem = current->next;
 while (nextItem != NULL) {
 if (strcmp(current->name, nextItem->name) > 0) {
 // 交换商品信息
 strcpy(tempName,current->name);
 strcpy(current->name,nextItem->name);
 strcpy(nextItem->name,tempName);
 tempQuantity = current->quantity;
 current->quantity = nextItem->quantity;
 nextItem->quantity = tempQuantity;
 }
 nextItem = nextItem->next;
 }
 current = current->next;
 }
}


void mergeLists(struct ShoppingItem** list1,struct ShoppingItem** list2){
	struct ShoppingItem* current =*list1;
	//printf("%s\n",current->name);
	while(current->next!=NULL)current=current->next;
	//printf("6\n");
	current->next=*list2;
	*list2=NULL;
	}



void deleteItem(char itemName[], int deleteAll) {
 struct ShoppingItem* current = shoppingList;
 struct ShoppingItem* prev = NULL;
 while (current != NULL) {
 if (strcmp(current->name, itemName) == 0) {
 if (prev == NULL) {
 // 如果要删除的是第一个节点
 struct ShoppingItem* temp = shoppingList;
shoppingList=shoppingList->next;
 free(temp);
 if (!deleteAll) break;
 } else {
 // 如果要删除的不是第一个节点
 prev->next=current->next;
 free(current);
 current = prev->next;
 if (!deleteAll) break;
 }
 } else {
 prev = current;
 current = current->next;
 }
 }
}

