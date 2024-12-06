#include "proxy_parse.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <pthreads.h>

#define MAX_CLIENTS 10

typedef struct cache_element cache_element;


// defining a struct for linked list of elements in cache memory
struct cache_element
{
    char* data;
    int len;
    char* url;
    time_t lru_time_track;
    cache_element* next;  

};

// defining a work flow or function that we will implement here

cache_element* find( char* url);

int add_cache_element(char* data, int size, char* url);

void remove_cache_element();

int port_number = 8000;

// need to setup individual socket connections

int proxy_socketid;

// jitne client utne hi socket and then utne hi threads

pthread_t tid[MAX_CLIENTS];  // tid here is thread id