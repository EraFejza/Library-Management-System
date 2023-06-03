#ifndef GET_DATA_H_INCLUDED
#define GET_DATA_H_INCLUDED
void readDataFromFile(FILE* file, struct person* p, int* numPeople)
{
    while (*numPeople < 150 && fscanf(file, "%s %s %lf %s %d %d",
                                            p[*numPeople].name, p[*numPeople].surname, &(p[*numPeople].phone),
                                            p[*numPeople].address, &(p[*numPeople].ID), &(p[*numPeople].dueDate)) == 6)
    {
        fscanf(file, "%d", &p[*numPeople].numOfBooks);
        for(int i=0; i<p[*numPeople].numOfBooks; i++){
            fscanf(file, "%s", p[*numPeople].BB[i]);
        }
        (*numPeople)++;
    }

}
void printPersonArray(struct person* p, int numPeople) {
    for (int i = 0; i < numPeople; i++) {
        printf("Person %d:\n", i + 1);
        printf("Name: %s\n", p[i].name);
        printf("Surname: %s\n", p[i].surname);
        printf("Phone: %lf\n", p[i].phone);
        printf("Address: %s\n", p[i].address);
        printf("ID: %d\n", p[i].ID);
        printf("Due Date: %d\n", p[i].dueDate);
        printf("Number of Books: %d\n", p[i].numOfBooks);

        printf("Books Borrowed:\n");
        for (int j = 0; j < p[i].numOfBooks; j++) {
            printf("%s\n", p[i].BB[j]);
        }

        printf("\n");
    }
}
void readBookDataFromFile(FILE* file, struct book* p, int* numBooks)
{
    while (*numBooks < 300 && fscanf(file, "%s %s %d %d",
                                           p[*numBooks].title, p[*numBooks].author, &(p[*numBooks].amount), &(p[*numBooks].quantity)) == 4)
    {
        (*numBooks)++;
    }
}
void printBookData(struct book* p, int numBooks) {
    for (int i = 0; i < numBooks; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", p[i].title);
        printf("Author: %s\n", p[i].author);
        printf("Amount: %d\n", p[i].amount);
        printf("Quantity: %d\n", p[i].quantity);
        printf("\n");
    }
}


#endif // GET_DATA_H_INCLUDED


