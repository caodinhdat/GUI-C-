#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<stdio.h>
using namespace std;
class Date
{
public:
	int day;
	int month;
	int year;
};
class Employee_Infor
{
public:
	Employee_Infor()
	{}
	Employee_Infor(int ID, string roomID, string employeeID, string employeeName, string address, string birthday, string startDay, string level, string phoneNumber)
	{
		this->ID = ID;
		this->roomID = roomID;
		this->employeeID = employeeID;
		this->employeeName = employeeName;
		this->address = address;
		this->birthday = birthday;
		this->startDay = startDay;
		this->level = level;
		this->phoneNumber = phoneNumber;
	}
	int ID;
	string roomID;
	string employeeID;
	string employeeName;
	string address;
	string birthday;
	string startDay;
	string level;
	string phoneNumber;
	void setID(int ID)
	{
		this->ID = ID;
	}
	int getID()
	{
		return ID;
	}
	void setRoomID(string roomID)
	{
		this->roomID = roomID;
	}
	string getRoomID()
	{
		return roomID;
	}
	void setEmployeeID(string employeeID)
	{
		this->employeeID = employeeID;
	}
	string getEmployeeID()
	{
		return employeeID;
	}
	void setEmployeeName(string employeeName)
	{
		this->employeeName = employeeName;
	}
	string getemployeeName()
	{
		return employeeName;
	}
	void setAddress(string address)
	{
		this->address = address;
	}
	string getAddress()
	{
		return address;
	}
	void setBirthday(string birthday)
	{
		this->birthday = birthday;
	}
	string getBirthday()
	{
		return birthday;
	}
	void setStartday(string startDay)
	{
		this->startDay = startDay;
	}
	string getStartday()
	{
		return startDay;
	}
	void setLevel(string level)
	{
		this->level = level;
	}
	string getLevel()
	{
		return level;
	}
	void setPhonenumber(string phoneNumber)
	{
		this->phoneNumber = phoneNumber;
	}
	string getPhonenumber()
	{
		return phoneNumber;
	}
};
class Room_Infor
{
public:
	Room_Infor()
	{}
	Room_Infor(int ID, string roomID, string roomName)
	{
		this->ID = ID;
		this->roomID = roomID;
		this->roomName = roomName;
	}
	int ID;
	string roomID;
	string roomName;
	void setID(int ID)
	{
		this->ID = ID;
	}
	int getID()
	{
		return ID;
	}
	void setRoomID(string roomID)
	{
		this->roomID = roomID;
	}
	string getRoomID()
	{
		return roomID;
	}
	void setRoomName(string roomName)
	{
		this->roomName = roomName;
	}
	string getRoomname()
	{
		return roomName;
	}
};
class Project_Final
{
private:
	string roomID;
	string roomName;
	string employeeID;
	string employeeName;
	string address;
	string birthday;
	string startDay;
	string level;
	string phoneNumber;

public:
	vector<Employee_Infor> employeeInfor;
	vector<Room_Infor> roomInfor;
	vector<int> vtSortbyID;
	vector<string> vtSortbyName;
	vector<string> vtSortbyBirth;
	vector<Date> dateE;
	vector<int> allDate;
	void menu()
	{

	}
	void openFile(fstream& file)
	{
		file.open("D:\\Code Block\\input.txt", ios::in);
		if (!file)
		{
			cout << "File doesn't exist!\n";
		}
	}
	void readFile()
	{
		fstream file;
		openFile(file);
		string element;
		vector<string> vt;
		char ch;
		while (file >> noskipws >> ch)
		{
			element += ch;
			if (ch == ',')
			{
				vt.push_back(element.substr(0, element.size() - 1));
				element = "";
			}
			if (ch == '\n')
			{
				vt.push_back(element.substr(0, element.size() - 1));
				element = "";
			}
		}
		for (int i = 0; i < vt.size(); i += 10)
		{
			Employee_Infor elementE = { stoi(vt[i]),vt[i + 1],vt[i + 3],vt[i + 4],vt[i + 5],vt[i + 6],vt[i + 7],vt[i + 8],vt[i + 9] };
			employeeInfor.push_back(elementE);
			int IDRoom = roomInfor.size() + 1;
			Room_Infor elementR = { IDRoom,vt[i + 1],vt[i + 2] };
			int check = false;
			for (int i = 0; i < roomInfor.size(); i++)
			{
				if (roomInfor[i].getRoomID() == elementR.getRoomID())
				{
					check = true;
					break;
				}
			}
			if (!check)
			{
				roomInfor.push_back(elementR);
			}
		}
	}
	template <class val>
	void swap(val& val1, val& val2)
	{
		val tmp = val1;
		val1 = val2;
		val2 = tmp;
	}
	string inputRoomID()
	{
		string roomID;
		while (true)
		{
			cout << "Enter Room ID: ";
			getline(cin,roomID);
			if (checkRoomID(roomID))
			{
				cout << "Can not find Room ID!\n";
			}
			else
			{
				break;
			}
		}
		return roomID;
	}
	string inputRoomIDForAdd()
	{
		string roomID;
		while (true)
		{
			cout << "Enter Room ID: ";
			getline(cin, roomID);
			if (!checkRoomID(roomID))
			{
				cout << "Room ID already exist!\n";
			}
			else
			{
				break;
			}
		}
		return roomID;
	}
	string inputRoomName(string roomID)
	{
		string roomName;
		while (true)
		{
			cout << "Enter Room Name: ";
			getline(cin, roomName);
			if (checkDigit(roomName))
			{
				cout << "Format Room Name is not valid!\n";
			}
			else if (checkroomMatch(roomID, roomName) || !checkAddRoom(roomID,roomName))
			{
				cout << "Room ID and Room Name is not match\n";
			}
			else
			{
				break;
			}
		}
		return roomName;
	}
	string inputRoomName()
	{
		while (true)
		{
			cout << "\nEnter Room Name: ";
			getline(cin, roomName);
			if (checkDigit(roomName))
			{
				cout << "Format Room Name is not valid!\n";
			}
			else
			{
				break;
			}
		}
		return roomName;
	}
	string inputRoomNametoEdit(string roomID)
	{
		while (true)
		{
			cout << "\nEnter Room Name: ";
			getline(cin, roomName);
			if (checkDigit(roomName))
			{
				cout << "Format Room Name is not valid!\n";
			}
			else if (!checkAddRoom(roomID, roomName))
			{
				cout << "Room ID and Room Name is not match\n";
			}
			else
			{
				break;
			}
		}
		return roomName;
	}
	bool checkAddRoom(string roomID, string roomName)
	{
		bool checkMatch = true;
		for (int i = 0; i < roomInfor.size(); i++)
		{
			if (roomName == roomInfor[i].getRoomname())
			{
				if (roomID == roomInfor[i].getRoomID())
				{
					checkMatch = true;
				}
				else
				{
					checkMatch = false;
				}
				break;
			}
		}
		return checkMatch;
	}
	void RoomInformation()
	{
		cin.ignore();
		cout << "Enter information room \n";
		string roomID = inputRoomIDForAdd();
		string roomName = inputRoomName(roomID);
		int IDRoom = roomInfor.size() + 1;
		Room_Infor roomInitial;
		roomInitial.setID(IDRoom);
		roomInitial.setRoomID(roomID);
		roomInitial.setRoomName(roomName);
		bool checkRoom = checkRoomID(roomID);
		if (checkRoom)
		{
			roomInfor.push_back(roomInitial);
			cout << "Completed!\n";
		}
		else
		{
			cout << "Room ID already exist!\n";
		}
	}
	void menuEmployeeEdit()
	{
		cout << "1. Employee Name\n";
		cout << "2. Employee Address\n";
		cout << "3. Employee Level\n";
		cout << "4. Employee Phone Number\n";
		cout << "5. Employee Room ID\n";
	}
	void printInfor(Employee_Infor element)
	{
		if (element.getAddress().size() < 8)
		{
			cout << element.getID() << "\t" << element.getEmployeeID() << "\t\t" << element.getemployeeName() << "\t\t" << element.getAddress() << "\t\t" << element.getBirthday() << "\t";
			cout << element.getStartday() << "\t" << element.getLevel() << "\t\t" << element.getPhonenumber() << "\t" << element.getRoomID() << "\n";
		}
		else
		{
			cout << element.getID() << "\t" << element.getEmployeeID() << "\t\t" << element.getemployeeName() << "\t\t" << element.getAddress() << "\t" << element.getBirthday() << "\t";
			cout << element.getStartday() << "\t" << element.getLevel() << "\t\t" << element.getPhonenumber() << "\t" << element.getRoomID() << "\n";
		}
	}
	void displayEmployeeInfor()
	{
		cout << "Information Employee!\n";
		cout << "ID\t" << "EmployeeID\t" << "Name\t\t" << "Address\t\t" << "Birthday\t" << "JoinDate\t" << "Level\t\t" << "PhoneNumber\t" << "RoomID\n";
		for (int i = 0; i < employeeInfor.size(); i++)
		{
			printInfor(employeeInfor[i]);
		}
	}
	void displayRoomInfor()
	{
		cout << "Information Room!\n";
		cout << "ID\t" << "RoomID\t\t" << "RoomName\n";
		for (int i = 0; i < roomInfor.size(); i++)
		{
			cout << roomInfor[i].getID() << "\t" << roomInfor[i].getRoomID() << "\t\t" << roomInfor[i].getRoomname() << "\n";
		}
	}
	string inputEmployeeIDtoEdit()
	{
		string IDEditE;
		while (true)
		{
			cout << "Enter employee ID : \n";
			getline(cin,IDEditE);
			if (checkNotDigit(IDEditE))
			{
				cout << "ID must be a number!\n";
			}
			else
			{
				break;
			}
		}
		return IDEditE;
	}
	string inputEmployeeIDtoAdd()
	{
		string IDEditE;
		while (true)
		{
			cout << "Enter employee ID : ";
			getline(cin, IDEditE);
			if (checkNotDigit(IDEditE))
			{
				cout << "ID must be a number!\n";
			}
			else if (checkDupEmployee(IDEditE))
			{
				cout << "ID already exist\n";
			}
			else
			{
				break;
			}
		}
		return IDEditE;
	}
	string inputEmployeeName()
	{
		string employeeName;
		while (true)
		{
			cout << "Enter Employee Name: ";
			getline(cin, employeeName);
			if (checkDigit(employeeName))
			{
				cout << "Name is not valid!\n";
			}
			else
			{
				break;
			}
		}
		return employeeName;
	}
	string inputEmployeeAdd()
	{
		string employeeAddA;
		while (true)
		{
			cout << "Enter Employee Address: ";
			getline(cin, employeeAddA);
			if (checkDigit(employeeAddA))
			{
				cout << "Address is not valid!\n";
			}
			else
			{
				break;
			}
		}
		return employeeAddA;
	}
	string inputEmployeeBirth()
	{
		string employeeBirthA;
		while (true)
		{
			cout << "Enter Employee Birthday (dd/mm/yyyy): ";
			getline(cin, employeeBirthA);
			if (!checkDate(employeeBirthA))
			{
				cout << "Format date is wrong!\n";
			}
			else
			{
				break;
			}
		}
		return employeeBirthA;
	}
	string inputJoinDate()
	{
		string employeeJoinA;
		while (true)
		{
			cout << "Enter Employee Join Date (dd/mm/yyyy): ";
			getline(cin, employeeJoinA);
			if (!checkDate(employeeJoinA))
			{
				cout << "Format date is wrong!\n";
			}
			else
			{
				break;
			}
		}
		return employeeJoinA;
	}
	string inputEmployeeLevel()
	{
		string employeeLevelA;
		while (true)
		{
			cout << "Enter Employee Level (Intern, Fresher, Junior, Middle, Senior, Manager, Leader, Other): ";
			getline(cin, employeeLevelA);
			if (checkDigit(employeeLevelA))
			{
				cout << "Format level is not valid!\n";
			}
			else
			{
				break;
			}
		}
		return employeeLevelA;
	}
	string inputPhoneNumber()
	{
		string employeePhoneA;
		while (true)
		{
			cout << "Enter Employee Phone Number: ";
			getline(cin, employeePhoneA);
			if (checkNotDigit(employeePhoneA))
			{
				cout << "Format phone is wrong, it must be a number!\n";
			}
			else
			{
				break;
			}
		}
		return employeePhoneA;
	}
	void EditInformation_Employee()
	{
		cin.ignore();
		displayEmployeeInfor();
		int indexID = 0;
		while (true)
		{
			string IDEditE = inputEmployeeIDtoEdit();
			for (int i = 0; i < employeeInfor.size(); i++)
			{
				if (employeeInfor[i].getEmployeeID() == IDEditE)
				{
					indexID = employeeInfor[i].getID();
					break;
				}
			}
			if (indexID == 0)
			{
				cout << "Can not find employee!\n";
			}
			else
			{
				break;
			}
		}
		menuEmployeeEdit();
		string chooseEditS;
		while (true)
		{
			cout << "Please enter option you want to edit: \n";
			getline(cin,chooseEditS);
			if (checkNotDigit(chooseEditS))
			{
				cout << "Wrong input, please re-enter\n";
			}
			else
			{
				break;
			}
		}
		int chooseEdit = stoi(chooseEditS);
		switch (chooseEdit)
		{
		case 1:
		{
			string newNameE = inputEmployeeName();
			employeeInfor[indexID - 1].setEmployeeName(newNameE);
			cout << "Completed!\n";
			break;
		}
		case 2:
		{
			string newAddE = inputEmployeeAdd();
			employeeInfor[indexID - 1].setAddress(newAddE);
			cout << "Completed!\n";
			break;
		}
		case 3:
		{
			string newLevelE = inputEmployeeLevel();
			employeeInfor[indexID - 1].setLevel(newLevelE);
			cout << "Completed!\n";
			break;
		}
		case 4:
		{
			string newPhoneE = inputPhoneNumber();
			employeeInfor[indexID - 1].setPhonenumber(newPhoneE);
			cout << "Completed!\n";
			break;
		}
		case 5:
		{
			string newRoomE = inputRoomID();
			employeeInfor[indexID - 1].setRoomID(newRoomE);
			cout << "Completed!\n";
			break;
		}
		default:
			cout << "No change!\n";
			break;
		}
	}
	void EditInformation_Room()
	{
		cin.ignore();
		displayRoomInfor();
		string IDRoomE = inputRoomID();
		int indexID = 0;
		for (int i = 0; i < roomInfor.size(); i++)
		{
			if (roomInfor[i].getRoomID() == IDRoomE)
			{
				indexID = roomInfor[i].getID();
				break;
			}
		}
		if (indexID == 0)
		{
			cout << "Can not find employee!\n";
		}
		else
		{
			string newRoomE = inputRoomNametoEdit(IDRoomE);
			roomInfor[indexID - 1].setRoomName(newRoomE);
		}
	}
	void displayEmployeeByID()
	{
		vtSortbyID.clear();
		for (int i = 0; i < employeeInfor.size(); i++)
		{
			vtSortbyID.push_back(stoi(employeeInfor[i].getEmployeeID()));
		}
		for (int i = 0; i < vtSortbyID.size() - 1; i++)
		{
			for (int j = i + 1; j < vtSortbyID.size(); j++)
			{
				if (vtSortbyID[i] > vtSortbyID[j])
				{
					swap(vtSortbyID[i], vtSortbyID[j]);
				}
			}
		}
		cout << "Sort by employee ID!\n";
		cout << "ID\t" << "EmployeeID\t" << "Name\t\t" << "Address\t\t" << "Birthday\t" << "JoinDate\t" << "Level\t\t" << "PhoneNumber\t" << "RoomID\n";
		for (int j = 0; j < vtSortbyID.size(); j++)
		{
			for (int i = 0; i < employeeInfor.size(); i++)
			{
				if (stoi(employeeInfor[i].getEmployeeID()) == vtSortbyID[j])
				{
					printInfor(employeeInfor[i]);
				}
			}
		}
		vtSortbyID.clear();
	}
	void displayEmployeeByName(string choose)
	{
		vtSortbyName.clear();
		for (int i = 0; i < employeeInfor.size(); i++)
		{
			vtSortbyName.push_back(employeeInfor[i].getemployeeName());
		}
		for (int i = 0; i < vtSortbyName.size() - 1; i++)
		{
			for (int j = i + 1; j < vtSortbyName.size(); j++)
			{
				if (vtSortbyName[i] > vtSortbyName[j])
				{
					swap(vtSortbyName[i], vtSortbyName[j]);
				}
			}
		}
		cout << "ID\t" << "EmployeeID\t" << "Name\t\t" << "Address\t\t" << "Birthday\t" << "JoinDate\t" << "Level\t\t" << "PhoneNumber\t" << "RoomID\n";
		if (choose == "1")
		{
			cout << "Ascending Order By Name!\n";
			for (int j = 0; j < vtSortbyName.size(); j++)
			{
				for (int i = 0; i < employeeInfor.size(); i++)
				{
					if (employeeInfor[i].getemployeeName() == vtSortbyName[j])
					{
						printInfor(employeeInfor[i]);
					}
				}
			}
			vtSortbyName.clear();
		}
		else if (choose == "2")
		{
			cout << "Descending Order By Name!\n";
			for (int j = vtSortbyName.size() - 1; j >= 0; j--)
			{
				for (int i = 0; i < employeeInfor.size(); i++)
				{
					if (employeeInfor[i].getemployeeName() == vtSortbyName[j])
					{
						printInfor(employeeInfor[i]);
					}
				}
			}
			vtSortbyName.clear();
		}
	}
	bool compareDate(Date& date1, Date& date2)
	{
		if (date1.year < date2.year)
			return true;
		if (date1.year == date2.year && date1.month < date2.month)
			return true;
		if (date1.year == date2.year && date1.month == date2.month &&
			date1.day < date2.day)
			return true;
		return false;
	}
	void displayEmployeeByBirthday()
	{
		vtSortbyBirth.clear();
		for (int i = 0; i < employeeInfor.size(); i++)
		{
			vtSortbyBirth.push_back(employeeInfor[i].getBirthday());
		}
		for (int i = 0; i < vtSortbyBirth.size(); i++)
		{
			string element = "";
			for (int j = 0; j < vtSortbyBirth[i].size(); j++)
			{
				element += vtSortbyBirth[i][j];
				if (vtSortbyBirth[i][j] == '/')
				{
					allDate.push_back(stoi(element));
					element = "";
				}
			}
			allDate.push_back(stoi(element));
			element = "";
		}
		for (int i = 0; i < allDate.size(); i += 3)
		{
			Date newDate;
			newDate.day = allDate[i];
			newDate.month = allDate[i + 1];
			newDate.year = allDate[i + 2];
			dateE.push_back(newDate);
		}
		allDate.clear();
		for (int i = 0; i < dateE.size() - 1; i++)
		{
			for (int j = i + 1; j < dateE.size(); j++)
			{
				if (!compareDate(dateE[i], dateE[j]))
				{
					swap(dateE[i], dateE[j]);
				}
			}
		}
		vtSortbyBirth.clear();
		string eBirth = "";
		for (int i = 0; i < dateE.size(); i++)
		{
			eBirth = to_string(dateE[i].day) + "/" + to_string(dateE[i].month) + "/" + to_string(dateE[i].year);
			vtSortbyBirth.push_back(eBirth);
			eBirth = "";
		}
		dateE.clear();
		cout << "Sort by birthday!\n";
		cout << "ID\t" << "EmployeeID\t" << "Name\t\t" << "Address\t\t" << "Birthday\t" << "JoinDate\t" << "Level\t\t" << "PhoneNumber\t" << "RoomID\n";
		for (int j = 0; j < vtSortbyBirth.size(); j++)
		{
			for (int i = 0; i < employeeInfor.size(); i++)
			{
				if (employeeInfor[i].getBirthday() == vtSortbyBirth[j])
				{
					printInfor(employeeInfor[i]);
				}
			}
		}
		vtSortbyBirth.clear();
	}
	bool isMatchName(string s1, string s2)
	{
		vector<int> index;
		if (s1.size() > s2.size())
		{
			return false;
		}
		for (int i = 0; i < s2.size(); i++)
		{
			if (s2[i] == s1[0])
			{
				index.push_back(i);
			}
		}
		for (int i = 0; i < index.size(); i++)
		{
			int iter = index[i];
			if (s1.size() > s2.size() - iter)
			{
				continue;
			}
			for (int j = 0; j < s1.size(); j++)
			{
				if (s1[j] != s2[j + iter])
				{
					break;
				}
				if (j == s1.size() - 1)
				{
					return true;
				}
			}
		}
		return false;
	}
	bool checkRoomID(string roomID)
	{
		bool checkRID = true;
		for (int i = 0; i < roomInfor.size(); i++)
		{
			if (roomInfor[i].getRoomID() == roomID)
			{
				checkRID = false;
				break;
			}
		}
		return checkRID;
	}
	bool checkNotDigit(string val)
	{
		bool checkChar = false;
		for (int i = 0; i < val.size(); i++)
		{
			if (val[i] < '0' || val[i] > '9')
			{
				checkChar = true;
				break;
			}
		}
		return checkChar;
	}
	bool checkDigit(string val)
	{
		bool checkChar = false;
		for (int i = 0; i < val.size(); i++)
		{
			if (val[i] >= '0' && val[i] <= '9')
			{
				checkChar = true;
				break;
			}
		}
		return checkChar;
	}
	bool checkDupEmployee(string emID)
	{
		bool checkDup = false;
		for (int i = 0; i < employeeInfor.size(); i++)
		{
			if (emID == employeeInfor[i].getEmployeeID())
			{
				checkDup = true;
				break;
			}
		}
		return checkDup;
	}
	bool checkroomMatch(string roomID, string roomName)
	{
		bool checkMatch = false;
		for (int i = 0; i < roomInfor.size(); i++)
		{
			if (roomInfor[i].getRoomID() == roomID)
			{
				if (roomInfor[i].getRoomname() != roomName)
				{
					checkMatch = true;
					break;
				}
			}
		}
		return checkMatch;
	}
	void findEmployeeByName()
	{
		cin.ignore();
		string fName = inputEmployeeName();
		cout << "\nFind by name!\n";
		cout << "ID\t" << "EmployeeID\t" << "Name\t\t" << "Address\t\t" << "Birthday\t" << "JoinDate\t" << "Level\t\t" << "PhoneNumber\t" << "RoomID\n";
		for (int i = 0; i < employeeInfor.size(); i++)
		{
			if (isMatchName(fName, employeeInfor[i].getemployeeName()))
			{
				printInfor(employeeInfor[i]);
			}
		}
	}
	void findEmployeeByID()
	{
		cin.ignore();
		string findID = inputEmployeeIDtoEdit();
		cout << "\nFind by ID!\n";
		cout << "ID\t" << "EmployeeID\t" << "Name\t\t" << "Address\t\t" << "Birthday\t" << "JoinDate\t" << "Level\t\t" << "PhoneNumber\t" << "RoomID\n";
		for (int i = 0; i < employeeInfor.size(); i++)
		{
			if (employeeInfor[i].getEmployeeID() == findID)
			{
				printInfor(employeeInfor[i]);
			}
		}
	}
	bool checkDate(string date)
	{
		string str1 = "";
		string str2 = "";
		string str3 = "";
		int index = 0;
		int indexF = 0;
		int indexS = 0;
		for (int i = 0; i < date.size(); i++)
		{
			if (date[i] == '/' && index == 0)
			{
				index++;
				indexF = i;
				continue;
			}
			if (date[i] == '/' && index == 1)
			{
				index++;
				indexS = i;
				break;
			}
		}
		str1 = date.substr(0, indexF);
		str2 = date.substr(indexF + 1, indexS - indexF - 1);
		str3 = date.substr(indexS + 1, date.size() - 1);
		if (str1 == "" || str2 == "" || str3 == "")
		{
			return false;
		}
		if (index != 2)
		{
			return false;
		}
		if (stoi(str1) < 0 || stoi(str1) > 31)
		{
			return false;
		}
		if (stoi(str2) < 0 || stoi(str2) > 12)
		{
			return false;
		}
		if (stoi(str3) < 0 || stoi(str3) > 2023)
		{
			return false;
		}
		return true;
	}

	void EmployeeInformation()
	{
		string roomIDA;
		string roomNameA;
		string employeeIDA;
		string employeeNameA;
		string employeeAddA;
		string employeeBirthA;
		string employeeJoinA;
		string employeeLevelA;
		string employeePhoneA;
		cout << "Add Employee!\n";
		cout << "Please enter employee information: \n";
		cin.ignore();
		roomIDA = inputRoomIDForAdd();
		roomNameA = inputRoomName(roomIDA);
		employeeIDA = inputEmployeeIDtoAdd();
		employeeNameA = inputEmployeeName();
		employeeAddA = inputEmployeeAdd();
		employeeBirthA = inputEmployeeBirth();
		employeeJoinA = inputJoinDate();
		employeeLevelA = inputEmployeeLevel();
		employeePhoneA = inputPhoneNumber();
		int lastID = employeeInfor.size() + 1;
		int IDRoom = roomInfor.size() + 1;
		Employee_Infor newEmployee = { lastID, roomIDA, employeeIDA, employeeNameA, employeeAddA,employeeBirthA,employeeJoinA,employeeLevelA,employeePhoneA };
		Room_Infor newRoom = { IDRoom,roomIDA,roomNameA };
		int check = false;
		for (int i = 0; i < roomInfor.size(); i++)
		{
			if (roomInfor[i].getRoomID() == newRoom.getRoomID())
			{
				check = true;
				break;
			}
		}
		if (!check)
		{
			roomInfor.push_back(newRoom);
		}
		employeeInfor.push_back(newEmployee);
		cout << "Completed!\n";
	}
	void removeEmployee()
	{
		cin.ignore();
		cout << "Remove Employee!\n";
		string employeeIDR = inputEmployeeIDtoEdit();
		bool checkID = false;
		int index = 0;
		for (int i = 0; i < employeeInfor.size(); i++)
		{
			if (employeeIDR == employeeInfor[i].getEmployeeID())
			{
				index = i;
				checkID = true;
				break;
			}
		}
		if (!checkID)
		{
			cout << "Can not find employee!\n";
		}
		else
		{
			employeeInfor.erase(employeeInfor.begin() + index);
			cout << "Completed!\n";
		}
	}
	void saveFile()
	{
		string outFileEm;
		cout << "Enter file name you want to save employee information: ";
		cin.ignore();
		getline(cin,outFileEm);
		ofstream outEm("D:\\Code Block\\" + outFileEm);
		outEm << "ID\t" << "EmployeeID\t" << "Name\t\t" << "Address\t\t" << "Birthday\t" << "JoinDate\t" << "Level\t\t" << "PhoneNumber\t" << "RoomID\n";
		for (int i = 0; i < employeeInfor.size(); i++)
		{
			if (employeeInfor[i].getAddress().size() < 8)
			{
				outEm << employeeInfor[i].getID() << "\t" << employeeInfor[i].getEmployeeID() << "\t\t" << employeeInfor[i].getemployeeName() << "\t\t" << employeeInfor[i].getAddress() << "\t\t" << employeeInfor[i].getBirthday() << "\t";
				outEm << employeeInfor[i].getStartday() << "\t" << employeeInfor[i].getLevel() << "\t\t" << employeeInfor[i].getPhonenumber() << "\t" << employeeInfor[i].getRoomID() << "\n";
			}
			else
			{
				outEm << employeeInfor[i].getID() << "\t" << employeeInfor[i].getEmployeeID() << "\t\t" << employeeInfor[i].getemployeeName() << "\t\t" << employeeInfor[i].getAddress() << "\t" << employeeInfor[i].getBirthday() << "\t";
				outEm << employeeInfor[i].getStartday() << "\t" << employeeInfor[i].getLevel() << "\t\t" << employeeInfor[i].getPhonenumber() << "\t" << employeeInfor[i].getRoomID() << "\n";
			}
		}
		cout << "This file has been saved at D:\\Code Block\\ " << outFileEm << "\n";
		cout << "Enter file name you want to save room information: ";
		string outFileRoom;
		cin >> outFileRoom;
		ofstream outRoom("D:\\Code Block\\" + outFileRoom);
		outRoom << "ID\t" << "RoomID\t\t" << "RoomName\n";
		for (int i = 0; i < roomInfor.size(); i++)
		{
			outRoom << roomInfor[i].getID() << "\t" << roomInfor[i].getRoomID() << "\t\t" << roomInfor[i].getRoomname() << "\n";
		}
		cout << "This file has been saved at D:\\Code Block\\ " << outFileRoom << "\n";
	}
};
void pressAnyKey() {
	cout << "\n\nPress any character to continue...\n";
	char ch;
	cin >> ch;
	system("cls");
}
void menu()
{
	cout << "*************************PROGRAM - DATCD************************\n";
	cout << "*   1. Display Employee Information                            *\n";
	cout << "*   2. Display Room Information                                *\n";
	cout << "*   3. Add Employee                                            *\n";
	cout << "*   4. Add Room                                                *\n";
	cout << "*   5. Edit Employee Information                               *\n";
	cout << "*   6. Edit Room Information                                   *\n";
	cout << "*   7. Display Employee Information By:                        *\n";
	cout << "*       a. In order of employee ID                             *\n";
	cout << "*       b. In ascending order of names                         *\n";
	cout << "*       c. In descending order of names                        *\n";
	cout << "*       d. In order of date of birth                           *\n";
	cout << "*   8. Find Employee By:                                       *\n";
	cout << "*       a. Name                                                *\n";
	cout << "*       b. Employee ID                                         *\n";
	cout << "*   9. Remove Employee By ID                                   *\n";
	cout << "*   10. Exit                                                   *\n";
	cout << "****************************************************************\n";
}
int main()
{
	Project_Final fl;
	fl.readFile();
	bool check = true;
	while (true)
	{
		menu();
		string chooseOption;
		cout << "Enter option: ";
		cin >> chooseOption;
		if (chooseOption == "1")
		{
			fl.displayEmployeeInfor();
			pressAnyKey();
		}
		else if (chooseOption == "2")
		{
			fl.displayRoomInfor();
			pressAnyKey();
		}
		else if (chooseOption == "3")
		{
			fl.EmployeeInformation();
			pressAnyKey();
		}
		else if (chooseOption == "4")
		{
			fl.RoomInformation();
			pressAnyKey();
		}
		else if (chooseOption == "5")
		{
			fl.EditInformation_Employee();
			pressAnyKey();
		}
		else if (chooseOption == "6")
		{
			fl.EditInformation_Room();
			pressAnyKey();
		}
		else if (chooseOption == "7")
		{
			cout << "\na. In order of employee ID\n";
			cout << "b. In ascending order of names\n";
			cout << "c. In descending order of names\n";
			cout << "d. In order of date of birth\n\n";
			string innerChoose;
			cout << "Enter option: ";
			cin >> innerChoose;
			if (innerChoose == "a")
			{
				fl.displayEmployeeByID();
				pressAnyKey();
			}
			else if (innerChoose == "b")
			{
				fl.displayEmployeeByName("1");
				pressAnyKey();
			}
			else if (innerChoose == "c")
			{
				fl.displayEmployeeByName("2");
				pressAnyKey();
			}
			else if (innerChoose == "d")
			{
				fl.displayEmployeeByBirthday();
				pressAnyKey();
			}
			else
			{
				cout << "Wrong input!\n";
				pressAnyKey();
			}
		}
		else if (chooseOption == "8")
		{
			cout << "\na. Name\n";
			cout << "b.Employee ID \n\n";
			string innerChoose;
			cout << "Enter option: ";
			cin >> innerChoose;
			if (innerChoose == "a")
			{
				fl.findEmployeeByName();
				pressAnyKey();
			}
			else if (innerChoose == "b")
			{
				fl.findEmployeeByID();
				pressAnyKey();
			}
			else
			{
				cout << "Wrong input!\n";
				pressAnyKey();
			}
		}
		else if (chooseOption == "9")
		{
			fl.removeEmployee();
			pressAnyKey();
		}
		else if (chooseOption == "10")
		{
			cout << "Do you want to save information of room and employee!\n";
			string innerChoose;
			cout << "Please enter yes(y) or no(n)\n";
			cin >> innerChoose;
			if (innerChoose == "y")
			{
				fl.saveFile();
			}
			break;
		}
		else
		{
			cout << "Wrong input!\n";
		}
	}
}
