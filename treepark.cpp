#include <bits/stdc++.h>

using namespace std;

struct Node {
    int n;
    vector<Node*>children;
    bool hasCat;
    int consecutivecats;

    Node(int n) {
        this->n = n;
        this->consecutivecats = 0;
    }
};

vector<Node*>nodes;

void buildTree(vector<vector<int>>edgelist) {
    for (int i = 0; i < edgelist.size(); i++) {
        (nodes[edgelist[i][0]])->children.push_back(nodes[edgelist[i][1]]);
    }
}

void dfs(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->n << " ";
    for (int i = 0; i < root->children.size(); i++) {
        dfs(root->children[i]);
    }
}

void traversing(Node* root, int catsonpath, int& result, int m) {
    if (root == NULL) {
        return;
    }
    if (root->children.size() == 0) {
        result++;
        return;
    }
    if (catsonpath != 0 && root->hasCat == 0) {
        catsonpath = 0;
    }
    else {
        catsonpath++;
    }

    if (catsonpath > m) {
        return;
    }

    for (int i = 0; i < root->children.size(); i++) {
        traversing(root->children[i], catsonpath, result, m);
    }

}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int>catArray{-1};
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        catArray.push_back(temp);
    }
    vector<vector<int>>edgelist;
    for (int i = 0; i < n-1;i++) {
        int a, b;
        cin >> a>>b;
        edgelist.push_back(vector<int>{a,b});
    }

    for (int i = 0; i < n+1 ;i ++) {
        Node* root = new Node(i);
        nodes.push_back(root);
    }

    for (int i = 1; i < nodes.size()+1; i++) {
        nodes[i]->hasCat = catArray[i];
        if (catArray[i] == 1) {
            nodes[i]->consecutivecats = 1;
        }

    }

    buildTree(edgelist);
    cout << "output" << endl;
    dfs(nodes[1]);
    int result = 0;
    if (nodes[1]->hasCat) traversing(nodes[1], 1, result, m);
    else traversing(nodes[1], 0, result, m);
    cout << result << endl;
    return 0;
} 
