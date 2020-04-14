#include <iostream>
using namespace std;
typedef struct list {
	int data;
	struct list *next;
}list;
list *newnode(int item) {
	list *ptr = new list;
	ptr->data = item;
	ptr->next = nullptr;
	return ptr;
}
list *insert(list *head, int item) {
	if (head == nullptr) {
		head = newnode(item);
		return head;
	}
	list *temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newnode(item);
  return head;
}
int getCount(list *head) {
	return head == nullptr ? 0 : 1 + getCount(head->next);
}
void traverse(list *head) {
	if (head == nullptr)
		return;
	list *temp = head;
	while (temp != nullptr) {
		cout << temp->data << ' ';
		temp = temp->next;
	}
}
int main() {   
	list *head = nullptr;
	int n, x;
  head = nullptr;
  cin >> n;
  for (int i = 0; i < n; i++) {       //reading n nums and inserting to linked list
    cin >> x;
    head = insert(head, x);
  }
  cout << getCount(head) << '\n';  
  traverse(head);
return 0;
}
