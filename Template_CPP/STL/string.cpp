#include <iostream>
#include <string>
using namespace std;

int main() {
    string str  = "1234567";
    char   ch[] = "abcdefg";

    // 构造字符串
    string str0("ABCDEFG");              // 定义一个字符串
    string str1(str);                    // 构造函数，全部复制
    string str2(str, 2, 5);              // 构造函数，从字符串str的第2个元素开始，复制5个元素，赋值给str_2
    string str3(ch, 5);                  // 将字符串ch的前5个元素赋值给str_3
    string str4(5, 'X');                 // 将 5 个 'X' 组成的字符串 "XXXXX" 赋值给 str_4
    string str5(str.begin(), str.end()); // 复制字符串 str 的所有元素，并赋值给 str_5
    cout << str << endl;
    cout << str0 << endl;
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 << endl;
    cout << str5 << endl;

    // 获取长度
    int    size       = 0;
    int    length     = 0;
    long   maxsize    = 0;
    int    capacity   = 0;
    string str_custom = str;
    str_custom.resize(5);
    size     = str_custom.size();
    length   = str_custom.length();
    maxsize  = str_custom.max_size();
    capacity = str_custom.capacity();
    cout << "size = " << size << endl;
    cout << "length = " << length << endl;
    cout << "maxsize = " << maxsize << endl;
    cout << "capacity = " << capacity << endl;

    // 获取字符
    char temp;
    char temp_1;
    temp   = str[2];    //"获取字符 'c'
    temp_1 = str.at(2); //获取字符 'c'
    cout << temp << " " << temp_1 << endl;

    // 查找
    string x("Hi, Peter, I'm sick. Please bought some drugs for me.");

    int p  = x.find('P');
    int rp = x.rfind('P');
    cout << "find() 查找的P在第 " << p << " 位" << endl;
    cout << "rfind()查找的P在第 " << rp << " 位" << endl;

    int q  = x.find("some", 0);
    int rq = x.rfind("some", 0);
    cout << "find() 查找的some在第 " << q << " 位" << endl;
    cout << "rfind()查找的some在第 " << rq << " 位" << endl;

    int l  = x.find(" drugs", 0, 5);
    int rl = x.rfind(" drugs", 0, 5);
    cout << "find() 查找的' drugs'在第 " << l << " 位" << endl;
    cout << "rfind()查找的' drugs'在第 " << rl << " 位" << endl;

    string y("sick");
    int    m  = x.find(y, 0);
    int    rm = x.rfind(y, 0);
    cout << "find() 查找的y字符串在第 " << m << " 位" << endl;
    cout << "rfind()查找的y字符串在第 " << rm << " 位" << endl;

    return 0;
}