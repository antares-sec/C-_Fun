#ifndef CALCULATOR
#define CALCULATOR


class Calculator{
    public:

        int x = 0;
        int y = 0;       
        
        void set_operation(int x, int y);

        template <typename DataTypes>
        DataTypes show_results();

};

#endif