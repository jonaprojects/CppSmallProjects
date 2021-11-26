

#include <stdio.h> // for input and output operations
#include <string.h> // for strcmp, strcpy, strstr, strchr, etc ...
#include <stdlib.h>
#include <malloc.h> // for allocating memory dynamically with malloc()
#include <ctype.h> // for toupper(), tolower() , etc

const char* contains(const char* big_string, const char* small_string){ // custom method for finding substrings. basically an implementation of the strstr() built in method.
    printf("i'm here !!\n");
    size_t big_length = strlen(big_string), small_length = strlen(small_string);
    if(big_length < small_length){
        return NULL;
    } else if(big_length == small_length){ // if the lengths are equal, just check whether the strings are equal
        return strcmp(big_string, small_string) == 0 ? big_string : NULL;
    }else{
        const char* ptr = strchr(big_string,small_string[0]);
        while(ptr != NULL){
            if(strncmp(ptr,small_string, small_length) == 0){
                return ptr;
            }
            ptr++;
            ptr = strchr(ptr, small_string[0]);
        }
        return NULL;
    }
}
int num_of_instances(const char* given_string, const char given_char){
    const char* current_ptr = strchr(given_string,given_char);
    int sum = 0;
    while(current_ptr != NULL){
        ++sum;
        ++current_ptr;
        current_ptr = strchr(current_ptr, given_char);
    }
    return sum;
}

char* custom_to_upper(const char* given_string){ // memory leak ?
    size_t string_length = strlen(given_string);
    char* uppered_characters = (char*)malloc((string_length+1)*sizeof(char)); // plus one for the null terminator
    for(size_t i = 0; i<string_length;++i){
        if(isalpha(given_string[i])){
            if(islower(given_string[i])){
                uppered_characters[i] = toupper(given_string[i]);
            }else{
                uppered_characters[i] = given_string[i];
            }

        }else{
            uppered_characters[i] = given_string[i];
        }
    }
    uppered_characters[string_length] = '\0';
    return uppered_characters;
}
int main()
{
    /*
    // READING A FILE IN C 
    FILE* my_file = fopen("my_file.txt","r");
    char buffer[255];
    while(fgets(buffer,255,my_file) != NULL){
        printf("%s\n",buffer);
    }
    fclose(my_file); // closing a file
    */
    const char* message = "hello world";
    const char* substring = "ell";
    printf("the length of the string is %zu\n",strlen(message));
    const char* result = contains(message,substring);
    printf("Result: %s\n",result);
    printf("The length of the string is %zu\n",strlen(message));
    result = strstr(message,substring);
    printf("The result is also %s\n",result);
    const char* other_message = "this is another message";
    if(strcmp(message,other_message) == 0){
        printf("The messages are equal");
    }
    else{
        printf("The messages are not equal\n");
    }
    char my_letter = 'g';
    const char* instance = strchr(message, my_letter); // find the first instance of 'e' in the string
    if(instance != NULL){
        printf("Found the pointer to the first 'e' instance successfully !");
    }else{
        printf("The string does not contain the letter '%c' at all !", my_letter);
    }
    return 0;
}
