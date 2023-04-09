#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int cont = 0;

    for(unsigned int i=0; s[i]!='\0';i++){
        ++cont;
    }

    return cont;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    
    bool eq = true;
    unsigned int i = 0;

    while(!(s1[i]=='\0' && s2[i]=='\0')){
        if(s1[i]!=s2[i]){
            eq = false;
            break;
        }
        i++;
    }

    return eq;

}

bool fstring_less_eq(fixstring s1, fixstring s2) {

    bool s1_less_s2 = true;
    unsigned int pos_s1 = 0;
    unsigned int pos_s2 = 0;

    char abc[] = {"abcdefghijklmnopqrstuvwxyz"};

    if(fstring_eq(s1,s2)){
        s1_less_s2 = false;
    }

    else{
        for(unsigned int i=0;;i++){
            if(s1[i]==s2[i]){
                ++pos_s1;
                ++pos_s2;
                continue;
            }
    
            for(unsigned int n=0;s1[i]!=abc[n]&&s1[i]!='\0';n++){
                ++pos_s1;
            }
            for(unsigned int n=0;s2[i]!=abc[n]&&s2[i]!='\0';n++){
                ++pos_s2;
            }
            s1_less_s2 = pos_s1<pos_s2 ? true:false;
            break;
        }        
    }

    return s1_less_s2;       
}

