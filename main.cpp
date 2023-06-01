#include "cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest.h"
#include "MyDictionary.cpp"

TEST(MyDictionary, Test){
    MyDictionary tree("first");
    tree.insert(tree.root, "a");
    tree.insert(tree.root, "b");
    tree.insert(tree.root, "b");
    tree.insert(tree.root, "c");
    tree.insert(tree.root, "c");
    tree.insert(tree.root, "c");
    tree.insert(tree.root, "d");
    tree.insert(tree.root, "e");
    tree.insert(tree.root, "f");
    tree.insert(tree.root, "j");
    std::cout << tree.numOfWords(tree.root) << " " << std::endl;
    tree.print(tree.root);
    tree.deleteWord(*&tree.root, "e");
    tree.deleteWord(*&tree.root, "c");
    std::cout << std::endl;
    std::cout << tree.numOfWords(tree.root) << " " << std::endl;
    tree.print(tree.root);
}
