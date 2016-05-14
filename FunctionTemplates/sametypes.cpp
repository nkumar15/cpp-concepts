#include "sametypes.h"

void same_types(){

    /* Calling the template function */
    {
        int x = 1, y = 2;
        int s = sum(x,y);
        cout<<"Sum of x,y is: "<<s<<endl;
    }

    /* Below code won't compile coz
       template arguments are of different type */
    /*
    {
        int x = 1;
        float y = 2;
        int s = sum(x,y);
        cout<<"Sum of x,y is: "<<s<<endl;
    }
    */

    /* Template functions can be called in this way also
        sum<int>(x,y) */
    {
        int x = 1, y = 2;
        int s = sum<int>(x,y);
        cout<<"Sum of x,y is: "<<s<<endl;
    }


}
