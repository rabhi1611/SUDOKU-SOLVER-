#include<bits/stdc++.h>
using namespace std;
bool rakh_paye(int mat[][9],int i,int j,int n,int number){
	for(int a=0;a<n;a++){
		if(mat[a][j]==number || mat[i][a]==number){
			return false;
		}
	}
	int rn=sqrt(n);
	int x=(i/rn)*rn,y=(j/rn)*rn;
	for(int q=x;q<x+rn;q++){
		for(int w=y;w<y+rn;w++){
			if(mat[q][w]==number){
				return false;
			}
		}
	}
	return true;
}

bool solve_sudoku(int mat[][9],int i,int j,int n){
	if(i==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	if(j==n){
		return solve_sudoku(mat,i+1,0,n);
	}
	if(mat[i][j]!=0){
		return solve_sudoku(mat,i,j+1,n);
	}
	for(int number=1;number<=9;number++){
		if(rakh_paye(mat,i,j,n,number)){
			mat[i][j]=number;
			bool next=solve_sudoku(mat,i,j+1,n);
			if(next==true){
				return true;
			}
		}
	}
	mat[i][j]=0;
	return false;
}
int main() {
	int n;
	cin>>n;
	int mat[9][9]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
        }
	}

	solve_sudoku(mat,0,0,n);
	return 0;
}