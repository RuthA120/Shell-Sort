#include "MyObj.cpp"
#include <vector>

vector<int> ShellSort(vector<MyObj>& arr, int code){
  vector<int> res; //holds values for h-list
  int n = arr.size(); //keep track of size of array
  int k = 0; //max number

  if(code == 0){
    res.push_back(1);
  }
  else if(code == 1){
    while(pow(2, (k+1))-1 <= n){ //check until array size is reached
      k++; //increasing number
    }
    for(int i=k; i>0; i--){
      res.push_back(pow(2, i)-1);
    }
  }
  else if(code == 2){
    while((pow(3, k+1)-1)/2 <= n){ //check until array size is reached
      k++; //increasing number
      cout << (pow(3, k+1)-1)/2 << endl;
    }
    for(int i=k; i>0; i--){
      res.push_back((pow(3, i)-1)/2);
    }
  }
  else if(code == 3){
    int c = 1; //current number
    res.push_back(c);
    while(c < n){ //checking until c is greater than or equal to array size
      res.push_back(c*2);
      res.push_back(c*3);
      res.push_back(c*6);
      c = res.at(res.size()-1); //initalize c to just added number/item
    }

    for(int i=res.size()-1; i>res.size()-4; i--){ //removing numbers that may be larger than size of array
      if(res.at(i) > n){
        res.pop_back();
      }
    }

    vector<int> reversed; //vector that temporarily holds reversed vector
    int j=0; //keeps track of iteration for reversed vector
    for(int i=res.size()-1; i>=0; i--){ //reversing the hlist
        reversed.push_back(res.at(i));
    }

    res = reversed;
  }
  else{
    std::cerr << "You inputted an invalid value" << std::endl;
    return res;
  }



  for(int k=0; k<res.size(); k++){
    int h = res[k];
    cout << "h occuring: " << h << endl << endl;

    for(int j=0; j<n; j++){
      MyObj temp = arr[j];
      int i = j;
      while((i >= h) && (temp < arr[i-h])){
        arr[i] = arr[i-h];
        i = i - h;
      }
      arr[i] = temp;

    }

  }

  return res;
}
