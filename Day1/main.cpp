#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    long int sum = 0;
    int number = 0;
    fstream file;
    file.open("input.txt", ios::in);

    if (!file) {
        cerr << "Error in opening file..!!";
        return 1; // Return 1 to indicate an error
    }

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            string nums;
            for (char digit : line) {
                
                if (isdigit(digit)) {
                    nums.append(1, digit);
                }
            }
            number = ((nums[0]-'0')*10) + ((nums.at(nums.length() - 1)) - '0');
            sum += number;
            cout << "Number is " << number << endl;
            nums="";
        }
        file.close();
    } else {
        cerr << "Unable to open file";
        return 1; // Return 1 to indicate an error
    }

    cout << "Sum of all digits that match the next digit in the list is " << sum << endl;
    return 0;
}
