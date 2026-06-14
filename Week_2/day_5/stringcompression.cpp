#include <iostream>
#include <vector>
#include <string>

using namespace std;

int compress(vector<char>& chars) {
    int i = 0;
    int index = 0;

    while (i < chars.size()) {
        char current = chars[i];
        int count = 0;

        while (i < chars.size() && chars[i] == current) {
            count++;
            i++;
        }

        chars[index++] = current;

        if (count > 1) {
            string cnt = to_string(count);

            for (char c : cnt) {
                chars[index++] = c;
            }
        }
    }

    return index;
}

int main() {
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);

    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++) {
        cin >> chars[i];
    }

    int len = compress(chars);

    cout << "\nCompressed Length: " << len << endl;
    cout << "Compressed Array: ";

    for (int i = 0; i < len; i++) {
        cout << chars[i] << " ";
    }

    cout << endl;

    return 0;
}