#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>

using namespace std;

// Data structures to represent questions and tests
struct Question {
    string text;
    vector<string> options;
    char correctOption;
};

struct Test {
    string name;
    vector<Question> questions;
};

// Function to load questions from a CSV file
void loadQuestionsFromFile(const string& filename, vector<Question>& questions) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file '" << filename << "'" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Question question;
        getline(ss, question.text, ',');
        string option;
        while (getline(ss, option, ',')) {
            question.options.push_back(option);
        }
        question.correctOption = question.options.back()[0]; // Use the first character of the last option
        question.options.pop_back();
        questions.push_back(question);
    }

    file.close();
}

// Function to conduct a test
void conductTest(const Test& test) {
    int score = 0;

    for (const Question& question : test.questions) {
        cout << question.text << endl;
        for (size_t i = 0; i < question.options.size(); ++i) {
            cout << static_cast<char>('A' + i) << ". " << question.options[i] << endl;
        }

        char userAnswer;
        cout << "Your answer: ";
        cin >> userAnswer;

        // Convert to uppercase
        userAnswer = toupper(userAnswer);

        if (userAnswer == question.correctOption) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Incorrect. The correct answer is option " << question.correctOption << "." << endl;
        }

        cout << endl;
    }

    cout << "Your score: " << score << "/" << test.questions.size() << endl;
}

void questions() {
    cout << "\t\t\tWelcome To Csc 201 CBT\n" << endl;

    // Load questions from a CSV file (Sampleq.csv)
    vector<Question> questions;
    loadQuestionsFromFile("C:/Users/abdul/OneDrive/Documents/A_Femi-SunmonuCSC201/CA 1/Sampleq.csv", questions);

    cout << "Number of questions loaded: " << questions.size() << endl;

    // Create a test with all loaded questions
    Test test;
    test.name = "Data Processing";
    test.questions.assign(questions.begin(), questions.end());

    // Conduct the test
    cout << "Welcome to the " << test.name << "!" << endl;
    cout << "You will be presented with " << test.questions.size() << " questions." << endl;
    cout << "Choose the correct letter for each question (A, B, C, D)." << endl << endl;

    conductTest(test);
} 

void login() {
    int count = 0; // Declare and initialize count
    string user, pass, u, p;
    system("cls");
    cout << "please enter the following details" << endl;
    cout << "USERNAME :";
    cin >> user;
    cout << "PASSWORD :";
    cin >> pass;

    ifstream input("student_credentials.txt");
    while (input >> u >> p) {
        if (u == user && p == pass) {
            count = 1;
            cout << "\nHello " << user << "\n<LOGIN SUCCESSFUL>";
        }
    }
    input.close();
    if (count == 1) {
        cout << "\nHello " << user << "\n<LOGIN SUCCESSFUL>";
        cin.get();
        cin.get();
        questions();
    } else {
        int d;
        cout << "\nLOGIN ERROR\nPlease check your username and password\n";
        cout << "\nPress 1 Login AGAIN" << endl;
        cin >> d;
        cout << endl;
        if (d == 1) {
            login();
        } else {
            cout << "Please Enter a Valid Input from the Options Given\n"
                 << endl;
        }
    }
}

void landingpg() {
    int c;

    cout << "\tMENU\t\n";
    cout << "Press 1 to LOGIN" << endl;
    cout << "Press 2 to EXIT" << endl;
    cin >> c;
    cout << endl;

    switch (c) {
    case 1:
        login();
        break;
    case 2:
        exit(0);
    default:
        cout << "Please Enter a Valid Input from the Options Given\n" << endl;
        landingpg();
    }
}

int main() {
    landingpg();
    return 0;
}
