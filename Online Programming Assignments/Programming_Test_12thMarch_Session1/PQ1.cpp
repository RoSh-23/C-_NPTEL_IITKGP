#include<iostream>
#include<cstring>
using namespace std;

char * AllocateMemory(char *, char *);

char * createMesaage(char *s, char *str,char *msg){
    strcpy(s, str);
    strcat(s, msg);
    return s;
}


char* client1(char* msg){
    char str[] = "client1: ";    
    char *s = AllocateMemory(str, msg);
    
    char *s1 = createMesaage(s,str,msg);
        
    return s1;
}

char* client2(char* msg){
    char str[] = "client2: ";
    char *s = AllocateMemory(str, msg);
    
    char *s1 = createMesaage(s,str,msg);
    
    
    return s1;
}

char* client3(char* msg){
    char str[] = "client3: ";
    
    char *s = AllocateMemory(str, msg);
    
    char *s1 = createMesaage(s,str,msg);
    
    
    return s1;
}
Rectangle::Rectangle(int _w, int _h) : w(_w), h(_h) // LINE-1

{ /* do not write anything */ }

Printer::Printer(int _ar) : ar(_ar) // LINE-2

{ /* do not write anything */ }

PrintableRect::PrintableRect(int _w, int _h) : Rectangle(_w, _h), Printer(_w * _h) // LINE-3

{ /* do not write anything */ }


    cin >> i >> msg;
    const char * caller(fun_ptr *, int, char*);
    const char *s = caller(fp, i, msg);
    cout << s;
    return 0;
}

const char* caller(fun_ptr *fp, int i, char* msg){

    if(i >= 0 && i < 3)
        fp[i](msg);

    else{    	
        const char *s = "unknown client";
    	return s;
	}
}