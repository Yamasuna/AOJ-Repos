#include <iostream>
#include <cstring>

using namespace std;

#define DICTIONARY_NUM  (1046527)

string dictionary[DICTIONARY_NUM];

int HashFunc1(long long key)
{
    return (key % DICTIONARY_NUM);
}

int HashFunc2(long long key)
{
    return 1 + (key % (DICTIONARY_NUM - 1));
}

int HashFunc_OpenAddress(long long key, int idx)
{
    return (HashFunc1(key) + idx * HashFunc2(key)) % DICTIONARY_NUM;
}

/* convert character to number */
int getChar(char ch)
{
    int ret;

    switch(ch) {
        case 'A':
            ret = 1;
            break;
        case 'C':
            ret = 2;
            break;
        case 'G':
            ret = 3;
            break;
        case 'T':
            ret = 4;
            break;
        default:
            ret = 0;
            break;
    }

    return ret;
}

/* generate key for hash */
long long getKey(string str)
{
    long long key = 0;
    long long coeff = 1;

    for (long long loop = 0; loop < str.length(); loop++) {
        key += coeff * getChar(str.at(loop));
        coeff *= 5;
    }
    return key;
}

int InsertKey(string str)
{
    long long key, h;
    long long loop;
    int ret;

    key = getKey(str);
    loop = 0;
    while(true) {
        h = HashFunc_OpenAddress(key, loop);
        /* 既に登録されていたら登録不要 */
        if (dictionary[h] == str) {
            ret = 0;
            break;
        /* 空きがあった場合登録 */
        } else if (dictionary[h] == "\0") {
            dictionary[h] = str;
            ret = 1;
            break;
        }
        loop++;
    }
    return ret;
}

int SearchKey(string str)
{
    long long key, h;
    long long loop;
    int ret;

    key = getKey(str);
    loop = 0;
    while(true) {
        h = HashFunc_OpenAddress(key, loop);
        if (dictionary[h] == str) {
            ret = 1;
            break;
        } else if (dictionary[h] == "\0") {
            ret = 0;
            break;
        }
        loop++;
    }
    return ret;
}

int main(void)
{
    int command_num;
    int ret;
    string command;
    string str;

    cin >> command_num;

    /* Initialize dictionary */
    for (int loop = 0; loop < DICTIONARY_NUM; loop++) {
        dictionary[loop] = "\0";
    }

    for (int loop = 0; loop < command_num; loop++) {
        cin >> command >> str;

        if (command == "insert") {
            ret = InsertKey(str);
        } else if (command == "find") {
            if (SearchKey(str)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        } else {
            cout << "invalid command" << " " << command << endl;
        }
    }
    return 0;
}
