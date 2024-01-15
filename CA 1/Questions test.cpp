#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

// Data structures to represent questions and tests
struct Question {
    string text;
    vector<string> options;
    char correctOption;  // Use char for correctOption
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
        question.correctOption = question.options.back()[0];  // Take the first character as the correct option
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

        // Convert the user's answer to uppercase
        userAnswer = toupper(userAnswer);

        // Add input validation
        while (cin.fail() || (userAnswer < 'A' || userAnswer > static_cast<char>('A' + question.options.size()))) {
            cin.clear();  // clear input buffer to restore cin to a usable state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ignore last input
            cout << "Invalid input. Please enter a letter between A and " << static_cast<char>('A' + question.options.size() - 1) << ": ";
            cin >> userAnswer;
            userAnswer = toupper(userAnswer);
        }

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

int main() {
    cout << "Attempting to load questions from: Sampleq.csv" << endl;

    // Load questions from a CSV file (Sampleq.csv)
    vector<Question> questions;
    loadQuestionsFromFile("C:/Users/abdul/OneDrive/Documents/A_Femi-SunmonuCSC201/CA 1/Sampleq.csv", questions);

    cout << "Number of questions loaded: " << questions.size() << endl;

    // Create a test with all loaded questions
    Test test;
    test.name = "Sample Test";
    test.questions.assign(questions.begin(), questions.end());

    // Conduct the test
    cout << "Welcome to the " << test.name << "!" << endl;
    cout << "You will be presented with " << test.questions.size() << " questions." << endl;
    cout << "Choose the correct option for each question." << endl << endl;

    conductTest(test);

    return 0;
}
