#include <vector>
#include <ctime>                // keep this line if you want to generate different random objects for each run
#include "ShellSort.cpp"

vector<int> ShellSort(vector<MyObj>& , int);

//last left off comparing the code 0,1,2,3 outputs to one another --> should recieve same outcome for same vector
//..but need to switch a few things around so this can execute successfully



int main()
{
      srand(time(0));              // keep this line if you want to generate different random objects for each run

      
      int n = 100; //total number of arrays
      double total = 0.0; //hold total number of comparisons
      vector<int> comparisonArray; //hold each comparison

      for(int i=0; i<n; i++){ //create 5 different arrays with 10 elements in each
         cout << "Array " << i+1 << endl;
         vector<MyObj> vec;
         
         for(int j=0; j<9000; j++){ //add 10 elements in each array
            MyObj s;
            vec.push_back(s);
         }
         cout << "Code is " << 3 << endl;
         
         /*cout << "Array BEFORE:" << endl;
         for(int r = 0; r < 10; r++) {
            cout << vec[r] << endl; //printing elements in the array
         }*/

         cout << "CompareCount BEFORE check: " << MyObj::compareCount << endl;

         vector<MyObj> original = vec; //keeping original vector
         cout << endl;
         cout << endl;

         cout << vec.size() << " elements in each array" << endl;

         vector<int> hlist = ShellSort(vec, 3); 
         cout << "hlist: " << endl;
         for(int i=0; i<hlist.size(); i++){ //print h list
            cout << hlist.at(i) << endl;
         }
         
         /*cout << "Array AFTER:" << endl;
         for(int r = 0; r < 10; r++) {
            cout << vec[r] << endl; //printing elements in the array
         }*/
   
         cout << "Compare: " << (vec[0] < vec[1]) << endl;
         cout << "CompareCount : " << MyObj::compareCount << endl;

         comparisonArray.push_back(MyObj::compareCount);

         total += MyObj::compareCount; //add number of comparisons to average value
         for(int c=0; c<vec.size(); c++){
            vec.at(c).reset();
         }

         cout << "---- Next Array ---- " << endl;
         cout << endl;     

      }

      double average = total/n;

      cout << "AVERAGE # OF COMPARISONS : " << average << endl;

      double variance = 0.0;

      for (int i = 0; i < n; i++){
         double difference = comparisonArray.at(i) - average;
         variance += difference*difference;
      }

      variance = variance/n;

      double standardDeviation = sqrt(variance);
      cout << "STANDARD DEVIATION OF COMPARISONS : " << standardDeviation << endl;

   

   return 0;
}

