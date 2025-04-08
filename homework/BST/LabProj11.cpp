// Academic Integrity Affidavit:
// I certify that this program code is my work.  Others may have
// assisted me with planning and concepts, but the code was written,
// solely, by me.
// I understand that submitting code that is totally or partially
// the product of other individuals is a violation of the Academic
// Integrity Policy and accepted ethical precepts. Falsified
// execution results are also results of improper activities. Such
// violations may result in zero credit for the assignment, reduced
// credit for the assignment, or course failure.
//
// Name: <Jack Sangl>
// Section: <Lab 003L>
// Assignment: BST

#include <iostream>
#include <cctype>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

struct TreeNode
{
    string studentName;
    float averageGrade;
    int numCourses;
    TreeNode *left;
    TreeNode *right;
};

void Insert(TreeNode *&root, string studentName, float grade);
void PrintTree(TreeNode *root, ofstream &out);
void DeleteTree(TreeNode *&root);

int main()
{

    // open file
    string file_name, output_file;
    cout << "Please enter input file with path: ";
    cin >> file_name;
    cout << "Please enter output file with path: ";
    cin >> output_file;

    ifstream myFile(file_name);
    ofstream myOutFile(output_file);
    // check if failed to open
    if (!(myFile.is_open()) || !(myOutFile.is_open()))
    {
        cerr << "YOUR FILE FAILED TO OPEN" << endl;
        return 1;
    }

    TreeNode *root = NULL;

    string myFileRead, studentName, extracted;
    stringstream ss(myFileRead);
    float grade = 0;

    while (getline(myFile, myFileRead))
    {
        stringstream ss(myFileRead);

        getline(ss, extracted, ' ');
        studentName = extracted;
        getline(ss, extracted, ' ');
        getline(ss, extracted, ' ');
        grade = stof(extracted);
        getline(ss, extracted, ' ');
        Insert(root, studentName, grade);
    }

    PrintTree(root, myOutFile);
    myFile.close();

    DeleteTree(root);
    return 0;
}

void Insert(TreeNode *&root, string studentName, float grade)
{

    if (root == NULL)
    {
        root = new TreeNode;
        root->numCourses = 1;
        root->studentName = studentName;
        root->averageGrade = grade;
        root->left = NULL;
        root->right = NULL;
        return;
    }

    if (root->studentName == studentName)
    {
        // this will configure avg grade by reverting back to total then dividing by the total courses
        // ie 82 avg * 2 course = 164 % then if u add a 54% = 218 / 3 courses = whatever
        root->averageGrade *= root->numCourses;
        root->numCourses += 1;
        root->averageGrade = (root->averageGrade + grade) / root->numCourses;
        return;
    }
    if (studentName < root->studentName)
        Insert(root->left, studentName, grade);
    else if (studentName > root->studentName)
        Insert(root->right, studentName, grade);

    return;
    }
    void PrintTree(TreeNode * root, ofstream & out)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            PrintTree(root->left, out);
            out << root->studentName << " " << root->averageGrade << endl;
            PrintTree(root->right, out);
        }
    }

void DeleteTree(TreeNode *&root) {
    if (root == NULL) return;
    DeleteTree(root->left);
    DeleteTree(root->right);
    delete root;
    root = NULL;
}

/*
Alex 70
Ben 75
Bob 70
Bruce 85
Carte 75
Charles 90
Eddy 35
Luke 85
Mike 80
Patric 30
Peter 95
Pique 55

*/