#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

//return element from [a ... b]
template <typename T>
T randFromRange (T min, T max){
    return rand() % (max-min+1) + min;
}

#endif // TOOLS_H_INCLUDED
