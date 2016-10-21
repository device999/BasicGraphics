#include<algorithm>
#include<iostream>
#include<map>
#include <numeric>
#include<string>
#include<vector>

using namespace std;
void sortingTel(vector<pair<string,string>>& array)
{
    sort(array.begin(), array.end());
    for (vector<pair<string, string>>::iterator it1 = array.begin(); it1 != array.end(); ++it1)
    {
        cout << it1->first.c_str() << " " << it1->second.c_str() << endl;
    }
}

string toLower(string satze)
{
    std::transform(satze.begin(), satze.end(), satze.begin(), (int (*)(int))std::tolower);
    return satze;
}

int main()
{
    map<string, string> telephoneBook;
    map<string, string>::iterator it1;
    string test = "Standard Template Library STL uses C++ templates to "
            "abstract away MANY differences of datatype implementations while not introducing "
            "ANY overhead!";
    cout<<toLower(test) <<endl;


    telephoneBook[toLower("Max")] = "0157/123456";
    telephoneBook[toLower("Stefan")] = "0228/3734342";
    telephoneBook[toLower("Anne")] = "0228/7629431";
    telephoneBook[toLower("Office")] = "0228/272930";
    telephoneBook[toLower("Bank")] = "0228/2223332";
    for (it1 = telephoneBook.begin(); it1 != telephoneBook.end(); ++it1)
    {
        cout << it1->first.c_str() << "  " << it1->second.c_str() << endl;
    }
    cout << endl;
    cout<<"Welcome to our telephone service :)"<<endl;
    while(true)
    {
        cout<<"Which number you want to look for??"<<endl;
        cout<<"If you want to leave the searching, please type 0"<<endl;
        string name;
        cout<<"enter the name = ";
        cin>>name;
        if (name!="0")
        {
            name = toLower(name);
            it1 = telephoneBook.find(name);
            if (it1 == telephoneBook.end())
            {
                string newNumber;
                cout << "This person wasnt't found,please add him number "<<endl;
                cout << "Enter telephone numtber: ";
                cin>>newNumber;
                telephoneBook[name] = newNumber;
                cout << endl;
            }
            else
            {
                cout << it1->first.c_str() << " " << it1->second.c_str() << endl;
            }

        }
        else
        {
            break;
        }
    }
    cout << "Here we go" << endl;
    vector<pair<string,string>> sortD;
    for (it1 = telephoneBook.begin(); it1 != telephoneBook.end(); ++it1)
    {
        pair<string, string> telephoneBook(it1->second.c_str(), it1->first.c_str());
        sortD.push_back(telephoneBook);
        cout << it1->second.c_str() << " " << it1->first.c_str() << endl;
    }
    cout << "-------------" << endl;
    sortingTel(sortD);
    cout << "-------------" << endl;
    reverse(sortD.begin(),sortD.end());
    for(vector<pair<string,string>>::iterator it1 = sortD.begin();it1!=sortD.end();++it1)
    {
        cout<<it1->first.c_str()<<" "<<it1->second.c_str()<<endl;
    }

}
