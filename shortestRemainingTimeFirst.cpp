#include<bits/stdc++.h>
using namespace std;

// Creating a process type struct
struct Process
{
    int pid;
    int burstTime;
    int arrivalTime;
    int remainingTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
};

//sorts the array w.r.t burst time
bool compareRemainingBurst(Process a, Process b)
{
    return (a.remainingTime < b.remainingTime);
}

//sorts the array w.r.t arrival time
bool compareArrival(Process a, Process b)
{
    return (a.arrivalTime < b.arrivalTime);
}

//sorts the array w.r.t pid time
bool comparePid(Process a, Process b)
{
   return (a.pid < b.pid);
}


int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    // The number of processes present in the system
    int numOfProcess;
    cout << "Please enter the number of processes: " << endl;
    cin >> numOfProcess;
    cin.ignore();

    Process process[numOfProcess];

    cout << "Please enter the arrival time and the burst time of each processes: " << endl;

    // taking burst time and arrival time of
    // each process
    for(int i=0; i<numOfProcess; i++)
    {
        process[i].pid = i+1;
        cin >> process[i].arrivalTime;
        cin >> process[i].burstTime;
        cin.ignore();
        process[i].remainingTime = process[i].burstTime;
    }

    // Printing the input table
    cout << "PID"  << "\t";
    cout << "Arrival Time" << "\t" ;
    cout << "Burst Time" << endl;
    for(int i=0; i<37; i++)
        cout << "-";
    cout << endl;

    for(int i=0; i<numOfProcess; i++)
    {
        cout << "P" << process[i].pid << "\t\t";
        cout << process[i].arrivalTime << "\t\t";
        cout << process[i].burstTime << endl;
    }
    cout << endl;



    // sorting the processes w.r.t arrival time
    sort(process, process+numOfProcess, compareArrival);


    int flag1 = 0;
    int flag2 = 0;
    int time = 0;
    int count = numOfProcess;
    deque<Process> processQueue;
    vector<Process> doneProcesses;

    processQueue.push_back(process[0]);

    // runs until every process gets executed
    while(count > 0)
    {
        // flag2 checks for completion of a process
        flag1 = 0;
        // flag1 checks if a new process has come or not
        flag2 = 0;

        // untill the current process gets fully executed
        // or a new process arives
        while(processQueue[0].remainingTime > 0)
        {
            processQueue[0].remainingTime -= 1;
            time += 1;

            if(processQueue[0].remainingTime == 0)
            {
                processQueue[0].completionTime = time;
                flag1 = 1;
            }
                

            // checking for the arrival of new process
            for(int i=1; i<numOfProcess; i++)
            {
                if(time == process[i].arrivalTime)
                {
                    processQueue.push_back(process[i]);
                    flag2 = 1;
                    break;
                }
            }

            if(flag2 == 1)
                break;
        }

        // if the process has done executing
        if(flag1 == 1)
        {
            doneProcesses.push_back(processQueue[0]);
            processQueue.pop_front();
            count--;
        }
        
        int len = processQueue.size();
        sort(processQueue.begin(), processQueue.end(), compareRemainingBurst);
    }

    sort(doneProcesses.begin(), doneProcesses.end(), comparePid);



    // calculating Turn Around Time
    for(int i=0; i<numOfProcess; i++)
    {
        doneProcesses[i].turnAroundTime = doneProcesses[i].completionTime  - doneProcesses[i].arrivalTime;
    }

    // calculating Waiting Time
    for(int i=0; i<numOfProcess; i++)
    {
        doneProcesses[i].waitingTime = doneProcesses[i].turnAroundTime  - doneProcesses[i].burstTime;

        if(doneProcesses[i].waitingTime < 0)
            doneProcesses[i].waitingTime = 0;
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
        cout << doneProcesses[i].arrivalTime << "\t\t";
        cout << doneProcesses[i].burstTime << "\t\t";
        cout << doneProcesses[i].completionTime << "\t\t\t";
        cout << doneProcesses[i].turnAroundTime << "\t\t\t";
        cout << doneProcesses[i].waitingTime << endl;
    }
    cout << endl;

    // calculating average waiting time
    int sum = 0;
    for(int i=0; i<numOfProcess; i++)
    {
        sum += doneProcesses[i].waitingTime;
    }
    cout << "Average waiting time: ";
    cout << sum / (numOfProcess * 1.0) << endl;


    // calculating average turnaround time
    sum = 0;
    for(int i=0; i<numOfProcess; i++)
    {
        sum += doneProcesses[i].turnAroundTime;
    }
    cout << "Average turn around time: ";
    cout << sum / (numOfProcess * 1.0) << endl;

    return 0;
}
