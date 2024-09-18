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
    std::cout << "此账号拥有的角色以及所消耗的原石为：" << std::endl;
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
    std::cout << "链表已经全部清空。" << std::endl;
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
    std::cout << "以添加此角色" << std::endl;
    std::cout << std::endl;
}

bool Hero::find(const std::string& name) {
    for (Node* temp = head; temp != NULL; temp = temp->next) {
        if (temp->data.name == name) {
            std::cout << "您已经拥有角色：" << name << "，抽取此角色消耗原石 " << temp->data.stones << std::endl;
            std::cout << std::endl;
            return true;
        }
    }
    std::cout << "您还未拥有此角色" << std::endl;
    std::cout << std::endl;
    return false;
}

int Hero::heronums() const {
    std::cout << "您拥有五星角色的个数为：" << num << std::endl;
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
    std::cout << "您总共拥有 " << num << " 个账号，它们分别是：" << std::endl;
    std::cout << "----------------------" << std::endl;
    size_t i = 1;
    for (auto temp = head; temp != NULL; temp = temp->next) {
        std::cout << "第 " << i << " 个账号UID：" << temp->data.UID << std::endl;
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
    std::cout << "链表已经全部清空" << std::endl << std::endl;
}

void Accout::append(const AccoutNode& node) {
    auto temp = new AccoutNode(node);
    temp->next = head;
    head = temp;
    num++;
    std::cout << "已添加此账号" << std::endl << std::endl;
}

Hero Accout::find(const int& UID) {
    for (AccoutNode* temp = head; temp != NULL; temp = temp->next) {
        if (temp->data.UID == UID) {
            std::cout << "拥有此UID " << UID << " 的账号" << "，已读取该账号的信息" << std::endl << std::endl;
            return temp->data.link;
        }
    }
    std::cout << "您未拥有此账号" << std::endl << std::endl;
    return Hero(0, NULL);
}

void Accout::deleteAccout(const int& UID) {
    if (head->data.UID == UID) {
        auto temp = head;
        head = head->next;
        delete temp;
        num--;
        std::cout << "已删除UID为 " << UID << " 的结点" << std::endl << std::endl;
        return;
    }
    auto previous = head;
    for (auto current = head->next; current != NULL; current = current->next) {
        if (current->data.UID == UID) {
            previous->next = current->next;
            delete current;
            num--;
            std::cout << "已删除UID为 " << UID << " 的账号" << std::endl << std::endl;
            return;
        }
        previous=current;
    }
    std::cout << "不存在UID为 " << UID << " 的账号" << std::endl << std::endl;
}

int Accout::accoutnums() const {
    std::cout << "您拥有 " << num << " 个账号" << std::endl << std::endl;
    return num;
}