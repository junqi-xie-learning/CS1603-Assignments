#include <iostream>
using namespace std;

void flip(bool lights[5][5], int i, int j)
{
    lights[i][j] = !lights[i][j];
    if (j - 1 >= 0)
        lights[i][j - 1] = !lights[i][j - 1];
    if (i - 1 >= 0)
        lights[i - 1][j] = !lights[i - 1][j];
    if (i + 1 < 5)
        lights[i + 1][j] = !lights[i + 1][j];
    if (j + 1 < 5)
        lights[i][j + 1] = !lights[i][j + 1];
}

int main()
{
    bool lights[5][5] = { };
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
            lights[i][j] = static_cast<int>(cin.get() - '0');
        cin.get();
    }
    
    int min_flip = INT32_MAX;

    // try all the possibilities of the first row
    for (int a = 0; a < 2; ++a)
    {
        for (int b = 0; b < 2; ++b)
        {
            for (int c = 0; c < 2; ++c)
            {
                for (int d = 0; d < 2; ++d)
                {
                    for (int e = 0; e < 2; ++e)
                    {
                        bool lights_copy[5][5] = { };
                        for (int i = 0; i < 5; ++i)
                            for (int j = 0; j < 5; ++j)
                                lights_copy[i][j] = lights[i][j];
                        
                        // calculate the rest of the matrix based on the first row
                        int flip_time = a + b + c + d + e;
                        for (int i = 1; i < 5; ++i)
                            for (int j = 0; j < 5; ++j)
                                if (!lights_copy[i - 1][j])
                                {
                                    flip(lights_copy, i, j);
                                    ++flip_time;
                                }
                        
                        // test if the result obtained is a solution
                        bool has_found = true;
                        for (int j = 0; j < 5; ++j)
                            has_found &= lights_copy[4][j];
                        
                        // update the minimal
                        if (has_found)
                            min_flip = min(flip_time, min_flip);

                        flip(lights, 0, 4);
                    }
                    flip(lights, 0, 3);
                }
                flip(lights, 0, 2);
            }
            flip(lights, 0, 1);
        }
        flip(lights, 0, 0);
    }

    cout << min_flip << endl;
    return 0;
}