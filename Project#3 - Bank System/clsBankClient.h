#pragma once
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include <string>
class clsBankClient : public clsPerson
{
private:
    enum enMode { EmptyMode = 0, UpdateMode = 1,AddNewMode = 2 };
    
	enMode _Mode;

	string _AccountNumber;
	string _PINCode;
	float _Balance;
    bool _MarkToDelete = false;
    inline static const string _Delim = "/##/";
    inline static const string _ClientsFileName = "Clients.txt";
    inline static vector <clsBankClient> _vClients;

    static clsBankClient _ConvertLineToClientObject(const string& Line) {
        vector <string> vClientInfo = clsString::SeperateWords(Line, _Delim);
        return clsBankClient(UpdateMode, vClientInfo[0], vClientInfo[1], vClientInfo[2], vClientInfo[3],
            vClientInfo[4], vClientInfo[5], stod(vClientInfo[6]));

    }

    static void _LoadFileToVector() {
        if (!_vClients.empty()) 
            return;
        
        fstream MyFile(_ClientsFileName, ios::in);
        string line;
        if (MyFile.is_open()) {

            while (getline(MyFile, line)) {

                _vClients.push_back(_ConvertLineToClientObject(line));
            }
            MyFile.close();
        }
        
    }

    static clsBankClient _FindClient(const string& AccountNumber, const string& PIN = "", bool WithPIN = false) {
        _LoadFileToVector();
        for (const clsBankClient& Client : _vClients) {
            if (Client.getAccountNumber() == AccountNumber && (!WithPIN || Client.getPINCode() == PIN)) {
                return Client;
            }
        }
        
        return _ReturnEmptyClientObject();
    }

    static clsBankClient _ReturnEmptyClientObject() {
        return clsBankClient(EmptyMode, "", "", "", "", "", "", 0);

    }

    string _ObjectToLine(const clsBankClient & Client ){
        string line = "";

        line += Client.getFirstName() + _Delim;
        line += Client.getLastName() + _Delim;
        line += Client.getEmail() + _Delim;
        line += Client.getPhone() + _Delim;
        line += Client.getAccountNumber() + _Delim;
        line += Client.getPINCode() + _Delim;
        line += to_string(Client.getBalance());

        return line;
    }
    void _SaveLineToFile(const string& line , bool Overwrite) {
        fstream MyFile(_ClientsFileName, Overwrite ? ios::out : ios::out | ios::app);

        if (MyFile.is_open()) {

            MyFile << line << endl;
        }
        MyFile.close();
    }

    void _UpdateFile(bool Overwrite) {
        
        bool WrittenToFile = false;
        for (const clsBankClient& Client : _vClients) {
            if (!Client._MarkToDelete) {
                string line = _ObjectToLine(Client);
                _SaveLineToFile(line, Overwrite);
                Overwrite = false;
                WrittenToFile = true;
           }

            if (!WrittenToFile) {
                _SaveLineToFile("",true);
            }
         
        }
  
    }
    void _UpdateClient() {
        

        for (clsBankClient& Client : _vClients) {
            if (Client.getAccountNumber() == getAccountNumber()) {
                Client = *this;
                break;
            }
        }

        _UpdateFile(true);
    }

    void _AddNewClient() {
        string line = _ObjectToLine(*this);
        _SaveLineToFile(line, false);
        _Mode = UpdateMode;
        _vClients.push_back(*this);


    }


public:
    
    clsBankClient(enMode Mode,
        const string& FirstName,
        const string& LastName,
        const string& Email,
        const string& Phone,
        const string& AccountNumber,
        const string& PINCode,
        float Balance)
        : clsPerson(FirstName, LastName, Email, Phone),
        _Mode(Mode),
        _AccountNumber(AccountNumber),
        _PINCode(PINCode),
        _Balance(Balance) {}

    bool isEmpty() const { return _Mode == EmptyMode; }
    bool isDeleted() const { return _Mode == EmptyMode;}
    void setPINCode(const string& PINCode) { _PINCode = PINCode; }
    void setBalance(const float Balance) { _Balance = Balance; }
    string getAccountNumber() const { return _AccountNumber; }
    string getPINCode() const { return _PINCode; }
    string getFullName() const { return getFirstName()+ " "+getLastName(); }
    float getBalance() const { return _Balance; }

    void Print() const {
        cout << "\n\nClient Information:";
        cout << "\nFirst name:    " << getFirstName();
        cout << "\nLast name:     " << getLastName();
        cout << "\nEmail:         " << getEmail();
        cout << "\nPhone:         " << getPhone();
        cout << "\nAccount number:" << _AccountNumber;
        cout << "\nPIN:           " << _PINCode;
        cout << "\nBalance:       " << _Balance;
        cout << endl;
    }

    static clsBankClient Find(const string& AccountNumber) {
        
        return _FindClient(AccountNumber);
    }
    static clsBankClient Find(const string& AccountNumber, const string& PIN) {
      
        return _FindClient(AccountNumber, PIN, true);
    }
    static bool isClientExist(const string& AccountNumber) {

        return !Find(AccountNumber).isEmpty();
    }

    enum enSaveStatus { FailedEmptyObject = 0, Success = 1,AccountAlreadyExist = 2 };
    enSaveStatus Save() {
        _LoadFileToVector();
        switch (_Mode) {

        case enMode::EmptyMode:
            return enSaveStatus::FailedEmptyObject;
        case enMode::UpdateMode:
            _UpdateClient();
            return enSaveStatus::Success;
        case enMode::AddNewMode:
            if (isClientExist(_AccountNumber))
                return enSaveStatus::AccountAlreadyExist;
            else {
                _AddNewClient();
                
                return enSaveStatus::Success;
            }

        }

    }


    void Delete() {
        _MarkToDelete = true;
        _UpdateClient();
        *this = _ReturnEmptyClientObject();
   
    }

    static clsBankClient getAddNewClientObject(const string& AccountNumber) {
        return clsBankClient{ enMode::AddNewMode,"","","","",AccountNumber,"",0 };
    }
    static vector<clsBankClient> GetClientsList() {
        _LoadFileToVector();
        return _vClients;
    }

                  
    static double getTotalBalances() {
        double TotalBalances = 0;

        _LoadFileToVector();

        for (const clsBankClient& Client : _vClients) {
            TotalBalances += Client.getBalance();
        }
        return TotalBalances;
    }
};

