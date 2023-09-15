#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ShoppingItem {
	char name[50]; // 商品名称
	int quantity; // 商品数量
	struct ShoppingItem* next; // 指向下一个节点的指针
};

struct ShoppingItem* shoppingList = NULL;
struct ShoppingItem* shoppingList2 = NULL;


//添加商品到购物清单：
void addItem(char itemName[], int itemQuantity) {
	struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	strcpy(newItem->name, itemName);
	newItem->quantity = itemQuantity;
	newItem->next = NULL;
	if (shoppingList == NULL) {
		shoppingList = newItem;
	} else {
		struct ShoppingItem* current = shoppingList;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newItem;  //此处填写若干语句；
	}
}

void addItem2(char itemName2[], int itemQuantity2) {
	struct ShoppingItem* newItem2 = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	strcpy(newItem2->name, itemName2);
	newItem2->quantity = itemQuantity2;
	newItem2->next = NULL;
	if (shoppingList2 == NULL) {
		shoppingList2 = newItem2;
	} else {
		struct ShoppingItem* current = shoppingList2;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newItem2;
	}
}//第二个链表；


//从购物清单中移除商品：
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
		previous = current;
		current = current->next;
		//此处填写两行；
	}
}

//查看购物清单
void displayList() {
	struct ShoppingItem* current = shoppingList;
	printf("购物清单:\n");
	while (current != NULL) {
		printf("%s - 数量：%d\n", current->name, current->quantity);
		current=current->next;//此处填写一句；
	}
	printf("\n");
}

//修改购物清单
void updateQuantity(char itemName[], int newItemQuantity) {
	struct ShoppingItem* current = shoppingList;
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			current->quantity = newItemQuantity; //此处填写一句。
			break;
		}
		current = current->next;
	}
}

//清空购物清单：
void clearList() {
	while (shoppingList != NULL) {
		struct ShoppingItem* temp = shoppingList;
		shoppingList = shoppingList->next;
		//此处填写两句。
		free(temp);
	}
}

//计算购物清单中商品的总数量：
int totalQuantity() {
	struct ShoppingItem* current = shoppingList;
	int total = 0;
	while (current != NULL) {
		total += current->quantity;
		current = current->next;
		//此处填写两句；
	}
	return total;                                
}

//查找购物清单中的商品：
void findItem(char itemName[]) {
	struct ShoppingItem* current = shoppingList;
	printf("查找商品 %s ：\n", itemName);
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			printf("%s - 数量：%d\n", current->name, current->quantity);
			return;
		}
		current = current->next; //此处填写一句
	}
	printf("未找到商品 %s。\n", itemName);
}


//排序购物清单：
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
				strcpy(tempName, current->name);
				strcpy(current->name, nextItem->name);
				strcpy(nextItem->name, tempName);
				
				tempQuantity = current->quantity;
				current->quantity = nextItem->quantity;
				nextItem->quantity = tempQuantity;
			}
			nextItem = nextItem->next;
		}
		current = current->next;
	}
}

//合并购物清单：
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
	struct ShoppingItem* current = *list1;
	while (current->next != NULL) {
		current = current->next;        
	}
	// 遍历到第一个购物清单的末尾
	//补充循环语句；
	// 将第二个购物清单连接到第一个清单的末尾
	current->next = *list2;
	*list2 = NULL;
}

//删除购物清单中的商品：
void deleteItem(char itemName[], int deleteAll) {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* prev = NULL;
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			if (prev == NULL) {
				struct ShoppingItem* temp = shoppingList;
				shoppingList = shoppingList->next;//如果要删除的是第一个节点
				free(temp);
				if (!deleteAll) break;
			} else {
				prev->next = current->next;//// 如果要删除的不是第一个节点v
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

int main() {
	// 示例测试
	addItem("苹果", 5);
	addItem("香蕉", 3);
	addItem("橙子", 2);
	addItem("橙子", 6);
	
	printf("添加商品后的购物清单：\n");
	displayList();
	
	
	
	updateQuantity("苹果", 10);
	removeItem("橙子");
	
	printf("修改和移除商品后的购物清单：\n");
	displayList();
	
	printf("\n购物清单中商品的总数量：%d\n", totalQuantity());
	
	printf("\n");
	findItem("香蕉");
	findItem("梨子");
	printf("\n");
	
	sortList();
	
	printf("排序后的购物清单：\n");
	displayList();
	
	// 删除购物清单中的商品
	deleteItem("香蕉", 0);  // 只删除一个香蕉
	deleteItem("橙子", 1);  // 删除所有橙子
	
	printf("删除商品的购物清单：\n");
	displayList();
	
	addItem2("老虎",5 );
	addItem2("老虎",5 );
	addItem2("老虎",5 );
	mergeLists(&shoppingList,&shoppingList2);
	printf("合并商品链表");
	displayList();
	
	
	clearList();
	
	printf("清空购物清单后的购物清单：\n");
	displayList();
	
	return 0;
}
