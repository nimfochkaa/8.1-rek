#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

bool hasSQorQS_recursive(const char* str, int index = 0) {
    if (str[index + 1] == '\0') return false;
    if ((str[index] == 'S' && str[index + 1] == 'Q') || (str[index] == 'Q' && str[index + 1] == 'S'))
        return true;
    return hasSQorQS_recursive(str, index + 1);
}

void replaceSQorQS_recursive(char* result, const char* str, int& j, int index = 0) {
    if (str[index] == '\0') {
        result[j] = '\0';
        return;
    }
    if ((str[index] == 'S' && str[index + 1] == 'Q') || (str[index] == 'Q' && str[index + 1] == 'S')) {
        result[j++] = '*';
        result[j++] = '*';
        result[j++] = '*';
        replaceSQorQS_recursive(result, str, j, index + 2);
    }
    else {
        result[j++] = str[index];
        replaceSQorQS_recursive(result, str, j, index + 1);
    }
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (hasSQorQS_recursive(str))
        cout << "The string contains 'SQ' or 'QS'." << endl;
    else
        cout << "The string does not contain 'SQ' or 'QS'." << endl;

    char result[201];
    int j = 0;
    replaceSQorQS_recursive(result, str, j);
    cout << "Modified string: " << result << endl;

    return 0;
}
