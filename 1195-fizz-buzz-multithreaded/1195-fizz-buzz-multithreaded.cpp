class FizzBuzz {
private:
    int n;
    std::mutex m;
    std::condition_variable cv;
    int num,turn;
public:
    FizzBuzz(int n) 
    {
        this->n = n;
        this->num=1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(num <= n )
        {
            std::unique_lock lock(m);
            while(num<=n && ((num%3 == 0 && num%5 != 0)==0))
                cv.wait(lock);
            if(num<=n)
            {
                printFizz();
                num++;
            }
            lock.unlock();
            cv.notify_all();
        }    
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(num <= n )
        {
            std::unique_lock lock(m);
            while(num<=n && ((num%3 != 0 && num%5 == 0)==0))
                cv.wait(lock);
            if(num<=n)
            {
                printBuzz();
                num++;
            }
            lock.unlock();
            cv.notify_all();
        }    
        
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(num <= n )
        {
            std::unique_lock lock(m);
            while(num<=n && ((num%3 == 0 && num%5 == 0)==0))
                cv.wait(lock);
            if(num<=n)
            {
                printFizzBuzz();
                num++;
            }
            lock.unlock();
            cv.notify_all();
        }    
        
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(num <= n )
        {
            std::unique_lock lock(m);
            while(num<=n && ((num%3 != 0 && num%5 != 0)==0))
                cv.wait(lock);
            if(num<=n)
            {
                printNumber(num);
                num++;
            }
            lock.unlock();
            cv.notify_all();
        }    
        
    }
};