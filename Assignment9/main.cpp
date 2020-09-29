using namespace std;
#include <iostream>
#include <string>
#include "NumberList.cpp"
#include "StringList.cpp"

int main()
{
    // define NumberList object
    NumberList list;

    // Create list of five integers
    list.appendNode(8);
    list.appendNode(9);
    list.appendNode(13);
    list.appendNode(36);
    list.appendNode(46);
    list.displayList(); // display list

    // delete node 13 from list
    list.deleteNode(13);
    list.displayList();

// -----------------------------------

    // define StringList object
    StringList strlist;

    // Create list of five integers
    strlist.appendNode("hi");
    strlist.appendNode("my");
    strlist.appendNode("name");
    strlist.appendNode("is");
    strlist.appendNode("anthony");
    strlist.displayList(); // display list

    // delete node 13 from list
    strlist.deleteNode("is");
    strlist.displayList();

    return 0;
}