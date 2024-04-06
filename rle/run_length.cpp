#include "run_length.h"
using namespace std;

void decode_tuple(unsigned int count, int byte)
{
    for (unsigned int i = 0; i < count; ++i)
        cout << ' ' << byte;
}

void decode()
{
    int current_count;
    int current_value;
    cout << 0;
    for (;;)
    {
        cin >> current_count;
        if (current_count == -1)
            break;
        if (current_count < -1 || current_count > 255)
        {
            cout << " error";
            return;
        }

        cin >> current_value;
        if (current_value < 0 || current_value > 255)
        {
            cout << " error";
            return;
        }

        decode_tuple(current_count, current_value);
    }

    cout << ' ' << -1;
}


bool is_valid_value(int value)
{
    return (value >= -1 && value <= 255);
}

void encode()
{
    // implement encode function
    // NOTE: do not printout new line (i.e., std::endl or '\n')
    cout << 1;
    int 
        current_value=-1, 
        last_value=-1,
        count=1;
    // initial values
    cin >> current_value;
    last_value=current_value;

    while(current_value>=0) {
        cin >> current_value;
        if(is_valid_value(current_value)) {      
            if(current_value!=last_value || count==255 || current_value==-1)
            {
                cout << ' ' << count << ' ' << last_value;
                count=1;
                last_value=current_value;
            }
            else 
                count++;
        }
    }
    if(current_value == -1)
        cout << " -1";
    else 
        cout << " error";
}
