#include<bits/stdc++.h>
using namespace std;

int main()
{
    /*
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); */

    // The number of processes present in the system
    int numOfProcess;
    int timeQuant;

    cout << "Please enter the number of processes: " << endl;
    cin >> numOfProcess;
    cin.ignore();

    int burstTime[numOfProcess] = {0};
    int arrivalTime[numOfProcess] = {0};
    int remainingTime[numOfProcess] = {0};
    int completionTime[numOfProcess] = {0};
    int turnAroundTime[numOfProcess] = {0};
    int waitingTime[numOfProcess] = {0};

    cout << "Please enter the arrival time and the  burst time of each processes: " << endl;

    // taking burst time and arrival time of
    // each process
    for(int i=0; i<numOfProcess; i++)
    {
        cin >> arrivalTime[i];
        cin >> burstTime[i];
        cin.ignore();
        remainingTime[i] = burstTime[i];
    }
    cout << "Please enter the time quant: " << endl;
    cin >> timeQuant;

    // printing the input table
    cout << "PID"  << "\t";
    cout << "Arrival Time" << "\t";
    cout << "Burst Time" << endl;
    for(int i=0; i<37; i++)
        cout << "-";
    cout << endl;

    for(int i=0; i<numOfProcess; i++)
    {
        cout << "P" << i+1 << "\t\t";
        cout << arrivalTime[i] << "\t\t";
        cout << burstTime[i] << endl;
    }
    cout << endl;

    int time = 0;
    int temp = timeQuant;
    int count = numOfProcess;
    // untill every process gets completely executed
    while(count>=0)
    {
        for(int i=0; i<numOfProcess; i++)
        {
            // checking if the process has arrived yet
            if(arrivalTime[i] > time)
            {
                continue;
            }

            // if the process has been fully executed
            else if(remainingTime[i] == 0)
            {
                count--;
                continue;
            }

            // remaining burst time is less than time quant
            else if(remainingTime[i] <= timeQuant)
            {
                time += remainingTime[i];
                remainingTime[i] = 0;
                completionTime[i] = time;
            }

            else
            {
                remainingTime[i] -= timeQuant;
                time += timeQuant;
            }
        }
    }

    // calculating Turn Around Time
    for(int i=0; i<numOfProcess; i++)
    {
        turnAroundTime[i] = completionTime[i] - arrivalTime[i];
    }

    // calculating Waiting Time
    for(int i=0; i<numOfProcess; i++)
    {
        waitingTime[i] = turnAroundTime[i] - burstTime[i];
    }


    // printing the output table
    cout << "PID"  << "\t";
    cout << "Arrival Time" << "\t";
    cout << "Burst Time" << "\t";
    cout << "Completion Time" << "\t\t";
    cout <<"Turn Around Time" << "\t";
    cout << "Waiting Time" << endl;
    for(int i=0; i<105; i++)
        cout << "-";
    cout << endl;

    for(int i=0; i<numOfProcess; i++)
    {
        cout << "P" << i+1 << "\t\t";
        cout << arrivalTime[i] << "\t\t";
        cout << burstTime[i] << "\t\t";
        cout << completionTime[i] << "\t\t\t";
        cout << turnAroundTime[i] << "\t\t\t";
        cout << waitingTime[i] << endl;
    }
    cout << endl;

    // calculating average waiting time
    int sum = 0;
    for(int i=0; i<numOfProcess; i++)
    {
        sum += waitingTime[i];
    }
    cout << "Average waiting time: ";
    cout << sum / (numOfProcess * 1.0) << endl;

    // calculating average turnaround time
    sum = 0;
    for(int i=0; i<numOfProcess; i++)
    {
        sum += turnAroundTime[i];
    }
    cout << "Average turn around time: ";
    cout << sum / (numOfProcess * 1.0) << endl;


    return 0;
}
