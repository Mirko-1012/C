#include <stdio.h>

void readVotes(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int vote;
        do {
            printf("Enter vote for candidate %d (0 - 30): ", i + 1);
            scanf("%d", &vote);
            if(vote < 0 || vote > 30){
                printf("Invalid vote. Please enter a value between 0 and 30.\n");
            }
        } while(vote < 0 || vote > 30);
        a[i] = vote;
    }
}

void printArray(int a[], int n) {
    printf("Votes for candidates:\n");
    for (int i = 0; i < n; i++) {
        printf("Candidate %d: %d\n", i + 1, a[i]);
    }
}

double average(const int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return (double)sum / n;
}

int minArray(const int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

int maxArray(const int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int countPassed(const int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 18) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;

    do {
        printf("Enter the number of candidates (1 - 50): ");
        scanf("%d", &n);
        if(n < 1 || n > 50){
            printf("Invalid number of candidates. Please enter a value between 1 and 100.\n");
        }
    } while(n < 1 || n > 50);

    int votes[n];
    readVotes(votes, n);
    printArray(votes, n);

    double avg = average(votes, n);
    int min = minArray(votes, n);
    int max = maxArray(votes, n);
    int passed = countPassed(votes, n);

    printf("Average votes: %.2f\n", avg);
    printf("Minimum votes: %d\n", min);
    printf("Maximum votes: %d\n", max);
    printf("Number of candidates who passed (18 or more votes): %d\n", passed);

    return 0;
}