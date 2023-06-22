#include<iostream>
#include<vector>
#include<cstdlib>
#include<fstream>
#include<ctime>
using namespace std;
int main() {

    srand(time(NULL));
    int num = 0;
    int heads = 0;
    int tails = 0;
    char op;
    ofstream ofile;

    cout<<"Do you want to store the data in a separate file?(y/n)";
    cin>>op;

    if (op == 'y' || op == 'Y' || op == 'yes') {

      string filename;
      cout<<"Enter filename: \n";
      cin>>filename;
      ofile.open(filename.c_str());
    }

    cout<<"How many times do you want to flip the coin? \n";
    cout<<"0 as tails\n";
    cout<<"1 as heads";


    cin>>num;
    
    vector<int> total(num); //vectors are essentially dynamic arrays

    for(int i = 0; i<total.size(); i++) {

      total[i] = rand()%2;
      if(total[i] == 0) {
        
        if (op == 'y' || op == 'Y' || op == 'yes') {

          ofile<<"Tails"<<total[i]<<" ";
        }
        tails++;
      }
      else if(total[i] == 1) {

        ofile<<"Heads"<<total[i]<<" ";
        heads++;
      }

    }
    cout<<"Total: "<<total.size()<<endl;
    cout<<"Heads: "<<heads<<endl;
    cout<<"Tails: "<<tails<<endl;

    ofile.close();
}