#include<iostream>
#include<stack>
#include<queue>

using namespace std;


int main(){

  queue<int> q1;
  queue<int> q2;

  cout<<"Enter Numbers in the queue\n"<<endl;
  cout<<"To stop Entering numbers press 0\n"<<endl;
  int n;
  cin>>n;

  while(n){
    q1.push(n);
    cin>>n;
  }

  stack<int>s;
  int temp,queueBack = -32768;
  bool flag = false;

  while(!q1.empty()){
    temp = q1.front();
    q1.pop();

    if((temp <= q1.front()) && (temp < queueBack)){
      flag = true;
      break;
    }

    if((temp <= q1.front()) && (temp >= queueBack)){
     q2.push(temp);
     queueBack = temp;
    }

    else if(temp > q1.front() && s.empty()){
      s.push(temp);
    }

    else if(temp > q1.front() && !s.empty()){
      if(temp <= s.top()) s.push(temp);
      if(temp > s.top()){
        flag = true;
        break;
      }

    }

  }

  if(flag == false){
    while(!s.empty()){
      q2.push(s.top());
      s.pop();
    }

  }


 if(flag == true){
   cout<<"Can't be represented in ascendng order"<<endl;
 }
 if(flag == false){
   cout<<"Can be represented in ascending order"<<endl;
 }



}
