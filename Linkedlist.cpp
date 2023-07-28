// Linkedlist.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void inserthead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = head;
        }
    }

    void inserttail(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAfter(Node* prevNode, int value) {
        if (prevNode == nullptr) {
            return;
        }
        Node* newNode = new Node(value);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        if (prevNode == tail) {
            tail = newNode;
        }
    }

    void removehead() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    }

    void removetail() {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        current->next = nullptr;
        delete tail;
        tail = current;
    }

    void removeAfter(Node* prevNode) {
        if (prevNode == nullptr || prevNode->next == nullptr) {
            return;
        }
        Node* temp = prevNode->next;
        prevNode->next = temp->next;
        if (temp == tail) {
            tail = prevNode;
        }
        delete temp;
    }

    Node* search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList linkedList;

    linkedList.inserthead(3);
    linkedList.inserthead(2);
    linkedList.inserthead(1);
    linkedList.display(); // 출력: 1 2 3

    linkedList.inserttail(4);
    linkedList.display(); // 출력: 1 2 3 4

    Node* node = linkedList.search(2);
    if (node != nullptr) {
        linkedList.insertAfter(node, 5);
    }
    linkedList.display(); // 출력: 1 2 5 3 4

    linkedList.removehead();
    linkedList.display(); // 출력: 2 5 3 4

    linkedList.removetail();
    linkedList.display(); // 출력: 2 5 3

    Node* nodeToRemove = linkedList.search(5);
    linkedList.removeAfter(nodeToRemove);
    linkedList.display(); // 출력: 2 5

    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
