#ifndef BOOK_H
#define BOOK_H


class book
{
    char bno[6];
	char bname[50];
	char aname[20];

    public:
        book();
        virtual ~book();
        void create_book();
        void show_book();
        void modify_book();
        char* retbno();
        void report();

    protected:
    private:
};

#endif // BOOK_H
