// json_c_tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "tests.h"
#include <string.h>

int _tmain(int argc, _TCHAR* argv[])
{
    if(argc<2){
        printf("usage: json_c_tests.exe test_name");
        return 1;
    }
    if(wcscmp(argv[1],L"test_floating")==0){
        return main_test_floating();
    }

    if(wcscmp(argv[1],L"test_cast")==0){
        return main_test_cast();
    }

    if(wcscmp(argv[1],L"test_parse")==0){
        return main_test_parse();
    }
    
	return 0;
}

