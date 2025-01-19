#include<bits/stdc++.h>// خضر علي جنيدي , روان محمد عبد الله, زين رائد سليم
using namespace std;
class Graph {
private:
    int V; // عدد العقد في البيان
    vector<vector<int>> adj; // قائمة الجوار و مخزنة على شكل adjacency list
    void bridgeUtil(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent, int& count)
    {
    static int time = 0; 
    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent, count);
            low[u] = min(low[u], low[v]);
            // شرط الجسر
            if (low[v] > disc[u]) {
                count++; // زيادة العد
            }
        } 
        else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

public:
    Graph(int V)  // الباني
    {
    this->V = V;
    adj.resize(V);
    }
    void addEdge(int u, int v) // تابع لإضافة الوصلات إلى البيان
    {
    adj[u].push_back(v);
    adj[v].push_back(u); // لأننا نتعامل مع بيان غير موجه
    }
    int countBridges() // تابع يحسب عدد الجسور في البيان إعتمادا على التابع المعرف مسبقا
    {
    vector<bool> visited(V, false);
    vector<int> disc(V);
    vector<int> low(V);
    vector<int> parent(V, -1);
    int count = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            bridgeUtil(i, visited, disc, low, parent, count);
        }
    }

    return count; // إرجاع عدد الجسور
    }
    void generateRandomGraph(int edges) // تابع لتوليد بيان عشوائي من خلال إضافة وصلات عشوائية بين العقد
    {
    srand(time(0)); // لتوليد أرقام عشوائية
    for (int i = 0; i < edges; i++) {
        int u = rand() % V;
        int v = rand() % V;

        // تجنب إضافة حلقة ذاتية أو حافة موجودة مسبقا
        if (u != v && find(adj[u].begin(), adj[u].end(), v) == adj[u].end()) {
            addEdge(u, v);
        }
    }
    }
};

int main() {
    int Numb_Of_Vertices; // عدد الرؤوس
    int Num_Of_Edges;    // عدد الحواف
    cout<<"Enter The Number Of The Vertices in The Graph :  ";
    cout<<"Enter The Number Of The Edges in The Graph :  ";

    Graph g(Numb_Of_Vertices);// تعريف بيان جديد من الصف Graph

    g.generateRandomGraph(Num_Of_Edges);//توليد وصلات البيان بشكل عشوائي من خلال تابع توليد البيانات العشوائية 

    int Num_Of_Bridge = g.countBridges();//   حساب عدد الجسور عن طريق التابع الذي عرفناه سابقا
    if(Num_Of_Bridge==0)cout<<"The Graph has 0 bridge "<<endl;
    else cout<<"There are bridges in the Graph"<<endl;
}
//-----------End--OF--Code----------------------------------------------------------------------------
