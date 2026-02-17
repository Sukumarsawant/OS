
//thread producer(func)
// producer.join to avoid terminating the main before the threads are finshed 
// we can do producer.detach so that producer can run independently in the backgroudn instead of main waiting for it 
//MUTEX lock is so that only one thread touches the shared variable at a time 


// if there are two locks m1 and m2 and both waiting for each other thats a deadlock state 

#include<bits/stdc++.h>
#include<mutex>
#include<windows.h>
using ll = long long ;
#define int ll
// #include<pthread.h>


using namespace std;

mutex m1,m2 ;

int counter =0 ;

void bind_to_core0() {
    DWORD_PTR mask = 0x1;  // Affinity mask for core 0 (bit 0 set)
    if (!SetProcessAffinityMask(GetCurrentProcess(), mask)) {
        cout << "Failed to set affinity: " << GetLastError()<<endl;
    }
}
// for uniprocessor make value -> 1000000000
// 100000
void producerinc(){

    /*------DEADLOCK FOR 2 LOCKS m1 and m2 first*/
    while(true){
        cout<<"producer locking m1"<<endl;
        m1.lock();
        cout<<"producer locked m1"<<endl;

    Sleep(100);
    
    cout<<"producer locking m2"<<endl;
    m2.lock();
    cout<<"producer locked m2"<<endl;

    
    m1.unlock();
    cout<<"producer unlocks m1"<<endl;
    
    
    m2.unlock();
    cout<<"producer unlocks m2"<<endl;
    }
}
void consumerinc(){
      /*------DEADLOCK FOR 2 LOCKS m1 and m2 first*/
 while(true){

        cout<<"consumer locking m2"<<endl;
        m2.lock();
        cout<<"consumer locked m2"<<endl;

    Sleep(100);

        cout<<"consumer locking m1"<<endl;
        m1.lock();
        cout<<" consumer locked m1"<<endl;


    
    m1.unlock();
    cout<<"consumer unlocks m1"<<endl;
    
    
    m2.unlock();
    cout<<"consumer unlocks m2"<<endl;
    }
}

signed main(){
    // bind_to_core0();  
    //-> for uniprocessor 

    thread producer,consumer;

    producer = thread(producerinc);
    consumer = thread(consumerinc);

    producer.join();
    consumer.join();

    cout<<counter<<endl;

}