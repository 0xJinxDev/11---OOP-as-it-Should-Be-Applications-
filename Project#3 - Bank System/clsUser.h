#pragma once
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
class clsUser : public clsPerson
{

private:
   
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;
    bool _MarkedForDelete = false;
    inline static vector <clsUser> _vUsers;
    inline static const string _Delim = "/##/";
    inline static const string _UsersFileName = "Users.txt";

    static clsUser _ConvertLineToObject(const string& Line) {
        vector <string> vUserInfo = clsString::SeperateWords(Line, _Delim);

        if (vUserInfo.size() == 7) {
            return clsUser(UpdateMode, vUserInfo[0], vUserInfo[1], vUserInfo[2], vUserInfo[3], vUserInfo[4], vUserInfo[5], stoi(vUserInfo[6]));
        }
       return _ReturnEmptyUserObject();
    }

    static clsUser _ReturnEmptyUserObject() {
        return clsUser(EmptyMode, "", "", "", "", "", "", 0);
    }

    string _ConvertObjectToLine(const clsUser& User) {
        string line = "";

        line += User.getFirstName() + _Delim;
        line += User.getLastName() + _Delim;
        line += User.getEmail() + _Delim;
        line += User.getPhone() + _Delim;
        line += User.getUserName() + _Delim;
        line += User.getPassword() + _Delim;
        line += to_string(User.getPermissions());

        return line;
    }
    void _SaveLineToFile(const string& Line ,bool OverWrite) {

        fstream MyFile(_UsersFileName, OverWrite ? ios::out : ios::out | ios::app);

        if (MyFile.is_open()) {
            MyFile << Line << endl;
        }
        MyFile.close();

    }

    static void _LoadFileToVector() {
        if (!_vUsers.empty())
            return;

        fstream MyFile(_UsersFileName, ios::in);
        string line;

        if (MyFile.is_open()) {
            while (getline(MyFile, line)) {
                if(line != "")
                _vUsers.push_back(_ConvertLineToObject(line));
            }
        }

        MyFile.close();

    }
    static clsUser _FindUser(const string& Username, const string& Password = "", bool WithPassword = false) {
        _LoadFileToVector();
        for (const clsUser& User : _vUsers) {
            if (User.getUserName() == Username && (!WithPassword || User.getPassword() == Password)) {
                return User;
            }
        }

        return _ReturnEmptyUserObject();
    }

    void _UpdateFile(bool Overwrite)
    {
        _vUsers.erase(
            remove_if(_vUsers.begin(), _vUsers.end(),
                [](clsUser& User)
                {
                    return User._MarkedForDelete;
                }),
            _vUsers.end()
        );

        if (_vUsers.empty())
        {
            _SaveLineToFile("", true);
            return;
        }

        for (clsUser& User : _vUsers)
        {
            _SaveLineToFile(_ConvertObjectToLine(User), Overwrite);
            Overwrite = false;
        }
    }

    void _UpdateUser() {

        for (clsUser& User : _vUsers) {

            if (User.getUserName() == getUserName()) {
                User = *this;
                break;
            }
        }
        _UpdateFile(true);
    }

    void _AddNewUser() {
        string line = _ConvertObjectToLine(*this);
        _SaveLineToFile(line, false);
        _Mode = UpdateMode;
        _vUsers.push_back(*this);

    }
public:

    clsUser(enMode Mode,
        const string& FirstName,
        const string& LastName,
        const string& Email,
        const string& Phone,
        const string& Username,
        const string& Password,
        int Permissions)
        :clsPerson(FirstName,LastName,Email,Phone),
        _Mode(Mode),
        _UserName(Username),
        _Password(Password),
        _Permissions(Permissions){}
    enum enPermissions
    {
        pShowClientList = 1 << 0,
        pAddNewClient = 1 << 1,
        pDeleteClient = 1 << 2,
        pUpdateClient = 1 << 3,
        pFindClient = 1 << 4,
        pTransactions = 1 << 5,
        pManageUsers = 1 << 6
    };

    static bool IsAdmin(short Privilege)
    {
        short AllPermissions =
            pShowClientList |
            pAddNewClient |
            pDeleteClient |
            pUpdateClient |
            pFindClient |
            pTransactions |
            pManageUsers;

        return Privilege == AllPermissions;
    }

    void setUserName(const string& Username) { _UserName = Username; }
    void setPassword(const string& Password) { _Password = Password; }
    void setPermissions(int Permissions) { _Permissions = Permissions; }
    string getUserName() const { return _UserName; }
    string getPassword() const { return _Password; }
    string getFullName() const { return getFirstName(); + " " + getLastName(); }
    int getPermissions() const { return _Permissions; }

    bool isEmpty() const { return _Mode == EmptyMode; }
    bool isDeleted() const { return _Mode == EmptyMode; }

    static clsUser Find(const string& Username) {

        return _FindUser(Username);
    }
    static clsUser Find(const string& Username, const string& Password) {

        return _FindUser(Username, Password, true);
    }
    static bool isUserExist(const string& Username) {

        return !Find(Username).isEmpty();
    }
    enum enSaveResult { FailedEmptyObject = 0, Success = 1, UserAlreadyExist = 2 };
    enSaveResult Save()
    {
        _LoadFileToVector();

        switch (_Mode)
        {

        case EmptyMode: return FailedEmptyObject;
        case UpdateMode: _UpdateUser();  return Success;
        case AddNewMode:
            if (isUserExist(_UserName))
                return UserAlreadyExist;
            else
                _AddNewUser();

            return Success;

        }

        return FailedEmptyObject;
    }

    void Delete()
    {
        _MarkedForDelete = true;
        _UpdateUser();
        *this = _ReturnEmptyUserObject();
    }

    static clsUser GetAddNewUserObject(const string& Username)
    {
        return clsUser(AddNewMode, "", "", "", "", Username, "", 0);
    }

    static vector<clsUser> GetUsersList()
    {
        _LoadFileToVector();
        return _vUsers;
    }
    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->getPermissions() == -1)
        {
            return true;
        }

        return ((this->getPermissions() & Permission) == Permission);
    }
};

