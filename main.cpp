#include <iostream>
#include <map>
#include <string>

using namespace std;

void call_patient(map<string, int> &registry)
{
    string caller = registry.begin()->first;
    if (registry.begin()->second == 1)
    {
        registry.erase(registry.begin());
    }
    else
    {
        registry.begin()->second--;
    }

    cout << "Calling " << caller << endl;
}

void add_patient(map<string, int> &registry, string last_name)
{
    map<string, int>::iterator it_patient = registry.find(last_name);
    if (it_patient == registry.end())
    {
        registry[last_name] = 1;
    }
    else
    {
        registry[last_name] += 1;
    }
}

int main()
{
    string command;
    map<string, int> registry;

    while (command != "exit")
    {
        cout << "Enter command: ";
        cin >> command;

        if (command == "next")
        {
            if (registry.empty())
            {
                cout << "No patients, enter exit or last name: ";
            }
            call_patient(registry);
        }
        else
        {
            add_patient(registry, command);
        }
    }
}