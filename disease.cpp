#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX_DISEASES = 100; // indexes 0-99

class Patient {
private:
    string fname;
    string lname;
    int age;


public:
	void setFirstName(string firstname){
		fname = firstname;
	}
	void setLastName(string lastname){
		lname = lastname;
	}
	void setAge(int pAge){
		age = pAge;
	}
    string getFirstName(){
    	return fname;
	}

    string getLastName(){
    	return lname;
	}
	int getAge(){
		return age;
	}

    void getData() const {
        cout << "Patient's Full Name: " << fname << " " << lname << endl;
        cout << "Patient's Age: " << age << endl;
    }
};


class Disease {
private:
    string diseases[MAX_DISEASES];
    int diseaseCount;

public:
    Disease() : diseaseCount(3) {
        diseases[0] = "Flu";
        diseases[1] = "Cold";
        diseases[2] = "COVID-19";
    }

    void displayDiseases() {
        cout << "List of Diseases:\n";
        for (int i = 0; i < diseaseCount; ++i) {
            cout << "- " << diseases[i] << '\n';
        }
        cout << endl;
    }

    void addDiseases(int numDiseases) {
        if (diseaseCount + numDiseases <= MAX_DISEASES) {
            for (int i = 0; i < numDiseases; ++i) {
                string newDisease;
                cout << "Enter disease #" << i + 1 << ": ";
                getline(cin, newDisease);
                diseases[diseaseCount++] = newDisease;
            }
            cout << "Diseases have been added to the list.\n\n";
        } else {
            cout << "Cannot add more diseases. Maximum limit reached.\n\n";
        }
    }
};

// Patient's Child class

class Prediction : public Patient {
private:

    static string symptom;

public:

    static string DiseasePrediction() {
    	
    	Patient patient;
		string fName;
        string lName;
        int pAge;
		cout<<"Enter your first name: "<<endl;
        cin>>fName;
        cout<<"Enter your last name: "<<endl;
        cin>>lName;
		cout<<"Enter your age: "<<endl;
        cin>>pAge;
        
         cin.ignore();
        
		patient.setFirstName(fName);
        patient.setLastName(lName);
        patient.setAge(pAge);
        // Accessing parent class members using accessor functions
        cout << "Enter your symptom: " << endl;
        getline(cin, symptom);
        
        string prediction;
	       if(symptom == "fever" || symptom == "cough" || symptom == "sore throat" || symptom == " body aches" || symptom == "fatigue"|| symptom == "respiratory symptoms"){
				prediction = "You might have influenza (Flu), allergies common cold \n\n";
			}
			else if(symptom == "severe headache" || symptom == "severe fever"){
				prediction = "You might have influenza (Flu), covid-19, malaria, typhoid\n\n";
			}
			else if(symptom == "runny nose" || symptom == "sneezing" || symptom == "congestion" || symptom == "coughing"){
				prediction = "You might have Gastroenteritisand Food Poisoning\n\n";
			}			
			else if(symptom == "nausea" || symptom == "vomiting" || symptom == "abdominal pain") {
				prediction = "You might have Hypothyroidism and Depression\n\n";
			}
			else if(symptom == "weight gain" || symptom == "mood changes" || symptom == "difficulty concentrating"){
				prediction = "You might have Lyme Disease and Rheumatoid Arthritis\n\n";
			}
			else if(symptom == "Joint pain"){
				prediction = "Type 1 Diabetes and Flu\n\n";
			}
			else if(symptom == "increased thirst" || symptom == "frequent urination"){
				prediction = "You might have Chronic Fatigue Syndrome and Depression\n\n";
			}
			else if(symptom == "persistent fatigue" || symptom == "sleep disturbances" || symptom == "cognitive difficulties"){
				prediction = "You might have Chronic Obstructive Pulmonary Disease (COPD) and Asthma\n\n";
			}
			else if(symptom ==  "shortness of breath" || symptom == "wheezing") {
				prediction = "You might have Anxiety and Hyperthyroidism \n\n";
			}
			else if(symptom == "nervousness" || symptom == "irritability" || symptom == "increased heart rate"){
				prediction = "Celiac Disease and Irritable Bowel Syndrome (IBS)\n\n";
			}
			else{
				prediction = "wrong symptom\n";

			}

			ofstream outFile("prediction_data.txt", ios::app);
        	if (outFile.is_open()) {
            
				outFile << "\n \t\t\t ****** User Information ******  \n\n";
            	outFile << "First Name: " << patient.getFirstName()<< "\n";
            	outFile << "Last Name: " << patient.getLastName()<< "\n";
            	outFile << "Age: " << patient.getAge()<< "\n";
            	outFile << "Symptom: " << symptom << "\n";
            	outFile << "Predicted Disease: " << prediction << "\n";
            	outFile << "\n \t\t ---------------------------------------------- \n\n";

	            outFile.close();

    	        return prediction;
        } else {
            cout << "Error opening the file!" << endl;
            return "Error";
        }
    }
    
     void readPredictedFile() {
        ifstream inFile("prediction_data.txt");
        if (inFile.is_open()) {
            cout << "\n \t\t ****** Predicted Diseases File Data ******  \n\n";
            string line;
            while (getline(inFile, line)) {
                cout << line << endl;
            }
            inFile.close();
        } else {
            cout << "Error opening the file!" << endl;
        }
    }
    
};

string Prediction::symptom;

int main() {
    Disease diseaseObject;
    Prediction predict;

    char choice;
    cout << "\n\t\t\t***** DISEASE PREDICTION SYSTEM *****\n "<< endl;
    while (true) {
    	cout << "\t\t\t\t  Choose Any Option \n "<<endl;
        cout << "If you want to add any disease --> Press A " << endl;
        cout << "If you want to display all diseases --> Press B " << endl;
        cout << "If you want to predict the disease --> Press D " << endl;
		cout << "If you want to read the predicted diseases report --> Press R " << endl;        
        cout << "If you want to exit from the system --> Press Y/N " << endl;
        cin >> choice;
        switch (choice) {
            case 'A':
            case 'a':
                int numNewDiseases;
                cout << "How many new diseases do you want to add? ";
                cin >> numNewDiseases;
                cin.ignore(); // use for clean the buffer.
                diseaseObject.addDiseases(numNewDiseases);
                diseaseObject.displayDiseases();
                break;
            case 'B':
            case 'b':
                cout << "\n\t\t\t ***** Display All Diseases ***** " << endl;
                diseaseObject.displayDiseases();
                break;
            case 'D':
            case 'd':
                cout << "\n\t\t\t ***** Predict Your Disease ***** " << endl;
                // using scope resolution
                cout << Prediction::DiseasePrediction();
                break;
            case 'R':
            case 'r':
            	Prediction().readPredictedFile();
            	break;
            	
            case 'Y':
            case 'y':
                cout << "Thank You For Using This System. Good Bye :) " << endl;
                return 0;
                break;
            case 'N':
            case 'n':
                break;
            default:
                cout << "Invalid Choice. Please Choose Again " << endl;
                break;
        }
    }

    return 0;
}

