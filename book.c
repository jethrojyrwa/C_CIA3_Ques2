#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOKNAME_LEN 100
#define BOOKCAT_LEN 10
#define NAME_LEN 50
#define NUMB 50

struct Book {
	unsigned int bookNo;
	char bookName[BOOKNAME_LEN];
	char bookCategory[BOOKCAT_LEN];
	char authorName[NAME_LEN];
	char publisherName[NAME_LEN];
    float cost;
	
};

void main()
{
    int ch;
	FILE *ptr;
	struct Book b;
	
	do{
	    printf("\n\nMENU");
	    printf("\n1. Read Book Data");
	    printf("\n2. Display Books in Alphabetical Order");
	    printf("\n3. Display Books with cost > 100");
	    printf("\n4. Display Books with cost > 200 and given Pubslisher");
	    printf("\n5. EXIT");
	    printf("\nEnter your choice: ");
	    scanf("%d",&ch);
	    
	    switch(ch)
	    {
	        case 1:
	        //PART 1
        	ptr = fopen("bookData","wb");
            if (ptr==NULL)
            {
                printf("\nFile Error");
                break;
            }
            
            for(int i=0;i<NUMB;i++)
            {
                printf("\nBook No.: ");
                scanf("%d",&b.bookNo);
                
                printf("\nBook Name: ");
                scanf("%s",b.bookName);
                
                printf("\nBook Category: ");
                scanf("%s",b.bookCategory);
                
                printf("\nAuthor Name: ");
                scanf("%s",b.authorName);
                
                printf("\nPublisher Name: ");
                scanf("%s",b.publisherName);
                
                printf("\nCost: ");
                scanf("%f",&b.cost);
                
                fwrite(&b,sizeof(struct Book),1,ptr);
                
            }
            fclose(ptr);
            break;
            
            case 2:
            //PART 2 
            ptr = fopen("bookData", "rb");
            if (ptr==NULL) {
                printf("Error opening file");
                break;
            }
        
            struct Book books[50];
            fread(books, sizeof(struct Book), 50, ptr);
        
            for (int i = 0; i < NUMB-1; i++) {
                for (int j = i + 1; j < NUMB; j++) {
                    if (strcmp(books[i].bookName, books[j].bookName) > 0) {
                        struct Book temp = books[i];
                        books[i] = books[j];
                        books[j] = temp;
                    }
                }
            }
            printf("\nBooks sorted by name:\n");
            
            for (int i = 0; i < NUMB; i++) {
                printf("Book Name: %s\n", books[i].bookName);
                printf("Book No: %d\n", books[i].bookNo);
                printf("Category: %s\n", books[i].bookCategory);
                printf("Author Name: %s\n", books[i].authorName);
                printf("Publisher Name: %s\n", books[i].publisherName);
                printf("Cost: %.2f\n\n", books[i].cost);
            }
            fclose(ptr);
            break;
            
            case 3:
            //PART 3 
            ptr = fopen("bookData","rb");
            if (ptr==NULL) {
                printf("Error opening file");
                break;
            }
            
            for(int i=0;i<NUMB;i++)
            {
                size_t book = fread(&b, sizeof(struct Book), 1, ptr);
                if (book != 1) {
                    perror("Error reading file");
                } else {
                    if(b.cost > 100)
                    {
                        printf("Book No: %d\n", b.bookNo);
                        printf("Book Name: %s\n", b.bookName);
                        printf("Category: %s\n", b.bookCategory);
                        printf("Author Name: %s\n", b.authorName);
                        printf("Publisher Name: %s\n", b.publisherName);
                        printf("Cost: %.2f\n\n", b.cost);
                    }
                }
            }
            fclose(ptr);
            break;
            
            case 4:
            //PART 4 
            char pname[NAME_LEN];
            printf("Enter publisher Name: ");
            scanf("%s",pname);
            printf("\n");
            
            ptr = fopen("bookData","rb");
            if (ptr==NULL) {
                printf("Error opening file");
                break;
            }
            
            for(int i=0;i<NUMB;i++)
            {
                size_t book = fread(&b, sizeof(struct Book), 1, ptr);
                if (book != 1) {
                    perror("Error reading file");
                } else {
                    if((b.cost > 200) && (strcmp(b.publisherName, pname) == 0))
                    {
                        printf("Book No: %d\n", b.bookNo);
                        printf("Book Name: %s\n", b.bookName);
                        printf("Category: %s\n", b.bookCategory);
                        printf("Author Name: %s\n", b.authorName);
                        printf("Publisher Name: %s\n", b.publisherName);
                        printf("Cost: %.2f\n\n", b.cost);
                    }
                }
            }
            fclose(ptr);
            break;
            
            case 5:
            break;
        }
	}while(ch!=5);    
}
