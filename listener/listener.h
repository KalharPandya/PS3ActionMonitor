Exponential exponent;
class variable{
    public:
    int value = 0;
    String name;
    variable(){
        exponent.setB(3);
        exponent.setBoundry(0,255);
    }
    double getProcessedValue(){
        return exponent.compute(value);
    }

    void display(){
        Serial.println(name+"="+value);
    }
};
class listener
{
public:
    int *var;
    int prevValue;
    String name;
    variable v;
    listener() {}
    listener(int *ref)
    {
        set(ref);
    }
    listener(int *ref, String n)
    {
        set(ref, n);
    }

    void set(int *ref, String n = "Noname")
    {
        var = ref;
        prevValue = *var;
        name = n;
    }
    bool check()
    {
        if (prevValue != *var)
        {
            prevValue = *var;
            return true;
        }
        return false;
    }

    variable get()
    {
        v.value = *var;
        v.name = name;
        return v;
    }
};