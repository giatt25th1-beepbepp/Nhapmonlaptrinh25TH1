#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Account.h"

using namespace std;

template<typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
struct LinkedList {
    Node<T>* head = nullptr;

    void Show();
    void Add(T item);
    bool Remove(int id);
    bool Update(int id);
    void Find(string username);
    void Export(string filename);
    void Import(string filename);
};

template <typename T>
void LinkedList<T>::Show() {
    if (head == nullptr) {
        cout << "No items available!" << endl;
        return;
    }
    Node<T>* temp = head;
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

template <typename T>
void LinkedList<T>::Add(T item) {
    Node<T>* newNode = new Node<T>{ item, nullptr };
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

template <typename T>
bool LinkedList<T>::Remove(int id) {
    if (!head) return false;

    Node<T>* temp = head;
    Node<T>* prev = nullptr;

    if (temp->data.id == id) {
        head = temp->next;
        delete temp;
        return true;
    }

    while (temp != nullptr && temp->data.id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return false;

    prev->next = temp->next;
    delete temp;
    return true;
}

template <typename T>
bool LinkedList<T>::Update(int id) {
    Node<T>* temp = head;
    while (temp != nullptr) {
        if (temp->data.id == id) {
            cout << "Enter new information for ID " << id << ":" << endl;
            cin >> temp->data;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <typename T>
void LinkedList<T>::Find(string username) {
    Node<T>* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->data.usr == username) {
            cout << temp->data << endl;
            found = true;
        }
        temp = temp->next;
    }
    if (!found) cout << "No account found with username: " << username << endl;
}

// Hàm Export: Lưu dạng text để an toàn với std::string
template <typename T>
void LinkedList<T>::Export(string filename) {
    ofstream outFile(filename);
    if (!outFile) return;
    Node<T>* temp = head;
    while (temp != nullptr) {
        outFile << temp->data.id << endl;
        outFile << temp->data.lnk << endl;
        outFile << temp->data.usr << endl;
        outFile << temp->data.pwd << endl;
        outFile << temp->data.desc << endl;
        temp = temp->next;
    }
    outFile.close();
}

// Hàm Import: Đọc dữ liệu từ file vào danh sách
template <typename T>
void LinkedList<T>::Import(string filename) {
    ifstream inFile(filename);
    if (!inFile) return;
    T item;
    while (inFile >> item.id) {
        inFile.ignore();
        getline(inFile, item.lnk);
        getline(inFile, item.usr);
        getline(inFile, item.pwd);
        getline(inFile, item.desc);
        Add(item);
    }
    inFile.close();
}