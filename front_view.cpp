#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;
	node(int inputdata) {
		data = inputdata;
		left = NULL;
		right = NULL;
	}
};
node* buildTree() {
	int x;
	cin >> x;
	if (x == -1) {
		return NULL;
	} else {
		node* n = new node(x);
		n->left = buildTree();
		n->right = buildTree();

		return n;
	}
}
vector<int> top_view(node* root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    queue<pair<node*,int>>q;
    map<int,int>mpp;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        node* n=it.first;
        int line=it.second;
        if(mpp.find(line)==mpp.end()){
            mpp[line]=n->data;
        }
        if(n->left!=NULL){
            q.push({n->left,line-1});
        }
        if(n->right!=NULL){
            q.push({n->right,line+1});
        }
    }
    for(auto x:mpp){
        ans.push_back(x.second);
    }
    return ans;
}
int main(){
    node *root=buildTree();
    vector<int>ans=top_view(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
}
