/* Prog.c */
#include <stdio.h>
void bad()
{
    char* new_name = "Quick brown fox jumped over the lazy dao";
    unsigned char* temp;
    temp = (unsigned char*)(&new_name);

}

int main(){
    struct {
        char *name;
        int age;
    } student = {.name = "John", .age = 22};
    bad();
    printf("student.name = %s\nstudent.age = %d\n", student.name, student.age);
    return 0;
}
