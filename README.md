# Process Scheduling Simulator

Hey there! This is a simple C program that simulates **First Come First Served (FCFS)** and **Shortest Job First (SJF)** scheduling algorithms. 
It calculates things like **waiting time**, **turnaround time**, and **response time** for each process and displays it all for you!

## What It Does

- **First Come First Served (FCFS)**: The process that arrives first is executed first.
- **Shortest Job First (SJF)**: The process with the shortest burst time gets executed first.
- It will calculate and show the **average waiting time**, **average turnaround time**, and **average response time**.

## How to Run

Open a terminal in the project directory and run:

```bash
gcc scheduler.c -o scheduler
```

- `scheduler.c` — source file  
- `scheduler` — output executable name

---

Run the compiled program:

```bash
./scheduler    # Linux / Mac
scheduler.exe  # Windows
```

The program will prompt you to:

1. Enter the number of processes.
2. Enter the arrival time and burst time for each process.

Example:

```
Enter the number of processes: 4
Enter the arrival time and burst time for process 1: 0 8
Enter the arrival time and burst time for process 2: 1 4
Enter the arrival time and burst time for process 3: 2 9
Enter the arrival time and burst time for process 4: 3 5
```

---

## Output

The program will display:

1. **Gantt Chart** showing the order of execution.  
2. **Process table** with:

| PID | AT | BT | WT | TAT | RT |

- AT — Arrival Time  
- BT — Burst Time  
- WT — Waiting Time  
- TAT — Turnaround Time  
- RT — Response Time

3. **Average waiting, turnaround, and response times**.

Example output:

```
=== First Come First Served (FCFS) ===
Gantt Chart: | P1 |   P2   |   P3   |   P4   |
PID     AT     BT     WT     TAT    RT
1       0      8      0      8      0
2       1      4      7      11     7
3       2      9      10     19     10
4       3      5      18     23     18

Average Waiting Time: 8.75
Average Turnaround Time: 15.25
Average Response Time: 8.75
```

```
=== Shortest Job First (SJF) ===
Gantt Chart: | P2 | P4 |   P1   |   P3   |
PID     AT     BT     WT     TAT    RT
1       0      8      0      8      0
2       1      4      7      11     7
4       3      5      9      14     9
3       2      9      15     24     15

Average Waiting Time: 7.75
Average Turnaround Time: 14.25
Average Response Time: 7.75
```

---

## Notes

- Both **FCFS** and **SJF** are non-preemptive.  
- If no process has arrived at the current time, the CPU stays idle until a process arrives.  
- In SJF, if multiple processes have the same burst time, the one with **earlier arrival** is selected first.

