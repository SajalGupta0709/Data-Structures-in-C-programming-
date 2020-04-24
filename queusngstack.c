#include<iostream>
#include<stack>

using namespace std;

struct queue{
 stack<int>s1;
 stack<int>s2;

};

void Enqueue(int x, queue* q){
  (q->s1).push(x);

}

void Dequeue(queue* q){
  if((q->s2).empty() && !(q->s1).empty()){
    while(!(q->s1).empty()){
      (q->s2).push((q->s1).top());
      (q->s1).pop();

    }

  }
  (q->s2).pop();


}

int  peek(queue* q){
  if((q->s2).empty() && !(q->s1).empty()){
    while(!(q->s1).empty()){
      (q->s2).push((q->s1).top());
      (q->s1).pop();

    }

  }
  return ((q->s2).top());



}

int main(){
  cout<<"Enter The values To Enqueue In the Queue"<<endl;
  cout<<"To stop Entering press 0"<<endl;

  queue* q = new queue();
  int n;
  cin>>n;
  while(n){
    Enqueue(n,q);
    cout<<"Enter Another Number"<<endl;
    cin>>n;
  }

  cout<<"press 1 to Dequeue the queue"<<endl;
  cin>>n;
  while(n == 1){
    cout<<"peek Element is:: "<<peek(q)<<endl;
    Dequeue(q);
    if((q->s1).empty() && (q->s2).empty()){
    cout<<"The stack Queue is Empty now\n";
    break;

   }
    cin>>n;
  }


}
