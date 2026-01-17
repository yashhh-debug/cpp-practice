#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;
using namespace std;

// Function to list files
void listFiles() {
    string path;
    cout << "Enter directory path: ";
    cin.ignore();
    getline(cin, path);

    try {
        if (!fs::exists(path)) {
            cout << "Directory does not exist.\n";
            return;
        }

        cout << "\nFiles and directories:\n";
        for (const auto& entry : fs::directory_iterator(path)) {
            cout << entry.path().filename() << endl;
        }
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Function to create a file
void createFile() {
    string filename;
    cout << "Enter file name (with path): ";
    cin.ignore();
    getline(cin, filename);

    ofstream file(filename);
    if (file) {
        cout << "File created successfully.\n";
        file.close();
    } else {
        cout << "Failed to create file.\n";
    }
}

// Function to create directory
void createDirectory() {
    string dirname;
    cout << "Enter directory name (with path): ";
    cin.ignore();
    getline(cin, dirname);

    if (fs::create_directory(dirname)) {
        cout << "Directory created successfully.\n";
    } else {
        cout << "Failed to create directory.\n";
    }
}

// Function to delete file
void deleteFile() {
    string filename;
    cout << "Enter file name (with path): ";
    cin.ignore();
    getline(cin, filename);

    if (fs::remove(filename)) {
        cout << "File deleted successfully.\n";
    } else {
        cout << "Failed to delete file.\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== File Manager =====\n";
        cout << "1. List files\n";
        cout << "2. Create file\n";
        cout << "3. Create directory\n";
        cout << "4. Delete file\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                listFiles();
                break;
            case 2:
                createFile();
                break;
            case 3:
                createDirectory();
                break;
            case 4:
                deleteFile();
                break;
            case 5:
                cout << "Exiting File Manager...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
