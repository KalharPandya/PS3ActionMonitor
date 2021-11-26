class variable{
    public:
    int value;
    String name;
    void display(){
        Serial.println(name+"="+value);
    }
};
class listener
{
public:
    int *var;
    int prevValue;
    bool use_threshold = false;
    int threshold = 10;
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
            if(*var!=0 && use_threshold && abs(*var - prevValue) < threshold)
                return false;
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