#include <iostream>
#include<utility>
#include <time.h>
using namespace std;

pair <int, int> random_walk(int n){
   int x(0), y(0); 
   string direction[] = {"N", "NW", "W", "SW", "S", "SE", "E", "NE"};
  
  for(int i = 0; i < n; ++i){
    int r = rand() % 8;
   
    if (direction[r] == "N"){
      y += 1;
      }
    else if (direction[r] == "NW"){
      x -= 1;
      y += 1;
      }
    else if (direction[r] == "W"){
      x -= 1;
      }
    else if (direction[r] == "SW"){
      x -= 1;
      y -= 1;
      }
    else if (direction[r] == "S"){
      y -= 1;
      }
    else if (direction[r] == "SE"){
      x += 1;
      y -= 1;
      }
    else if (direction[r] == "E"){
      x += 1;
      }
    else{
      x += 1;
      y += 1;
      }
    }
  return {x,y};
}

int main() {
  srand ( time(NULL) );

  pair<int, int> p; //Taking a pair to store our function's result
  
  int k(0), num_walks(50000); //k is the counter for how many times panda falls in a hole
  
  for(int i = 1; i <= 30; ++i){
    for(int j = 0; j < num_walks; ++j){
      
      p = random_walk(i);
      
      if(p == make_pair(4,4) || p == make_pair(-4,4) || p == make_pair(-4,-4) || p == make_pair(4,-4)){
        k += 1;       
      }
    }
    cout << "Iteration #" << i << ": Panda falls for " << k << "times" << endl;
  }
  
  double total_walks = num_walks*30; //sample space
  
  cout << "\nNumber of times that the Panda ended up in holes = " << k << endl;
  
  cout << "\nProbability that the Panda will get killed = " << (k / total_walks)*100 << "%" << endl;
}