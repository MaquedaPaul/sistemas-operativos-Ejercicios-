
int f, c = 5;
struct file
{
    char *name;
    char file[];
};
void read();
void write();
void append();
void close();
void read_line(int);

void create_file(char *name, int filas, int columnas)
{

    char file[filas][columnas]{0};
    struct file archivo = {.name = name, .file = file};
};
