#include "list.hpp"
#include <iostream>

list::Node *list::from_string(const char *s) {
    int i = 0;
    if (s[i] == '\0')
        return nullptr;
    list::Node *head = new Node{s[i], nullptr};
    list::Node *cur = head;
    i += 1;
    for (; s[i] != '\0'; ++i) {
        cur->next = new Node{s[i], nullptr};
        cur = cur->next;

    }
    return head;
}

void list::free(list::Node *head) {
    if (head == nullptr)
        return;
    list::Node *cur = head;
    list::Node *n = head->next;
    while (n != nullptr) {
        delete cur;
        cur = n;
        n = cur->next;
    }
    delete cur;
}

void list::print(std::ostream& out, list::Node* head) {
    while (head != nullptr) {
        out << head->data;
        head = head->next;
    }
}

int list::length(Node *head) {
    int i = 0;
    for (; head != nullptr; ++i) {
        head = head->next;
    }
    return i;
}

list::Node* list::copy(list::Node* head) {
    list::Node *out = new list::Node{head->data, nullptr};
    list::Node *cur = out;
    head = head->next;
    while (head != nullptr) {
        out->next = new Node{head->data, nullptr};
        head = head->next;
        out = out->next;
    }
    return cur;
}


int list::compare(list::Node* lhs, list::Node* rhs) {
    while (lhs != nullptr && rhs != nullptr) {
        if (lhs->data == rhs->data) 
            continue;
        else
            return lhs->data - rhs->data;
    }
    if (lhs == nullptr && rhs == nullptr)
        return 0;
    else if (rhs == nullptr)
        return 1;
    else
        return -1;
}

list::Node* list::reverse(list::Node* head) {
    list::Node *cur = new list::Node{head->data, nullptr};
    list::Node *prev;
    head = head->next;
    while (head != nullptr) {
        prev = new Node{head->data, cur};
        cur = prev;
        head = head->next;
    }
    return cur;
}

list::Node* list::append(list::Node* lhs, list::Node* rhs) {
    list::Node* out = new list::Node{lhs->data, nullptr};
    list::Node *cur = out->next;
    lhs = lhs->next;
    while (lhs != nullptr) {
        cur = new Node{lhs->data, nullptr};
        lhs = lhs->next;
        cur = cur->next;
    }
    while (rhs != nullptr) { 
        cur = new Node{rhs->data, nullptr};
        rhs = rhs->next;
        cur = cur->next;
    }
    return out;
}

int list::index(list::Node* head, list::Node* node) {
    int i = 0;
    for (; head != node; ++i) {
        head = head->next;
    }
    return i;
}

list::Node* list::find_char(list::Node* head, char c) {
    int i = 0;
    for (; head->data != c; ++i) {
        head = head->next;
        if (head == nullptr) {
            return nullptr;
        }
    }
    return head;
}

list::Node* list::find_list(list::Node* haystack, list::Node* needle) {
    int i = 0;
    list::Node *tmp;
    list::Node *tmp2;
    if (needle == nullptr)
        return nullptr;
    for (; haystack != nullptr; ++i) {
        if (needle->data == haystack->data) {
            tmp = haystack;
            tmp2 = needle;
            for (; tmp->data == tmp2->data;) {
                tmp = tmp->next;
                tmp2 = tmp2->next;
                if (tmp2 == nullptr) 
                    return haystack;
                if (tmp == nullptr)
                    break;
            }
        }
        haystack = haystack->next;
    }
    return nullptr;
}

list::Node* list::nth(list::Node *head, int n) {
    for (; n >= 0 && head != nullptr; --n) {
        head = head->next;
    }
    return head;
}

list::Node* list::last(list::Node *head) {
    for (; head->next != nullptr; head = head->next);
    return head;
}