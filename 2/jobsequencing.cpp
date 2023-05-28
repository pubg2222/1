#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// A structure to represent a job

struct Job
{
    char id;    // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// Comparator function for sorting jobs

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}
// Returns maximum profit from jobs
void printJobScheduling(vector<Job> &arr)
{
    int n;
    cout << "Enter the length of free slot: ";
    cin >> n;
    // Sort all jobs according to decreasing order of profit

    sort(arr.begin(), arr.end(), comparison);
    int result[n]; // To store result (Sequence of jobs)
    bool slot[n];  // To keep track of free time slots
    // Initialize all slots to be free
    for (int i = 0; i < n; i++)
        slot[i] = false;
    // Iterate through all given jobs
    for (int i = 0; i < n; i++)
    {
        // Find a free slot for this job (Note that we start
        // from the last possible slot)
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
        {
            // Free slot found
            if (slot[j] == false)
            {
                result[j] = i;  // Add this job to result
                slot[j] = true; // Make this slot occupied
                break;
            }
        }
    }
    // Print the result
    cout << "Job sequence with maximum profit: ";
    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << arr[result[i]].id << " ";
}
int main()
{
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;
    vector<Job> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter details for Job " << i + 1 << endl;
        cout << "Id: ";
        cin >> arr[i].id;
        cout << "Deadline: ";
        cin >> arr[i].dead;
        cout << "Profit: ";
        cin >> arr[i].profit;
    }
    // Function call
    printJobScheduling(arr);
    return 0;
}
/*
The given code implements a job scheduling algorithm using a greedy approach. It takes input for a set of jobs with their deadlines and profits, and then determines the sequence of jobs that maximizes the total profit.

Let's go through the code step by step:

1. First, the necessary header files (`iostream`, `vector`, and `algorithm`) are included.

2. A structure `Job` is defined to represent a job. It contains three members:
   - `id`: Represents the job ID (a character)
   - `dead`: Represents the deadline of the job (an integer)
   - `profit`: Represents the profit if the job is completed before or on the deadline (an integer)

3. The code defines a comparison function `comparison` that compares two jobs based on their profits. It is used for sorting the jobs in descending order of profit.

4. The `printJobScheduling` function is defined, which takes a reference to a vector of `Job` objects as input. It performs the job scheduling algorithm and prints the job sequence with maximum profit.

5. The function prompts the user to enter the length of the free time slot (the total number of slots available for scheduling).

6. The `arr` vector of `Job` objects is sorted in descending order of profit using the `sort` function and the `comparison` function as the comparator.

7. Two arrays, `result` and `slot`, are initialized. The `result` array will store the indices of the jobs in the order they are scheduled, and the `slot` array will keep track of the availability of time slots.

8. A loop iterates through all the given jobs:

   a. For each job, another loop finds a free time slot starting from the last possible slot (min(n, arr[i].dead) - 1) and moving backward.

   b. If a free slot is found, the current job is added to the `result` array at that slot, and the `slot` array is marked as occupied.

9. After the loop completes, the function prints the job sequence with maximum profit by iterating through the `slot` array and printing the job IDs for occupied slots.

10. In the `main` function:

   a. The user is prompted to enter the number of jobs.

   b. A vector `arr` is created with size `n` to store the job details.

   c. A loop is used to input the details of each job, including the ID, deadline, and profit.

   d. Finally, the `printJobScheduling` function is called with the `arr` vector as an argument.

11. The program ends by returning 0.

Overall, the code implements a job scheduling algorithm based on maximum profit, sorting the jobs in descending order of profit, and assigning jobs to time slots starting from the last possible slot. The output is the job sequence that maximizes the total profit.
*/