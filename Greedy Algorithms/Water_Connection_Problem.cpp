#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ============== WATER CONNECTION PROBLEM ============
// ==> STATEMENT
// Every house in the colony has at most one pipe going into it and at most one pipe going out of it. Tanks and taps are to be installed in a manner such that every house with one outgoing pipe but no incoming pipe gets a tank installed on its roof and every house with only an incoming pipe and no outgoing pipe gets a tap.

// Given two integers n and p denoting the number of houses and the number of pipes. The connections of pipe among the houses contain three input values: a_i, b_i, d_i denoting the pipe of diameter d_i from house a_i to house b_i, find out the efficient solution for the network. 

// The output will contain the number of pairs of tanks and taps t installed in first line and the next t lines contain three integers: house number of tank, house number of tap and the minimum diameter of pipe between them.

// ==> EXAMPLES
// Input:  4 2
//         1 2 60
//         3 4 50
// Output: 2
//         1 2 60
//         3 4 50
// Explanation:
// Connected components are: 1->2 and 3->4
// Therefore, our answer is 2 followed by 1 2 60 and 3 4 50.

// Input: 9 6
//        7 4 98
//        5 9 72
//        4 6 10
//        2 8 22
//        9 7 17
//        3 1 66
// Output: 3
//         2 8 22
//         3 1 66
//         5 6 10
// Explanation:
// Connected components are 3->1, 5->9->7->4->6 and 2->8. 
// Therefore, our answer is 3 followed by 2 8 22, 3 1 66, 5 6 10

// ==> APPROACH
// Perform DFS from appropriate houses to find all different connected components. The number of different connected components is our answer t. 
// The next t lines of the output are the beginning of the connected component, end of the connected component and the minimum diameter from the start to the end of the connected component in each line. 
// Since, tanks can be installed only on the houses having outgoing pipe and no incoming pipe, therefore these are appropriate houses to start DFS from i.e. perform DFS from such unvisited houses.

int number_of_houses,number_of_pipes;
int ending_vertex_pipes[1100];

int main(){

}