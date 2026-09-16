#include <iostream>
using namespace std;

int main() {
    int rows = 0, cols = 0;
    while (rows <= 0 || cols <= 0) {
        cout << "Enter number of students (rows) and subjects (cols): ";
        cin >> rows >> cols;
        if (rows <= 0 || cols <= 0) {
            cout << "Invalid input. Both numbers must be greater than 0.\n";
        }
    }

    int** marks = new int*[rows];
    for (int r = 0; r < rows; ++r) {
        marks[r] = new int[cols];
    }

    cout << "Enter marks (0 to 100) for each student row by row:\n";
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            do {
                cin >> *(*(marks + r) + c);
            } while (*(*(marks + r) + c) < 0 || *(*(marks + r) + c) > 100);
        }
    }

    cout << "\n--- Marks Matrix ---\n";
    int topStudent = 1;
    int maxTotal = -1;

    for (int r = 0; r < rows; ++r) {
        int currentTotal = 0;
        cout << "Student " << (r + 1) << ": ";
        for (int c = 0; c < cols; ++c) {
            cout << marks[r][c] << "\t";
            currentTotal += marks[r][c];
        }
        cout << "| Total: " << currentTotal << "\n";
        if (r == 0 || currentTotal > maxTotal) {
            maxTotal = currentTotal;
            topStudent = r + 1;
        }
    }
    cout << "\nTop Student: " << topStudent << " with Total Marks: " << maxTotal << "\n";

    for (int r = 0; r < rows; ++r) {
        delete[] marks[r];
    }
    delete[] marks;
    marks = nullptr;

    return 0;
}