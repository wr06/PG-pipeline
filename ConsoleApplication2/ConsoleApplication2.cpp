// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>
using namespace std;

vector<string> search = { "1234","1243","1324","1342","1423","1432","2134","2143","2314","2341","2413","2431","3124","3142","3214","3241","3412","3421","4123","4132","4213","4231","4312","4321" };

string changere(string input,string changenum) {
    if (input.size() != 4 || changenum.size() != 4) {
        return "wrong input";
    }
    vector<string> result(4, "");
    for (int i = 0; i < 4; i++) {
        int loca = changenum[i] - '0' - 1;
        result[i] = input[loca];
    }
    string set = accumulate(result.begin(), result.end(), string());
    return set;
}

bool searchnum(string input, string output) {
    bool ifsearch = false;
    for (int i = 0; i < 24; i++) {
        string mid = changere(input, search[i]);
        for (int j = 0; j < 24; j++) {
            if (output == changere(mid, search[j])) {
                ifsearch = true;
                cout << search[i] << "×" << search[j] << endl;
            }
        }
    }
    return ifsearch;
}

int main()
{
    string input;
    cout << "输入=" << endl;
    cin >> input;
    string output;
    cout << "输出=" << endl;
    cin >> output;
    if (!searchnum(input,output)) {
        cout << "no solution";
    }
    
    
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
