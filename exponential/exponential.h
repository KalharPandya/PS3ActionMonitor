class Exponential{
    public:
    double b = 1;
    double min = 0,max = 255;
    int offset = 1;
    void setBoundry(double min, double max){
        this->min = min;
        this->max = max; 
    }
    void setB(double b){
        this->b = b;
    }
    double compute(double x){
         x = (abs(x)-min)/(max-min);
        offset = x/abs(x);
        return ((pow(2.7,(b*x))/(pow(2.7,b)))*(max-min) + min) * offset;
    }
};