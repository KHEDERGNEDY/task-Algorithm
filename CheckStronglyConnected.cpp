#include <iostream>
#include<vector>
#include <list>
#include <cstdlib>
#include <ctime>
using namespace std;
class graph{
private:
    int V;
    int data;
    graph*next;
    graph*prev;
    vector<vector<int> > adjArray;
    vector<vector<int> > adjMatrix;
    list<int>*adjList;
    //خوارزمية DFS 
    void DFSArray(int v,vector<bool>&visited){
    visited[v]=true;
    for(int i=0;i<V;i++){
        if(adjArray[v][i]&& !visited[i]){
            DFSArray(i,visited);
        }}}
    void DFSMatrix(int v,vector<bool>&visited){
    visited[v]=true;
    for(int i=0;i<V;i++){
        if(adjMatrix[v][i]&& !visited[i]){
            DFSMatrix(i,visited);
        }}}
    void DFSList(int v,vector<bool>&visited){
    visited[v]=true;
    list<int>::iterator i;
    for( i= adjList[v].begin();i != adjList[v].end();i++){
        if(!visited[*i]){
            DFSList(*i,visited);
        }}}
public :
    //باني
    graph(int V){
    this->V=V;
    adjArray.resize(V,vector<int>(V,0));
    adjMatrix.resize(V,vector<int>(V,0));
    adjList=new list<int>[V];
    }
    void addEdge(int v, int w){
    adjArray[v][w]=1;
    adjMatrix[v][w]=1;
    adjList[v].push_back(w);
    }
    //التحقق إذا كان البيان متصل بقوة
    bool ConnectedArray(){
    vector<bool>visited(V,false);
    DFSArray(0,visited);
    for(bool v : visited){
        if(!v){
            return false;
        }
    }
    return true;
    }
    bool ConnectedMatrix(){
    vector<bool>visited(V,false);
    DFSMatrix(0,visited);
    for(bool v : visited){
        if(!v){
            return false;
        }
    }
    return true;
    }
    bool ConnectedList(){
    vector<bool>visited(V,false);
    DFSList(0,visited);
    for(bool v : visited){
        if(!v){
            return false;
        }
    }
    return true;
    }
void append(graph*& head, int data,int v) {
    graph* newNode = new graph(v);
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    graph* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}
//
يتم استخدام التابع append لإضافة كل قيمة عشوائية كعقدة جديدة في القائمة المرتبطة الثنائية

// تابع يوليد بيان عشوائي 
graph* generateRandomList(int numNodes) {
    graph* head = nullptr;
    srand(time(0)); // تهيئة مولد الأرقام العشوائية

    for (int i = 0; i < numNodes; i++) {
        int randomValue = rand() % 100; // 
rand() % 100 يستخدم لتوليد رقم عشوائي بين 0 و 99. الدالة rand() تولد رقمًا عشوائيًا، و% 100 يضمن أن الرقم سيكون في النطاق من 0 إلى 99.
      
//  append(head, randomValue);
يتم استخدام التابع append لإضافة كل قيمة عشوائية كعقدة جديدة في القائمة المرتبطة الثنائية
    }

    return head;
}
};


int main()
{
int numNodes = 5; 
//تحديد عدد العقد التي سيتم إنشاؤها في القائمة المرتبطة
graph g1(numNodes);
    graph* head = g1.generateRandomList(numNodes); 
//إنشاء قائمة مرتبطة ثنائية تحتوي على قيم عشوائية
graph  g(numNodes); if(g.ConnectedArray()&&g.ConnectedMatrix()&&g.ConnectedList()){
        cout<<"the graph is strongly connected."<<endl;
    }
    else{
        cout<<"the graph is not strongly connected."<<endl;
    }
    return 0;
}
