#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>

using namespace std;

struct Question {
    string text;
    vector<string> options;
    char correctOption;
};

struct Test {
    string name;
    vector<Question> questions;
};

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
        question.correctOption = question.options.back()[0];
        question.options.pop_back();
        questions.push_back(question);
    }

    file.close();
}

void conductTest(const Test& test) {
    int score = 0;
    vector<Question> incorrectQuestions;

    for (size_t i = 0; i < test.questions.size(); ++i) {
        const Question& question = test.questions[i];
        cout << "Question " << i + 1 << ": " << question.text << endl;
        for (size_t j = 0; j < question.options.size(); ++j) {
            cout << static_cast<char>('A' + j) << ". " << question.options[j] << endl;
        }

        char userAnswer;
        cout << "Your answer (A, B, C, D): ";
        cin >> userAnswer;
        userAnswer = toupper(userAnswer);

        while (userAnswer != 'A' && userAnswer != 'B' && userAnswer != 'C' && userAnswer != 'D') {
            cout << "Invalid input. Please enter A, B, C, or D: ";
            cin >> userAnswer;
            userAnswer = toupper(userAnswer);
        }

        if (userAnswer == question.correctOption) {
            score++;
        } else {
            incorrectQuestions.push_back(question);
        }

        cout << endl;
    }

    cout << "Your score: " << score << "/" << test.questions.size() << endl;

    int choice;
    cout << "Press 1 to view script, or Press 2 to exit: ";
    cin >> choice;
    if (choice == 1) {
        cout << "\nScript:\n";
        cout << "\nFollowing are the questions gotten wrong:\n";
        for (size_t i = 0; i < incorrectQuestions.size(); ++i) {
            const Question& question = incorrectQuestions[i];
            cout << "Question " << i + 1 << ": " << question.text << endl;
            cout << "Correct answer: " << question.correctOption << endl;
            cout << endl;
        }
    } else if (choice == 2) {
        exit(0);
    } else {
        cout << "Invalid choice. Exiting.\n";
        exit(1);
    }
}

void questions() {
    cout << "\n\t\t\tWelcome To Csc 201 CBT\n" << endl;

    vector<Question> questions;
    loadQuestionsFromFile("C:\\Users\\abdul\\OneDrive\\Documents\\A_Femi-SunmonuCSC201\\CA 1\\Final Draft\\Sampleq.csv", questions);

    cout << "Number of questions To be answered: " << questions.size() << endl;

    Test test;
    test.name = "Data Processing Test";
    test.questions.assign(questions.begin(), questions.end());

    cout << "Welcome to the " << test.name << "!" << endl;
    cout << "You will be presented with " << test.questions.size() << " questions." << endl;
    cout << "Choose the correct letter for each question (A, B, C, D)." << endl << endl;

    conductTest(test);
}

void login() {
    int count = 0;
    string user, pass, u, p;
    system("cls");
    cout << "please enter the following details" << endl;
    cout << "USERNAME :";
    cin >> user;
    cout << "PASSWORD :";
    cin >> pass;

    ifstream input("C:\\Users\\abdul\\OneDrive\\Documents\\A_Femi-SunmonuCSC201\\CA 1\\Final Draft\\student_credentials.txt");
    while (input >> u >> p) {
        if (u == user && p == pass) {
            count = 1;
            cout << "\nHello " << user << "\n<LOGIN SUCCESSFUL>";
            cout << "\nPress Return Key to Continue";
        }
    }
    input.close();
    if (count == 1) {
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
            cout << "Please Enter a Valid Input from the Options Given\n" << endl;
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
