#include <iostream>
#include "RedBlackTree.h"
//#include "RedBlackTree.cpp"
#include <vector>

using namespace std;


bool checkTime(Time key)
{
    if (key.hour > 24 || key.hour < 0)
    {
        cout << "Time is entered incorrectly" << endl;
        return false;
    }
    else if (key.minutes > 60 || key.minutes < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}


vector<Time>* getDataTree(Node* r, Node* TNill, vector<Time>* data)
{
    if (r == TNill)
        return data;

    getDataTree(r->leftchild, TNill, data);
    data->push_back(r->key);
    getDataTree(r->rightchild, TNill, data);
}


void Test(vector<Time>* rightAnswer, vector<Time>* dataTree, int number)
{
    bool flag = true;
    vector<Time>::iterator i = rightAnswer->begin();
    vector<Time>::iterator p = dataTree->begin();
    for (; p != dataTree->end() && flag; ++i, ++p)
    {
        if (i->hour != p->hour || i->minutes != p->minutes)
        {
            flag = false;
        }
    }

    cout << "Test " << number;
    if (flag)
        cout << ": pass\n";
    else
        cout << ": fail\n";
}


int main()
{
    // ================================== Data for tests ====================================
    RBTree Tree1;
    Time time;
    vector<Time> data;
    vector<Time> rightAnswer;

    //==================================== Test 1 =================================================
    time.hour = 17;
    time.minutes = 47;
    Tree1.Insert(time, Tree1.TNill);
    getDataTree(Tree1.root, Tree1.TNill, &data);
    rightAnswer = { Time(17, 47) };

    Test(&rightAnswer, &data, 1);
    Tree1.PrintTree(Tree1.root); cout << "\n";
    Tree1.ClearRBTree(Tree1.root);
    data.clear();

    //==================================== Test 2 =================================================
    time.hour = 10;
    time.minutes = 44;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 17;
    time.minutes = 47;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 22;
    time.minutes = 40;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 6;
    time.minutes = 18;
    Tree1.Insert(time, Tree1.TNill);
    getDataTree(Tree1.root, Tree1.TNill, &data);
    rightAnswer = { Time(6, 18), Time(10, 44),
                    Time(17, 47), Time(22, 40) };
    Tree1.PrintTree(Tree1.root); cout << "\n";
    Test(&rightAnswer, &data, 2);
    Tree1.ClearRBTree(Tree1.root);
    data.clear();

    //==================================== Test 3 =================================================
    time.hour = 10;
    time.minutes = 44;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 17;
    time.minutes = 47;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 22;
    time.minutes = 40;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 23;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    getDataTree(Tree1.root, Tree1.TNill, &data);
    rightAnswer = { Time(10, 44), Time(17, 47),
                    Time(22, 40), Time(23, 00) };
    Tree1.PrintTree(Tree1.root); cout << "\n";
    Test(&rightAnswer, &data, 3);
    Tree1.ClearRBTree(Tree1.root);
    data.clear();

    //==================================== Test 4 =================================================
    time.hour = 17;
    time.minutes = 47;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 22;
    time.minutes = 40;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 23;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    getDataTree(Tree1.root, Tree1.TNill, &data);
    rightAnswer = { Time(17, 47), Time(22, 40), Time(23, 00) };
    Tree1.PrintTree(Tree1.root); cout << "\n";
    Test(&rightAnswer, &data, 4);
    Tree1.ClearRBTree(Tree1.root);
    data.clear();

    //==================================== Test 5 =================================================
    time.hour = 17;
    time.minutes = 47;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 10;
    time.minutes = 44;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 6;
    time.minutes = 18;
    Tree1.Insert(time, Tree1.TNill);
    getDataTree(Tree1.root, Tree1.TNill, &data);
    rightAnswer = { Time(6, 18), Time(10, 44), Time(17, 47) };
    Tree1.PrintTree(Tree1.root); cout << "\n";
    Test(&rightAnswer, &data, 5);
    Tree1.ClearRBTree(Tree1.root);
    data.clear();

    //==================================== Test 6 =================================================
    time.hour = 17;
    time.minutes = 47;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 10;
    time.minutes = 44;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 17;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    getDataTree(Tree1.root, Tree1.TNill, &data);
    rightAnswer = { Time(10, 44), Time(17, 00), Time(17, 47) };
    Tree1.PrintTree(Tree1.root); cout << "\n";
    Test(&rightAnswer, &data, 6);
    Tree1.ClearRBTree(Tree1.root);
    data.clear();

    //==================================== Test 7 =================================================
    time.hour = 17;
    time.minutes = 47;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 22;
    time.minutes = 40;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 22;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    getDataTree(Tree1.root, Tree1.TNill, &data);
    rightAnswer = { Time(17, 47), Time(22, 00), Time(22, 40) };
    Tree1.PrintTree(Tree1.root); cout << "\n";
    Test(&rightAnswer, &data, 7);
    Tree1.ClearRBTree(Tree1.root);
    data.clear();

    //==================================== Test 8 =================================================
    time.hour = 17;
    time.minutes = 47;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 10;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 22;
    time.minutes = 40;
    Tree1.Insert(time, Tree1.TNill);
    getDataTree(Tree1.root, Tree1.TNill, &data);
    rightAnswer = { Time(10, 00), Time(17, 47), Time(22, 40) };
    Tree1.PrintTree(Tree1.root); cout << "\n";
    Test(&rightAnswer, &data, 8);
    Tree1.ClearRBTree(Tree1.root);
    data.clear();

    //==================================== Test 9 =================================================
    time.hour = 17;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 14;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 20;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 18;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    Tree1.ChangeColor(time, Tree1.TNill, 15);
    time.hour = 21;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    Tree1.ChangeColor(time, Tree1.TNill, 15);
    time.hour = 14;
    time.minutes = 00;
    Tree1.Delete(time, Tree1.TNill);
    getDataTree(Tree1.root, Tree1.TNill, &data);
    rightAnswer = { Time(17, 00), Time(18, 00), Time(20, 00), Time(21, 00) };
    Tree1.PrintTree(Tree1.root); cout << "\n";
    Test(&rightAnswer, &data, 9);
    Tree1.ClearRBTree(Tree1.root);
    data.clear();

    //==================================== Test 10 =================================================
    time.hour = 17;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 22;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 14;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 10;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    Tree1.ChangeColor(time, Tree1.TNill, 15);
    time.hour = 16;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    Tree1.ChangeColor(time, Tree1.TNill, 15);
    time.hour = 22;
    time.minutes = 00;
    Tree1.Delete(time, Tree1.TNill);
    getDataTree(Tree1.root, Tree1.TNill, &data);
    rightAnswer = { Time(10, 00), Time(14, 00), Time(16, 00), Time(17, 00) };
    Tree1.PrintTree(Tree1.root); cout << "\n";
    Test(&rightAnswer, &data, 10);
    Tree1.ClearRBTree(Tree1.root);
    data.clear();

    //==================================== Test 11 =================================================
    time.hour = 17;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 14;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 20;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 18;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 21;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 14;
    time.minutes = 00;
    Tree1.Delete(time, Tree1.TNill);
    getDataTree(Tree1.root, Tree1.TNill, &data);
    rightAnswer = { Time(17, 00), Time(18, 00), Time(20, 00), Time(21, 00) };
    Tree1.PrintTree(Tree1.root); cout << "\n";
    Test(&rightAnswer, &data, 11);
    Tree1.ClearRBTree(Tree1.root);
    data.clear();

    //==================================== Test 12 =================================================
    time.hour = 17;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 22;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 14;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 10;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 16;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 22;
    time.minutes = 00;
    Tree1.Delete(time, Tree1.TNill);
    getDataTree(Tree1.root, Tree1.TNill, &data);
    rightAnswer = { Time(10, 00), Time(14, 00), Time(16, 00), Time(17, 00) };
    Tree1.PrintTree(Tree1.root); cout << "\n";
    Test(&rightAnswer, &data, 12);
    Tree1.ClearRBTree(Tree1.root);
    data.clear();

    //==================================== Test 13 =================================================
    time.hour = 17;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 14;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 20;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 18;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 21;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 14;
    time.minutes = 00;
    Tree1.Delete(time, Tree1.TNill);
    getDataTree(Tree1.root, Tree1.TNill, &data);
    rightAnswer = { Time(17, 00), Time(18, 00), Time(20, 00), Time(21, 00) };
    Tree1.PrintTree(Tree1.root); cout << "\n";
    Test(&rightAnswer, &data, 13);
    Tree1.ClearRBTree(Tree1.root);
    data.clear();

    //==================================== Test 14 =================================================
    time.hour = 17;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 22;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 14;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 16;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 10;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 22;
    time.minutes = 00;
    Tree1.Delete(time, Tree1.TNill);
    getDataTree(Tree1.root, Tree1.TNill, &data);
    rightAnswer = { Time(10, 00), Time(14, 00), Time(16, 00), Time(17, 00) };
    Tree1.PrintTree(Tree1.root); cout << "\n";
    Test(&rightAnswer, &data, 14);
    Tree1.ClearRBTree(Tree1.root);
    data.clear();

    //==================================== Test 15 =================================================
    time.hour = 17;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 14;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 20;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 18;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    Tree1.ChangeColor(time, Tree1.TNill, 15);
    time.hour = 21;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    Tree1.ChangeColor(time, Tree1.TNill, 15);
    time.hour = 14;
    time.minutes = 00;
    Tree1.Delete(time, Tree1.TNill);
    getDataTree(Tree1.root, Tree1.TNill, &data);
    rightAnswer = { Time(17, 00), Time(18, 00), Time(20, 00), Time(21, 00) };
    Tree1.PrintTree(Tree1.root); cout << "\n";
    Test(&rightAnswer, &data, 15);
    Tree1.ClearRBTree(Tree1.root);
    data.clear();

    //==================================== Test 16 =================================================
    time.hour = 17;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 22;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 14;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    time.hour = 10;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    Tree1.ChangeColor(time, Tree1.TNill, 15);
    time.hour = 16;
    time.minutes = 00;
    Tree1.Insert(time, Tree1.TNill);
    Tree1.ChangeColor(time, Tree1.TNill, 15);
    time.hour = 22;
    time.minutes = 00;
    Tree1.Delete(time, Tree1.TNill);
    getDataTree(Tree1.root, Tree1.TNill, &data);
    rightAnswer = { Time(10, 00), Time(14, 00), Time(16, 00), Time(17, 00) };
    Tree1.PrintTree(Tree1.root); cout << "\n";
    Test(&rightAnswer, &data, 16);
    Tree1.ClearRBTree(Tree1.root);
    data.clear();


    // ============================= Delete tree =========================================
    cout << endl;
    Tree1.DeleteRBTree(Tree1.root);
    cin.get();
    cin.get();
    return 0;
}
