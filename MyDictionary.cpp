#include "MyDictionary.hpp"

MyDictionary::MyDictionary() : root(nullptr) {}

MyDictionary::MyDictionary(string _word) : root(new Node(_word)) {
    root->word = _word;
    root->left = nullptr;
    root->right = nullptr;
}

MyDictionary::MyDictionary(const MyDictionary &obj) {
    root = copyTree(obj.root);
}

MyDictionary::MyDictionary(MyDictionary &&obj) noexcept: root(obj.root) {
    clear(obj.root);
}

MyDictionary::~MyDictionary() {
    clear(root);
}

MyDictionary &MyDictionary::operator=(const MyDictionary &obj) {
    if (this != &obj) {
        clear(root);
        root = copyTree(obj.root);
    }
    return *this;
}

MyDictionary &MyDictionary::operator=(MyDictionary &&obj) noexcept {
    if (this != &obj) {
        clear(root);
        root = obj.root;
        clear(obj.root);
    }
    return *this;
}

bool MyDictionary::operator==(const MyDictionary &obj) {
    return isEqual(root, obj.root);
}

bool MyDictionary::operator!=(const MyDictionary &obj) {
    return !(*this == obj);
}

int MyDictionary::findWord(string word) {
    int res = 0;
    if (!findWord(root, res, word)) throw exception();
    return res;
}

bool MyDictionary::findWord(Node *root, int &res, string word) {
    if (root != nullptr) {
        if (root->word == word) {
            res = root->count;
            return true;
        }
        if (findWord(root->left, res, word)) {
            return true;
        }
        if (findWord(root->right, res, word)) {
            return true;
        }
    }
    return false;
}


void MyDictionary::insert(Node *&root, string word) {
    if (!root) {
        root = new Node(word, nullptr, nullptr);
        return;
    }
    if (root->word == word) {
        root->count++;
        return;
    }
    if (word.compare(root->word) < 0) {
        insert(root->left, word);
    }

    if (word.compare(root->word) > 0) {
        insert(root->right, word);
    }
}

bool MyDictionary::deleteWord(Node *&root, string word) {
    if (root == nullptr) return false;
    if (word.compare(root->word) < 0) return deleteWord(root->left, word);
    if (word.compare(root->word) > 0) return deleteWord(root->right, word);
    if (root->count == 1) {
        Node *_tmp = root;
        if (root->left == nullptr)
            root = root->right;
        else if (root->right == nullptr)
            root = root->left;
        else {
            del(root->left, _tmp);
        }
        delete _tmp;
    } else {
        root->count--;
    }
    return true;
}

int MyDictionary::numOfWords(const Node *root) {
    if (root == nullptr) {
        return 0;
    }
    const int res = (root->count) + numOfWords(root->left) + numOfWords(root->right);
    return res;
}

void MyDictionary::print(const Node *root) {
    if (root == nullptr) return;
    print(root->left);
    cout << root->count << " " << root->word << " ";
    print(root->right);
}


void MyDictionary::del(Node *&leftSubTree, Node *&root) {
    if (leftSubTree->right) {
        del(leftSubTree->right, root);
    } else {
        root->word = leftSubTree->word;
        root = leftSubTree;
        leftSubTree = leftSubTree->left;
    }
}

void MyDictionary::clear() {
    if (root != nullptr) {
        clear(root);
        root = nullptr;
    }
}

void MyDictionary::clear(Node *node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

bool MyDictionary::isEqual(Node *elem1, Node *elem2) {
    if (elem1 == nullptr)
        return elem1 == nullptr;
    else
        return elem1->word == elem2->word && elem1->count == elem2->count
               && elem1->right == elem2->right && elem1->left == elem2->left &&
               isEqual(elem1->left, elem2->left) &&
               isEqual(elem1->right, elem2->right);
}

Node *MyDictionary::copyTree(Node *obj) {
    if (obj != nullptr) {
        return new Node(obj->count, obj->word, obj->left, obj->right);
    }
    return nullptr;
}

