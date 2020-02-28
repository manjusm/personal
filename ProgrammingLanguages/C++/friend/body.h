#pragma once

class Handle;

class Body {
    
    friend class Handle;
    
    public:
    Body();
    Body(int);
    ~Body();

    private:
        int someData;
};
