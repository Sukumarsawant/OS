
//thread producer(func)
// producer.join to avoid terminating the main before the threads are finshed 
// we can do producer.detach so that producer can run independently in the backgroudn instead of main waiting for it 
//MUTEX lock is so that only one thread touches the shared variable at a time 

#include<bits/stdc++.h>
#include<mutex>
#include<windows.h>
using ll = long long ;
#define int ll
// #include<pthread.h>


using namespace std;

mutex m ;

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
    for(int i =0; i < 10000000; ++i ){
        lock_guard<mutex> lock(m);
        // m.lock();
        counter++;
        // m.unlock();
        // this_thread::sleep_for(chrono::milliseconds(1));
    }
}
void consumerinc(){
    for(int i =0; i < 10000000; ++i ){
        lock_guard<mutex> lock(m);
        // m.lock();
        counter--;
        // m.unlock();
        // this_thread::sleep_for(chrono::milliseconds(1));
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