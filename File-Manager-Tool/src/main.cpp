#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

int main() {
    string path;

    cout << "Enter directory path: ";
    getline(cin, path);

    try {
        if (!fs::exists(path)) {
            cout << "Directory does not exist!" << endl;
            return 0;
        }

        cout << "\nFiles and folders:\n";
        for (const auto& entry : fs::directory_iterator(path)) {
            cout << entry.path().filename() << endl;
        }
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
