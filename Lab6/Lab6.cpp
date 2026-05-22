
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
		cout << "TopLeft was created with default constructor (" << TL_data << ")" << endl;
	}

	TopLeft(int d) {
		TL_data = d;
		cout << "TopLeft was created with parameterized constructor (" << TL_data << ")" << endl;
	}

	~TopLeft() {
		cout << "TopLeft with data (" << TL_data << ") is being destroyed" << endl;
	}

};

class TopRight {
protected:
	double TR_data;
public:
	TopRight() {
		TR_data = -1.0;
		cout << "TopRight was created with default constructor (" << TR_data << ")" << endl;
	}

	TopRight(double d) : TR_data(d) {
		cout << "TopRight was created with parameterized constructor (" << TR_data << ")" << endl;
	}

	~TopRight() {
		cout << "TopRight with data (" << TR_data << ") is being destroyed" << endl;
	}
};

class MidLeft :protected TopLeft {
protected:
	int ML_data;
public:

	MidLeft() : TopLeft(), ML_data(-1) {
		cout << "MidLeft was created with default constructor (" << ML_data << ")" << endl;

	}

	MidLeft(int TL_data, int ML_data) : TopLeft(TL_data) {
		this->ML_data = ML_data;
		cout << "MidLeft was created with parameterized constructor (" << ML_data << ")" << endl;
	}

	~MidLeft() {
		cout << "MidLeft with data (" << ML_data << ") is being destroyed" << endl;
	}
};

class MidCenter : protected TopLeft, protected TopRight {
protected:
	double MC_data;
public:
	MidCenter() : TopLeft(), TopRight(), MC_data(-1.0) {
		cout << "MidCenter was created with default constructor (" << MC_data << ")" << endl;
	}
	MidCenter(int TL_data, double TR_data, double MC_data) : TopLeft(TL_data), TopRight(TR_data), MC_data(MC_data) {
		cout << "MidCenter was created with parameterized constructor (" << MC_data << ")" << endl;
	}
	~MidCenter() {
		cout << "MidCenter with data (" << MC_data << ") is being destroyed" << endl;
	}
};

class MidRight : protected TopRight, protected MidCenter {
protected:
	double MR_data;
public:
	MidRight() : TopRight(), MidCenter(), MR_data(0.0) {
		cout << "MidRight was created with default constructor (" << MR_data << ")" << endl;
	}
	MidRight(double TR_data_main, int TL_data, double TR_data_MC, double MC_data, double MR_data) :
		TopRight(TR_data_main),
		MidCenter(TL_data, TR_data_MC, MC_data),
		MR_data(MR_data)
	{
		cout << "MidRight was created with parameterized constructor (" << MR_data << ")" << endl;
	}
	~MidRight() {
		cout << "MidRight with data (" << MR_data << ") is being destroyed" << endl;
	}
};

class Bottom : protected TopLeft, protected MidLeft, protected MidRight {
protected:
	int B_data;
public:
	Bottom() : TopLeft(), MidLeft(), MidRight(), B_data(0) {
		cout << "Bottom was created with default constructor (" << B_data << ")" << endl;
	}
	Bottom(int TL_data, int TL_data_ML, int ML_data, double TR_data_main, int TL_data_MC, double TR_data_MC, double MC_data, double MR_data, int B_data) :
		TopLeft(TL_data),
		MidLeft(TL_data_ML, ML_data),
		MidRight(TR_data_main, TL_data_MC, TR_data_MC, MC_data, MR_data),
		B_data(B_data)
	{
		cout << "Bottom was created with parameterized constructor (" << B_data << ")" << endl;
	}
	~Bottom() {
		cout << "Bottom with data (" << B_data << ") is being destroyed" << endl;
	}

	
};

// Virtual

class VrTopLeft {
protected:
	int TL_data;
public:
	VrTopLeft() : TL_data(0) { 
		cout << "VrTopLeft was created with default constructor (" << TL_data << ")" << endl;
	}

	VrTopLeft(int d) {
		TL_data = d;
		cout << "VrTopLeft was created with parameterized constructor (" << TL_data << ")" << endl;
	}

	~VrTopLeft() {
		cout << "VrTopLeft with data (" << TL_data << ") is being destroyed" << endl;
	}

};

class VrTopRight {
protected:
	double TR_data;
public:
	VrTopRight() {
		TR_data = 0.0;
		cout << "VrTopRight was created with default constructor (" << TR_data << ")" << endl;
	}
	
	VrTopRight(double d) : TR_data(d) {
		cout << "VrTopRight was created with parameterized constructor (" << TR_data << ")" << endl;
	}
	
	~VrTopRight() {
		cout << "VrTopRight with data (" << TR_data << ") is being destroyed" << endl;
	}
};

class VrMidLeft : virtual protected VrTopLeft {
protected:
	int ML_data;
public:

	VrMidLeft() : VrTopLeft(), ML_data(0) {
		cout << "VrMidLeft was created with default constructor (" << ML_data << ")" << endl;

	}

	VrMidLeft(int TL_data, int ML_data) : VrTopLeft(TL_data) {
		this->ML_data = ML_data;
		cout << "VrMidLeft was created with parameterized constructor (" << ML_data << ")" << endl;
	}

	~VrMidLeft() {
		cout << "VrMidLeft with data (" << ML_data << ") is being destroyed" << endl;
	}
};

class VrMidCenter : virtual protected VrTopLeft, virtual  protected VrTopRight {
protected:
	double MC_data;
public:
	VrMidCenter() : VrTopLeft(), VrTopRight(), MC_data(0.0) {
		cout << "VrMidCenter was created with default constructor (" << MC_data << ")" << endl;
	}
	VrMidCenter(int TL_data, double TR_data, double MC_data) : VrTopLeft(TL_data), VrTopRight(TR_data), MC_data(MC_data) {
		cout << "VrMidCenter was created with parameterized constructor (" << MC_data << ")" << endl;
	}
	~VrMidCenter() {
		cout << "VrMidCenter with data (" << MC_data << ") is being destroyed" << endl;
	}
};

class VrMidRight : virtual protected VrTopRight, protected VrMidCenter {
protected :
	double MR_data;
public:
	VrMidRight() : VrTopRight(), VrMidCenter(), MR_data(0.0) {
		cout << "VrMidRight was created with default constructor (" << MR_data << ")" << endl;
	}
	VrMidRight(double TR_data_main, int TL_data, double TR_data_MC, double MC_data, double MR_data) : VrTopRight(TR_data_main), VrMidCenter(TL_data, TR_data_MC, MC_data), MR_data(MR_data) {
		cout << "VrMidRight was created with parameterized constructor (" << MR_data << ")" << endl;
	}
	~VrMidRight() {
		cout << "VrMidRight with data (" << MR_data << ") is being destroyed" << endl;
	}
};

class VrBottom : virtual protected VrTopLeft, protected VrMidLeft, protected VrMidRight, virtual protected VrTopRight {
protected:
	int B_data;
public:
	VrBottom() : VrTopLeft(), VrMidLeft(), VrTopRight(), VrMidRight(), B_data(0) {
		cout << "VrBottom was created with default constructor (" << B_data << ")" << endl;
	}
	VrBottom(int TL_data_main, int ML_data, double TR_data_main, double MC_data, int TL_data_MC, double TR_data_MC, double MR_data, int B_data):
		VrTopLeft(TL_data_main),
		VrTopRight(TR_data_main),
		VrMidLeft(TL_data_main, ML_data),
		VrMidRight(TR_data_main, TL_data_MC, TR_data_MC, MC_data, MR_data),
		B_data(B_data)
	{
		cout << "VrBottom was created with parameterized constructor (" << B_data << ")" << endl;
	}
	~VrBottom() {
		cout << "VrBottom with data (" << B_data << ") is being destroyed" << endl;
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


int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Data* storage[3] = { nullptr, nullptr, nullptr };

	int main_choice;
	do {
		cout << "Main menu\n";
		cout << "1.Task: \n";
		cout << "2.Task: \n";
		cout << "3.Task: \n";
		cout << "0.Exit \n";
		cout << "Choise: ";
		cin >> main_choice;

		switch (main_choice) {

		case 1: {
			int sub_choice;
			do {
				cout << "\n--- Task 1 ---\n";
				cout << "Your choice: ";
				cin >> sub_choice;

				switch (sub_choice) {
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				}
			} while (sub_choice != 0); // Крутимо підменю, поки не введемо 0
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
				case 3:
					if (storage[2]) {
						delete storage[2];
						storage[2] = nullptr;
					}
					storage[2] = new AdditionalData();
					storage[2]->input_data();
					break;
				case 4:
					for (int i = 0; i < 3; ++i) {
						if (storage[i]) {
							storage[i]->display();
						}
					}
					break;
				case 5:
					for (int i = 0; i < 3; ++i) {
						if (storage[i]) {
							storage[i]->save("data_file.txt");
						}
					}
					break;
				case 6:
					for (int i = 0; i < 3; ++i) {
						if (storage[i]) {
							storage[i]->process();
						}
					}
					break;
				case 0:
					break;
				} 
			} while (sub_choice2 != 0); // Крутимо підменю, поки не введемо 0
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
				cout << "Your choice: ";
				cin >> sub_choice3;
				switch (sub_choice3) {
				case 1:
				
					break;
				case 2: {
	
					break;
				}
				case 3:

					break;
				case 0:
					break;
				}
			} while (sub_choice3 != 0);
			break;
		}
		case 0:
			cout << "\nThanks for working\n";
			break;
		}
	} while (main_choice != 0);

	return 0;
}

