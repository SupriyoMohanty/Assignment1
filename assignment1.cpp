//Record Management System

//Create a class for record management with the following functionalities,
//1. Add record
//2. Delete record
//3. Edit record
//4. Sort records based on ID
//5. Display record


#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Record {
public:
    struct Data {
        int id;
        string name;
    };

    void addRecord() {
        Data newRecord;
        cout << "Enter ID: ";
        cin >> newRecord.id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, newRecord.name);
        records.push_back(newRecord);
    }

    void deleteRecord() {
        int idToDelete;
        cout << "Enter ID to delete: ";
        cin >> idToDelete;
        records.erase(remove_if(records.begin(), records.end(),
                          [idToDelete](const Data& record) { return record.id == idToDelete; }),
                      records.end());
    }

    void editRecord() {
        int idToEdit;
        cout << "Enter ID to edit: ";
        cin >> idToEdit;

        auto z = find_if(records.begin(), records.end(),
                               [idToEdit](const Data& record) { return record.id == idToEdit; });
        if (z != records.end()) {
            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, z->name);
        } else {
            cout << "Record not found.\n";
        }
    }

    void sortRecords() {
        sort(records.begin(), records.end(),
                  [](const Data& a, const Data& b) { return a.id < b.id; });
    }

    void displayRecords() const {
        for (const auto& record : records) {
            cout << "ID: " << record.id << " | Name: " << record.name << endl;
        }
    }

private:
    vector<Data> records;
};

int main() {
    Record recordManager;
    int choice;

    do {
        cout << "\nRecord Management System:\n"
                  << "1. Add Record\n"
                  << "2. Delete Record\n"
                  << "3. Edit Record\n"
                  << "4. Sort Records\n"
                  << "5. Display Records\n"
                  << "0. Exit\n"
                  << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                recordManager.addRecord();
                break;
            case 2:
                recordManager.deleteRecord();
                break;
            case 3:
                recordManager.editRecord();
                break;
            case 4:
                recordManager.sortRecords();
                break;
            case 5:
                recordManager.displayRecords();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Wrong choice!\n";
        }
    } while (choice != 0);

    return 0;
}
