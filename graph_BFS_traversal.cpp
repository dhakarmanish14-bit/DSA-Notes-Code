#include<iostream>
#include<queue>
using namespace std;
void createAdjacentMatrix(int graph[10][10],int n){
    cout<<"enter adjacent matrix row wise" <<endl;
    cout<<"-> where edge=row and column=node"<<endl;
    cout<<"-> 1 for edge present and 0 for edge absent "<<endl;
    cout<<"enter matrix"<<endl;
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           cin>>graph[i][j];}}}
void BFS(int start,int n,int graph[10][10]){
     bool visited[10]={false};
     queue<int>q1;
     visited[start]=true;
     q1.push(start);
     while(!q1.empty()){
          int nodeNo=q1.front();
          q1.pop();
          cout<<nodeNo<<" "<<endl;
          for(int i=0;i<n;i++){
             if(graph[nodeNo][i]==1&& !visited[i]){
                visited[i]=true;
                q1.push(i);}}}}    
               
              
int main(){
    int n;
    cout<<"enter no. of nodes of graph"<<endl;
    cin>>n;
    int graph[10][10];
    createAdjacentMatrix(graph,n);
    BFS(0,n,graph);
    return 0;}