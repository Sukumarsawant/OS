
//thread t1(func)
// t1.join to avoid terminating the main before the threads are finshed 
// we can do t1.detach so that t1 can run independently in the backgroudn instead of main waiting for it 

#include<bits/stdc++.h>
#include<windows.h>
// #include<pthread.h>

using namespace std;

int counter =0 ;

void bind_to_core0() {
    DWORD_PTR mask = 0x1;  // Affinity mask for core 0 (bit 0 set)
    if (!SetProcessAffinityMask(GetCurrentProcess(), mask)) {
        cout << "Failed to set affinity: " << GetLastError()<<endl;
    }
}

void t1inc(){
    for(int i =0; i < 1000; ++i ){
        counter++;
        cout<<" + "<<counter<<endl;
        this_thread::sleep_for(chrono::milliseconds(2));
    }
}
void t2inc(){
    for(int i =0; i < 1000; ++i ){
        counter--;
        cout<<" - "<<counter<<endl;
        this_thread::yield();
        this_thread::sleep_for(chrono::milliseconds(2));
    }
}
void t3waste(){
    int ct =0;
    for(int i =0; i < 1000; ++i ){
        ct--;
        // this_thread::sleep_for(chrono::milliseconds(200));
    }
}
int main(){
    bind_to_core0(); 

    thread t1,t2,t3;

    t1 = thread(t1inc);
    t2 = thread(t2inc);
    t3 = thread(t3waste);

    t1.join();
    t2.join();
    t3.join();

    cout<<counter<<endl;

}