#include <iostream>
#include <map>
#include <string>

using namespace std;

void call_patient(map<string, string> &registry)
{
    map<string, string>::iterator caller = registry.begin();
    cout << "Calling patient: " << caller->second << endl;
    registry.erase(caller);
}

void add_patient(map<string, string> &registry, string last_name, int &count)
{
    cout << "Input patient`s last name: ";
    cin >> last_name;
    registry.insert(pair<string, string> (last_name + to_string(count), last_name));
    count++;
}

int main()
{
    string command;
    string last_name;
    int count = 0;
    map<string, string> registry;

    cout << "Enter command (next, new or exit): ";
    cin >> command;

    while (command != "exit")
    {
        if (command == "next")
        {
            if (registry.empty())
            {
                cout << "Registry is empty!" << endl;
                break;
            }
            call_patient(registry);
            cout << endl << "Enter command (next, new or exit): ";
            cin >> command;
        }
        else if (command == "new")
        {
            add_patient(registry, last_name, count);
            cout << endl << "Enter command (next, new or exit): ";
            cin >> command;
        }
        else
        {
            cerr << "Unknown command" << endl;
            cout << "Enter command (next, new or exit): ";
            cin >> command;
        }
    }
}