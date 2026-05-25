#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Without virtual

class TopLeft {
protected:
	int TL_data;
public:
	TopLeft() : TL_data(-1) {
		cout << "TopLeft was created with default constructor" << endl;
	}
	TopLeft(int TL_data) : TL_data(TL_data) {
		cout << "TopLeft was created with parameterized constructor" << endl;
	}	
	~TopLeft() {
		cout << "TopLeft destructor called" << endl;
	}

	void input() {
		cout << "Enter data for TopLeft: ";
		cin >> TL_data;
	}
};

class TopRight {
protected :
	double TR_data;
public:
	TopRight() : TR_data(-1.0) {
		cout << "TopRight was created with default constructor" << endl;
	}
	TopRight(double TR_data) : TR_data(TR_data) {
		cout << "TopRight was created with parameterized constructor" << endl;
	}
	~TopRight() {
		cout << "TopRight destructor called" << endl;
	}
	void input() {
		cout << "Enter data for TopRight: ";
		cin >> TR_data;
	}
};

class MLeft : public TopLeft {
protected:
	int ML_data;
public:
	MLeft() : ML_data(-1) {
		cout << "MLeft was created with default constructor" << endl;
	}
	MLeft(int TL_data, int ML_data) : 
		TopLeft(TL_data), 
		ML_data(ML_data) {
		cout << "MLeft was created with parameterized constructor" << endl;
	}
	~MLeft() {
		cout << "MLeft destructor called" << endl;
	}
	void input() {
		TopLeft::input();
		cout << "Enter data for MLeft: ";
		cin >> ML_data;
	}
};

class MCenter : public TopLeft, public TopRight {
protected:
	double MC_data;
public:
	MCenter() : MC_data(-1.0) {
		cout << "MCenter was created with default constructor" << endl;
	}
	MCenter(int TL_data, double TR_data, double MC_data) :
		TopLeft(TL_data), 
		TopRight(TR_data), 
		MC_data(MC_data) {
		cout << "MCenter was created with parameterized constructor" << endl;
	}
	~MCenter() {
		cout << "MCenter destructor called" << endl;
	}
	void input() {
		TopLeft::input();
		TopRight::input();
		cout << "Enter data for MCenter: ";
		cin >> MC_data;
	}
};

class MRight : public TopRight, public MCenter {
protected:
	double MR_data;
public:
	MRight() : MR_data(-1.0) {
		cout << "MRight was created with default constructor" << endl;
	}
	MRight(double TR_data_main, int TL_data, double TR_data, double MC_data, double MR_data) :
		TopRight(TR_data_main), 
		MCenter(TL_data, TR_data, MC_data),
		MR_data(MR_data) {
		cout << "MRight was created with parameterized constructor" << endl;
	}
	~MRight() {
		cout << "MRight destructor called" << endl;
	}
	void input() {
		TopRight::input();
		MCenter::input();
		cout << "Enter data for MRight: ";
		cin >> MR_data;
	}
};

class Bottom : public MLeft, public TopLeft, public MRight {
protected:
	int B_data;
public:
	Bottom() : B_data(-1) {
		cout << "Bottom was created with default constructor" << endl;
	}
	Bottom(int TL_data_ML, int ML_data, int TL_data_main, double TR_data_main, int TL_data_MC, double TR_data_MC, double MC_data, double MR_data, int B_data) :
		MLeft(TL_data_ML, ML_data),
		TopLeft(TL_data_main),
		MRight(TR_data_main, TL_data_MC, TR_data_MC, MC_data, MR_data), 
		B_data(B_data) {
		cout << "Bottom was created with parameterized constructor" << endl;
	}
	~Bottom() {
		cout << "Bottom destructor called" << endl;
	}
	void input() {
		MLeft::input();
		TopLeft::input();
		MRight::input();
		cout << "Enter data for Bottom: ";
		cin >> B_data;
	}
};

// With virtual

class VrTopLeft {
protected:
	int VrTL_data;
public:
	VrTopLeft() : VrTL_data(0) {
		cout << "VrTopLeft was created with default constructor" << endl;
	}
	VrTopLeft(int VrTL_data) : VrTL_data(VrTL_data) {
		cout << "VrTopLeft was created with parameterized constructor" << endl;
	}
	virtual ~VrTopLeft() {
		cout << "VrTopLeft destructor called" << endl;
	}

	void input() {
		cout << "Enter data for VrTopLeft: ";
		cin >> VrTL_data;
	}
};

class VrTopRight {
protected:
	double VrTR_data;
public:
	VrTopRight() : VrTR_data(0.0) {
		cout << "VrTopRight was created with default constructor" << endl;
	}
	VrTopRight(double VrTR_data) : VrTR_data(VrTR_data) {
		cout << "VrTopRight was created with parameterized constructor" << endl;
	}
	virtual ~VrTopRight() {
		cout << "VrTopRight destructor called" << endl;
	}
	void input() {
		cout << "Enter data for VrTopRight: ";
		cin >> VrTR_data;
	}
};

class VrMLeft : public virtual VrTopLeft {
protected:
	int VrML_data;
public:
	VrMLeft() : VrML_data(0) {
		cout << "VrMLeft was created with default constructor" << endl;
	}
	VrMLeft(int TL_data, int ML_data) :
		VrTopLeft(TL_data),
		VrML_data(ML_data) {
		cout << "VrMLeft was created with parameterized constructor" << endl;
	}
	~VrMLeft() {
		cout << "VrMLeft destructor called" << endl;
	}
	void input() {
		VrTopLeft::input();
		cout << "Enter data for VrMLeft: ";
		cin >> VrML_data;
	}
};

class VrMCenter : public virtual VrTopLeft, public virtual VrTopRight {
protected:
	double VrMC_data;
public:
	VrMCenter() : VrMC_data(0.0) {
		cout << "VrMCenter was created with default constructor" << endl;
	}
	VrMCenter(int VrTL_data, double VrTR_data, double VrMC_data) :
		VrTopLeft(VrTL_data),
		VrTopRight(VrTR_data),
		VrMC_data(VrMC_data) {
		cout << "VrMCenter was created with parameterized constructor" << endl;
	}
	~VrMCenter() {
		cout << "VrMCenter destructor called" << endl;
	}
	void input() {
		VrTopLeft::input();
		VrTopRight::input();
		cout << "Enter data for VrMCenter: ";
		cin >> VrMC_data;
	}
};

class VrMRight : public virtual VrTopRight, public VrMCenter {
protected:
	double VrMR_data;
public:
	VrMRight() : VrMR_data(0.0) {
		cout << "VrMRight was created with default constructor" << endl;
	}
	VrMRight(double VrTR_data_main, int VrTL_data, double VrTR_data, double VrMC_data, double VrMR_data) :
		VrTopRight(VrTR_data_main),
		VrMCenter(VrTL_data, VrTR_data, VrMC_data),
		VrMR_data(VrMR_data) {
		cout << "VrMRight was created with parameterized constructor" << endl;
	}
	~VrMRight() {
		cout << "VrMRight destructor called" << endl;
	}
	void input() {
		VrTopRight::input();
		VrMCenter::input();
		cout << "Enter data for VrMRight: ";
		cin >> VrMR_data;
	}
};

class VrBottom : public virtual VrTopLeft, public virtual VrTopRight, public VrMLeft,  public VrMRight {
protected:
	int VrB_data;
public:
	VrBottom() : VrB_data(0) {
		cout << "VrBottom was created with default constructor" << endl;
	}
	VrBottom(int VrTL_data, double VrTR_data, int VrML_data, double VrMC_data, double VrMR_data, int VrB_data) :
		VrTopLeft(VrTL_data),
		VrTopRight(VrTR_data),
		VrMLeft(VrTL_data, VrML_data),
		VrMRight(VrTR_data, VrTL_data, VrTR_data, VrMC_data, VrMR_data),
		VrB_data(VrB_data) {
		cout << "VrBottom was created with parameterized constructor" << endl;
	}
	~VrBottom() {
		cout << "VrBottom destructor called" << endl;
	}
	
	void input() {
		cout << "Enter data for VrTopLeft:\n";
		cin >> VrTL_data;
		cout << "Enter data for VrTopRight:\n";
		cin >> VrTR_data;
		cout << "Enter data for VrMLeft:\n";
		cin >> VrML_data;
		cout << "Enter data for VrMCenter:\n";
		cin >> VrMC_data;
		cout << "Enter data for VrMRight:\n";
		cin >> VrMR_data;
		cout << "Enter data for VrBottom: ";
		cin >> VrB_data;

	}
};

// Task 2

class Data {
public:
	virtual void display() const = 0;
	virtual void save(const string& filename) = 0;
	virtual void process() = 0;

	virtual void input_data() = 0;

	virtual ~Data() {
		cout << "Data (base) destructor called" << endl;
	}

};

class SignalData : public Data {
protected:
	string signalType;
	double frequency;
public:
	SignalData() : signalType("Unknown"), frequency(0.0) {
		cout << "SignalData was created with default constructor" << endl;
	}
	SignalData(string type, double freq) : signalType(type), frequency(freq) {
		cout << "SignalData was created with parameterized constructor" << endl;
	}
	void display() const override {
		cout << "Signal Type: " << signalType << ", Frequency: " << frequency << " Hz" << endl;
	}
	void save(const string& filename) override {
		cout << "Saving SignalData to file: " << filename << endl;
	}
	void process() override {
		cout << "Processing " << signalType << " SignalData..." << endl;
	}
	~SignalData() {
		cout << "SignalData destructor called" << endl;
	}

	void input_data() override {
		cout << "Entering signal data:\n";
		cout << "Enter signal type: ";
		cin >> signalType;
		cout << "Enter frequency: ";
		cin >> frequency;
	}
	
};

class ResultData : public Data {
	protected:
	bool saved;
	double executionTime;
public:
	ResultData() : saved(false), executionTime(0.0) {
		cout << "ResultData was created with default constructor" << endl;
	}
	ResultData(bool saved, double executionTime) : saved(saved), executionTime(executionTime) {
		cout << "ResultData was created with parameterized constructor" << endl;
	}
	void display() const override {
		cout << "Result Data - Saved: " << (saved ? "Yes" : "No") << ", Execution Time: " << executionTime << " s" << endl;
	}
	void save(const string& filename) override {
		cout << "Saving ResultData to file: " << filename << endl;
		saved = true;
	}
	void process() override {
		cout << "Processing ResultData..." << endl;
	}
	~ResultData() {
		cout << "ResultData destructor called" << endl;
	}

	void input_data() override {
		cout << "Entering result data:\n";
		cout << "Enter saved status (0 for No, 1 for Yes): ";
		cin >> saved;
		cout << "Enter execution time: ";
		cin >> executionTime;
	}
};

class AdditionalData : public Data {
	protected:
		unsigned int size;
		string date;
public:
	AdditionalData() : size(0), date("Unknown") {
		cout << "AdditionalData was created with default constructor" << endl;
	}

	AdditionalData(unsigned int size, string date) : size(size), date(date) {
		cout << "AdditionalData was created with parameterized constructor" << endl;
	}
	~AdditionalData() {
		cout << "AdditionalData destructor called" << endl;
	}
	
	void display() const override {
		cout << "Additional Data - Size: " << size << " bytes, Date: " << date << endl;
	}
	void save(const string& filename) override {
		cout << "Saving AdditionalData to file: " << filename << endl;
	}
	void process() override {
		cout << "Processing AdditionalData..." << endl;
	}
	
	void input_data() override {
		cout << "Entering additional data:\n";
		cout << "Enter size (in bytes): ";
		cin >> size;
		cout << "Enter date (YYYY-MM-DD): ";
		cin >> date;
	}

};

// Task 3

class Person {
protected:
	string name;
	int age;
public:
	Person() : name("Unknown"), age(0) {
		cout << "Person was created with default constructor" << endl;
	}
	Person(string name, int age) : name(name), age(age) {
		cout << "Person was created with parameterized constructor" << endl;
	}
	virtual ~Person() {
		cout << "Person destructor called" << endl;
	}

	string tostring() {
		return "Name: " + name + ", Age: " + to_string(age);
	}
};

class Worker : public virtual  Person {
protected:
	string position;
public:
	Worker() : position("Unknown") {
		cout << "Worker was created with default constructor" << endl;
	}
	Worker(string name, int age, string position) : Person(name, age), position(position) {
		cout << "Worker was created with parameterized constructor" << endl;
	}
	~Worker() {
		cout << "Worker destructor called" << endl;
	}

	string tostring() {
		return "Position: " + position + ", " + Person::tostring();
	}
};

class Woman : public virtual Person {
protected:
	string hobby;
	public:
	Woman() : hobby("Unknown") {
		cout << "Woman was created with default constructor" << endl;
	}
	Woman(string name, int age, string hobby) : Person(name, age), hobby(hobby) {
		cout << "Woman was created with parameterized constructor" << endl;
	}
	~Woman() {
		cout << "Woman destructor called" << endl;
	}
	string tostring() {
		return "Hobby: " + hobby + ", " + Person::tostring();
	}
};

class FemaleWorker : public Worker, public Woman, public virtual Person {
protected:
	int experienceYears;
public:
	FemaleWorker() : experienceYears(0) {
		cout << "FemaleWorker was created with default constructor" << endl;
	}
	FemaleWorker(string name, int age, string position, string hobby, int experienceYears) :
		Person(name, age),
		Worker(name, age, position),
		Woman(name, age, hobby),
		experienceYears(experienceYears) {
		cout << "FemaleWorker was created with parameterized constructor" << endl;
	}
	~FemaleWorker() {
		cout << "FemaleWorker destructor called" << endl;
	}

	string tostring() {
		return "Name : " + name + ", Age: " + to_string(age) + ", Position: " + position + ", Hobby: " + hobby + ", Experience Years: " + to_string(experienceYears);
	}
	};


	int main() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		Data* storage[3] = { nullptr, nullptr, nullptr };
		FemaleWorker fw;
		int main_choice;

		do {
			cout << "\nMain menu\n";
			cout << "1.Task: Multiple Inheritance\n";
			cout << "2.Task: Data Management\n";
			cout << "3.Task:  \n";
			cout << "0.Exit \n";
			cout << "Choice: ";
			cin >> main_choice;

			switch (main_choice) {
			case 1: {
				int sub_choice;
				do {
					cout << "\n--- Task 1 ---\n";
					cout << "1. Create Bottom\n";
					cout << "2. Create Bottom (virtual)\n";
					cout << "3. Show sizes both\n";
					cout << "0. Back to main menu\n";
					cout << "Your choice: ";
					cin >> sub_choice;
					switch (sub_choice) {
					case 1: {
						Bottom b;
						cout << "Input data for Bottom:\n";
						b.input();
						break;
					}
					case 2: {
						VrBottom vrb;
						cout << "Input data for VrBottom:\n";
						vrb.input();
						break;
					}
					case 3: {
						cout << "Size of Bottom: " << sizeof(Bottom) << " bytes";
						cout << "\nSize of VrBottom: " << sizeof(VrBottom) << " bytes\n";
						break;
					}
					case 0:
						break;
					}
				} while (sub_choice != 0);
				break;
			}
			case 2: {
				int sub_choice2;
				do {
					cout << "\n--- Task 2 ---\n";
					cout << "1. Input SignalData\n";
					cout << "2. Input ResultData\n";
					cout << "3. Input AdditionalData\n";
					cout << "4. Display all data\n";
					cout << "5. Save all data\n";
					cout << "6. Process all data\n";
					cout << "0. Back to main menu\n";
					cout << "Your choice: ";
					cin >> sub_choice2;
					switch (sub_choice2) {
					case 1: {
						if (storage[0]) {
							delete storage[0];
							storage[0] = nullptr;
						}
						storage[0] = new SignalData();
						storage[0]->input_data();
						break;
					}
					case 2: {
						if (storage[1]) {
							delete storage[1];
							storage[1] = nullptr;
						}
						storage[1] = new ResultData();
						storage[1]->input_data();
						break;
					}
					case 3: {
						if (storage[2]) {
							delete storage[2];
							storage[2] = nullptr;
						}
						storage[2] = new AdditionalData();
						storage[2]->input_data();
						break;
					}
					case 4: {
						for (int i = 0; i < 3; ++i) {
							if (storage[i]) {
								storage[i]->display();
							}
						}
						break;
					}
					case 5: {
						for (int i = 0; i < 3; ++i) {
							if (storage[i]) {
								storage[i]->save("data_file_" + to_string(i) + ".txt");
							}
						}
						break;
					}
					case 6: {
						for (int i = 0; i < 3; ++i) {
							if (storage[i]) {
								storage[i]->process();
							}
						}
						break;
					}
					case 0:
						break;
					}
				} while (sub_choice2 != 0);

				// Очищення пам'яті після виходу з 2 завдання
				for (int i = 0; i < 3; i++) {
					if (storage[i] != nullptr) {
						delete storage[i];
						storage[i] = nullptr;
					}
				}
				break;
			}
			case 3: {
				int sub_choice3;
				do {
					cout << "\n--- Task 3---\n";
					cout << "1. Create FemaleWorker\n";
					cout << "2. Show FemaleWorker info\n";
					cout << "0. Back to main menu\n";
					cout << "Your choice: ";
					cin >> sub_choice3;
					switch (sub_choice3) {
					case 1:
						fw = FemaleWorker("Anna", 30, "Engineer", "Painting", 5);
						cout << "Data created successfully!\n";
						break;
					case 2:
						cout << fw.tostring() << endl;
						break;
					case 0:
						break;
					}
				} while (sub_choice3 != 0);
				break;
			}
			case 0: {
				cout << "\nThanks for working\n";
				break;
			}
			}
		} while (main_choice != 0);

		return 0;
	}