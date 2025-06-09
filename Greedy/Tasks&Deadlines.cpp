Tasks and deadlines
 Let us now consider a problem where we are given n tasks with durations and
 deadlines and our task is to choose an order to perform the tasks. For each task,
 we earn d-x points where d is the task’s deadline and x is the moment when we
 finish the task. What is the largest possible total score we can obtain?
 For example, suppose that the tasks are as follows:
 task duration deadline
 A 4 2
 B 3 5
 C 2 7
 D 4 5
 In this case, an optimal schedule for the tasks is as follows:

 0-2-5-9-13
C , B , A , D

 In this solution, C yields 5 points, B yields 0 points, A yields 7 points and D
 yields 8 points, so the total score is 10.
 Surprisingly, the optimal solution to the problem does not depend on the
 deadlines at all, but a correct greedy strategy is to simply perform the tasks
 sorted by their durations in increasing order. The reason for this is that if we
 ever perform two tasks one after another such that the first task takes longer
 than the second task, we can obtain a better solution if we swap the tasks. For
 example, consider the following schedule:
 60
X
 Y
 a
 Here a b,soweshould swap the tasks:
 Y
 X
 b
 b
 a
 Now X gives b points less and Y gives a points more, so the total score increases
 by a b 0.Inanoptimalsolution, for any two consecutive tasks, it must hold
 that the shorter task comes before the longer task. Thus, the tasks must be
 performed sorted by their durations