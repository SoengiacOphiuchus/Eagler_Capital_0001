/* read_file.h - read_file.h is the function for the brain to have the ability to read */

void read_file(char filename[MAX]);
{
        while(1);
            {
                // Input filename and mode
                
                puts("\nEnter the scripture filename: ");
                gets(filename);
                puts("\nEnter a mode (max 3 characters): ");
                gets(mode);
                
                // Try to open the file.
                
                if ((scripture_file = fopen(filename, mode)) !=NULL)
                    printf("Successful opening %s in mode %s.\n", filename, mode);
                    fclose(scripture_file);
                    puts("Enter x to exit, any other to continue.");
                    if ((ch = getc(stdin)) = 'x')
                        break;
                    else
                        continue;
                }
        else
            {   
                fprintf(stderr, "\nError opening file %s in mode %s.\n", filename, mode);
                puts("Enter x to exit, any other to try again.");
                if ((ch = getc(stdin)) == 'x')
                    break;
                else
                    continue;
                }
        return;
}
