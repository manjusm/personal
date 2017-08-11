
/*
Shoemaker's Problem
===================

    A shoemaker has N orders from customers that he must execute.
    The shoemaker can work on only one job each day. For each job i, 
    it takes Ti days for the shoemaker to finish the job, where Ti is 
    an integer and (1 ≤ Ti ≤ 1000). For each day of delay before 
    starting to work for the job i, shoemaker must pay a fine of Si 
    (1 ≤ Si ≤ 10000) rupees. Your task is to help the shoemaker find 
    the sequence in which to complete the jobs so that his total fine 
    is minimized. If multiple solutions are possible, print the one 
    that is lexicographically least (i.e., earliest in dictionary order).

    Solution hint
    =============
    Sort the jobs in terms of the ratios Si / Ti. To compare a/b and c/d, 
    cross-multiply to avoid floating point comparisons. 
    Use a stable sort to get the lexicographically smallest value.

    Input format
    ============
    The first line of input contains an integer N (1 ≤ N ≤ 100000). 
    Each of the next N lines contains two space separated integers: 
    the time Ti and fine Si for job i, 1 ≤ i ≤ N.

    Output format
    =============
    You program should print the sequence of jobs with minimal fine. 
    Each job should be represented by its position in the input and each 
    job should appear on a new line, by itself. If multiple solutions are 
    possible, print the one that is lexicographically least (i.e., earliest in dictionary order).

    Sample input
    ============
    4 
    3 4
    1 1000
    2 2
    5 5

    Sample output 
    =============
    2
    1
    3
    4 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

struct Job {
    int num;
    int t, s;
};

struct Job jobs[MAX+1];

int compare(struct Job *job1, struct Job *job2)
{
    int d =  job2->s * job1->t - job1->s * job2->t;
    if (d != 0) {
        return d;
    }
    return (job1->num - job2->num);
}


int main()
{
    int  n;  
    int j;
    scanf("%d", &n);
    for (j = 0; j < n; j++) {
        jobs[j].num = j;
        scanf("%d %d", &jobs[j].t, &jobs[j].s);
    }   
    qsort(jobs, n, sizeof(struct Job), (int(*)(const void *, const void *))compare);

    for (j = 0; j < n; j++) {
        printf("%d\n", (jobs[j].num+1));
    }
    return 0;
}
