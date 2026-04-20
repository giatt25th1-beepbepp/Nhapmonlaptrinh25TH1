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
struct Linkdelist {
	Node<T>* head;
	void Show();
	void Add(T item);
	bool Remove(int id);
	bool Update(int id);
	void Find(int id);
};
template <typename T>
void LinkedList<T>::Show() {
	if (head == NULL) {
		cout << "NO item available" << endl;
		return;
	}
	Node<T>* item = head;
	while (item != NULL) {
		cout << item->data << endl;
		item = item->next;
	}
};
template <typename T>
void LinkedList<T>::Add(T item) {
	Node <T>* newNode = new Node<T>;
	newNode->data = item;
	newNode->next = nullptr;
	if (head == nullptr) {
		head = newNode;
	}
	else {
		Node<T>* item = head;
		while (item->next != nullptr) {
			item = item->next;
		}
		item->next = newNode;
	}
};
bool LinkedList<T>::Remove(int id) {
	if (!head) {
		cout << "No account available " << endl;
		return false;
	}
	Node<T>* item = head;
	if (item->data.id == id) {
		head = item->next;
		delete item;
		return;
	}
}
template <typename T>
bool LinkedList<T> ::Update(int id) {
	if (!head) {
		cout << "No account svsilable" << endl;
		return false;
	}
	Node<T>* item = head;
	while (item != NULL) {
		if (item->data.id == id) {
			cin >> item->data;
			return true;
		}
		item = item->next;
	}
	return false;
}
template <typename T>
void LinkedList<T>::Find(string username) {
	if (!head) {
		cout << "No accountr available" << endl;
		return;
	}
	Node<T>* item = head;
	while (item != NULL) {
		if (item->data.username == username) {
			cout << item->data << endl;
			return;
		}
		item = item->next;
	}
	cout << "No account found" << endl;
}
template <typename T >
void LinkedList<T>::Export(string filename) {
	ofstream outFile(filename.ios::binary);
	if (!outFile) {
		cout << "Error opening file for writting" << endl;
		return;
	}
	Node <T>* item = head;
	while (item != NULL) {
		outFile.write(reinterpret_cast<char*>(&item->data). sizeof(T));
		item = item->next;
	}
	outFile.clone();
}
template <typename T>
