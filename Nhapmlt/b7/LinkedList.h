#pragma once
template<typename T>
struct Node {
	T data;
	Node* next;
};
template <typename YT>
struct LinkedList {
	Node <T>* head;
	void Show();
};
template <typename T>
void LinkedList<T>::Show() {
	if (head == NULL) {
		cout << item->data << endl;
		item = item->next;
	}
}