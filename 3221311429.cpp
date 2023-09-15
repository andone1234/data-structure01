#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ShoppingItem {
	char name[50]; // ��Ʒ����
	int quantity; // ��Ʒ����
	struct ShoppingItem* next; // ָ����һ���ڵ��ָ��
};

struct ShoppingItem* shoppingList = NULL;
struct ShoppingItem* shoppingList2 = NULL;


//�����Ʒ�������嵥��
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
		current->next = newItem;  //�˴���д������䣻
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
}//�ڶ�������


//�ӹ����嵥���Ƴ���Ʒ��
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
		//�˴���д���У�
	}
}

//�鿴�����嵥
void displayList() {
	struct ShoppingItem* current = shoppingList;
	printf("�����嵥:\n");
	while (current != NULL) {
		printf("%s - ������%d\n", current->name, current->quantity);
		current=current->next;//�˴���дһ�䣻
	}
	printf("\n");
}

//�޸Ĺ����嵥
void updateQuantity(char itemName[], int newItemQuantity) {
	struct ShoppingItem* current = shoppingList;
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			current->quantity = newItemQuantity; //�˴���дһ�䡣
			break;
		}
		current = current->next;
	}
}

//��չ����嵥��
void clearList() {
	while (shoppingList != NULL) {
		struct ShoppingItem* temp = shoppingList;
		shoppingList = shoppingList->next;
		//�˴���д���䡣
		free(temp);
	}
}

//���㹺���嵥����Ʒ����������
int totalQuantity() {
	struct ShoppingItem* current = shoppingList;
	int total = 0;
	while (current != NULL) {
		total += current->quantity;
		current = current->next;
		//�˴���д���䣻
	}
	return total;                                
}

//���ҹ����嵥�е���Ʒ��
void findItem(char itemName[]) {
	struct ShoppingItem* current = shoppingList;
	printf("������Ʒ %s ��\n", itemName);
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			printf("%s - ������%d\n", current->name, current->quantity);
			return;
		}
		current = current->next; //�˴���дһ��
	}
	printf("δ�ҵ���Ʒ %s��\n", itemName);
}


//�������嵥��
void sortList() {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* nextItem = NULL;
	char tempName[50];
	int tempQuantity;
	while (current != NULL) {
		nextItem = current->next;
		while (nextItem != NULL) {
			if (strcmp(current->name, nextItem->name) > 0) {
				// ������Ʒ��Ϣ
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

//�ϲ������嵥��
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
	struct ShoppingItem* current = *list1;
	while (current->next != NULL) {
		current = current->next;        
	}
	// ��������һ�������嵥��ĩβ
	//����ѭ����䣻
	// ���ڶ��������嵥���ӵ���һ���嵥��ĩβ
	current->next = *list2;
	*list2 = NULL;
}

//ɾ�������嵥�е���Ʒ��
void deleteItem(char itemName[], int deleteAll) {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* prev = NULL;
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			if (prev == NULL) {
				struct ShoppingItem* temp = shoppingList;
				shoppingList = shoppingList->next;//���Ҫɾ�����ǵ�һ���ڵ�
				free(temp);
				if (!deleteAll) break;
			} else {
				prev->next = current->next;//// ���Ҫɾ���Ĳ��ǵ�һ���ڵ�v
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
	// ʾ������
	addItem("ƻ��", 5);
	addItem("�㽶", 3);
	addItem("����", 2);
	addItem("����", 6);
	
	printf("�����Ʒ��Ĺ����嵥��\n");
	displayList();
	
	
	
	updateQuantity("ƻ��", 10);
	removeItem("����");
	
	printf("�޸ĺ��Ƴ���Ʒ��Ĺ����嵥��\n");
	displayList();
	
	printf("\n�����嵥����Ʒ����������%d\n", totalQuantity());
	
	printf("\n");
	findItem("�㽶");
	findItem("����");
	printf("\n");
	
	sortList();
	
	printf("�����Ĺ����嵥��\n");
	displayList();
	
	// ɾ�������嵥�е���Ʒ
	deleteItem("�㽶", 0);  // ֻɾ��һ���㽶
	deleteItem("����", 1);  // ɾ�����г���
	
	printf("ɾ����Ʒ�Ĺ����嵥��\n");
	displayList();
	
	addItem2("�ϻ�",5 );
	addItem2("�ϻ�",5 );
	addItem2("�ϻ�",5 );
	mergeLists(&shoppingList,&shoppingList2);
	printf("�ϲ���Ʒ����");
	displayList();
	
	
	clearList();
	
	printf("��չ����嵥��Ĺ����嵥��\n");
	displayList();
	
	return 0;
}
