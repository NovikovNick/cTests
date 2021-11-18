#include <iostream>
#include <bitset>

struct Node {
    uint64_t hash = 0;
    uint32_t counter = 0;
    Node *next = nullptr;
};

int64_t resolveCollision(uint64_t key, Node *node) {

    if (node->hash == key) {
        return node->counter++;
    }

    while (node->next != nullptr) {
        node = node->next;
        if (node->hash == key) {
            return node->counter++;
        }
    }

    Node *newOne = new Node;
    newOne->hash = key;
    node->next = newOne;

    return newOne->counter++;
}

int main() {

    int n;
    std::cout << "bucket size = ";
    std::cin >> n;

    long long res = 0;
    Node *arr = new Node[n];

    uint64_t ratios[] = {1, 1, 1, 1};

    for (int i = 0; i < 4; i++) {

        uint64_t ratio = ratios[i];

        uint64_t i1 = ratio % n;
        Node *node = &arr[i1];

        if (node->hash == 0) {
            node->hash = ratio;
            node->counter++;
        } else {
            res += resolveCollision(ratio, node);
        }
    }

    for (int i = 0; i < n; ++i) {
        Node *node = &arr[i];
        do {
            std::cout << std::to_string(node->hash) << " - ";
            node = node->next;
        } while (node != nullptr);
        std::cout << std::endl;
    }

    std::cout << "Result is " << res;

    delete arr;
}

/* SOLUTION */

