#include <iostream>
#include <cstdlib>                   // creation of a binary by an arr[] and some basic operation
#include <time.h>
using namespace std;
typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}node;
node *newnode(int item) {         // creating new node to for insertion 
	node *ptr = new node;
	ptr->data = item;
	ptr->left = ptr->right = nullptr;
	return ptr;
}
node *insert(node *root, int item) {
	if (root == nullptr) {
		root = newnode(item);
		return root;
	}
	node *temp = root;
  while (temp != nullptr) {
  	if (item == temp->data) {
  		cout << "copy!!\n";
  		return root;
  	} else 
  	if (item < temp->data) {
  		if (temp->left == nullptr) {
  			temp->left = newnode(item);
  			return root;
  		}
  		temp = temp->left;
  	} else {
  		if (temp->right == nullptr) {
  			temp->right = newnode(item);
  			return root;
  		}
  		temp = temp->right;
  	}
  }
}
node *create_tree(int arr[], int n) {
	node *root = nullptr;
	for (int i = 0; i < n; i++)
		root = insert(root, arr[i]);
	return root;
}
void inorder(node *root) {
	if (root == nullptr)
		return;
	node *ptr = root;
	inorder(ptr->left);
	cout << ptr->data << ' ';
	inorder(ptr->right);
}
void preorder(node *root) {
	if (root == nullptr)
		return;
	node *ptr = root;
	cout << ptr->data << ' ';
	preorder(ptr->left);
	preorder(ptr->right);
}
void postorder(node *root) {
	if (root == nullptr)
		return;
	node *ptr = root;
	preorder(ptr->left);
	preorder(ptr->right);
	cout << ptr->data << ' ';
}
bool search(node *root, int item) {   // search() has complexity of O(log(n))
	if (root == nullptr)
		return false;
  node * temp = root;
	while (temp != nullptr) {
		if (temp->data == item)
			return true;
		else 
			if (temp->data > item) 
				temp = temp->left;
			else 
				temp = temp->right;
	}
	return false;
}
int main() {                           // main()
  srand(time(0));
  int n = 10;
  int arr[n];
  for (int i = 0; i < n; i++)
  	arr[i] = rand() % 50;
  node *root = create_tree(arr, n);
  inorder(root);
  cout << '\n';
  preorder(root);
  cout << '\n';
  postorder(root);
  cout << '\n';
  int random = rand() % 50;
  cout << "no to be searched " << random << '\n';
  cout << (search(root, random) ? "present\n" : "absent\n"); 
return 0;
}
