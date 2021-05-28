// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
 BST<std::string>Tree;
    bool flagNotAdd = true;
    std::string word = "", string = "";
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        return Tree;
    }
    while (file >> string) {
        for (int j = 0; j < string.size(); j++) {
            flagNotAdd = true;
            if ((string[j] >= 'a' && string[j] <= 'z') ||
                (string[j] >= 'A' && string[j] <= 'Z')) {
             if (string[j] >= 'A' && string[j] <= 'Z')
              string[j] + 32;
             word += string[j];
            } else {
                if (!word.empty()) {
                    Tree.add(word);
                    word.clear();
                    flagNotAdd = false;
                    continue;
                }
            }
        }
        if (flagNotAdd && !word.empty()) {
            Tree.add(word);
            word.clear();
        }
    }
    file.close();
    return Tree;
}
