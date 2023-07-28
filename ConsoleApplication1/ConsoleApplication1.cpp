// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // 소멸자: Linked list의 모든 노드들을 메모리에서 해제
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // 맨 앞에 노드를 삽입
    void insertFront(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // 맨 뒤에 노드를 삽입
    void insertBack(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // 특정 노드 뒤에 새 노드를 삽입
    void insertAfter(Node* prevNode, int data) {
        if (prevNode == nullptr) {
            cout << "Previous node is null. Cannot insert after." << endl;
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

    // 데이터가 일치하는 노드를 삭제
    void remove(int data) {
        Node* current = head;
        Node* prevNode = nullptr;

        while (current != nullptr) {
            if (current->data == data) {
                if (prevNode != nullptr) {
                    prevNode->next = current->next;
                }
                else {
                    head = current->next;
                }

                delete current;
                return;
            }

            prevNode = current;
            current = current->next;
        }

        std::cout << "Data not found. Cannot remove." << std::endl;
    }

    // 데이터가 일치하는 노드를 탐색
    Node* search(int data) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Linked list의 모든 노드들을 출력
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList linkedList;
   
    int choice, data;
    do {
        std::cout << "1. Insert Front, 2. Insert Back, 3. Display, 4. Remove, 5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter data to insert at the front: ";
            std::cin >> data;
            linkedList.insertFront(data);
            break;
        case 2:
            std::cout << "Enter data to insert at the back: ";
            std::cin >> data;
            linkedList.insertBack(data);
            break;
        case 3:
            std::cout << "Linked List: ";
            linkedList.display();
            break;
        case 4:
            std::cout << "Enter data to remove: ";
            std::cin >> data;
            linkedList.remove(data);
            break;
        case 5:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << std::endl;
    } while (choice != 5);


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
