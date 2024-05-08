#include <iostream>
#include <vector>
using namespace std;

void selectionsort(vector<int>& arr){
  for(int i=0; i<arr.size()-1; i++){
    int min_index = i;
    for(int j=i+1; j<arr.size(); j++){
      if(arr[j]<arr[min_index]){
        min_index = j;
      }
    }
    if(min_index!=i){
      swap(arr[i], arr[min_index]);
    }
  }
}

int main(){
  vector<int>a = {23,76,12,9,3,76};

  selectionsort(a);

  for(auto i: a){
    cout<<i<<" ";
  }
}