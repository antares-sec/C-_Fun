#include <iostream>


template <typename X_VALUE, typename Y_VALUE>
class Calculator{
    public:
        X_VALUE x = 0;
        Y_VALUE y = 0;

        // Constructor
        Calculator(X_VALUE x_val, Y_VALUE y_val) : x(x_val), y(y_val){}

        // Virtual Function for result
        virtual auto result() const -> decltype(x + y) = 0;

        // Virtual Destructor
        virtual ~Calculator() = default;
        
};

template <typename X, typename Y>
class Addition : public Calculator<X, Y> {
    public:
        // Constructor
        Addition(X x_val, Y y_val) : Calculator<X, Y> (x_val, y_val){}

        auto result() const -> decltype(this->x + this->y) override{
            return this->x + this->y;
        }
};

template <typename X, typename Y>
class Multiplication : public Calculator <X, Y>{
    public:
        // Constructor
        Multiplication(X x_val, Y y_val) : Calculator<X, Y> (x_val, y_val){}

        auto result() const -> decltype(this->x + this->y) override{
            return this->x * this->y;
        }
};

template <typename X, typename Y>
class Substraction : public Calculator <X, Y>{
    public:
        // Constructor
        Substraction(X x_val, Y y_val) : Calculator<X, Y> (x_val, y_val){}

        auto result() const -> decltype(this->x - this->y) override{
            return this->x - this->y;
        }
}; 

template <typename X, typename Y>
class Divide : public Calculator <X, Y> {
    public: 
        // Constructor
        Divide(X x_val, Y y_val) : Calculator<X, Y> (x_val, y_val){}

        auto result() const -> decltype(this->x / this->y) override{
            return this->x / this->y;
        }
};

void printBanner(){
    std::cout << "\t\tMENU\t\t" << std::endl;
    std::cout << "1. Addition " << std::endl;
    std::cout << "2. Multiplication " << std::endl;
    std::cout << "3. Substraction " << std::endl;
    std::cout << "4. Divide" << std::endl;;
}

auto programRun() {
    bool runProgram = true;
    double results = 0;
    double x = 0, y = 0;
    while (runProgram) {
        // Printing Menu Banner
        printBanner();

        // Variable holding a choosing 
        int choose = 0;
        std::cout << "Input : "; std::cin >> choose;

        // Handler input
        if (choose > 4 || choose < 1) {
            std::cout << "Error, when processing your input!" << std::endl;    
            runProgram = false;
            break;
        }
        else {
            switch (choose) {
                case 1:
                    std::cout << "Input the first number    : "; std::cin >> x;
                    std::cout << "Input the second number   : "; std::cin >> y;
                    {
                        Addition<double, double> ad(x, y);
                        results = ad.result();
                    }
                    break;

                case 2:
                    std::cout << "Input the first number    : "; std::cin >> x;
                    std::cout << "Input the second number   : "; std::cin >> y;
                    {
                        Multiplication<double, double> mp(x, y);
                        results = mp.result();
                    }
                    break;

                case 3:
                    std::cout << "Input the first number    : "; std::cin >> x;
                    std::cout << "Input the second number   : "; std::cin >> y;
                    {
                        Substraction<double, double> sub(x, y);
                        results = sub.result();
                    }
                    break;

                case 4:
                    std::cout << "Input the first number    : "; std::cin >> x;
                    std::cout << "Input the second number   : "; std::cin >> y;
                    if (y != 0) {
                        Divide<double, double> div(x, y);
                        results = div.result();
                    } else {
                        std::cout << "Error: Division by zero!" << std::endl;
                    }
                    break;

                default:
                    std::cout << "Thank You!" << std::endl;
                    runProgram = false;
                    break;
            }
            if (runProgram) {
                std::cout << "Result: " << results << std::endl;
            }
        }
    }

}


int main(){
    programRun();
    return 0;
}

