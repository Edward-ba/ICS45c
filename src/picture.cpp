#include "picture.hpp"
#include <iostream>
#include <utility>

Picture::Picture() {
    this->head = nullptr;
    this->tail = nullptr;
}

Picture::Picture(const Picture& other) {
    ListNode* head = other.head;
    this->head = new ListNode{head->shape, nullptr};
    ListNode *cur = this->head;
    head = head->next;
    while (head != nullptr) {
        cur = cur->next;
        cur = new ListNode{head->shape, nullptr};
        head = head->next;
    }
    this->tail = cur;
}

Picture::Picture(Picture&& other) {
    this->head = other.head;
    this->tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
}

void Picture::swap(Picture& other) {
    std::swap(this->head, other.head);
    std::swap(this->tail, other.tail);
}

Picture& Picture::operator=(const Picture& other) {
    if (this->head != nullptr) {
        ListNode* tmp = this->head->next;
        while (tmp != nullptr) {
            delete this->head->shape;
            delete this->head;
            this->head = tmp;
            tmp = this->head->next;
        }
        delete this->head->shape;
        delete this->head;
    }
    ListNode* head = other.head;
    this->head = new ListNode{head->shape, nullptr};
    ListNode *cur = this->head;
    head = head->next;
    while (head != nullptr) {
        cur = cur->next;
        cur = new ListNode{head->shape, nullptr};
        head = head->next;
    }
    this->tail = cur;
    return *this;
}

Picture& Picture::operator=(Picture&& other) {
    if (this->head == other.head) {
        return *this;
    }
    if (this->head != nullptr) {
        ListNode *n = this->head->next;
        while (n != nullptr) {
            delete this->head->shape;
            delete this->head;
            this->head = n;
            n = n->next;
        }
        delete this->head->shape;
        delete this->head;
    }
    this->head = other.head;
    this->tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
    return *this;
}

void Picture::add(const Shape& shape) {
    if (this->head == nullptr) {
        this->head = new ListNode{shape.clone(), nullptr};
        this->tail = this->head;
    }
    else {
        this->tail->next = new ListNode{shape.clone(), nullptr};
        this->tail = this->tail->next;
    }
}

void Picture::print_all(std::ostream& out) const {
    ListNode *tmp = this->head;
    while (tmp != nullptr) {
        tmp->shape->print(out);
        tmp = tmp->next;
    }
}

void Picture::draw_all(std::ostream& out) const {
    ListNode *tmp = this->head;
    while (tmp != nullptr) {
        tmp->shape->draw(out);
        tmp = tmp->next;
    }
}

double Picture::total_area() const {
    double out = 0;
    ListNode *tmp = this->head;
    while (tmp != nullptr) {
        out += tmp->shape->area();
        tmp = tmp->next;
    }
    return out;
}

Picture::~Picture() {
    if (this->head == nullptr)
        return;
    ListNode *n = this->head->next;
    while (n != nullptr) {
        delete this->head->shape;
        delete this->head;
        this->head = n;
        n = n->next;
    }
    delete this->head->shape;
    delete this->head;
}