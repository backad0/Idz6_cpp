#include <string>
#include <iostream>

using namespace std;

struct Node {
    string word;
    int count;
    Node *left;
    Node *right;

    Node(string _word) : word(_word), count(1), left(nullptr), right(nullptr) {}

    Node(string _word, Node *_left, Node *_right) : word(_word), count(1), left(_left),
                                                    right(_right) {}

    Node(int _count, string _word, Node *_left, Node *_right) : count(_count), word(_word), left(_left),
                                                                right(_right) {}
};

class MyDictionary {
public:

    Node *root;

    MyDictionary();

    explicit MyDictionary(string _word);

    MyDictionary(const MyDictionary &obj);

    MyDictionary(MyDictionary &&obj) noexcept;

    ~MyDictionary();

    MyDictionary &operator=(const MyDictionary &obj);

    MyDictionary &operator=(MyDictionary &&obj) noexcept;

    bool operator==(const MyDictionary &obj);

    bool operator!=(const MyDictionary &obj);

    void clear();

    int findWord(string word);

    bool findWord(Node *const root, int &res, string word);

    void insert(Node *&root, string word);

    bool deleteWord(Node *&root, string word);

    int numOfWords(const Node *root);

    void print(const Node *root);


private:
    void clear(Node *node);

    void del(Node *&leftSubTree, Node *&root);

    bool isEqual(Node *elem1, Node *elem2);

    Node *copyTree(Node *obj);


};
