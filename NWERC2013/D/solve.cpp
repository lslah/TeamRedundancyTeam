#include <iostream>
#include <vector>

using namespace std;

int K_columns, N;
vector<int> column_sizes;
vector<int> row_sizes;

bool feasible(vector<int> const &numbers, int row) {
    if (numbers.empty()) return false;
    if (numbers[0] == 8) return false;
    for (int i = 0; i < row_sizes[row]; i++) {
        if ((N-numbers[i]) < (column_sizes[i] - row - 1)) {
            return false;
        }
    }
    return true;
}

void increment(vector<int> &numbers) {
    int len = numbers.size();
    numbers[len-1] += 1;

    int pos = len-1;
    while (pos > 0 && numbers[pos] > N) {
        pos--;
        numbers[pos] += 1;
    }
    for (int i = pos+1; i < len; i++) {
        numbers[i] = numbers[pos];
    }
}

int nbr(vector<int> numbers, int current_row) {
    int count = 0;
    numbers.resize(row_sizes[current_row]);
    for (int i = 0; i < row_sizes[current_row]; i++) {
        numbers[i] = numbers[i]+1;
    }

    bool last_row = current_row == column_sizes[0] -1;
    while (feasible(numbers, current_row)) {
        if (last_row) {
            count++;
        } else {
            count += nbr(numbers, current_row+1);
        }
        increment(numbers);
    }
    return count;

}

bool solve() {
    cin >> K_columns;

    if (!cin.good() || cin.eof()) return false;

    row_sizes.resize(K_columns);
    for (int i = 0; i < K_columns; i++) {
        cin >> row_sizes[i];
    }
    cin >> N;

    column_sizes.resize(row_sizes[0]);
    for (int i = 0; i < row_sizes[0]; i++) {
        int count = 0;
        for (int j = 0; j < K_columns; j++) {
            if (row_sizes[j] >= (i+1)) count++;
        }
        column_sizes[i] = count;
    }

    vector<int> numbers(K_columns, 0);
    cout << nbr(numbers, 0) << endl;

    return true;
}

int main(void) {
    while (solve()) {}
}
