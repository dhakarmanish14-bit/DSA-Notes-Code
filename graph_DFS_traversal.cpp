#include<iostream>
#include<stack>
using namespace std;
void createAdjacentMatrix(int graph[10][10],int n){
    cout<<"enter adjacent matrix row wise" <<endl;
    cout<<"-> where edge=row and column=node"<<endl;
    cout<<"-> 1 for edge present and 0 for edge absent "<<endl;
    cout<<"enter matrix"<<endl;
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           cin>>graph[i][j];}}}
void DFS(int start, int n, int graph[10][10]) {
    bool visited[10] = {false};
    stack<int> s;
    s.push(start);
    while(!s.empty()) {
        int node = s.top();
        s.pop();
        if(visited[node]) continue;
        visited[node] = true;
        cout << node << " ";
        for(int i = n - 1; i >= 0; i--) {
            if(graph[node][i] == 1 && !visited[i]) {
                s.push(i); }}}}
int main(){
    int n;
    cout<<"enter no. of nodes of graph"<<endl;
    cin>>n;
    int graph[10][10];
    createAdjacentMatrix(graph,n);
    DFS(0,n,graph);
    return 0;}