#ifndef STUDENT_H
#define STUDENT_H


class student
{
    char admno[6];
	char name[20];
	char stbno[6];
	int token;

    public:
        student();
        virtual ~student();
        void create_student();
        void show_student();
        void modify_student();
        char* retadmno();
        char* retstbno();
        int rettoken();
        void addtoken();
        void resettoken();
        void getstbno(char t[]);
        void report();

    protected:
    private:
};

#endif // STUDENT_H
