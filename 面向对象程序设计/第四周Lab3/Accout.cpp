// Account.cpp
#include "Accout.h"

Node::Node(const Data& data) : data(data), next(NULL) {}

Hero::Hero(int n, const Data* datas) : head(NULL), num(0) {
    num = n;
    for (size_t i = 0; i < n; i++) {
        Node* temp = new Node(datas[i]);
        temp->next = head;
        head = temp;
    }
}

void Hero::showList() {
    std::cout << "���˺�ӵ�еĽ�ɫ�Լ������ĵ�ԭʯΪ��" << std::endl;
    std::cout << "----------------------" << std::endl;
    for (Node* p = head; p != NULL; p = p->next) {
        std::cout << p->data.name << " --> " << p->data.stones << std::endl;
        std::cout << "   " << "|" << std::endl;
        std::cout << "   " << "|" << std::endl;
    }
    std::cout << "  " << "NULL" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << std::endl;
}

void Hero::freeList() {
    std::cout << "�����Ѿ�ȫ����ա�" << std::endl;
    num=0;
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    std::cout << std::endl;
}

void Hero::append(const Data& data) {
    Node* _new = new Node(data);
    num++;
    _new->next = head;
    head = _new;
    std::cout << "����Ӵ˽�ɫ" << std::endl;
    std::cout << std::endl;
}

bool Hero::find(const std::string& name) {
    for (Node* temp = head; temp != NULL; temp = temp->next) {
        if (temp->data.name == name) {
            std::cout << "���Ѿ�ӵ�н�ɫ��" << name << "����ȡ�˽�ɫ����ԭʯ " << temp->data.stones << std::endl;
            std::cout << std::endl;
            return true;
        }
    }
    std::cout << "����δӵ�д˽�ɫ" << std::endl;
    std::cout << std::endl;
    return false;
}

int Hero::heronums() const {
    std::cout << "��ӵ�����ǽ�ɫ�ĸ���Ϊ��" << num << std::endl;
    std::cout << std::endl;
    return num;
}

AccoutNode::AccoutNode(const AccoutData& data) : data(data), next(NULL) {}

Accout::Accout(AccoutData* arr, int n) : head(NULL), num(0) {
    num = n;
    for (size_t i = 0; i < n; i++) {
        AccoutNode* temp = new AccoutNode(arr[i]);
        temp->next = head;
        head = temp;
    }
}

void Accout::showAccoutList() {
    std::cout << "���ܹ�ӵ�� " << num << " ���˺ţ����Ƿֱ��ǣ�" << std::endl;
    std::cout << "----------------------" << std::endl;
    size_t i = 1;
    for (auto temp = head; temp != NULL; temp = temp->next) {
        std::cout << "�� " << i << " ���˺�UID��" << temp->data.UID << std::endl;
        std::cout << "   " << "|" << std::endl;
        std::cout << "   " << "|" << std::endl;
        i++;
    }
    std::cout << "  " << "NULL" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << std::endl;
}

void Accout::freeLink() {
    num=0;
    while (head != NULL) {
        auto temp = head;
        head = head->next;
        delete temp;
    }
    std::cout << "�����Ѿ�ȫ�����" << std::endl << std::endl;
}

void Accout::append(const AccoutNode& node) {
    auto temp = new AccoutNode(node);
    temp->next = head;
    head = temp;
    num++;
    std::cout << "����Ӵ��˺�" << std::endl << std::endl;
}

Hero Accout::find(const int& UID) {
    for (AccoutNode* temp = head; temp != NULL; temp = temp->next) {
        if (temp->data.UID == UID) {
            std::cout << "ӵ�д�UID " << UID << " ���˺�" << "���Ѷ�ȡ���˺ŵ���Ϣ" << std::endl << std::endl;
            return temp->data.link;
        }
    }
    std::cout << "��δӵ�д��˺�" << std::endl << std::endl;
    return Hero(0, NULL);
}

void Accout::deleteAccout(const int& UID) {
    if (head->data.UID == UID) {
        auto temp = head;
        head = head->next;
        delete temp;
        num--;
        std::cout << "��ɾ��UIDΪ " << UID << " �Ľ��" << std::endl << std::endl;
        return;
    }
    auto previous = head;
    for (auto current = head->next; current != NULL; current = current->next) {
        if (current->data.UID == UID) {
            previous->next = current->next;
            delete current;
            num--;
            std::cout << "��ɾ��UIDΪ " << UID << " ���˺�" << std::endl << std::endl;
            return;
        }
        previous=current;
    }
    std::cout << "������UIDΪ " << UID << " ���˺�" << std::endl << std::endl;
}

int Accout::accoutnums() const {
    std::cout << "��ӵ�� " << num << " ���˺�" << std::endl << std::endl;
    return num;
}