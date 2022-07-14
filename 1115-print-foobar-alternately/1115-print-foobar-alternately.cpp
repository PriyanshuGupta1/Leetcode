class FooBar {
private:
    int n;
    std:: mutex(m);
    std:: condition_variable cv;
    int turn,itr;
public:
    FooBar(int n) {
        this->n = n;
        this->itr=n;
        turn=0;
    }
    
    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) 
        {
            std:: unique_lock lock(m);
            while(turn == 1)
                cv.wait(lock);
            printFoo();
            // cv.unlock();
            turn = 1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std:: unique_lock lock(m);
            while(turn == 0)
                cv.wait(lock);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            // cv.unlock();
            turn = 0;
            cv.notify_all();
        }
    }
};