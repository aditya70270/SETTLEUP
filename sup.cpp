#include <iostream>
using namespace std;

#define MAX_PERSONS 10

int get_Minimum(int array[], int num) {
    int min_Index = 0;
    for (int i = 1; i < num; i++) {
        if (array[i] < array[min_Index])
            min_Index = i;
    }
    return min_Index;
}

int get_Maximum(int array[], int num) {
    int max_Index = 0;
    for (int i = 1; i < num; i++) {
        if (array[i] > array[max_Index])
            max_Index = i;
    }
    return max_Index;
}

int minimum_of_two(int number1, int number2) {
    if (number1 < number2)
        return number1;
    else
        return number2;
}

void minCashFlowRecursion(int amount[], int num) {
    int maxCredit = get_Maximum(amount, num), maxDebit = get_Minimum(amount, num);

    if (amount[maxCredit] == 0 && amount[maxDebit] == 0)
        return;

    int minimum = minimum_of_two(-amount[maxDebit], amount[maxCredit]);
    amount[maxCredit] -= minimum;
    amount[maxDebit] += minimum;

    cout << "Person " << maxDebit << " pays " << minimum << " to " << maxCredit << "." << endl;

    minCashFlowRecursion(amount, num);
}

void minCashFlow(int graph[][MAX_PERSONS], int num) {
    int amount[MAX_PERSONS] = {0};

    for (int p = 0; p < num; p++) {
        for (int i = 0; i < num; i++) {
            amount[p] += (graph[i][p] - graph[p][i]);
        }
    }

    minCashFlowRecursion(amount, num);
}

int main() {
    int num_persons;
    cout << "Enter the number of persons: ";
    cin >> num_persons;

    int graph[MAX_PERSONS][MAX_PERSONS];

    cout << "Enter the expenses for each person:\n";
    for (int i = 0; i < num_persons; i++) {
        for (int j = 0; j < num_persons; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                cout << "Expense from Person " << i + 1 << " to Person " << j + 1 << ": ";
                cin >> graph[i][j];
            }
        }
    }

    minCashFlow(graph, num_persons);

    return 0;
}